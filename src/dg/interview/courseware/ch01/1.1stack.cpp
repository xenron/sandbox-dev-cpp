#include<iostream>
#include<cstring>

using namespace std; 

const size_t MAXSIZE=255;
enum STATUS{SUCCESS,STACKOVERFLOAT,NOELEMENT};

template <class T>
class stack{
public:
    stack();
    ~stack(){};
    STATUS push(T newelem);
    STATUS pop();
    T      top();
    size_t size();
private:
    size_t nsize;
    T elem[MAXSIZE];
};

template <class T>
stack<T>::stack(){
	nsize=0;
}

template <class T>
STATUS stack<T>::push(T newelem){
    if (nsize == MAXSIZE) return STACKOVERFLOAT;
    elem[nsize]=newelem;
    nsize = nsize + 1;
    return SUCCESS;
}

template <class T>
STATUS stack<T>::pop(){
    if (nsize == 0) return NOELEMENT;
    nsize = nsize-1;
    return SUCCESS;
}

template <class T>
T stack<T>::top(){
    return elem[nsize-1];
}

template <class T>
size_t stack<T>::size(){
	return nsize;
}

int main()
{
	stack<int> a;
	a.push(10);
	a.push(11);
	cout << "size :" << a.size();
	cout << "\ntop elem:" << a.top();
	a.pop();
	cout << "\nsize :" << a.size();
	cout << "\ntop elem:" << a.top();
	a.pop();
	return 0; 
}
