# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "E:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build

# Include any dependencies generated for this target.
include Common/Debug/CMakeFiles/Debug.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Common/Debug/CMakeFiles/Debug.dir/compiler_depend.make

# Include the progress variables for this target.
include Common/Debug/CMakeFiles/Debug.dir/progress.make

# Include the compile flags for this target's objects.
include Common/Debug/CMakeFiles/Debug.dir/flags.make

Common/Debug/CMakeFiles/Debug.dir/DebugConsole.cpp.obj: Common/Debug/CMakeFiles/Debug.dir/flags.make
Common/Debug/CMakeFiles/Debug.dir/DebugConsole.cpp.obj: E:/Coding/CppProjects/Programming-Game-AI-by-Example-src/Buckland_Chapter4-SimpleSoccer/Common/Debug/DebugConsole.cpp
Common/Debug/CMakeFiles/Debug.dir/DebugConsole.cpp.obj: Common/Debug/CMakeFiles/Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Common/Debug/CMakeFiles/Debug.dir/DebugConsole.cpp.obj"
	cd /d E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build\Common\Debug && E:\Coding\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Common/Debug/CMakeFiles/Debug.dir/DebugConsole.cpp.obj -MF CMakeFiles\Debug.dir\DebugConsole.cpp.obj.d -o CMakeFiles\Debug.dir\DebugConsole.cpp.obj -c E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\Common\Debug\DebugConsole.cpp

Common/Debug/CMakeFiles/Debug.dir/DebugConsole.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Debug.dir/DebugConsole.cpp.i"
	cd /d E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build\Common\Debug && E:\Coding\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\Common\Debug\DebugConsole.cpp > CMakeFiles\Debug.dir\DebugConsole.cpp.i

Common/Debug/CMakeFiles/Debug.dir/DebugConsole.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Debug.dir/DebugConsole.cpp.s"
	cd /d E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build\Common\Debug && E:\Coding\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\Common\Debug\DebugConsole.cpp -o CMakeFiles\Debug.dir\DebugConsole.cpp.s

# Object files for target Debug
Debug_OBJECTS = \
"CMakeFiles/Debug.dir/DebugConsole.cpp.obj"

# External object files for target Debug
Debug_EXTERNAL_OBJECTS =

Common/Debug/libDebug.a: Common/Debug/CMakeFiles/Debug.dir/DebugConsole.cpp.obj
Common/Debug/libDebug.a: Common/Debug/CMakeFiles/Debug.dir/build.make
Common/Debug/libDebug.a: Common/Debug/CMakeFiles/Debug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libDebug.a"
	cd /d E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build\Common\Debug && $(CMAKE_COMMAND) -P CMakeFiles\Debug.dir\cmake_clean_target.cmake
	cd /d E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build\Common\Debug && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Debug.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Common/Debug/CMakeFiles/Debug.dir/build: Common/Debug/libDebug.a
.PHONY : Common/Debug/CMakeFiles/Debug.dir/build

Common/Debug/CMakeFiles/Debug.dir/clean:
	cd /d E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build\Common\Debug && $(CMAKE_COMMAND) -P CMakeFiles\Debug.dir\cmake_clean.cmake
.PHONY : Common/Debug/CMakeFiles/Debug.dir/clean

Common/Debug/CMakeFiles/Debug.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\Common\Debug E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build\Common\Debug E:\Coding\CppProjects\Programming-Game-AI-by-Example-src\Buckland_Chapter4-SimpleSoccer\build\Common\Debug\CMakeFiles\Debug.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : Common/Debug/CMakeFiles/Debug.dir/depend

