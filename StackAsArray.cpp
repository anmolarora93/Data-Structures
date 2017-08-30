#include <iostream>
using namespace std;

template<class T>
class STACK{
  int tos;
  int size_of_stack;
  T *stack;
public:
  STACK();
  STACK(T);
  bool _stackOverflow();
  bool _stackUnderflow();
  void _pushItem(T);
  T _popItem();
  void _displayStack();
  ~STACK();
};

template <class T>
STACK::STACK(){
  stack=new T[25];
  tos=stack[0];
  this.size_of_stack=25;
}

template <class T>
STACK::STACK(int size_of_stack){
  this.size_of_stack=size_of_stack;
  stack=new T[size_of_stack];
  tos=stack[0];
}

bool STACK:: _stackOverflow(){
  return (tos==this.size_of_stack?true:false);
}

bool STACK::_stackUnderflow(){
  return (tos==-1?true:false)
}

template<class T>
void STACK:: _pushItem(T item_to_be_pushed){
  if(!_stackOverflow()){
    stack[tos++]=item_to_be_pushed;
  }
  else{
    throw "STACK OVERFLOW!!";
  }
}

template <class T>
T STACK::_popItem(){
  if(!_stackUnderflow()){
    return stack[--tos];
  }
  else{
    throw "STACK UNDERFLOW!!";
  }
}

void STACK::_displayStack(){
  if(!_stackUnderflow()){
    for(int i=tos;i>=0;i--){
      cout<<stack[i]<<" ";
    }
  }
  else{
    cout<<"STACK is Currently Empty";
  }
}

STACK::~STACK(){
  delete [] stack;
  size_of_stack=-1;
  tos=-1;
}

int main(int argc, char const *argv[])
{
  STACK <int> first_stack=new STACK[];
  STACK <int> second_stack=new STACK[50];

  while(!first_stack._stackOverflow()){

  }
  return 0;
}
