PROJS:=tetris/ sdl/ appbase/ util/
EXE  :=tetris.x
LF+=-L/opt/homebrew/Cellar/sdl2/2.0.14_1/lib/ -lSDL2
LF+=-L/opt/homebrew/Cellar/sdl2_image/2.0.5/lib/ -lSDL2_image
CF+=-I/usr/include/SDL2/ -I./tetris/
CF+=-I/opt/homebrew/Cellar/sdl2/2.0.14_1/include/SDL2/
CF+=-I/opt/homebrew/Cellar/sdl2_image/2.0.5/include/SDL2/
include common.mk
