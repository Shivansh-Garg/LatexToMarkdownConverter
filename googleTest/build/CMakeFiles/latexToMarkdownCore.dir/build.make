# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build

# Include any dependencies generated for this target.
include CMakeFiles/latexToMarkdownCore.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/latexToMarkdownCore.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/latexToMarkdownCore.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/latexToMarkdownCore.dir/flags.make

parser.cpp: /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/parser.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][MyParser] Building parser with bison 3.8.2"
	cd /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest && /usr/bin/bison -d -o /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y

parser.hpp: parser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate parser.hpp

lexer.cpp: /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/lexer.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[FLEX][MyLexer] Building scanner with flex 2.6.4"
	cd /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest && /usr/bin/flex -o/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/lexer.cpp /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/lexer.l

CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.o: CMakeFiles/latexToMarkdownCore.dir/flags.make
CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.o: /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp
CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.o: CMakeFiles/latexToMarkdownCore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.o -MF CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.o.d -o CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.o -c /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp

CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp > CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.i

CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp -o CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.s

CMakeFiles/latexToMarkdownCore.dir/parser.cpp.o: CMakeFiles/latexToMarkdownCore.dir/flags.make
CMakeFiles/latexToMarkdownCore.dir/parser.cpp.o: parser.cpp
CMakeFiles/latexToMarkdownCore.dir/parser.cpp.o: CMakeFiles/latexToMarkdownCore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/latexToMarkdownCore.dir/parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/latexToMarkdownCore.dir/parser.cpp.o -MF CMakeFiles/latexToMarkdownCore.dir/parser.cpp.o.d -o CMakeFiles/latexToMarkdownCore.dir/parser.cpp.o -c /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp

CMakeFiles/latexToMarkdownCore.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/latexToMarkdownCore.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp > CMakeFiles/latexToMarkdownCore.dir/parser.cpp.i

CMakeFiles/latexToMarkdownCore.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/latexToMarkdownCore.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp -o CMakeFiles/latexToMarkdownCore.dir/parser.cpp.s

CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.o: CMakeFiles/latexToMarkdownCore.dir/flags.make
CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.o: lexer.cpp
CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.o: parser.hpp
CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.o: CMakeFiles/latexToMarkdownCore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.o -MF CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.o.d -o CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.o -c /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/lexer.cpp

CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/lexer.cpp > CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.i

CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/lexer.cpp -o CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.s

# Object files for target latexToMarkdownCore
latexToMarkdownCore_OBJECTS = \
"CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.o" \
"CMakeFiles/latexToMarkdownCore.dir/parser.cpp.o" \
"CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.o"

# External object files for target latexToMarkdownCore
latexToMarkdownCore_EXTERNAL_OBJECTS =

liblatexToMarkdownCore.a: CMakeFiles/latexToMarkdownCore.dir/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp.o
liblatexToMarkdownCore.a: CMakeFiles/latexToMarkdownCore.dir/parser.cpp.o
liblatexToMarkdownCore.a: CMakeFiles/latexToMarkdownCore.dir/lexer.cpp.o
liblatexToMarkdownCore.a: CMakeFiles/latexToMarkdownCore.dir/build.make
liblatexToMarkdownCore.a: CMakeFiles/latexToMarkdownCore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library liblatexToMarkdownCore.a"
	$(CMAKE_COMMAND) -P CMakeFiles/latexToMarkdownCore.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/latexToMarkdownCore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/latexToMarkdownCore.dir/build: liblatexToMarkdownCore.a
.PHONY : CMakeFiles/latexToMarkdownCore.dir/build

CMakeFiles/latexToMarkdownCore.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/latexToMarkdownCore.dir/cmake_clean.cmake
.PHONY : CMakeFiles/latexToMarkdownCore.dir/clean

CMakeFiles/latexToMarkdownCore.dir/depend: lexer.cpp
CMakeFiles/latexToMarkdownCore.dir/depend: parser.cpp
CMakeFiles/latexToMarkdownCore.dir/depend: parser.hpp
	cd /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/CMakeFiles/latexToMarkdownCore.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/latexToMarkdownCore.dir/depend

