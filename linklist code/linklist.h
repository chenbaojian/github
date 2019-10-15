#include<stdlib.h>
#include <iostream>
using namespace std;
template<typename T> class linklistcy;//ǰ������˵��
//����һ������ڵ���ģ��
template<typename T>class node
{
	friend  class linklistcy<T>;//����linklistcyΪlistnode����Ԫ�����Է���˽�г�Ա
private:
	T m_data;//������
	node* m_next = nullptr;//ָ����,ָ����һ��ָ��
public:
	node() = default;
	node(const T& val) :m_data(val) {}//���캯��
	const T& data() const//��������������
	{
		return m_data;
	}
	node<T>* next()//������һ��ָ��
	{
		return m_next;
	}
};
//����һ��ѭ��������ģ��
template<typename T>class linklistcy
{
private:
	node<T>* m_head;//����һ��ͷָ��
public:
	linklistcy();//���캯��
	linklistcy(T elem);//���صĹ��캯��,���������Ľڵ�
	linklistcy(int n, T elem);//���صĹ��캯��
	~linklistcy();//��������
	void clearlist() const;//�������
	bool empty() const;//�ж������Ƿ�Ϊ��
	int length()const;//�ж�����ĳ���
	node<T>* getelem(int n)const;//�õ������������
	int locateelem(T elem)const;//��λ
	bool insert(int n, T elem);//����һ���ڵ�
	bool Delete(int n);//ɾ���ڵ�
	void display();//��ʾ����
	void remove(T elem);//�Ƴ�����
	static int count;
};
template<typename T>linklistcy<T>::linklistcy()//�յĵ�ѭ������
{
	m_head = new node<T>;//m_headָ�����һ��δ��ʼ����node<T>���͵Ķ���
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
	delete m_head;//�ͷ�ͷ���
}
template<typename T> void linklistcy<T>::clearlist()const
{
	node<T>* temp, * p = m_head->m_next;
	while (p != m_head)
	{
		temp = p->m_next;
		delete p;
		p = temp;//�ͷŶ�̬�ڴ�
		count--;
	}
	m_head->m_next = m_head;
}
template<typename T>bool linklistcy<T>::empty() const
{
	//����ڵ����һ���ڵ�Ϊ�գ��������Ϊ��
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
	return 0;//��ʾδ�ҵ�
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
		//�� ����һ���ڵ�
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
template<typename T>bool linklistcy<T>::Delete(int n)//ɾ���ڼ����ڵ�
{
	node<T>* ptemp = m_head;
	if (n < length())
	{
		for (int i = 0; i < n - 1; ++i)
		{
			ptemp = ptemp->m_next;
		}
		node<T>* t = ptemp->m_next;//ָ��ɾ���Ľڵ�
		ptemp->m_next = ptemp->m_next->m_next;//����ɾ���Ľڵ����һ���ڵ�ָ���ɾ���Ľڵ����һ���ڵ�
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
template<typename T>void linklistcy<T>::remove(T elem)//ɾ����ֵ��ͬ�Ľڵ�
{
	node<T>* ptemp = m_head;
	while (ptemp->m_next != m_head)
	{
		if (ptemp->m_next->m_data == elem)//�ҵ���ɾ���Ľڵ���ͬ
		{
			node<T>* t = ptemp->m_next;//ָ��ɾ���Ľڵ�
			ptemp->m_next = ptemp->m_next->m_next;//����ɾ���Ľڵ����һ�ڵ�ָ���ɾ���ڵ����һ���ڵ�
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
