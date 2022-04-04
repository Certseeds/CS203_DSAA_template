#include <catch2/catch_test_macros.hpp>
#include <catch2/internal/catch_xmlwriter.hpp>

#include <catch2/internal/catch_stream.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include <sstream>

static std::string encode( std::string const& str, Catch::XmlEncode::ForWhat forWhat = Catch::XmlEncode::ForTextNodes ) {
    Catch::ReusableStringStream oss;
    oss << Catch::XmlEncode( str, forWhat );
    return oss.str();
}

TEST_CASE( "XmlEncode", "[XML]" ) {
    SECTION( "normal string" ) {
        REQUIRE( encode( "normal string" ) == "normal string" );
    }
    SECTION( "empty string" ) {
        REQUIRE( encode( "" ) == "" );
    }
    SECTION( "string with ampersand" ) {
        REQUIRE( encode( "smith & jones" ) == "smith &amp; jones" );
    }
    SECTION( "string with less-than" ) {
        REQUIRE( encode( "smith < jones" ) == "smith &lt; jones" );
    }
    SECTION( "string with greater-than" ) {
        REQUIRE( encode( "smith > jones" ) == "smith > jones" );
        REQUIRE( encode( "smith ]]> jones" ) == "smith ]]&gt; jones" );
    }
    SECTION( "string with quotes" ) {
        std::string stringWithQuotes = "don't \"quote\" me on that";
        REQUIRE( encode( stringWithQuotes ) == stringWithQuotes );
        REQUIRE( encode( stringWithQuotes, Catch::XmlEncode::ForAttributes ) == "don't &quot;quote&quot; me on that" );
    }
    SECTION( "string with control char (1)" ) {
        REQUIRE( encode( "[\x01]" ) == "[\\x01]" );
    }
    SECTION( "string with control char (x7F)" ) {
        REQUIRE( encode( "[\x7F]" ) == "[\\x7F]" );
    }
}

// Thanks to Peter Bindels (dascandy) for some of the tests
TEST_CASE("XmlEncode: UTF-8", "[XML][UTF-8][approvals]") {
#define ESC(lit) reinterpret_cast<const char*>(lit)
    SECTION("Valid utf-8 strings") {
        CHECK(encode(ESC(u8"Here be 👾")) == ESC(u8"Here be 👾"));
        CHECK(encode(ESC(u8"šš")) == ESC(u8"šš"));

        CHECK(encode("\xDF\xBF")         == "\xDF\xBF"); // 0x7FF
        CHECK(encode("\xE0\xA0\x80")     == "\xE0\xA0\x80"); // 0x800
        CHECK(encode("\xED\x9F\xBF")     == "\xED\x9F\xBF"); // 0xD7FF
        CHECK(encode("\xEE\x80\x80")     == "\xEE\x80\x80"); // 0xE000
        CHECK(encode("\xEF\xBF\xBF")     == "\xEF\xBF\xBF"); // 0xFFFF
        CHECK(encode("\xF0\x90\x80\x80") == "\xF0\x90\x80\x80"); // 0x10000
        CHECK(encode("\xF4\x8F\xBF\xBF") == "\xF4\x8F\xBF\xBF"); // 0x10FFFF
    }
    SECTION("Invalid utf-8 strings") {
        SECTION("Various broken strings") {
            CHECK(encode(ESC("Here \xFF be \xF0\x9F\x91\xBE")) == ESC(u8"Here \\xFF be 👾"));
            CHECK(encode("\xFF") == "\\xFF");
            CHECK(encode("\xC5\xC5\xA0") == ESC(u8"\\xC5Š"));
            CHECK(encode("\xF4\x90\x80\x80") == ESC(u8"\\xF4\\x90\\x80\\x80")); // 0x110000 -- out of unicode range
        }

        SECTION("Overlong encodings") {
            CHECK(encode("\xC0\x80") == "\\xC0\\x80"); // \0
            CHECK(encode("\xF0\x80\x80\x80") == "\\xF0\\x80\\x80\\x80"); // Super-over-long \0
            CHECK(encode("\xC1\xBF") == "\\xC1\\xBF"); // ASCII char as UTF-8 (0x7F)
            CHECK(encode("\xE0\x9F\xBF") == "\\xE0\\x9F\\xBF"); // 0x7FF
            CHECK(encode("\xF0\x8F\xBF\xBF") == "\\xF0\\x8F\\xBF\\xBF"); // 0xFFFF
        }

        // Note that we actually don't modify surrogate pairs, as we do not do strict checking
        SECTION("Surrogate pairs") {
            CHECK(encode("\xED\xA0\x80") == "\xED\xA0\x80"); // Invalid surrogate half 0xD800
            CHECK(encode("\xED\xAF\xBF") == "\xED\xAF\xBF"); // Invalid surrogate half 0xDBFF
            CHECK(encode("\xED\xB0\x80") == "\xED\xB0\x80"); // Invalid surrogate half 0xDC00
            CHECK(encode("\xED\xBF\xBF") == "\xED\xBF\xBF"); // Invalid surrogate half 0xDFFF
        }

        SECTION("Invalid start byte") {
            CHECK(encode("\x80") == "\\x80");
            CHECK(encode("\x81") == "\\x81");
            CHECK(encode("\xBC") == "\\xBC");
            CHECK(encode("\xBF") == "\\xBF");
            // Out of range
            CHECK(encode("\xF5\x80\x80\x80") == "\\xF5\\x80\\x80\\x80");
            CHECK(encode("\xF6\x80\x80\x80") == "\\xF6\\x80\\x80\\x80");
            CHECK(encode("\xF7\x80\x80\x80") == "\\xF7\\x80\\x80\\x80");
        }

        SECTION("Missing continuation byte(s)") {
            // Missing first continuation byte
            CHECK(encode("\xDE") == "\\xDE");
            CHECK(encode("\xDF") == "\\xDF");
            CHECK(encode("\xE0") == "\\xE0");
            CHECK(encode("\xEF") == "\\xEF");
            CHECK(encode("\xF0") == "\\xF0");
            CHECK(encode("\xF4") == "\\xF4");

            // Missing second continuation byte
            CHECK(encode("\xE0\x80") == "\\xE0\\x80");
            CHECK(encode("\xE0\xBF") == "\\xE0\\xBF");
            CHECK(encode("\xE1\x80") == "\\xE1\\x80");
            CHECK(encode("\xF0\x80") == "\\xF0\\x80");
            CHECK(encode("\xF4\x80") == "\\xF4\\x80");

            // Missing third continuation byte
            CHECK(encode("\xF0\x80\x80") == "\\xF0\\x80\\x80");
            CHECK(encode("\xF4\x80\x80") == "\\xF4\\x80\\x80");
        }
    }
#undef ESC
}

