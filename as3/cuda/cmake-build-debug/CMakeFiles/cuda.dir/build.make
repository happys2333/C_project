# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = H:\developmenttool\apps\CLion\ch-0\202.7319.72\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = H:\developmenttool\apps\CLion\ch-0\202.7319.72\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\project\C_project\as3\cuda

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\project\C_project\as3\cuda\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\cuda.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\cuda.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\cuda.dir\flags.make

CMakeFiles\cuda.dir\main.cu.obj: CMakeFiles\cuda.dir\flags.make
CMakeFiles\cuda.dir\main.cu.obj: ..\main.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\project\C_project\as3\cuda\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CUDA object CMakeFiles/cuda.dir/main.cu.obj"
	C:\PROGRA~1\NVIDIA~2\CUDA\v11.0\bin\nvcc.exe -forward-unknown-to-host-compiler $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -x cu -dc G:\project\C_project\as3\cuda\main.cu -o CMakeFiles\cuda.dir\main.cu.obj -Xcompiler=-FdCMakeFiles\cuda.dir\,-FS

CMakeFiles\cuda.dir\main.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CUDA source to CMakeFiles/cuda.dir/main.cu.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

CMakeFiles\cuda.dir\main.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CUDA source to assembly CMakeFiles/cuda.dir/main.cu.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

# Object files for target cuda
cuda_OBJECTS = \
"CMakeFiles\cuda.dir\main.cu.obj"

# External object files for target cuda
cuda_EXTERNAL_OBJECTS =

CMakeFiles\cuda.dir\cmake_device_link.obj: CMakeFiles\cuda.dir\main.cu.obj
CMakeFiles\cuda.dir\cmake_device_link.obj: CMakeFiles\cuda.dir\build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\project\C_project\as3\cuda\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CUDA device code CMakeFiles\cuda.dir\cmake_device_link.obj"
	C:\PROGRA~1\NVIDIA~2\CUDA\v11.0\bin\nvcc.exe  -forward-unknown-to-host-compiler -D_WINDOWS -Xcompiler=" /GR /EHsc" -Xcompiler="-Zi -Ob0 -Od /RTC1" -Xcompiler=-MDd -Wno-deprecated-gpu-targets -shared -dlink $(cuda_OBJECTS) $(cuda_EXTERNAL_OBJECTS) -o CMakeFiles\cuda.dir\cmake_device_link.obj  cudadevrt.lib cudart_static.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib  -Xcompiler=-FdG:\project\C_project\as3\cuda\cmake-build-debug\CMakeFiles\cuda.dir\,-FS

# Rule to build all files generated by this target.
CMakeFiles\cuda.dir\build: CMakeFiles\cuda.dir\cmake_device_link.obj

.PHONY : CMakeFiles\cuda.dir\build

# Object files for target cuda
cuda_OBJECTS = \
"CMakeFiles\cuda.dir\main.cu.obj"

# External object files for target cuda
cuda_EXTERNAL_OBJECTS =

cuda.exe: CMakeFiles\cuda.dir\main.cu.obj
cuda.exe: CMakeFiles\cuda.dir\build.make
cuda.exe: CMakeFiles\cuda.dir\cmake_device_link.obj
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\project\C_project\as3\cuda\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CUDA executable cuda.exe"
	H:\developmenttool\apps\CLion\ch-0\202.7319.72\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\cuda.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\mt.exe --manifests  -- E:\vs\VC\Tools\MSVC\14.27.29110\bin\Hostx64\x64\link.exe /nologo $(cuda_OBJECTS) $(cuda_EXTERNAL_OBJECTS) CMakeFiles\cuda.dir\cmake_device_link.obj @<<
 /out:cuda.exe /implib:cuda.lib /pdb:G:\project\C_project\as3\cuda\cmake-build-debug\cuda.pdb /version:0.0 -static-libgcc -static-libstdc++ /debug /INCREMENTAL /subsystem:console  cudadevrt.lib cudart_static.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib  -LIBPATH:"C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.0/lib/x64" "cudadevrt.lib" "cudart_static.lib" 
<<

# Rule to build all files generated by this target.
CMakeFiles\cuda.dir\build: cuda.exe

.PHONY : CMakeFiles\cuda.dir\build

CMakeFiles\cuda.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cuda.dir\cmake_clean.cmake
.PHONY : CMakeFiles\cuda.dir\clean

CMakeFiles\cuda.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" G:\project\C_project\as3\cuda G:\project\C_project\as3\cuda G:\project\C_project\as3\cuda\cmake-build-debug G:\project\C_project\as3\cuda\cmake-build-debug G:\project\C_project\as3\cuda\cmake-build-debug\CMakeFiles\cuda.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\cuda.dir\depend
