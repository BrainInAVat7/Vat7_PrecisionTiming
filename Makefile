# Makefile for posix Vat7 Precision Timing

.PHONY: all clean posix sdl run-demo run-demo-sdl windows

# File info
POSIX_SRC = src/vt7_pt_posix.c \
      src/vt7_pt_demo.c

SDL_SRC = src/vt7_pt_sdl.c \
      src/vt7_pt_demo.c

WINDOWS_SRC = src/vt7_pt_windows.c \
	src/vt7_pt_demo.c

POSIX_DEMO = bin/vt7_pt_demo_posix
SDL_DEMO = bin/vt7_pt_demo_sdl
WINDOWS_DEMO = bin/vt7_pt_demo_windows.exe

# Build flags and extensions
# Had to remove =5 from Wimplicit-fallthrough to compile with clang.
CFLAGS = -std=c17 \
	-I./include \
	-Werror \
	-Wall -Wextra -Wpedantic \
	-Wshadow \
	-Wconversion -Wsign-conversion \
	-Wcast-align \
	-Wstrict-prototypes \
	-Wmissing-prototypes \
	-Wformat=2 \
	-Wundef \
	-Wnull-dereference \
	-Wdouble-promotion \
	-Wimplicit-fallthrough

all: posix


$(POSIX_DEMO): $(POSIX_SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(POSIX_DEMO) $(POSIX_SRC)

$(SDL_DEMO): $(SDL_SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(SDL_DEMO) $(SDL_SRC) -lSDL3


$(WINDOWS_DEMO): $(WINDOWS_SRC)
	mkdir -p bin
	i686-w64-mingw32-gcc $(CFLAGS) -o $(WINDOWS_DEMO) $(WINDOWS_SRC)

posix: $(POSIX_DEMO)


sdl: $(SDL_DEMO)


windows: $(WINDOWS_DEMO)


run-demo: $(POSIX_DEMO)
	./$(POSIX_DEMO)

run-demo-sdl: $(SDL_DEMO)
	./$(SDL_DEMO)

clean:
	rm -rf bin
