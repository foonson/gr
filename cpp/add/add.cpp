#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <fstream>

char gcop[5] = "+-x/";
int gTotal = 100;

class Question {
public:

  Question(int a_, int b_, int op_):
    _op(op_), _right(0), _wrong(0)
  {
    if (_op==0) { 
      _x = a_;
      _y = b_;
      _ans = _x + _y ; 
    }
    else if (_op==1) { 
      _y = a_;
      _ans = b_;
      _x = _ans + _y ; 
    }
    else if (_op==2) { 
      _x = a_;
      _y = b_;
      _ans = _x * _y ; 
    }
    else if (_op==3) { 
      _y = a_;
      _ans = b_;
      _x = _ans * _y ; 
    }
  }
  bool check(int ans_) {
    if (ans_==_ans) {
      _right++;
      return true;
    }
    _wrong++;
    return false;
  }

  void display() {
    std::cout << _x << " " << gcop[_op] << " " << _y << " = ";
    
  }

  void displayAll() {
    display();
    std::cout << _ans << "   " << _right << " " << _wrong << "\n";
    
  }

  void save(std::ofstream& o) {
    o << _x << " ";
    o << _y << " ";
    o << _op << " ";
    o << _ans << " ";
    o << _right << " ";
    o << _wrong << "\n";
  }

  void load(std::ifstream& i) {
    i >> _x;
    i >> _y;
    i >> _op;
    i >> _ans;
    i >> _right;
    i >> _wrong;
  }


  void ask() {
  } 
 
  int _x;
  int _y;
  int _op;
  int _ans;
  int _right;
  int _wrong;
};

void save(std::vector<Question>& vq) {
  // save
  std::ofstream ofile;
  ofile.open("add.dat");
  for (auto& q:vq) {
    q.save(ofile);
  }
  ofile.close();
}

void ask(int& count, Question& q) {

  do {
    std::cout << "(" << count << ")    ";
    q.display();
    std::string sline;

    getline(std::cin, sline);
    if (sline.empty()) continue;
    int ans = atoi(sline.c_str());
    if (q.check(ans)) {
      count++;
      break;
    } else {
      count--;
    }
  } while (true);
}

int main() {
  bool done=false;
  std::vector<Question> vq;


  std::ifstream ifile;
  ifile.open("add.dat");


  std::cout << gTotal << "\n";

  for (int op=0;op<4;op++) {
    for (int x=1;x<=12;x++) {
      for (int y=1;y<=12;y++) {
        //vq.push_back(Question(0, 0, 0));
        vq.push_back(Question(x, y, op));
      }
    }
  }


  int count = 1;
  if (!ifile.good()) {
    ifile.close();
    save(vq);
    std::cout << "First time\n";
  } else {
    for (auto& q:vq) {
      q.load(ifile);
      if (q._wrong>0 && q._right < q._wrong*2) {
        //q.displayAll();
        ask(count, q);
      }
    }
    ifile.close();
  }

  //for (auto& q:vq) {
  //  q.displayAll();
  //}
  //return -1;

  int x = 0;
  int y = 0;
  int op = 0;
  srand(time(NULL));
  int ans = 0;
  do {
    int i = rand()%vq.size();
    Question& q = vq[i];
    if (q._right > 2) {
      continue;
    }

    ask(count, q);
    
    if (count>gTotal) {
      done=true;
    }

  } while (!done);
 
  save(vq);

  //for (auto& q:vq) {
  //  q.displayAll();
  //}
}
