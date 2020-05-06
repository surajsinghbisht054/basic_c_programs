#include <iostream>
using namespace std;
 
const int SIZE = 10;


template <class StackType> class stack {
  StackType stck[SIZE];
  int tos;

public:
  stack() {
     tos = 0;
  }
    void push(StackType ob)
    {
      if(tos==SIZE) {
        cout << "Stack is full.\n";
        return;
      }
      stck[tos] = ob;
      tos++;
    }
 	
 	int contain(){
 		return tos;
 	}
    StackType pop()
    {
      if(tos==0) {
        cout << "Stack is empty.\n";
        return 0; // return null on empty stack
      }
      tos--;
      return stck[tos];
    }
};
 
int main() {
  stack<char> s1;
  stack<float> s2;
  stack<string> s3;
  stack<int> s4;
 
  s1.push('a');
  s1.push('b');
  s2.push(1.23);
  s3.push("Suraj");
  s4.push(4);
  cout << "Stack One Length  : " << s1.contain() << endl;
  cout << "Pop Stack One     : " << s1.pop() << endl;
  cout << "Pop Stack Two     : " << s2.pop() << endl;
  cout << "Pop Stack Three   : " << s3.pop() << endl;
  cout << "Pop Stack Four    : " << s4.pop() << endl;
  return 0;
}


