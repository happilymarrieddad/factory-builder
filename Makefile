#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp

#CC specifies which compiler we're using
COMPILER = g++
DEBUGGER = gdb

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -std=c++14
DEBUG_FLAG = -g

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lGL -lGLU -lGLEW -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

#OBJ_NAME specifies the name of our exectuable
DEBUG_EXECUTABLE = dbug
EXECUTABLE = app
EXECUTABLE_PATH = dist/
BUILD_COMMAND = make build 

#This is the target that compiles our executable
all : $(OBJS)
	$(BUILD_COMMAND)
run : $(EXECUTABLE_PATH)
	$(EXECUTABLE_PATH)$(EXECUTABLE)
build: $(OBJS)
	$(COMPILER) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXECUTABLE_PATH)$(EXECUTABLE)
debug: $(OBJS)
	$(COMPILER) $(OBJS) $(DEBUG_FLAG) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXECUTABLE_PATH)$(DEBUG_EXECUTABLE) && $(DEBUGGER) $(EXECUTABLE_PATH)$(DEBUG_EXECUTABLE)