#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
class node{
public:
	T data;
	node* next;
	node(T data){
		this->data = data;
		this->next = NULL;
	}
	~node(){
		data = -999999;
		delete[] next;
	}
};

template <class T>
class STACK{
	node<T>* tos;
public:
	STACK();
	void _pushItem(T data);
	T _popItem();
	void _displayStack();
	bool _stackUnderflow();
	~STACK();
};

template<class T>
STACK<T>::STACK()
{
	tos = NULL;
}

template <class T>
void STACK<T>::_pushItem(T data){
	node<T> *p = new node<T>(data);
	if (tos == NULL)
		tos = p;
	else{
		p->next = tos;
		tos = p;
	}
}

template<class T>
T STACK<T>::_popItem(){
	if (_stackUnderflow())
		throw "STACK UNDERFLOW";
	else{
		T popedElement;
		node<T>* q = tos;
		popedElement = q->data;
		tos = q->next;
		q->next = NULL;
		delete q;
		return popedElement;
	}
}

template <class T>
void STACK<T>::_displayStack(){
	if (_stackUnderflow()){
		cout << "Stack is Currently Empty";
	}
	else{
		node<T>* q = tos;
		while (q!=NULL){
			cout << q->data <<endl;
			q = q->next;
		}
	}
}

template <class T>
bool STACK<T>::_stackUnderflow(){
	return (tos == NULL ? true : false);
}

template<class T>
STACK<T>::~STACK(){
	tos = NULL;
}

int main()
{

	srand((int)time(NULL));
	string charset = "abcdefghijklmnopqrstuvwxyz";
	int item_popped = 0;

	STACK <int> first_stack;
	for (int iterator = 0; iterator < 25; iterator++){
		first_stack._pushItem(rand() % 100000 + 1);
	}
	cout << "This is the First Stack" << endl;
	first_stack._displayStack();
	cout << endl;
	
	STACK <int> second_stack;
	try{
		for (int iterator = 0; iterator < 17; iterator++){
			item_popped = first_stack._popItem();
			second_stack._pushItem(item_popped);
		}
		cout << "This is the Second Stack" << endl;
		second_stack._displayStack();
		cout << endl;
	}
	catch (string* error_msg){
		cout << error_msg;
	}

	int randomSize = 0;
	randomSize = rand() % 75;
	STACK <float> third_stack;
	for (int iterator = 0; iterator < randomSize; iterator++){
		third_stack._pushItem((float)(rand() / static_cast <float>(RAND_MAX)));
	}
	cout << "This is the Third Stack of size: " << randomSize << endl;
	third_stack._displayStack();
	cout << endl;
	
	randomSize = rand() % 75;
	STACK <char> fourth_stack;
	for (int iterator = 0; iterator < randomSize; iterator++){
		fourth_stack._pushItem(charset[rand() % 25 + 1]);
	}
	cout << "This is the Fourth Stack of size: " << randomSize << endl;
	fourth_stack._displayStack();
	
	return 0;
}