CC = gcc                             # Compile
SRC = main.c function.c              # Source files
CFLAGS = -Wall -Wextra -Wpedantic    # Compiler flags
OBJ = main.o function.o              # Object files
TARGET = random_num_generator        # Executable

# Target to build the executable
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

# Target to compile function.c
function.o: function.c function.h
	$(CC) -c $(CFLAGS) function.c

# Target to compile main.c
main.o: main.c function.h
	$(CC) -c $(CFLAGS) main.c

# Target to clean up object files and executable
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)

