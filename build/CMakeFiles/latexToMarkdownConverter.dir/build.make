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
CMAKE_SOURCE_DIR = /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build

# Include any dependencies generated for this target.
include CMakeFiles/latexToMarkdownConverter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/latexToMarkdownConverter.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/latexToMarkdownConverter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/latexToMarkdownConverter.dir/flags.make

parser.cpp: ../src/parser.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][PARSER] Building parser with bison 3.8.2"
	cd /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter && /usr/bin/bison --defines=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.hpp -o /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp src/parser.y

parser.hpp: parser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate parser.hpp

lexer.cpp: ../src/lexer.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[FLEX][LEXER] Building scanner with flex 2.6.4"
	cd /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter && /usr/bin/flex --header-file=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/lexer.hpp -o/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/lexer.cpp src/lexer.l

lexer.hpp: lexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate lexer.hpp

CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.o: CMakeFiles/latexToMarkdownConverter.dir/flags.make
CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.o: CMakeFiles/latexToMarkdownConverter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.o -MF CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.o.d -o CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.o -c /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/main.cpp

CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/main.cpp > CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.i

CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/main.cpp -o CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.s

CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.o: CMakeFiles/latexToMarkdownConverter.dir/flags.make
CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.o: ../src/AST.cpp
CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.o: CMakeFiles/latexToMarkdownConverter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.o -MF CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.o.d -o CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.o -c /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp

CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp > CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.i

CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/src/AST.cpp -o CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.s

CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.o: CMakeFiles/latexToMarkdownConverter.dir/flags.make
CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.o: lexer.cpp
CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.o: parser.hpp
CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.o: CMakeFiles/latexToMarkdownConverter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.o -MF CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.o.d -o CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.o -c /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/lexer.cpp

CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/lexer.cpp > CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.i

CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/lexer.cpp -o CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.s

CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.o: CMakeFiles/latexToMarkdownConverter.dir/flags.make
CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.o: parser.cpp
CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.o: CMakeFiles/latexToMarkdownConverter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.o -MF CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.o.d -o CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.o -c /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp

CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp > CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.i

CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp -o CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.s

# Object files for target latexToMarkdownConverter
latexToMarkdownConverter_OBJECTS = \
"CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.o" \
"CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.o" \
"CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.o" \
"CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.o"

# External object files for target latexToMarkdownConverter
latexToMarkdownConverter_EXTERNAL_OBJECTS =

latexToMarkdownConverter: CMakeFiles/latexToMarkdownConverter.dir/src/main.cpp.o
latexToMarkdownConverter: CMakeFiles/latexToMarkdownConverter.dir/src/AST.cpp.o
latexToMarkdownConverter: CMakeFiles/latexToMarkdownConverter.dir/lexer.cpp.o
latexToMarkdownConverter: CMakeFiles/latexToMarkdownConverter.dir/parser.cpp.o
latexToMarkdownConverter: CMakeFiles/latexToMarkdownConverter.dir/build.make
latexToMarkdownConverter: CMakeFiles/latexToMarkdownConverter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable latexToMarkdownConverter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/latexToMarkdownConverter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/latexToMarkdownConverter.dir/build: latexToMarkdownConverter
.PHONY : CMakeFiles/latexToMarkdownConverter.dir/build

CMakeFiles/latexToMarkdownConverter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/latexToMarkdownConverter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/latexToMarkdownConverter.dir/clean

CMakeFiles/latexToMarkdownConverter.dir/depend: lexer.cpp
CMakeFiles/latexToMarkdownConverter.dir/depend: lexer.hpp
CMakeFiles/latexToMarkdownConverter.dir/depend: parser.cpp
CMakeFiles/latexToMarkdownConverter.dir/depend: parser.hpp
	cd /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build /mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/CMakeFiles/latexToMarkdownConverter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/latexToMarkdownConverter.dir/depend

