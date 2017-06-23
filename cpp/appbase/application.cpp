#include <csignal> //std:signal
#include <cstdlib> //std::exit
#include <time.h> //srand(time(NULL));
#include <thread>

#include "application.h"
//#include "auplay/AudioPlayer.h"

Application* Application::_pApp = NULL;

Application::Application() {
  //START("");
  srand(time(NULL));
  _pApp = this;
  _disposed = false;
  _exit = false;
  registerSignalHandler();
  //END("");
}

Application::~Application() {
  //START("");
  dispose();
  //END("");
}

void Application::initialize() {
  
}

void Application::dispose() {
  //START("");
  if (!_disposed) {
    //_screen.dispose();
    //_keyboard.dispose();
    _disposed = true;
  }
  //END("");
}

void Application::signalHandler(int signum) {
  printf("signal %d\n", signum);
  if (signum==SIGINT) {
    //ERR << "SIGINT" << LEND;
    Application::_pApp->_exit = true;
  }
  if (signum==SIGQUIT) {  // core
    //ERR << "SIGQUIT" << LEND;
    Application::_pApp->_exit = true;
  }
  if (signum==SIGSEGV) {  // segmentation
    printf("SIGSEGV\n");
    //ERR << "SIGSEGV" << LEND;
    Application::_pApp->_exit = true;
    //Application::_pApp->dispose();
    //g_log.dispose();
    std::exit(-1);
  }
}

void Application::registerSignalHandler() {
  std::signal(SIGINT, signalHandler);
  std::signal(SIGTERM, signalHandler);
  std::signal(SIGSEGV, signalHandler);
  std::signal(SIGILL, signalHandler);
  std::signal(SIGABRT, signalHandler);
  std::signal(SIGFPE, signalHandler);
}

void Application::inputLoop() {
  printf("inputLoop\n");
  //START("");
  do {

    if (_exit) {
      break;
    }   

    //Key key;
    //_keyboard.getKey(key);
    //keyListen(key);
    //_queueKey.put(key);
    //LOG << key._ch << LEND;

  } while (true);
  //END("");
}

void Application::renderLoop() {
  printf("renderLoop\n");
}

void Application::evaluateLoop() {
  printf("evaluateLoop\n");
}
/*
  START("");
  do {
    
    if (_exit) {
      break;
    }

    optional<Key> opKey = std::experimental::nullopt;

    if (!_queueKey.empty()) {
      opKey = _queueKey.get();
    }

    SPLayers vpLayers;
    for (auto& pEvalGroup: _vpEvalGroups) {
      if (!pEvalGroup->enabled()) {
        continue;
      }
      for (auto& pLayer: pEvalGroup->layers()) {
        vpLayers.push_back(pLayer); 
        pLayer->clearDelta();
      }
    }

    bool needRender = false;
    for (auto& pEvalGroup: _vpEvalGroups) {
      if (!pEvalGroup->enabled()) {
        continue;
      }

      if (opKey) {
        auto& key = *opKey;//.value();
        auto& vpListeners = pEvalGroup->keyListeners();
        for (auto& pListener: vpListeners) {
          pListener->keyListen(key);
        }
      }

      auto& vpEvals = pEvalGroup->evaluations();

      size_t i = 0;
      while (i<vpEvals.size()) {
        auto& pEval = vpEvals[i];
        //LOG << pEval->toString() << LEND;
        pEval->evaluate();
        //if (pEval->needEvaluate()) {
        //  pEval->evaluateImpl();
        //  pEval->triggerDependEvals();
        //}
        i++;
      }


      for (auto& pEval: vpEvals) {
        if (pEval->renderType()==RENDER_FULL) {
          pEval->clearLayer();
        }
      }

      for (auto& pEval: vpEvals) {
        if (pEval->renderType()==RENDER_FULL) {
          pEval->renderFull();
          needRender = true;
        }
        if (pEval->renderType()==RENDER_DELTA) {
          pEval->renderDelta();
          needRender = true;
        }
        pEval->renderType(RENDER_OFF);
      }

      //LOG << UString::toString(vpLayers.size()) << LEND;

      auto it = vpEvals.begin();
      while(it!=vpEvals.end()) {
        auto& n = *it;
        if (n->completed()) {
          n->onComplete();
          it = vpEvals.erase(it);
          LOG << "vpEvals.erase" << LEND;
        } else {
          it++;
        }
      }

      if (_interval>0) {
        this_thread::sleep_for(std::chrono::milliseconds(_interval));
      }
    }
    if (needRender) {
      if (!vpLayers.empty()) {
        screen().render(vpLayers);
      }
    }
  } while (true);
  END("");
}
*/

void Application::startThreads() {
  //START("");
  std::thread t1(&Application::inputLoop, this);
  std::thread t2(&Application::renderLoop, this);
  std::thread t3(&Application::evaluateLoop, this);

  t1.join();
  t2.join();
  t3.join();
  //END("");
}

/*
void Application::sound(const string& pathName_) {
  //AudioPlayer* ap = (AudioPlayer::file(pathName_.c_str()));
  //if(ap) {
  //  ap->play();
  //}
}
*/

