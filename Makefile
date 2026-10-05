# Makefile for posix Vat7 Precision Timing

.PHONY: all clean posix sdl windows

# Demo 1 File Info
POSIX_SRC_DEMO_1 = src/vt7_pt_posix.c \
      src/vt7_pt_pattern_1_demo.c

SDL_SRC_DEMO_1 = src/vt7_pt_sdl.c \
      src/vt7_pt_pattern_1_demo.c

WIN_SRC_DEMO_1 = src/vt7_pt_windows.c \
	src/vt7_pt_pattern_1_demo.c

POSIX_DEMO_1 = bin/vt7_pt_posix_pattern_1_demo
SDL_DEMO_1 = bin/vt7_pt_sdl_pattern_1_demo
WIN_DEMO_1 = bin/vt7_pt_windows_pattern_1_demo.exe


# Demo 1 File Info
POSIX_SRC_DEMO_2 = src/vt7_pt_posix.c \
      src/vt7_pt_pattern_2_demo.c

SDL_SRC_DEMO_2 = src/vt7_pt_sdl.c \
      src/vt7_pt_pattern_2_demo.c

WIN_SRC_DEMO_2 = src/vt7_pt_windows.c \
	src/vt7_pt_pattern_2_demo.c

POSIX_DEMO_2 = bin/vt7_pt_posix_pattern_2_demo
SDL_DEMO_2 = bin/vt7_pt_sdl_pattern_2_demo
WIN_DEMO_2 = bin/vt7_pt_windows_pattern_2_demo.exe


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


$(POSIX_DEMO_1): $(POSIX_SRC_DEMO_1)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(POSIX_DEMO_1) $(POSIX_SRC_DEMO_1)

$(SDL_DEMO_1): $(SDL_SRC_DEMO_1)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(SDL_DEMO_1) $(SDL_SRC_DEMO_1) -lSDL3

$(WIN_DEMO_1): $(WIN_SRC_DEMO_1)
	mkdir -p bin
	i686-w64-mingw32-gcc $(CFLAGS) -o $(WIN_DEMO_1) $(WIN_SRC_DEMO_1)

$(POSIX_DEMO_2): $(POSIX_SRC_DEMO_2)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(POSIX_DEMO_2) $(POSIX_SRC_DEMO_2)

$(SDL_DEMO_2): $(SDL_SRC_DEMO_2)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(SDL_DEMO_2) $(SDL_SRC_DEMO_2) -lSDL3

$(WIN_DEMO_2): $(WIN_SRC_DEMO_2)
	mkdir -p bin
	i686-w64-mingw32-gcc $(CFLAGS) -o $(WIN_DEMO_2) $(WIN_SRC_DEMO_2)

posix: $(POSIX_DEMO_1) $(POSIX_DEMO_2)


sdl: $(SDL_DEMO_1) $(SDL_DEMO_2)


windows: $(WIN_DEMO_1) $(WIN_DEMO_2)


clean:
	rm -rf bin
