# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kaloka/CLionProjects/OGLhangman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kaloka/CLionProjects/OGLhangman/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OGLhangman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OGLhangman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OGLhangman.dir/flags.make

CMakeFiles/OGLhangman.dir/main.cpp.o: CMakeFiles/OGLhangman.dir/flags.make
CMakeFiles/OGLhangman.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaloka/CLionProjects/OGLhangman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OGLhangman.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OGLhangman.dir/main.cpp.o -c /home/kaloka/CLionProjects/OGLhangman/main.cpp

CMakeFiles/OGLhangman.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLhangman.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaloka/CLionProjects/OGLhangman/main.cpp > CMakeFiles/OGLhangman.dir/main.cpp.i

CMakeFiles/OGLhangman.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLhangman.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaloka/CLionProjects/OGLhangman/main.cpp -o CMakeFiles/OGLhangman.dir/main.cpp.s

CMakeFiles/OGLhangman.dir/src/glad.c.o: CMakeFiles/OGLhangman.dir/flags.make
CMakeFiles/OGLhangman.dir/src/glad.c.o: ../src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaloka/CLionProjects/OGLhangman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/OGLhangman.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OGLhangman.dir/src/glad.c.o -c /home/kaloka/CLionProjects/OGLhangman/src/glad.c

CMakeFiles/OGLhangman.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OGLhangman.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kaloka/CLionProjects/OGLhangman/src/glad.c > CMakeFiles/OGLhangman.dir/src/glad.c.i

CMakeFiles/OGLhangman.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OGLhangman.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kaloka/CLionProjects/OGLhangman/src/glad.c -o CMakeFiles/OGLhangman.dir/src/glad.c.s

CMakeFiles/OGLhangman.dir/src/helpers.cpp.o: CMakeFiles/OGLhangman.dir/flags.make
CMakeFiles/OGLhangman.dir/src/helpers.cpp.o: ../src/helpers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaloka/CLionProjects/OGLhangman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OGLhangman.dir/src/helpers.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OGLhangman.dir/src/helpers.cpp.o -c /home/kaloka/CLionProjects/OGLhangman/src/helpers.cpp

CMakeFiles/OGLhangman.dir/src/helpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLhangman.dir/src/helpers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaloka/CLionProjects/OGLhangman/src/helpers.cpp > CMakeFiles/OGLhangman.dir/src/helpers.cpp.i

CMakeFiles/OGLhangman.dir/src/helpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLhangman.dir/src/helpers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaloka/CLionProjects/OGLhangman/src/helpers.cpp -o CMakeFiles/OGLhangman.dir/src/helpers.cpp.s

CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.o: CMakeFiles/OGLhangman.dir/flags.make
CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.o: ../src/glBoilerplateAndHelpers/sprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaloka/CLionProjects/OGLhangman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.o -c /home/kaloka/CLionProjects/OGLhangman/src/glBoilerplateAndHelpers/sprite.cpp

CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaloka/CLionProjects/OGLhangman/src/glBoilerplateAndHelpers/sprite.cpp > CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.i

CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaloka/CLionProjects/OGLhangman/src/glBoilerplateAndHelpers/sprite.cpp -o CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.s

CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.o: CMakeFiles/OGLhangman.dir/flags.make
CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.o: ../src/glBoilerplateAndHelpers/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaloka/CLionProjects/OGLhangman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.o -c /home/kaloka/CLionProjects/OGLhangman/src/glBoilerplateAndHelpers/texture.cpp

CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaloka/CLionProjects/OGLhangman/src/glBoilerplateAndHelpers/texture.cpp > CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.i

CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaloka/CLionProjects/OGLhangman/src/glBoilerplateAndHelpers/texture.cpp -o CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.s

# Object files for target OGLhangman
OGLhangman_OBJECTS = \
"CMakeFiles/OGLhangman.dir/main.cpp.o" \
"CMakeFiles/OGLhangman.dir/src/glad.c.o" \
"CMakeFiles/OGLhangman.dir/src/helpers.cpp.o" \
"CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.o" \
"CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.o"

# External object files for target OGLhangman
OGLhangman_EXTERNAL_OBJECTS =

OGLhangman: CMakeFiles/OGLhangman.dir/main.cpp.o
OGLhangman: CMakeFiles/OGLhangman.dir/src/glad.c.o
OGLhangman: CMakeFiles/OGLhangman.dir/src/helpers.cpp.o
OGLhangman: CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/sprite.cpp.o
OGLhangman: CMakeFiles/OGLhangman.dir/src/glBoilerplateAndHelpers/texture.cpp.o
OGLhangman: CMakeFiles/OGLhangman.dir/build.make
OGLhangman: lib/glfw/src/libglfw3.a
OGLhangman: /usr/lib/libOpenGL.so
OGLhangman: /usr/lib/libGLX.so
OGLhangman: /usr/lib/libGLU.so
OGLhangman: /usr/lib/librt.so
OGLhangman: /usr/lib/libm.so
OGLhangman: CMakeFiles/OGLhangman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kaloka/CLionProjects/OGLhangman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable OGLhangman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OGLhangman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OGLhangman.dir/build: OGLhangman

.PHONY : CMakeFiles/OGLhangman.dir/build

CMakeFiles/OGLhangman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OGLhangman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OGLhangman.dir/clean

CMakeFiles/OGLhangman.dir/depend:
	cd /home/kaloka/CLionProjects/OGLhangman/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kaloka/CLionProjects/OGLhangman /home/kaloka/CLionProjects/OGLhangman /home/kaloka/CLionProjects/OGLhangman/cmake-build-debug /home/kaloka/CLionProjects/OGLhangman/cmake-build-debug /home/kaloka/CLionProjects/OGLhangman/cmake-build-debug/CMakeFiles/OGLhangman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OGLhangman.dir/depend

