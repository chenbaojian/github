#include<iostream>
using namespace std;
template<typename T>class stack;
template<typename T>class stacknode
{
	friend class stack<T>;
	stacknode<T>* next;
	T data;
public:
	stacknode() :data(0), next(nullptr) {}
	stacknode(const T& val) :data(val), next(nullptr) {}
	~stacknode()=default;
};

template<typename T>class stack
{
	stacknode<T>* m_top;
public:
	stack();
	stack(int n,T val);
	stack(const T&) = delete;
	stack& operator=(const T&) = delete;
	~stack();
	void clear();
	void push(const T& val);
	void pop();
	bool empty()const { return m_top == nullptr; }
	const T& top() { return m_top->data; }
	void display();
};
template<typename T>stack<T>::stack()
{
	push(0);
}
template<typename T>stack<T>::stack(int n,T val)
{
	for(int i=1;i<n+1;i++)
	push(val);
}
template<typename T>stack<T>::~stack()
{
	clear();
}
template<typename T>void stack<T>::clear()
{
	stacknode<T>* p = nullptr;
	while (m_top != nullptr)
	{
		p = m_top;
		m_top = m_top->next;
		delete p;
	}
}
template<typename T>void stack<T>::push(const T&val)
{
	stacknode<T>* node = new stacknode<T>(val);
	node->next = m_top;
	m_top = node;
}
template<typename T>void stack<T>::pop()
{
	stacknode<T>* q = m_top;
	
	cout << "Õ»¶¥ÔªËØÎª£º" << m_top->data;
	m_top = m_top->next;
	delete q;
}
template<typename T>void stack<T>::display()
{
	stacknode<T>* p = m_top;
	while (p != nullptr)
	{
		cout << p->data<<" " ;
		p = p->next;
	}
}