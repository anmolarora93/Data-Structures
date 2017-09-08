#include <iostream>
#include <time.h>
#include <stdlib.h>
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
		this->data = 0;
		this->next = NULL;
	}
};

template <class T>
class linkedlist{
	node<T>* head;
public:
	linkedlist(){
		head = NULL;
	}
	void _insertNode(T data);
	void _deleteNode(int index);
	void _displayList();
	~linkedlist();
};

template <class T>
void linkedlist<T>::_insertNode(T data){
	node<T> *p = new node<T>(data);
	
	if (head == NULL){
		head = p;
	}
	else{
		node<T>* q = head;
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

template <class T>
void linkedlist<T>::_deleteNode(int index){
	if (head == NULL)
		throw "LIST EMPTY";
	if (index == 1){
		node<T> *temp = head;
		head = head->next;
		delete temp;
	}
	else{
		node<T>* p = head;
		node<T>* q = NULL;
		int node_count = 1;
		while (node_count != index && p!= NULL)
		{
			q = p;
			p = p->next;
			node_count++;
		}
		if (p==NULL)
			cout << "Index Does not Exist";
		else{
			q->next = p->next;
			delete p;
		}
	}
}

template <class T>
void linkedlist<T>::_displayList(){
	node<T>*p = head;
	if (head == NULL){
		cout << "List is Empty !!!";
	}
	else{
		while (p != NULL){
			if (p->next == NULL){
				cout << p->data;
			}
			else{
				cout << p->data << "-->";
			}
			p = p->next;
		}
		cout << endl;
	}
}

template <class T>
linkedlist<T>::~linkedlist(){
	head = NULL;
	delete head;
}

int main()
{
	srand((int)time(NULL));
	int randomSize = 0;
	int delElements = 0;
	int elementDel = 0;
	string charset = "abcdefghijklmnopqrstuvwxyz";

	linkedlist<int> list1;
	for (int iterator = 0; iterator < 25; iterator++){
		list1._insertNode(rand() % 100000 + 1);
	}
	cout << "This is the First List" << endl;
	list1._displayList();
	cout << endl;

	linkedlist<float> list2;
	randomSize = rand() % 75;
	for (int iterator = 0; iterator < randomSize; iterator++){
		list2._insertNode((float)(rand() / static_cast <float>(RAND_MAX)));
	}
	cout << "This is the Second List of size: " << randomSize << endl;
	list2._displayList();
	cout << endl;
	delElements = rand() % randomSize;
	cout << "Now Let us Delete "<<delElements<<" Elements from the List" << endl;
	for (int delIterator = 0; delIterator < delElements; delIterator++)
		list2._deleteNode((rand() % randomSize)+1);
	cout << "The List After Deleting Elements is: " << endl;
	list2._displayList();

	randomSize = rand() % 75;
	linkedlist<char> list3;
	for (int iterator = 0; iterator < randomSize; iterator++){
		list3._insertNode(charset[rand() % 25 + 1]);
	}
	cout << "\nThis is the Third List of size: " << randomSize << endl;
	list3._displayList();
	cout << endl;

	return 0;
}
