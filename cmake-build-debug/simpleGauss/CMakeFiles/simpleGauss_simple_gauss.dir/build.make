# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/denis/CLion-2021.1.3/clion-2021.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/denis/CLion-2021.1.3/clion-2021.1.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/denis/Seagate/Projects/SimpleGauss

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug

# Include any dependencies generated for this target.
include simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/depend.make

# Include the progress variables for this target.
include simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/progress.make

# Include the compile flags for this target's objects.
include simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/flags.make

simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.o: simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/flags.make
simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.o: ../simpleGauss/main_simple_gauss.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.o"
	cd /media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug/simpleGauss && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.o -c /media/denis/Seagate/Projects/SimpleGauss/simpleGauss/main_simple_gauss.cpp

simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.i"
	cd /media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug/simpleGauss && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/denis/Seagate/Projects/SimpleGauss/simpleGauss/main_simple_gauss.cpp > CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.i

simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.s"
	cd /media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug/simpleGauss && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/denis/Seagate/Projects/SimpleGauss/simpleGauss/main_simple_gauss.cpp -o CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.s

# Object files for target simpleGauss_simple_gauss
simpleGauss_simple_gauss_OBJECTS = \
"CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.o"

# External object files for target simpleGauss_simple_gauss
simpleGauss_simple_gauss_EXTERNAL_OBJECTS =

simpleGauss/simpleGauss_simple_gauss: simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/main_simple_gauss.cpp.o
simpleGauss/simpleGauss_simple_gauss: simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/build.make
simpleGauss/simpleGauss_simple_gauss: simpleGauss/libsimpleGauss.so
simpleGauss/simpleGauss_simple_gauss: simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simpleGauss_simple_gauss"
	cd /media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug/simpleGauss && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simpleGauss_simple_gauss.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/build: simpleGauss/simpleGauss_simple_gauss

.PHONY : simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/build

simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/clean:
	cd /media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug/simpleGauss && $(CMAKE_COMMAND) -P CMakeFiles/simpleGauss_simple_gauss.dir/cmake_clean.cmake
.PHONY : simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/clean

simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/depend:
	cd /media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/denis/Seagate/Projects/SimpleGauss /media/denis/Seagate/Projects/SimpleGauss/simpleGauss /media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug /media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug/simpleGauss /media/denis/Seagate/Projects/SimpleGauss/cmake-build-debug/simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : simpleGauss/CMakeFiles/simpleGauss_simple_gauss.dir/depend

