message(STATUS "> Found SEGYREADER's source directory")

set(target_name segy_reader)

add_library(${target_name} STATIC "")

target_sources(${target_name}
    PRIVATE
        "${PROJECT_SOURCE_DIR}/src/segy_reader.cpp"
        "${PROJECT_SOURCE_DIR}/include/segy_reader.hpp"
)

target_include_directories(${target_name}
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include"
)

set_property(TARGET ${target_name} PROPERTY FOLDER "SEGYReader")
