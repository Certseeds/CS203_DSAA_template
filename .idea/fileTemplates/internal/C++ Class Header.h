#set( $GITHUB_USER = "Certseeds" )
#parse("FILE_HEAD_CPP.h")
#parse("LICENSE_AGPL_CPP.h")
#[[#ifndef]]# ${INCLUDE_GUARD}
#[[#define]]# ${INCLUDE_GUARD}

${NAMESPACES_OPEN}

class ${NAME} {

};

${NAMESPACES_CLOSE}

#[[#endif]]# //${INCLUDE_GUARD}
