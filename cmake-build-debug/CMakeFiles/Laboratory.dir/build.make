# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/beatrice/CLionProjects/Laboratory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/beatrice/CLionProjects/Laboratory/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Laboratory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Laboratory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Laboratory.dir/flags.make

CMakeFiles/Laboratory.dir/main.cpp.o: CMakeFiles/Laboratory.dir/flags.make
CMakeFiles/Laboratory.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/beatrice/CLionProjects/Laboratory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Laboratory.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Laboratory.dir/main.cpp.o -c /home/beatrice/CLionProjects/Laboratory/main.cpp

CMakeFiles/Laboratory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Laboratory.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/beatrice/CLionProjects/Laboratory/main.cpp > CMakeFiles/Laboratory.dir/main.cpp.i

CMakeFiles/Laboratory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Laboratory.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/beatrice/CLionProjects/Laboratory/main.cpp -o CMakeFiles/Laboratory.dir/main.cpp.s

# Object files for target Laboratory
Laboratory_OBJECTS = \
"CMakeFiles/Laboratory.dir/main.cpp.o"

# External object files for target Laboratory
Laboratory_EXTERNAL_OBJECTS =

Laboratory: CMakeFiles/Laboratory.dir/main.cpp.o
Laboratory: CMakeFiles/Laboratory.dir/build.make
Laboratory: libcore.a
Laboratory: CMakeFiles/Laboratory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/beatrice/CLionProjects/Laboratory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Laboratory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Laboratory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Laboratory.dir/build: Laboratory

.PHONY : CMakeFiles/Laboratory.dir/build

CMakeFiles/Laboratory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Laboratory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Laboratory.dir/clean

CMakeFiles/Laboratory.dir/depend:
	cd /home/beatrice/CLionProjects/Laboratory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/beatrice/CLionProjects/Laboratory /home/beatrice/CLionProjects/Laboratory /home/beatrice/CLionProjects/Laboratory/cmake-build-debug /home/beatrice/CLionProjects/Laboratory/cmake-build-debug /home/beatrice/CLionProjects/Laboratory/cmake-build-debug/CMakeFiles/Laboratory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Laboratory.dir/depend

