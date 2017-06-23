
#include "pch.h"
#include "sdl/sdl.h"
#include "appbase/application.h"
#include "tetrisApp.h"

int main() {
  std::cout << "tetris" << std::endl;
  TetrisApp app;
  app.initialize();
  app.startThreads();
}

