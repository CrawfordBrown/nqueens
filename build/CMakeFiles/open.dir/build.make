# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.9/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.9/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2/build

# Include any dependencies generated for this target.
include CMakeFiles/open.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/open.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/open.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/open.dir/flags.make

CMakeFiles/open.dir/nqueensOpenMP.cpp.o: CMakeFiles/open.dir/flags.make
CMakeFiles/open.dir/nqueensOpenMP.cpp.o: /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2/nqueensOpenMP.cpp
CMakeFiles/open.dir/nqueensOpenMP.cpp.o: CMakeFiles/open.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/open.dir/nqueensOpenMP.cpp.o"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/open.dir/nqueensOpenMP.cpp.o -MF CMakeFiles/open.dir/nqueensOpenMP.cpp.o.d -o CMakeFiles/open.dir/nqueensOpenMP.cpp.o -c /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2/nqueensOpenMP.cpp

CMakeFiles/open.dir/nqueensOpenMP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/open.dir/nqueensOpenMP.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2/nqueensOpenMP.cpp > CMakeFiles/open.dir/nqueensOpenMP.cpp.i

CMakeFiles/open.dir/nqueensOpenMP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/open.dir/nqueensOpenMP.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2/nqueensOpenMP.cpp -o CMakeFiles/open.dir/nqueensOpenMP.cpp.s

# Object files for target open
open_OBJECTS = \
"CMakeFiles/open.dir/nqueensOpenMP.cpp.o"

# External object files for target open
open_EXTERNAL_OBJECTS =

open: CMakeFiles/open.dir/nqueensOpenMP.cpp.o
open: CMakeFiles/open.dir/build.make
open: /usr/local/lib/libomp.dylib
open: CMakeFiles/open.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable open"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/open.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/open.dir/build: open
.PHONY : CMakeFiles/open.dir/build

CMakeFiles/open.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/open.dir/cmake_clean.cmake
.PHONY : CMakeFiles/open.dir/clean

CMakeFiles/open.dir/depend:
	cd /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2 /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2 /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2/build /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2/build /Users/crawford/Documents/Napier/Year_4/CandPSystems/cw_2/build/CMakeFiles/open.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/open.dir/depend

