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
CMAKE_SOURCE_DIR = "/home/tomer/Advanced Programmin 1/Ex3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tomer/Advanced Programmin 1/Ex3/build"

# Include any dependencies generated for this target.
include CMakeFiles/Exceptions.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exceptions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exceptions.dir/flags.make

CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.o: CMakeFiles/Exceptions.dir/flags.make
CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.o: ../MatrixExceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tomer/Advanced Programmin 1/Ex3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.o -c "/home/tomer/Advanced Programmin 1/Ex3/MatrixExceptions.cpp"

CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tomer/Advanced Programmin 1/Ex3/MatrixExceptions.cpp" > CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.i

CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tomer/Advanced Programmin 1/Ex3/MatrixExceptions.cpp" -o CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.s

# Object files for target Exceptions
Exceptions_OBJECTS = \
"CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.o"

# External object files for target Exceptions
Exceptions_EXTERNAL_OBJECTS =

libExceptions.a: CMakeFiles/Exceptions.dir/MatrixExceptions.cpp.o
libExceptions.a: CMakeFiles/Exceptions.dir/build.make
libExceptions.a: CMakeFiles/Exceptions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tomer/Advanced Programmin 1/Ex3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libExceptions.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Exceptions.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Exceptions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exceptions.dir/build: libExceptions.a

.PHONY : CMakeFiles/Exceptions.dir/build

CMakeFiles/Exceptions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Exceptions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Exceptions.dir/clean

CMakeFiles/Exceptions.dir/depend:
	cd "/home/tomer/Advanced Programmin 1/Ex3/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tomer/Advanced Programmin 1/Ex3" "/home/tomer/Advanced Programmin 1/Ex3" "/home/tomer/Advanced Programmin 1/Ex3/build" "/home/tomer/Advanced Programmin 1/Ex3/build" "/home/tomer/Advanced Programmin 1/Ex3/build/CMakeFiles/Exceptions.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Exceptions.dir/depend

