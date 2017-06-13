CC=g++
CF+=-std=c++17
CF+=-Wall
CF+=-g
CF+=-pthread
LF+=-lpthread
INC+=-I.

SRCS := $(shell find $(PROJS) -type f -name "*.cpp")
HDRS := $(shell find $(PROJS) -type f -name "*.h")
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(OBJS)
	$(CC) $(LF) $(OBJS) -o $(EXE)

%.o: %.cpp $(HDRS)
	$(CC) $(CF) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(EXE)
