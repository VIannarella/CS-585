# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /home/victor/cmake-Linux/bin/cmake

# The command to remove a file.
RM = /home/victor/cmake-Linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/victor/gtest-1.7.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/victor/gtest-1.7.0/build

# Include any dependencies generated for this target.
include CMakeFiles/gtest_main_unittest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gtest_main_unittest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtest_main_unittest.dir/flags.make

CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o: CMakeFiles/gtest_main_unittest.dir/flags.make
CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o: ../test/gtest_main_unittest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/gtest-1.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o -c /home/victor/gtest-1.7.0/test/gtest_main_unittest.cc

CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/victor/gtest-1.7.0/test/gtest_main_unittest.cc > CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.i

CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/victor/gtest-1.7.0/test/gtest_main_unittest.cc -o CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.s

CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o.requires:

.PHONY : CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o.requires

CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o.provides: CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o.requires
	$(MAKE) -f CMakeFiles/gtest_main_unittest.dir/build.make CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o.provides.build
.PHONY : CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o.provides

CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o.provides.build: CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o


# Object files for target gtest_main_unittest
gtest_main_unittest_OBJECTS = \
"CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o"

# External object files for target gtest_main_unittest
gtest_main_unittest_EXTERNAL_OBJECTS =

gtest_main_unittest: CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o
gtest_main_unittest: CMakeFiles/gtest_main_unittest.dir/build.make
gtest_main_unittest: libgtest_main.so
gtest_main_unittest: libgtest.so
gtest_main_unittest: CMakeFiles/gtest_main_unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/victor/gtest-1.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gtest_main_unittest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main_unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtest_main_unittest.dir/build: gtest_main_unittest

.PHONY : CMakeFiles/gtest_main_unittest.dir/build

CMakeFiles/gtest_main_unittest.dir/requires: CMakeFiles/gtest_main_unittest.dir/test/gtest_main_unittest.cc.o.requires

.PHONY : CMakeFiles/gtest_main_unittest.dir/requires

CMakeFiles/gtest_main_unittest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtest_main_unittest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtest_main_unittest.dir/clean

CMakeFiles/gtest_main_unittest.dir/depend:
	cd /home/victor/gtest-1.7.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/victor/gtest-1.7.0 /home/victor/gtest-1.7.0 /home/victor/gtest-1.7.0/build /home/victor/gtest-1.7.0/build /home/victor/gtest-1.7.0/build/CMakeFiles/gtest_main_unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtest_main_unittest.dir/depend

