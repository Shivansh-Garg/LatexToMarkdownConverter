# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(latexToMarkdownConverter VERSION 1.0 LANGUAGES C CXX)

# Set the source directory
set(SRC_DIR "src")
set(OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Find Flex and Bison packages
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Specify the output files for the generated lexer and parser
set(LEXER_OUT "${OUTPUT_DIR}/lexer.cpp")
set(PARSER_OUT "${OUTPUT_DIR}/parser.cpp")

# Generate the lexer and parser
flex_target(LEXER "${SRC_DIR}/lexer.l" "${LEXER_OUT}" DEFINES_FILE "${OUTPUT_DIR}/lexer.hpp")
bison_target(PARSER "${SRC_DIR}/parser.y" "${PARSER_OUT}" DEFINES_FILE "${OUTPUT_DIR}/parser.hpp")
add_flex_bison_dependency(LEXER PARSER)

# Include the output directory for generated headers
include_directories("${OUTPUT_DIR}")

# Add the executable target
add_executable(latexToMarkdownConverter
    "${SRC_DIR}/main.cpp"
    "${SRC_DIR}/AST.cpp"
    "${LEXER_OUT}"
    "${PARSER_OUT}"
)

target_include_directories(latexToMarkdownConverter PRIVATE "${SRC_DIR}")

