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
CMAKE_SOURCE_DIR = G:\C_project\project\source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\C_project\project\source\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/source.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/source.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/source.dir/flags.make

CMakeFiles/source.dir/library.cpp.obj: CMakeFiles/source.dir/flags.make
CMakeFiles/source.dir/library.cpp.obj: ../library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\C_project\project\source\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/source.dir/library.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\source.dir\library.cpp.obj -c G:\C_project\project\source\library.cpp

CMakeFiles/source.dir/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/source.dir/library.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\C_project\project\source\library.cpp > CMakeFiles\source.dir\library.cpp.i

CMakeFiles/source.dir/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/source.dir/library.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\C_project\project\source\library.cpp -o CMakeFiles\source.dir\library.cpp.s

# Object files for target source
source_OBJECTS = \
"CMakeFiles/source.dir/library.cpp.obj"

# External object files for target source
source_EXTERNAL_OBJECTS =

libsource.a: CMakeFiles/source.dir/library.cpp.obj
libsource.a: CMakeFiles/source.dir/build.make
libsource.a: CMakeFiles/source.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\C_project\project\source\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsource.a"
	$(CMAKE_COMMAND) -P CMakeFiles\source.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\source.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/source.dir/build: libsource.a

.PHONY : CMakeFiles/source.dir/build

CMakeFiles/source.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\source.dir\cmake_clean.cmake
.PHONY : CMakeFiles/source.dir/clean

CMakeFiles/source.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\C_project\project\source G:\C_project\project\source G:\C_project\project\source\cmake-build-debug G:\C_project\project\source\cmake-build-debug G:\C_project\project\source\cmake-build-debug\CMakeFiles\source.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/source.dir/depend
