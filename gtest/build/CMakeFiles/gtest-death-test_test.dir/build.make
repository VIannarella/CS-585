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
include CMakeFiles/gtest-death-test_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gtest-death-test_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtest-death-test_test.dir/flags.make

CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o: CMakeFiles/gtest-death-test_test.dir/flags.make
CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o: ../test/gtest-death-test_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/gtest-1.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o -c /home/victor/gtest-1.7.0/test/gtest-death-test_test.cc

CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/victor/gtest-1.7.0/test/gtest-death-test_test.cc > CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.i

CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/victor/gtest-1.7.0/test/gtest-death-test_test.cc -o CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.s

CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o.requires:

.PHONY : CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o.requires

CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o.provides: CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o.requires
	$(MAKE) -f CMakeFiles/gtest-death-test_test.dir/build.make CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o.provides.build
.PHONY : CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o.provides

CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o.provides.build: CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o


# Object files for target gtest-death-test_test
gtest__death__test_test_OBJECTS = \
"CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o"

# External object files for target gtest-death-test_test
gtest__death__test_test_EXTERNAL_OBJECTS =

gtest-death-test_test: CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o
gtest-death-test_test: CMakeFiles/gtest-death-test_test.dir/build.make
gtest-death-test_test: libgtest_main.so
gtest-death-test_test: libgtest.so
gtest-death-test_test: CMakeFiles/gtest-death-test_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/victor/gtest-1.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gtest-death-test_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest-death-test_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtest-death-test_test.dir/build: gtest-death-test_test

.PHONY : CMakeFiles/gtest-death-test_test.dir/build

CMakeFiles/gtest-death-test_test.dir/requires: CMakeFiles/gtest-death-test_test.dir/test/gtest-death-test_test.cc.o.requires

.PHONY : CMakeFiles/gtest-death-test_test.dir/requires

CMakeFiles/gtest-death-test_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtest-death-test_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtest-death-test_test.dir/clean

CMakeFiles/gtest-death-test_test.dir/depend:
	cd /home/victor/gtest-1.7.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/victor/gtest-1.7.0 /home/victor/gtest-1.7.0 /home/victor/gtest-1.7.0/build /home/victor/gtest-1.7.0/build /home/victor/gtest-1.7.0/build/CMakeFiles/gtest-death-test_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtest-death-test_test.dir/depend

