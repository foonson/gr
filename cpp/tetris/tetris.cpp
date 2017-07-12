
#include "pch.h"
//#include "sdl/sdl.h"
#include "tApp.h"

int main() {
  std::cout << "tetris" << std::endl;
  tetris::TApp app;
  app.initialize();
  app.startThreads();
}

