# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = "/cygdrive/c/Users/Christopher Irvine/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe"

# The command to remove a file.
RM = "/cygdrive/c/Users/Christopher Irvine/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Prog2_CWK3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Prog2_CWK3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Prog2_CWK3.dir/flags.make

CMakeFiles/Prog2_CWK3.dir/main.cpp.o: CMakeFiles/Prog2_CWK3.dir/flags.make
CMakeFiles/Prog2_CWK3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Prog2_CWK3.dir/main.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Prog2_CWK3.dir/main.cpp.o -c "/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3/main.cpp"

CMakeFiles/Prog2_CWK3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Prog2_CWK3.dir/main.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3/main.cpp" > CMakeFiles/Prog2_CWK3.dir/main.cpp.i

CMakeFiles/Prog2_CWK3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Prog2_CWK3.dir/main.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3/main.cpp" -o CMakeFiles/Prog2_CWK3.dir/main.cpp.s

CMakeFiles/Prog2_CWK3.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Prog2_CWK3.dir/main.cpp.o.requires

CMakeFiles/Prog2_CWK3.dir/main.cpp.o.provides: CMakeFiles/Prog2_CWK3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Prog2_CWK3.dir/build.make CMakeFiles/Prog2_CWK3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Prog2_CWK3.dir/main.cpp.o.provides

CMakeFiles/Prog2_CWK3.dir/main.cpp.o.provides.build: CMakeFiles/Prog2_CWK3.dir/main.cpp.o


# Object files for target Prog2_CWK3
Prog2_CWK3_OBJECTS = \
"CMakeFiles/Prog2_CWK3.dir/main.cpp.o"

# External object files for target Prog2_CWK3
Prog2_CWK3_EXTERNAL_OBJECTS =

Prog2_CWK3.exe: CMakeFiles/Prog2_CWK3.dir/main.cpp.o
Prog2_CWK3.exe: CMakeFiles/Prog2_CWK3.dir/build.make
Prog2_CWK3.exe: CMakeFiles/Prog2_CWK3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Prog2_CWK3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Prog2_CWK3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Prog2_CWK3.dir/build: Prog2_CWK3.exe

.PHONY : CMakeFiles/Prog2_CWK3.dir/build

CMakeFiles/Prog2_CWK3.dir/requires: CMakeFiles/Prog2_CWK3.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Prog2_CWK3.dir/requires

CMakeFiles/Prog2_CWK3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Prog2_CWK3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Prog2_CWK3.dir/clean

CMakeFiles/Prog2_CWK3.dir/depend:
	cd "/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3" "/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3" "/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3/cmake-build-debug" "/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3/cmake-build-debug" "/cygdrive/c/Users/Christopher Irvine/Documents/Programming/Prog2_CWK3/cmake-build-debug/CMakeFiles/Prog2_CWK3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Prog2_CWK3.dir/depend
