# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/velhomago/qlchallenge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/velhomago/qlchallenge/build

# Include any dependencies generated for this target.
include CMakeFiles/qlchallenge.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/qlchallenge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qlchallenge.dir/flags.make

CMakeFiles/qlchallenge.dir/src/Main.cpp.o: CMakeFiles/qlchallenge.dir/flags.make
CMakeFiles/qlchallenge.dir/src/Main.cpp.o: ../src/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/velhomago/qlchallenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/qlchallenge.dir/src/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/qlchallenge.dir/src/Main.cpp.o -c /home/velhomago/qlchallenge/src/Main.cpp

CMakeFiles/qlchallenge.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qlchallenge.dir/src/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/velhomago/qlchallenge/src/Main.cpp > CMakeFiles/qlchallenge.dir/src/Main.cpp.i

CMakeFiles/qlchallenge.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qlchallenge.dir/src/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/velhomago/qlchallenge/src/Main.cpp -o CMakeFiles/qlchallenge.dir/src/Main.cpp.s

# Object files for target qlchallenge
qlchallenge_OBJECTS = \
"CMakeFiles/qlchallenge.dir/src/Main.cpp.o"

# External object files for target qlchallenge
qlchallenge_EXTERNAL_OBJECTS =

qlchallenge: CMakeFiles/qlchallenge.dir/src/Main.cpp.o
qlchallenge: CMakeFiles/qlchallenge.dir/build.make
qlchallenge: CMakeFiles/qlchallenge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/velhomago/qlchallenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable qlchallenge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qlchallenge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qlchallenge.dir/build: qlchallenge

.PHONY : CMakeFiles/qlchallenge.dir/build

CMakeFiles/qlchallenge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/qlchallenge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/qlchallenge.dir/clean

CMakeFiles/qlchallenge.dir/depend:
	cd /home/velhomago/qlchallenge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/velhomago/qlchallenge /home/velhomago/qlchallenge /home/velhomago/qlchallenge/build /home/velhomago/qlchallenge/build /home/velhomago/qlchallenge/build/CMakeFiles/qlchallenge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qlchallenge.dir/depend
