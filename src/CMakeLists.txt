
file(GLOB LOCAL_DIR "*")

foreach( item ${LOCAL_DIR} )
  if( IS_DIRECTORY ${item})
      if( EXISTS "${item}/CMakeLists.txt" )
	 MESSAGE( "Add directory ${item} to tests" )
	 add_subdirectory(${item})
      endif( EXISTS "${item}/CMakeLists.txt" )
  endif( IS_DIRECTORY ${item} )
endforeach(item ${LOCAL_DIR} )


