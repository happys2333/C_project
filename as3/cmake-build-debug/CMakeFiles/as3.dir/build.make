# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/happys/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.72/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/happys/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.72/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/happys/Desktop/project/C++/C_project/as3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/happys/Desktop/project/C++/C_project/as3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/as3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/as3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/as3.dir/flags.make

CMakeFiles/as3.dir/main.cpp.o: CMakeFiles/as3.dir/flags.make
CMakeFiles/as3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/happys/Desktop/project/C++/C_project/as3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/as3.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/as3.dir/main.cpp.o -c /Users/happys/Desktop/project/C++/C_project/as3/main.cpp

CMakeFiles/as3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/as3.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/happys/Desktop/project/C++/C_project/as3/main.cpp > CMakeFiles/as3.dir/main.cpp.i

CMakeFiles/as3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/as3.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/happys/Desktop/project/C++/C_project/as3/main.cpp -o CMakeFiles/as3.dir/main.cpp.s

CMakeFiles/as3.dir/cross_system.cpp.o: CMakeFiles/as3.dir/flags.make
CMakeFiles/as3.dir/cross_system.cpp.o: ../cross_system.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/happys/Desktop/project/C++/C_project/as3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/as3.dir/cross_system.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/as3.dir/cross_system.cpp.o -c /Users/happys/Desktop/project/C++/C_project/as3/cross_system.cpp

CMakeFiles/as3.dir/cross_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/as3.dir/cross_system.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/happys/Desktop/project/C++/C_project/as3/cross_system.cpp > CMakeFiles/as3.dir/cross_system.cpp.i

CMakeFiles/as3.dir/cross_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/as3.dir/cross_system.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/happys/Desktop/project/C++/C_project/as3/cross_system.cpp -o CMakeFiles/as3.dir/cross_system.cpp.s

# Object files for target as3
as3_OBJECTS = \
"CMakeFiles/as3.dir/main.cpp.o" \
"CMakeFiles/as3.dir/cross_system.cpp.o"

# External object files for target as3
as3_EXTERNAL_OBJECTS =

as3: CMakeFiles/as3.dir/main.cpp.o
as3: CMakeFiles/as3.dir/cross_system.cpp.o
as3: CMakeFiles/as3.dir/build.make
as3: CMakeFiles/as3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/happys/Desktop/project/C++/C_project/as3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable as3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/as3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/as3.dir/build: as3

.PHONY : CMakeFiles/as3.dir/build

CMakeFiles/as3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/as3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/as3.dir/clean

CMakeFiles/as3.dir/depend:
	cd /Users/happys/Desktop/project/C++/C_project/as3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/happys/Desktop/project/C++/C_project/as3 /Users/happys/Desktop/project/C++/C_project/as3 /Users/happys/Desktop/project/C++/C_project/as3/cmake-build-debug /Users/happys/Desktop/project/C++/C_project/as3/cmake-build-debug /Users/happys/Desktop/project/C++/C_project/as3/cmake-build-debug/CMakeFiles/as3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/as3.dir/depend

