# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -g
# Source files
SOURCES = main.cpp vm.cpp
# Header files
HEADERS = vm.h
# Object files
OBJECTS = $(SOURCES:.cpp=.o)
# Executable name
EXECUTABLE = vm

# Target to compile the program
all: $(EXECUTABLE)

# Linking object files to create the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Compiling source files into object files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the generated files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
