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
include CMakeFiles/Pub.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pub.dir/flags.make

CMakeFiles/Pub.dir/Pub.cpp.o: CMakeFiles/Pub.dir/flags.make
CMakeFiles/Pub.dir/Pub.cpp.o: ../Pub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/velhomago/qlchallenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pub.dir/Pub.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pub.dir/Pub.cpp.o -c /home/velhomago/qlchallenge/Pub.cpp

CMakeFiles/Pub.dir/Pub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pub.dir/Pub.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/velhomago/qlchallenge/Pub.cpp > CMakeFiles/Pub.dir/Pub.cpp.i

CMakeFiles/Pub.dir/Pub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pub.dir/Pub.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/velhomago/qlchallenge/Pub.cpp -o CMakeFiles/Pub.dir/Pub.cpp.s

# Object files for target Pub
Pub_OBJECTS = \
"CMakeFiles/Pub.dir/Pub.cpp.o"

# External object files for target Pub
Pub_EXTERNAL_OBJECTS =

Pub: CMakeFiles/Pub.dir/Pub.cpp.o
Pub: CMakeFiles/Pub.dir/build.make
Pub: CMakeFiles/Pub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/velhomago/qlchallenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Pub"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pub.dir/build: Pub

.PHONY : CMakeFiles/Pub.dir/build

CMakeFiles/Pub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pub.dir/clean

CMakeFiles/Pub.dir/depend:
	cd /home/velhomago/qlchallenge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/velhomago/qlchallenge /home/velhomago/qlchallenge /home/velhomago/qlchallenge/build /home/velhomago/qlchallenge/build /home/velhomago/qlchallenge/build/CMakeFiles/Pub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pub.dir/depend
