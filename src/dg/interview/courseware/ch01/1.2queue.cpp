#include<iostream>
#include<cstring>

using namespace std; 

const size_t MAXSIZE=255;
enum STATUS{SUCCESS,OVERFLOAT,NOELEMENT};

template <class T>
class queue{
public:
    queue();
    ~queue(){};
    STATUS push(T newelem);
    STATUS pop();
    T      front();
    size_t size();
private:
    size_t head,tail;
    T elem[MAXSIZE];
};

template <class T>
queue<T>::queue(){
	head=0,tail=0;
}

template <class T>
STATUS queue<T>::push(T newelem){
    if ((tail + 1) % MAXSIZE == head) return OVERFLOAT;
    elem[tail]=newelem;
    tail = (tail + 1) % MAXSIZE;
    return SUCCESS;
}

template <class T>
STATUS queue<T>::pop(){
    if (head == tail) return NOELEMENT;
    head = (head+1) % MAXSIZE;
    return SUCCESS;
}


template <class T>
T queue<T>::front(){
    return elem[head];
}

template <class T>
size_t queue<T>::size(){
	return tail-head;
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
	a.pop();
	return 0; 
}
