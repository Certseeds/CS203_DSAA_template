#ifndef UTF8_H
#define UTF8_H

// --- UTF-8 ---
// Macro copied from the sqlite code
// Kind of utf8-aware p++
#define _utf8_incr(zIn) {                        \
      if ((*(zIn++)) >= 0xc0) {                        \
         while ((*zIn & 0xc0) == 0x80) { zIn++; }      \
      }                                                \
   }

#ifdef __cplusplus
extern "C" {
#endif

int utf8_charlen(unsigned char *p);

int utf8_bytes_to_charpos(unsigned char *s, int pos);

// utf8_charpos_to_bytes returns -1 if s isn't a valid UTF-8 string
int utf8_charpos_to_bytes(unsigned char *s, int pos);

// utf8_to_codepoint returns 0 if conversion fails. If it succeeds,
// the value pointed by lenptr is set to the number of bytes of the
// UTF-8 character
unsigned int utf8_to_codepoint(const unsigned char *u,
                               int *lenptr);

// Returns the length in bytes, 0 if invalid
int isutf8(const unsigned char *u);

// strchr-like function for utf8 characters. Returns NULL if
// "needle" is an invalid utf8 character.
unsigned char *utf8_search(const unsigned char *haystack,
                           const unsigned char *needle);

// ------------------------------------------------------
// The second argument to these functions must be an
// array of at least 5 elements (it will store a single
// utf8 character). A pointer to this array will be
// returned if functions succeed.
// ------------------------------------------------------
unsigned char *decimal_to_utf8(unsigned int d,
                               unsigned char *utf8);

unsigned char *codepoint_to_utf8(unsigned int cp,
                                 unsigned char *utf8);

#ifdef __cplusplus
}
#endif

#endif
