# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lixiang/Desktop/cpp-practice/Calendar_output

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lixiang/Desktop/cpp-practice/build

# Include any dependencies generated for this target.
include CMakeFiles/Calendar_output.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Calendar_output.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Calendar_output.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Calendar_output.dir/flags.make

CMakeFiles/Calendar_output.dir/main.cpp.o: CMakeFiles/Calendar_output.dir/flags.make
CMakeFiles/Calendar_output.dir/main.cpp.o: /Users/lixiang/Desktop/cpp-practice/Calendar_output/main.cpp
CMakeFiles/Calendar_output.dir/main.cpp.o: CMakeFiles/Calendar_output.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lixiang/Desktop/cpp-practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Calendar_output.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Calendar_output.dir/main.cpp.o -MF CMakeFiles/Calendar_output.dir/main.cpp.o.d -o CMakeFiles/Calendar_output.dir/main.cpp.o -c /Users/lixiang/Desktop/cpp-practice/Calendar_output/main.cpp

CMakeFiles/Calendar_output.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Calendar_output.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lixiang/Desktop/cpp-practice/Calendar_output/main.cpp > CMakeFiles/Calendar_output.dir/main.cpp.i

CMakeFiles/Calendar_output.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Calendar_output.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lixiang/Desktop/cpp-practice/Calendar_output/main.cpp -o CMakeFiles/Calendar_output.dir/main.cpp.s

# Object files for target Calendar_output
Calendar_output_OBJECTS = \
"CMakeFiles/Calendar_output.dir/main.cpp.o"

# External object files for target Calendar_output
Calendar_output_EXTERNAL_OBJECTS =

Calendar_output: CMakeFiles/Calendar_output.dir/main.cpp.o
Calendar_output: CMakeFiles/Calendar_output.dir/build.make
Calendar_output: CMakeFiles/Calendar_output.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lixiang/Desktop/cpp-practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Calendar_output"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Calendar_output.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Calendar_output.dir/build: Calendar_output
.PHONY : CMakeFiles/Calendar_output.dir/build

CMakeFiles/Calendar_output.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Calendar_output.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Calendar_output.dir/clean

CMakeFiles/Calendar_output.dir/depend:
	cd /Users/lixiang/Desktop/cpp-practice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lixiang/Desktop/cpp-practice/Calendar_output /Users/lixiang/Desktop/cpp-practice/Calendar_output /Users/lixiang/Desktop/cpp-practice/build /Users/lixiang/Desktop/cpp-practice/build /Users/lixiang/Desktop/cpp-practice/build/CMakeFiles/Calendar_output.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Calendar_output.dir/depend

