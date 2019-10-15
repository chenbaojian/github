#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;
/*���������Ľ����ģ��Ķ���*/
template<typename T>class huffmannode
{
public:
	int flag = 0;
	huffmannode(T value, huffmannode* left, huffmannode* right);//���캯��
	~huffmannode() = default;
	huffmannode* m_left;//������ָ��
	huffmannode* m_right;//������ָ��
	T m_data;//������,���Ȩֵ
};
template<typename T>huffmannode<T>::huffmannode(T value, huffmannode* left, huffmannode* right)
{
	m_data = value;
	m_left = left;
	m_right = right;
	flag = 0;
}
/*����һ������������ģ��*/
template<typename T>class huffman
{
public:
	void my_sort(int size);//ɭ������������
	void creat(T a[], int size);//������������
	void proorder();//ǰ�������������
	void inorder();//���������������
	void lastorder();//���������������
	void destroy();//���ٹ�������
	void print();//��ӡ��������
	huffman() = default;//���캯��
	~huffman() = default;//��������
private:
	void proorder(huffmannode<T>* pnode);
	void inorder(huffmannode<T>* pnode);
	void lastorder(huffmannode<T>* pnode);
	void destroy(huffmannode<T>* pnode);
	void print(huffmannode<T>* pnode);
	huffmannode<T>* root;//���������ĸ����
	huffmannode<T>* forest[30];//������������ɭ���еĸ����
};
template<typename T>void huffman<T>::my_sort(int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (forest[i]->m_data > forest[j]->m_data)
			{
				swap(forest[i], forest[j]);
			}
			else
				continue;
		}
	}
}
template<typename T>void huffman<T>::creat(T a[], int size)
{
	int j;
	int k = 0;
	for (int i = 0; i < size; i++)//ÿ���ڵ㶼��Ϊһ��ɭ��
	{
		huffmannode<T>* ptr = new huffmannode<T>(a[i], nullptr, nullptr);//����һ�����������ڵ�
		forest[i] = ptr;//˫����м���һ��Ԫ��
	}
	for (int i = 0; i < size - 1; i++)
	{
		//����ѡ��Ȩֵ�Ƚ�С��������
		my_sort(size + k);
		for (int j = 0;; j++)
		{
			if (forest[j]->flag != 1 && forest[j + 1]->flag != 1)
			{
				//�����½��??
				huffmannode<T>* node = new huffmannode<T>(forest[j]->m_data + forest[j + 1]->m_data, forest[j], forest[j + 1]);
				//�½�����ɭ����
				forest[size + k] = node;
				k++;
				//ɾ������Ȩֵ��С����
				forest[j]->flag = 1;
				forest[j + 1]->flag = 1;
				break;
			}
			else
				continue;
		}
	}
	root = forest[size + k - 1];
}
template<typename T>void huffman<T>::proorder()
{
	proorder(root);
}
template<typename T>void huffman<T>::proorder(huffmannode<T>* pnode)
{
	if (pnode != nullptr)
	{
		cout << pnode->m_data;
		proorder(pnode->m_left);
		proorder(pnode->m_right);
	}
}
template<typename T>void huffman<T>::inorder()
{
	inorder(root);
}
template<typename T>void huffman<T>::inorder(huffmannode<T>* pnode)
{
	if (pnode != nullptr)
	{
		inorder(pnode->m_left);
		cout << pnode->m_data;
		inorder(pnode->m_right);
	}
}
template<typename T>void huffman<T>::lastorder()
{
	lastorder(root);
}
template<typename T>void huffman<T>::lastorder(huffmannode<T>* pnode)
{
	if (pnode != nullptr)
	{
		lastorder(pnode->m_left);
		lastorder(pnode->m_right);
		cout << pnode->m_data;
	}
}
template<typename T>void huffman<T>::destroy()
{
	destory(root);
}
template<typename T>void huffman<T>::destroy(huffmannode<T>* pnode)
{
	if (pnode != nullptr)
	{
		destroy(pnode->m_left);
		destroy(pnode->m_right);
		delete pnode;
		pnode = nullptr;
	}
}
template<typename T>void huffman<T>::print()
{
	print(root);
}
template<typename T>void huffman<T>::print(huffmannode<T>* pnode)
{
	if (pnode != nullptr)
	{
		cout << "��ǰ��㣻" << pnode->m_data << ".";
		if (pnode->m_left != nullptr)
			cout << "��������Ϊ��" << pnode->m_left->m_data << ".";
		else
			cout << "��û�����㣺";
		if (pnode->m_right != nullptr)
			cout << " �����ҽ��Ϊ��" << pnode->m_right->m_data << ".";
		else
			cout << "��û���ҽ��";
		cout << endl;
		print(pnode->m_left);
		print(pnode->m_right);
	}
}