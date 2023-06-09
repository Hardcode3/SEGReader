
add_executable(test_textual_header test_textual_header.cpp)
target_link_libraries(test_textual_header PUBLIC segy_reader)
add_test(NAME test_textual_header COMMAND test_textual_header)

set_property(
    TARGET test_textual_header
    PROPERTY FOLDER "Tests/TextualHeader"
)
