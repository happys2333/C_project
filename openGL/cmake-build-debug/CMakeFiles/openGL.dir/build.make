# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = E:\developtool\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = E:\developtool\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\C_project\openGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\C_project\openGL\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/openGL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/openGL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/openGL.dir/flags.make

CMakeFiles/openGL.dir/main.cpp.obj: CMakeFiles/openGL.dir/flags.make
CMakeFiles/openGL.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\C_project\openGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/openGL.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\openGL.dir\main.cpp.obj -c G:\C_project\openGL\main.cpp

CMakeFiles/openGL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openGL.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\C_project\openGL\main.cpp > CMakeFiles\openGL.dir\main.cpp.i

CMakeFiles/openGL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openGL.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\C_project\openGL\main.cpp -o CMakeFiles\openGL.dir\main.cpp.s

# Object files for target openGL
openGL_OBJECTS = \
"CMakeFiles/openGL.dir/main.cpp.obj"

# External object files for target openGL
openGL_EXTERNAL_OBJECTS =

openGL.exe: CMakeFiles/openGL.dir/main.cpp.obj
openGL.exe: CMakeFiles/openGL.dir/build.make
openGL.exe: CMakeFiles/openGL.dir/linklibs.rsp
openGL.exe: CMakeFiles/openGL.dir/objects1.rsp
openGL.exe: CMakeFiles/openGL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\C_project\openGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable openGL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\openGL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/openGL.dir/build: openGL.exe

.PHONY : CMakeFiles/openGL.dir/build

CMakeFiles/openGL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\openGL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/openGL.dir/clean

CMakeFiles/openGL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\C_project\openGL G:\C_project\openGL G:\C_project\openGL\cmake-build-debug G:\C_project\openGL\cmake-build-debug G:\C_project\openGL\cmake-build-debug\CMakeFiles\openGL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/openGL.dir/depend