TEST_CASE("XmlWriter writes boolean attributes as true/false", "[XML][XmlWriter]") {
    using Catch::Matchers::ContainsSubstring;
    std::stringstream stream;
    {
        Catch::XmlWriter xml(stream);

        xml.scopedElement("Element1")
            .writeAttribute("attr1", true)
            .writeAttribute("attr2", false);
    }

    REQUIRE_THAT( stream.str(),
                  ContainsSubstring(R"(attr1="true")") &&
                  ContainsSubstring(R"(attr2="false")") );
}

TEST_CASE("XmlWriter does not escape comments", "[XML][XmlWriter][approvals]") {
    using Catch::Matchers::ContainsSubstring;
    std::stringstream stream;
    {
        Catch::XmlWriter xml(stream);

        xml.writeComment(R"(unescaped special chars: < > ' " &)");
    }
    REQUIRE_THAT( stream.str(),
                  ContainsSubstring(R"(<!-- unescaped special chars: < > ' " & -->)"));
}

TEST_CASE("XmlWriter errors out when writing text without enclosing element", "[XmlWriter][approvals]") {
    std::stringstream stream;
    Catch::XmlWriter xml(stream);
    REQUIRE_THROWS(xml.writeText("some text"));
}

TEST_CASE("XmlWriter escapes text properly", "[XML][XmlWriter][approvals]") {
    using Catch::Matchers::ContainsSubstring;
    std::stringstream stream;
    {
        Catch::XmlWriter xml(stream);
        xml.scopedElement("root")
           .writeText(R"(Special chars need escaping: < > ' " &)");
    }

    REQUIRE_THAT( stream.str(),
                  ContainsSubstring(R"(Special chars need escaping: &lt; > ' " &amp;)"));
}

TEST_CASE("XmlWriter escapes attributes properly", "[XML][XmlWriter][approvals]") {
    using Catch::Matchers::ContainsSubstring;
    std::stringstream stream;
    {
        Catch::XmlWriter xml(stream);
        xml.scopedElement("root")
           .writeAttribute("some-attribute", R"(Special chars need escaping: < > ' " &)");
    }

    REQUIRE_THAT(stream.str(),
                 ContainsSubstring(R"(some-attribute="Special chars need escaping: &lt; > ' &quot; &amp;")"));
}
