PROJS:=tetris/ sdl/ appbase/ util/
EXE  :=tetris.x
LF+=-lSDL2
CF+=-I/usr/include/SDL2/ -I./tetris/
include common.mk
