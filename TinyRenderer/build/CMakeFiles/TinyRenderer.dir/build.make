# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Applications\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\Applications\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Development\C++\MyTinyRenderer\src\render

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Development\C++\MyTinyRenderer\src\render\build

# Include any dependencies generated for this target.
include CMakeFiles/TinyRenderer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TinyRenderer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TinyRenderer.dir/flags.make

CMakeFiles/TinyRenderer.dir/lib.cpp.obj: CMakeFiles/TinyRenderer.dir/flags.make
CMakeFiles/TinyRenderer.dir/lib.cpp.obj: ../lib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Development\C++\MyTinyRenderer\src\render\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TinyRenderer.dir/lib.cpp.obj"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\TinyRenderer.dir\lib.cpp.obj /FdCMakeFiles\TinyRenderer.dir/ /FS -c D:\Development\C++\MyTinyRenderer\src\render\lib.cpp

CMakeFiles/TinyRenderer.dir/lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TinyRenderer.dir/lib.cpp.i"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe > CMakeFiles\TinyRenderer.dir\lib.cpp.i  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Development\C++\MyTinyRenderer\src\render\lib.cpp

CMakeFiles/TinyRenderer.dir/lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TinyRenderer.dir/lib.cpp.s"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\TinyRenderer.dir\lib.cpp.s /c D:\Development\C++\MyTinyRenderer\src\render\lib.cpp

CMakeFiles/TinyRenderer.dir/geometry.cpp.obj: CMakeFiles/TinyRenderer.dir/flags.make
CMakeFiles/TinyRenderer.dir/geometry.cpp.obj: ../geometry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Development\C++\MyTinyRenderer\src\render\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TinyRenderer.dir/geometry.cpp.obj"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\TinyRenderer.dir\geometry.cpp.obj /FdCMakeFiles\TinyRenderer.dir/ /FS -c D:\Development\C++\MyTinyRenderer\src\render\geometry.cpp

CMakeFiles/TinyRenderer.dir/geometry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TinyRenderer.dir/geometry.cpp.i"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe > CMakeFiles\TinyRenderer.dir\geometry.cpp.i  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Development\C++\MyTinyRenderer\src\render\geometry.cpp

CMakeFiles/TinyRenderer.dir/geometry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TinyRenderer.dir/geometry.cpp.s"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\TinyRenderer.dir\geometry.cpp.s /c D:\Development\C++\MyTinyRenderer\src\render\geometry.cpp

CMakeFiles/TinyRenderer.dir/buffer.cpp.obj: CMakeFiles/TinyRenderer.dir/flags.make
CMakeFiles/TinyRenderer.dir/buffer.cpp.obj: ../buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Development\C++\MyTinyRenderer\src\render\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TinyRenderer.dir/buffer.cpp.obj"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\TinyRenderer.dir\buffer.cpp.obj /FdCMakeFiles\TinyRenderer.dir/ /FS -c D:\Development\C++\MyTinyRenderer\src\render\buffer.cpp

CMakeFiles/TinyRenderer.dir/buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TinyRenderer.dir/buffer.cpp.i"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe > CMakeFiles\TinyRenderer.dir\buffer.cpp.i  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Development\C++\MyTinyRenderer\src\render\buffer.cpp

CMakeFiles/TinyRenderer.dir/buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TinyRenderer.dir/buffer.cpp.s"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\TinyRenderer.dir\buffer.cpp.s /c D:\Development\C++\MyTinyRenderer\src\render\buffer.cpp

CMakeFiles/TinyRenderer.dir/model.cpp.obj: CMakeFiles/TinyRenderer.dir/flags.make
CMakeFiles/TinyRenderer.dir/model.cpp.obj: ../model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Development\C++\MyTinyRenderer\src\render\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TinyRenderer.dir/model.cpp.obj"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\TinyRenderer.dir\model.cpp.obj /FdCMakeFiles\TinyRenderer.dir/ /FS -c D:\Development\C++\MyTinyRenderer\src\render\model.cpp

CMakeFiles/TinyRenderer.dir/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TinyRenderer.dir/model.cpp.i"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe > CMakeFiles\TinyRenderer.dir\model.cpp.i  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Development\C++\MyTinyRenderer\src\render\model.cpp

CMakeFiles/TinyRenderer.dir/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TinyRenderer.dir/model.cpp.s"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\TinyRenderer.dir\model.cpp.s /c D:\Development\C++\MyTinyRenderer\src\render\model.cpp

CMakeFiles/TinyRenderer.dir/render.cpp.obj: CMakeFiles/TinyRenderer.dir/flags.make
CMakeFiles/TinyRenderer.dir/render.cpp.obj: ../render.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Development\C++\MyTinyRenderer\src\render\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TinyRenderer.dir/render.cpp.obj"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\TinyRenderer.dir\render.cpp.obj /FdCMakeFiles\TinyRenderer.dir/ /FS -c D:\Development\C++\MyTinyRenderer\src\render\render.cpp

CMakeFiles/TinyRenderer.dir/render.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TinyRenderer.dir/render.cpp.i"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe > CMakeFiles\TinyRenderer.dir\render.cpp.i  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Development\C++\MyTinyRenderer\src\render\render.cpp

CMakeFiles/TinyRenderer.dir/render.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TinyRenderer.dir/render.cpp.s"
	D:\Applications\VisualStudio2019\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\TinyRenderer.dir\render.cpp.s /c D:\Development\C++\MyTinyRenderer\src\render\render.cpp

# Object files for target TinyRenderer
TinyRenderer_OBJECTS = \
"CMakeFiles/TinyRenderer.dir/lib.cpp.obj" \
"CMakeFiles/TinyRenderer.dir/geometry.cpp.obj" \
"CMakeFiles/TinyRenderer.dir/buffer.cpp.obj" \
"CMakeFiles/TinyRenderer.dir/model.cpp.obj" \
"CMakeFiles/TinyRenderer.dir/render.cpp.obj"

# External object files for target TinyRenderer
TinyRenderer_EXTERNAL_OBJECTS =

TinyRenderer.dll: CMakeFiles/TinyRenderer.dir/lib.cpp.obj
TinyRenderer.dll: CMakeFiles/TinyRenderer.dir/geometry.cpp.obj
TinyRenderer.dll: CMakeFiles/TinyRenderer.dir/buffer.cpp.obj
TinyRenderer.dll: CMakeFiles/TinyRenderer.dir/model.cpp.obj
TinyRenderer.dll: CMakeFiles/TinyRenderer.dir/render.cpp.obj
TinyRenderer.dll: CMakeFiles/TinyRenderer.dir/build.make
TinyRenderer.dll: CMakeFiles/TinyRenderer.dir/objects1.rsp
TinyRenderer.dll: CMakeFiles/TinyRenderer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Development\C++\MyTinyRenderer\src\render\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library TinyRenderer.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TinyRenderer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TinyRenderer.dir/build: TinyRenderer.dll

.PHONY : CMakeFiles/TinyRenderer.dir/build

CMakeFiles/TinyRenderer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TinyRenderer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TinyRenderer.dir/clean

CMakeFiles/TinyRenderer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Development\C++\MyTinyRenderer\src\render D:\Development\C++\MyTinyRenderer\src\render D:\Development\C++\MyTinyRenderer\src\render\build D:\Development\C++\MyTinyRenderer\src\render\build D:\Development\C++\MyTinyRenderer\src\render\build\CMakeFiles\TinyRenderer.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TinyRenderer.dir/depend
