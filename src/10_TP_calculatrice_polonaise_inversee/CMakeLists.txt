
file(GLOB LOCAL_CPP_SOURCES "src/*.cpp")


foreach( file ${LOCAL_CPP_SOURCES} )
    get_filename_component( FNAME ${file} NAME )
    string( REPLACE ".cpp" ".out" name ${FNAME})
    message("name = " ${name})
    add_executable( ${name} ${file} )
    string( REPLACE ".cpp" "" testname ${FNAME})
    add_test ( NAME ${testname} COMMAND ./${name} )
endforeach( file ${LOCAL_CPP_SOURCES} )



