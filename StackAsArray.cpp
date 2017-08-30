#include <iostream>
#include<time.h>
#include<string>
#include <stdlib.h>
using namespace std;

template<class T>
class STACK{
	int tos;
	int size_of_stack;
	T *stack;
public:
	STACK();
	STACK(int);
	bool _stackOverflow();
	bool _stackUnderflow();
	void _pushItem(T);
	T _popItem();
	void _displayStack();
	~STACK();
};

template <class T>
STACK<T>::STACK(){
	this->size_of_stack = 25;
	this->stack = new T[25];
	this->tos = -1;
}

template <class T>
STACK<T>::STACK(int size_of_stack){
	this->size_of_stack = size_of_stack;
	this->stack = new T[this->size_of_stack];
	this->tos = -1;
}

template <class T>
bool STACK<T>::_stackOverflow(){
	return (tos == size_of_stack-1 ? true : false);
}

template <class T>
bool STACK<T>::_stackUnderflow(){
	return (tos == -1 ? true : false);
}

template<class T>
void STACK<T>::_pushItem(T item_to_be_pushed){
	if (!_stackOverflow()){
		stack[++tos] = item_to_be_pushed;
	}
	else{
		throw "STACK OVERFLOW!!";
	}
}

template <class T>
T STACK<T>::_popItem(){
	if (!_stackUnderflow()){
		return stack[tos--];
	}
	else{
		throw "STACK UNDERFLOW!!";
	}
}

template <class T>
void STACK<T>::_displayStack(){
	cout << "The Stack Currently Contains:" << endl;
	T temp_iterator;
	while (!_stackUnderflow()){
		temp_iterator = _popItem();
		cout << temp_iterator << endl;
	}
}

template <class T>
STACK<T>::~STACK(){
	delete[] stack;
	size_of_stack = -1;
	tos = -1;
}

int main()
{
	srand((int)time(NULL));

	string charset = "abcdefghijklmnopqrstuvwxyz";
	int randomSize = 0;

	STACK <int> first_stack;
	
	
	try{
		for (int iterator = 0; iterator < 25; iterator++){
				first_stack._pushItem(rand() % 100000 + 1);
		}
		cout << "This is the First Stack" << endl;
		first_stack._displayStack();
		cout << endl;
	}
	catch (string * error_msg)
	{
		cout << "Exception Occured" << endl;
		cout << "Error Message";
	}


	randomSize = rand() % 75;
	STACK <int> second_stack(randomSize);
	try{
		for (int iterator = 0; iterator < randomSize; iterator++){
			second_stack._pushItem(rand() % 540000 + 1);
		}
		cout << "This is the Second Stack of size: " << randomSize << endl;
		second_stack._displayStack();
		cout << endl;
	}
	catch (string * error_msg)
	{
		cout << "Exception Occured" << endl;
		cout << "Error Message";
	}

	randomSize = rand() % 75;
	STACK <float> third_stack(randomSize);
	try{
		for (int iterator = 0; iterator < randomSize; iterator++){
			third_stack._pushItem((float)(rand()/static_cast <float>(RAND_MAX)));
		}
		cout << "This is the Third Stack of size: " << randomSize<<endl;
		third_stack._displayStack();
		cout << endl;
	}
	catch (string * error_msg)
	{
		cout << "Exception Occured" << endl;
		cout << "Error Message";
	}

	randomSize = rand() % 75;
	STACK <char> fourth_stack(randomSize);
	try{
		for (int iterator = 0; iterator < randomSize; iterator++){
			fourth_stack._pushItem(charset[rand()%25+1]);
		}
		cout << "This is the Fourth Stack of size: " <<randomSize<<endl;
		fourth_stack._displayStack();
	}
	catch (string * error_msg)
	{
		cout << "Exception Occured" << endl;
		cout << "Error Message";
	}
	return 0;
}