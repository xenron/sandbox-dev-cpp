#include<cstdio>

using namespace std;

enum STATUS{SUCCESS,NOELEMENT,INVAILD};

template <class T> 
class listnode{
public:
	T value;
	listnode<T> *next;
	listnode<T> *pre;
};

template <class T>
class list{
public:
	list();
	~list();
	STATUS push_front(T newelem);
	STATUS push_back(T newelem);
	STATUS insert(listnode<T> *p,T newelem);
	STATUS pop_front();
	STATUS pop_back();
	STATUS remove(listnode<T> *p1,listnode<T> *p2);
	listnode<T>* front();
	listnode<T>* back();
	int size();
private:
	listnode<T> *node;
	int nsize;
};

template <class T>
list<T>::list(){
	node = NULL;
	nsize = 0;
}

template <class T>
list<T>::~list(){
	for (int i=0;i<nsize;i++){
		listnode<T> *tmp = node;
		node = node->next;
		delete tmp;
	}
}

template <class T>
STATUS list<T>::push_front(T newelem){
	listnode<T> *tmp = new listnode<T>;
	tmp->value = newelem;
	
	if (nsize){
		tmp->next = node;
		tmp->pre = node->pre;
		node->pre->next = tmp;
		node->pre = tmp;
	} else node = tmp->next = tmp->pre = tmp;
	node = tmp;
	
	nsize++;
	return SUCCESS;
}

template <class T>
STATUS list<T>::push_back(T newelem){
	listnode<T> *tmp = new listnode<T>;
	tmp->value = newelem;

	if (nsize){
		tmp->next = node;
		tmp->pre = node->pre;
		node->pre->next = tmp;
		node->pre = tmp;
	} else node = tmp->next = tmp->pre = tmp;
	
	nsize++;
	return SUCCESS;
}

template <class T>
STATUS list<T>::insert(listnode<T> *p,T newelem){
	if (!p) return INVAILD;
	listnode<T> *tmp = new listnode<T>;
	
	tmp->value = newelem;
	tmp->next = p;
	tmp->pre = p->pre;
	p->pre->next = tmp;
	p->pre = tmp;
	
	nsize++;
	return SUCCESS;
}

template <class T>
STATUS list<T>::pop_front()
{
	if (!node) return NOELEMENT;
	listnode<T> *tmp = node;
	tmp->pre->next = tmp->next;
	tmp->next->pre = tmp->pre;
	node = node->next;
	delete tmp;
	nsize--;
	return SUCCESS;
}

template <class T>
STATUS list<T>::pop_back()
{
	if (!node) return NOELEMENT;
	listnode<T> *tmp = node->pre;
	tmp->pre->next = tmp->next;
	tmp->next->pre = tmp->pre;
	delete tmp;
	nsize--;
	return SUCCESS;
}

template <class T>
STATUS list<T>::remove(listnode<T> *p1,listnode<T> *p2){
	if (!p1 || !p2) return INVAILD;
	p2->pre=p1->pre;
	p2->pre->next = p2;
	
	while (p1!=p2){
		if (p1==node) node=p2;
		listnode<T> *tmp = p1;
		p1=p1->next;
		delete tmp;
		nsize--;
	}
	return SUCCESS;
}

template <class T>
listnode<T>* list<T>::front(){
	return node;
}

template <class T>
listnode<T>* list<T>::back(){
	return node->pre;
}

template <class T>
int list<T>::size(){
	return nsize;
}

int main()
{
	list<int> a;

	for (int i=10;i<16;i++)
		a.push_back(i);
	
	listnode<int> *p = a.front();
	
	for (int i=0;i<a.size();i++,p=p->next) printf("%d ",p->value);
	
	a.remove(a.front(),a.front()->next->next->next);
	
	p = a.front();
	
	for (int i=0;i<a.size();i++,p=p->next) printf("%d ",p->value);
	
	printf("\nsize:%d",a.size());
}
