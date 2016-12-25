// 2.请实现combine函数，利用这个函数合并两个链表，得到一个新的链表
// a = 1->2->3->4 和 b = 2->3->5 合并为 c = 1->2->3->4->5
// 另外只能返回结果c，不能修改a, b两个链表的数据。
// 函数样式为：
// template <class T>
// list<T> combine(list<T>  a, list<T>  b) {
//	list<T> c;
//	... // 实现合并操作
//		return c;
// }

#include<iostream>
#include<list>
using namespace std;

template <class T>
list<T> combine(list<T>  a, list<T>  b) {
	
	list<T> c;
	
	list<T>::iterator iter_a = a.begin();
	list<T>::iterator iter_b = b.begin();

	while (iter_b != b.end())
	{
		if (iter_a == a.end())
		{
			c.push_back(*iter_b);
			iter_b++;
		}
		else
		{

			if (*iter_b < *iter_a)
			{
				c.push_back(*iter_b);
				iter_b++;
			}
			else if (*iter_b == *iter_a)
			{
				c.push_back(*iter_a);
				iter_a++;
				iter_b++;
			}
			else
			{
				c.push_back(*iter_a);
				iter_a++;
			}
		}
	}

	while (iter_a != a.end())
	{
		c.push_back(*iter_a);
		iter_a++;
	}

	return c;
}

int main()
{

		list<int> a,b,c;
	
		for (int i = 1; i<=9; i+=2)
			a.push_back(i);
	
		b.push_back(2);
		b.push_back(3);
		b.push_back(5);
		b.push_back(6);
		b.push_back(7);
	
		c = combine(a, b);

	return 0;

}
