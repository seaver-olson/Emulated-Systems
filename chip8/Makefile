CC = gcc
CFLAGS = -w -lSDL2
files := mem.c display.c timer.c sys.c
objects := $(files:.c=.o)

.PHONY: all clean

# Build the final executable
all: main

main: $(objects)
	$(CC) $(objects) $(CFLAGS) -o $@

# Compile source files into object files
%.o: %.c
	$(CC) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(objects) main
