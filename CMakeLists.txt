cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(latexToMarkdownConverter VERSION 1.0 LANGUAGES C CXX)

# Define directories for source files and output
set(SRCDIRECTORY "src")
set(OUTPUTDIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

# Find Flex and Bison tools
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Set names for lexer and parser output files
set(LEXERFILE "${OUTPUTDIRECTORY}/lexer.cpp")
set(PARSERFILE "${OUTPUTDIRECTORY}/parser.cpp")

# Generate lexer and parser files from source
flex_target(LEXER "${SRCDIRECTORY}/lexer.l" "${LEXERFILE}" DEFINES_FILE "${OUTPUTDIRECTORY}/lexer.hpp")
bison_target(PARSER "${SRCDIRECTORY}/parser.y" "${PARSERFILE}" DEFINES_FILE "${OUTPUTDIRECTORY}/parser.hpp")
add_flex_bison_dependency(LEXER PARSER)

# Include directory for generated files
include_directories("${OUTPUTDIRECTORY}")

# Create the executable and list its source files
add_executable(latexToMarkdownConverter
    "${SRCDIRECTORY}/main.cpp"
    "${SRCDIRECTORY}/AST.cpp"
    "${LEXERFILE}"
    "${PARSERFILE}"
)

# Include the source directory for headers
target_include_directories(latexToMarkdownConverter PRIVATE "${SRCDIRECTORY}")
