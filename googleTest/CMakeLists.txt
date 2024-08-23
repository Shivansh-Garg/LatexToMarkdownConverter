cmake_minimum_required(VERSION 3.10)

# Project name
project(latexToMarkdownTest)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include main project's src directory
include_directories(${CMAKE_SOURCE_DIR}/../src)

# Find and configure Flex and Bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Define the Flex and Bison targets
BISON_TARGET(MyParser ${CMAKE_SOURCE_DIR}/../src/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(MyLexer ${CMAKE_SOURCE_DIR}/../src/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyLexer MyParser)

# Create a static library for the core functionality
set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/../src/AST.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp
)

add_library(latexToMarkdownCore STATIC ${SOURCE_FILES})

# Google Test - Fetch it if not already available
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Link Google Test libraries
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add the test executable
add_executable(tests
    ../test/test_main.cpp
    ../test/test_AST.cpp
)

# Link the Google Test libraries and the core library
target_link_libraries(tests gtest_main latexToMarkdownCore)

# Enable testing
enable_testing()

# Add test cases
add_test(NAME RunTests COMMAND tests)
