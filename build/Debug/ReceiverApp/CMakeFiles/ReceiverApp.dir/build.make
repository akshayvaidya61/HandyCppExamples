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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/avaidy15/Coding_Practice/IPC-Practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug

# Include any dependencies generated for this target.
include ReceiverApp/CMakeFiles/ReceiverApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ReceiverApp/CMakeFiles/ReceiverApp.dir/compiler_depend.make

# Include the progress variables for this target.
include ReceiverApp/CMakeFiles/ReceiverApp.dir/progress.make

# Include the compile flags for this target's objects.
include ReceiverApp/CMakeFiles/ReceiverApp.dir/flags.make

ReceiverApp/CMakeFiles/ReceiverApp.dir/src/main.cpp.o: ReceiverApp/CMakeFiles/ReceiverApp.dir/flags.make
ReceiverApp/CMakeFiles/ReceiverApp.dir/src/main.cpp.o: /Users/avaidy15/Coding_Practice/IPC-Practice/ReceiverApp/src/main.cpp
ReceiverApp/CMakeFiles/ReceiverApp.dir/src/main.cpp.o: ReceiverApp/CMakeFiles/ReceiverApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ReceiverApp/CMakeFiles/ReceiverApp.dir/src/main.cpp.o"
	cd /Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug/ReceiverApp && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ReceiverApp/CMakeFiles/ReceiverApp.dir/src/main.cpp.o -MF CMakeFiles/ReceiverApp.dir/src/main.cpp.o.d -o CMakeFiles/ReceiverApp.dir/src/main.cpp.o -c /Users/avaidy15/Coding_Practice/IPC-Practice/ReceiverApp/src/main.cpp

ReceiverApp/CMakeFiles/ReceiverApp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ReceiverApp.dir/src/main.cpp.i"
	cd /Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug/ReceiverApp && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/avaidy15/Coding_Practice/IPC-Practice/ReceiverApp/src/main.cpp > CMakeFiles/ReceiverApp.dir/src/main.cpp.i

ReceiverApp/CMakeFiles/ReceiverApp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ReceiverApp.dir/src/main.cpp.s"
	cd /Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug/ReceiverApp && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/avaidy15/Coding_Practice/IPC-Practice/ReceiverApp/src/main.cpp -o CMakeFiles/ReceiverApp.dir/src/main.cpp.s

# Object files for target ReceiverApp
ReceiverApp_OBJECTS = \
"CMakeFiles/ReceiverApp.dir/src/main.cpp.o"

# External object files for target ReceiverApp
ReceiverApp_EXTERNAL_OBJECTS =

ReceiverApp/ReceiverApp: ReceiverApp/CMakeFiles/ReceiverApp.dir/src/main.cpp.o
ReceiverApp/ReceiverApp: ReceiverApp/CMakeFiles/ReceiverApp.dir/build.make
ReceiverApp/ReceiverApp: ReceiverApp/CMakeFiles/ReceiverApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ReceiverApp"
	cd /Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug/ReceiverApp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReceiverApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ReceiverApp/CMakeFiles/ReceiverApp.dir/build: ReceiverApp/ReceiverApp
.PHONY : ReceiverApp/CMakeFiles/ReceiverApp.dir/build

ReceiverApp/CMakeFiles/ReceiverApp.dir/clean:
	cd /Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug/ReceiverApp && $(CMAKE_COMMAND) -P CMakeFiles/ReceiverApp.dir/cmake_clean.cmake
.PHONY : ReceiverApp/CMakeFiles/ReceiverApp.dir/clean

ReceiverApp/CMakeFiles/ReceiverApp.dir/depend:
	cd /Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/avaidy15/Coding_Practice/IPC-Practice /Users/avaidy15/Coding_Practice/IPC-Practice/ReceiverApp /Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug /Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug/ReceiverApp /Users/avaidy15/Coding_Practice/IPC-Practice/build/Debug/ReceiverApp/CMakeFiles/ReceiverApp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : ReceiverApp/CMakeFiles/ReceiverApp.dir/depend

