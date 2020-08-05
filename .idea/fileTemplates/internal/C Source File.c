#set( $GITHUB_USER = "Certseeds" )
#parse("FILE_HEAD_CPP.h")
#parse("LICENSE_MIT_CPP.h")
#if (${HEADER_FILENAME})
#[[#include]]# "${HEADER_FILENAME}"
#end
