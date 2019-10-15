#include<stdlib.h>
#include <iostream>
using namespace std;
template<typename T> class linklistcy;//前项引用说明
//定义一个链表节点类模板
template<typename T>class node
{
	friend  class linklistcy<T>;//定义linklistcy为listnode的友元，可以访问私有成员
private:
	T m_data;//数据域
	node* m_next = nullptr;//指针域,指向下一个指针
public:
	node() = default;
	node(const T& val) :m_data(val) {}//构造函数
	const T& data() const//返回数据域引用
	{
		return m_data;
	}
	node<T>* next()//返回下一个指针
	{
		return m_next;
	}
};
//定义一个循环单链表模板
template<typename T>class linklistcy
{
private:
	node<T>* m_head;//定义一个头指针
public:
	linklistcy();//构造函数
	linklistcy(T elem);//重载的构造函数,构造其他的节点
	linklistcy(int n, T elem);//重载的构造函数
	~linklistcy();//析构函数
	void clearlist() const;//清空链表
	bool empty() const;//判断链表是否为空
	int length()const;//判断链表的长度
	node<T>* getelem(int n)const;//得到链表的数据域
	int locateelem(T elem)const;//定位
	bool insert(int n, T elem);//插入一个节点
	bool Delete(int n);//删除节点
	void display();//显示链表
	void remove(T elem);//移除数据
	static int count;
};
template<typename T>linklistcy<T>::linklistcy()//空的单循环链表
{
	m_head = new node<T>;//m_head指向的是一个未初始化的node<T>类型的对象
	if (m_head == nullptr)
	{
		cout << " shen qing dong tai nei cun shi bai" << endl;
		return;
	}
	m_head->m_next = m_head;
}
template<typename T>linklistcy<T>::linklistcy(T elem) :linklistcy()
{
	insert(1, elem);
	count++;
}
template<typename T>linklistcy<T>::linklistcy(int n, T elem) : linklistcy()
{
	for (int i = 0; i < n; ++i)
	{
		insert(i, elem);
	}
}
template<typename T>linklistcy<T>::~linklistcy()
{
	clearlist();
	delete m_head;//释放头结点
}
template<typename T> void linklistcy<T>::clearlist()const
{
	node<T>* temp, * p = m_head->m_next;
	while (p != m_head)
	{
		temp = p->m_next;
		delete p;
		p = temp;//释放动态内存
		count--;
	}
	m_head->m_next = m_head;
}
template<typename T>bool linklistcy<T>::empty() const
{
	//如果节点的下一个节点为空，则该链表为空
	return m_head == m_head->m_next;
}
template<typename T> int linklistcy<T>::length() const
{
	return count;
}
template<typename T>node<T>* linklistcy<T>::getelem(int n)const
{
	node<T>* ptemp = m_head->m_next;
	if (n <= length())
	{
		for (int i = 1; i < n; i++)
		{
			ptemp = ptemp->m_next;
		}
		return ptemp;
	}
	else
	{
		cout << " out of ranger" << endl;
		return ptemp = nullptr;
	}
}
template<typename T>int linklistcy<T>::locateelem(T elem)const
{
	size_t location = 0;
	node<T>* ptemp = m_head->m_next;
	while (ptemp != m_head)
	{
		++location;
		if (ptemp->m_data == elem)
		{
			return location;
		}
		ptemp = ptemp->m_next;
	}
	return 0;//表示未找到
}
template<typename T> bool linklistcy<T>::insert(int n, T elem)
{
	node<T>* ptemp = m_head;
	if (n - 1 <= length())
	{
		for (int i = 0; i < n - 1; ++i)
		{
			ptemp = ptemp->m_next;
		}
		//先 生成一个节点
		node<T>* newnode = new node<T>;
		if (newnode == nullptr)
		{
			cout << " shen qing kong jian shi bai" << endl;
			return false;
		}
		newnode->m_data = elem;
		newnode->m_next = ptemp->m_next;
		ptemp->m_next = newnode;
		count++;
		return true;
	}
	else
	{
		cout << " out of range" << endl;
		return false;
	}
}
template<typename T>bool linklistcy<T>::Delete(int n)//删除第几个节点
{
	node<T>* ptemp = m_head;
	if (n < length())
	{
		for (int i = 0; i < n - 1; ++i)
		{
			ptemp = ptemp->m_next;
		}
		node<T>* t = ptemp->m_next;//指向删除的节点
		ptemp->m_next = ptemp->m_next->m_next;//将待删除的节点的上一个节点指向待删除的节点的下一个节点
		delete t;
		count--;
		return true;
	}
	else
	{
		cout << " out of range" << endl;
		return false;
	}
}
template<typename T>void linklistcy<T>::display()
{
	node<T>* ptemp = m_head->m_next;
	while (ptemp != m_head)
	{
		cout << ptemp->m_data << "  ";
		ptemp = ptemp->m_next;
	}
	cout << endl;
}
template<typename T>void linklistcy<T>::remove(T elem)//删除与值相同的节点
{
	node<T>* ptemp = m_head;
	while (ptemp->m_next != m_head)
	{
		if (ptemp->m_next->m_data == elem)//找到与删除的节点相同
		{
			node<T>* t = ptemp->m_next;//指向删除的节点
			ptemp->m_next = ptemp->m_next->m_next;//将待删除的节点的上一节点指向待删除节点的下一个节点
			delete t;
			count--;
		}
		else
		{
			ptemp = ptemp->m_next;
		}
	}
}
template<typename T>int linklistcy<T>::count = 0;
