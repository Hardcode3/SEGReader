cmake_minimum_required(VERSION 2.8.12...3.24)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(
    "SEGYREADER"
    VERSION 0.1
    DESCRIPTION "A segy reader code written in C++"
    HOMEPAGE_URL "https://github.com/Hardcode3/SEGYReader"
)

option(SEGYREADER_COMPILE_TESTS "Compile the tests of SEGYREADER" ON)


add_subdirectory(src)

if(SEGYREADER_COMPILE_TESTS)
    add_subdirectory(tests)
endif()
