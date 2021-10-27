include(CheckCXXCompilerFlag)



check_cxx_compiler_flag("-std=c++2a" HAS_STDCXX_2a)
if( HAS_STDCXX_2a)
    message("Your c++ compiler support C++20")
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
else()
    message(WARNING "Your c++ computer doesn't support c++20, we try 17")
    check_cxx_compiler_flag("-std=c++17" HAS_STDCXX_17)
    if( HAS_STDCXX_17)
        message(Your c++ compiler support C++17)
        set(CMAKE_CXX_STANDARD 17)
        set(CMAKE_CXX_STANDARD_REQUIRED ON)
    else()
        message(WARNING "Your c++ computer doesn't support c++20, we try 14")
        check_cxx_compiler_flag("-std=c++14" HAS_STDCXX_14)
        if( HAS_STDCXX_14)
            message(Your c++ compiler support C++14)
            set(CMAKE_CXX_STANDARD 14)
            set(CMAKE_CXX_STANDARD_REQUIRED ON)
        else()
            message(WARNING "Your c++ computer doesn't support c++14, we try 11")
            check_cxx_compiler_flag("-std=c++11" HAS_STDCXX_11)
            if( HAS_STDCXX_11)
                message(Your c++ compiler support C++11)
                set(CMAKE_CXX_STANDARD 11)
                set(CMAKE_CXX_STANDARD_REQUIRED ON)
            else()
                message(FATAL_ERROR "Your compiler doesn't support c++11 ... ")
            endif(HAS_STDCXX_11)
        endif(HAS_STDCXX_14)
    endif(HAS_STDCXX_17)
endif(HAS_STDCXX_2a)


MACRO(AddCXXFlag FLAG REQUIRED)
check_cxx_compiler_flag("-${FLAG}" "${FLAG}_AVAILABLE")
if(${${FLAG}_AVAILABLE})
    set(CMAKE_CXX_FLAGS "-${FLAG} ${CMAKE_CXX_FLAGS}")
    message(STATUS "flag: '-${FLAG}' enabled")
else()
    if( ${REQUIRED} )
        message(FATAL_ERROR "flag -${FLAG} is required but seems to be not supported by your compiler")
    else()
        message(STATUS "flag: -${FLAG} disabled")
    endif( ${REQUIRED} )
endif(${${FLAG}_AVAILABLE})
ENDMACRO(AddCXXFlag)

AddCXXFlag("Wall" TRUE)
AddCXXFlag("Wextra" TRUE)
AddCXXFlag("Wpedantic" TRUE)
AddCXXFlag("Wfatal-errors" TRUE)

