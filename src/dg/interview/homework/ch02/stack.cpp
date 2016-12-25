// 用下面的队列的定义用两个队列实现一个栈，要求top()的时间复杂度为O(1)

#include<iostream>
#include<queue>
using namespace std;

template <class T>
class stack {
public:
	stack() {};
	~stack() {};
	void push(T newelem);
	void pop();
	T top();
	int size();
private:
	queue<T> q1, q2;
	T top_record;
};

template <class T>
void stack<T>::push(T newelem)
{
	q2.push(newelem);
	int q1size = q1.size();
	for (int i = 0; i < q1size; i++)
	{
		q2.push(q1.front());
		q1.pop();
	}
	swap(q1, q2);
	top_record = q1.front();
}

template <class T>
void stack<T>::pop()
{
	if (q1.size()>0)
		q1.pop();

	if (q1.size() > 0)
	{
		top_record = q1.front();
	}
	else
	{
		top_record = (T)(0);
	}
}

template <class T>
T stack<T>::top()
{
	return top_record;
}

template <class T>
int stack<T>::size()
{
	return q1.size() + q2.size();
}


int main()
{
	stack<int> myStack;

	myStack.push(11);
	myStack.push(12);
	myStack.push(13);
	myStack.push(14);

	cout << myStack.size() << endl;

	cout << myStack.top() << endl;

	myStack.pop();

	cout << myStack.top() << endl;

	system("pause");

	return 0;
}
