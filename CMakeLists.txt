cmake_minimum_required(VERSION 3.10)

# Project name and version
project(latexToMarkdownConverter VERSION 1.0 LANGUAGES C CXX)


set(SRCDIRECTORY "src")
set(OUTPUTDIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(LEXERFILE "${OUTPUTDIRECTORY}/lexer.cpp")
set(PARSERFILE "${OUTPUTDIRECTORY}/parser.cpp")

flex_target(LEXER "${SRCDIRECTORY}/lexer.l" "${LEXERFILE}" DEFINES_FILE "${OUTPUTDIRECTORY}/lexer.hpp")
bison_target(PARSER "${SRCDIRECTORY}/parser.y" "${PARSERFILE}" DEFINES_FILE "${OUTPUTDIRECTORY}/parser.hpp")
add_flex_bison_dependency(LEXER PARSER)

include_directories("${OUTPUTDIRECTORY}")

add_executable(latexToMarkdownConverter
    "${SRCDIRECTORY}/main.cpp"
    "${SRCDIRECTORY}/AST.cpp"
    "${LEXERFILE}"
    "${PARSERFILE}"
)

target_include_directories(latexToMarkdownConverter PRIVATE "${SRCDIRECTORY}")

