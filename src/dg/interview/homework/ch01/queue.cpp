// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"

#include<iostream>
#include<cstring>
#include<list>
#include <numeric>
#include <algorithm>

using namespace System;
using namespace std;

const size_t MAXSIZE = 255;
enum STATUS { SUCCESS, OVERFLOAT, NOELEMENT };

template <class T>
class queue {
public:
	queue();
	~queue() {};
	STATUS push(T newelem);
	STATUS pop();
	T      front();
	size_t size();
	STATUS display();
private:
	size_t head, tail;
	//T elem[MAXSIZE];
	list<T> elem1;
};

template <class T>
queue<T>::queue() {
	head = 0, tail = 0;
}

template <class T>
STATUS queue<T>::push(T newelem) {
	if ((tail + 1) % MAXSIZE == head) return OVERFLOAT;
	// elem[tail]=newelem;
	elem1.push_back(newelem);
	tail = (tail + 1) % MAXSIZE;
	return SUCCESS;
}

template <class T>
STATUS queue<T>::pop() {
	if (head == tail) return NOELEMENT;
	head = (head + 1) % MAXSIZE;
	elem1.pop_front();
	return SUCCESS;
}


template <class T>
T queue<T>::front() {
	return elem1.front();
	// return elem[head];
}

template <class T>
size_t queue<T>::size() {
	return elem1.size();
	// return tail-head;
}

template <class T>
STATUS queue<T>::display() {
	typedef list<int> INTLIST;
	INTLIST::iterator plist;
	for (plist = elem1.begin(); plist != elem1.end(); plist++)
		cout << *plist << " ";
	return SUCCESS;
}

int main()
{
	queue<int> a;
	a.push(10);
	a.push(11);
	cout << "size :" << a.size();
	cout << "\ntop elem:" << a.front();

	a.pop();
	cout << "\nsize :" << a.size();
	cout << "\ntop elem:" << a.front();

	a.push(12);
	cout << "\ndisplay :";
	a.display();

	system("pause");

	return 0;
}
