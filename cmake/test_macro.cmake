
MACRO(AutoAddTests SRC_DIR)

file(GLOB LOCAL_CPP_SOURCES ${SRC_DIR}/*.cpp)

foreach( file ${LOCAL_CPP_SOURCES} )
    get_filename_component( FNAME ${file} NAME )
    string( REPLACE ".cpp" ".out" name ${FNAME})
    add_executable( ${name} ${file} )
    string( REPLACE ".cpp" "" testname ${FNAME})

    ## Check if bash runner file exists

    if( ${FNAME} MATCHES ".*(argv|argc|cin|norun).*.cpp" )
        message("Bypass test: " ${FNAME})
    else()
        ##message("add test direct call =" ${name})
        add_test ( NAME ${testname} COMMAND ./${name} )
    endif( ${FNAME} MATCHES ".*(argv|argc|cin|norun).*.cpp" )
    
endforeach( file ${LOCAL_CPP_SOURCES} )
ENDMACRO(AutoAddTests)


