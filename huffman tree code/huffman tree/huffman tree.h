#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;
/*哈夫曼树的结点类模板的定义*/
template<typename T>class huffmannode
{
public:
	int flag = 0;
	huffmannode(T value, huffmannode* left, huffmannode* right);//构造函数
	~huffmannode() = default;
	huffmannode* m_left;//左子树指针
	huffmannode* m_right;//右子树指针
	T m_data;//数据域,结点权值
};
template<typename T>huffmannode<T>::huffmannode(T value, huffmannode* left, huffmannode* right)
{
	m_data = value;
	m_left = left;
	m_right = right;
	flag = 0;
}
/*定义一个哈夫曼树类模板*/
template<typename T>class huffman
{
public:
	void my_sort(int size);//森林中树的排序
	void creat(T a[], int size);//创建哈夫曼树
	void proorder();//前序遍历哈夫曼树
	void inorder();//中序遍历哈夫曼树
	void lastorder();//后序遍历哈夫曼树
	void destroy();//销毁哈夫曼树
	void print();//打印哈夫曼树
	huffman() = default;//构造函数
	~huffman() = default;//析构函数
private:
	void proorder(huffmannode<T>* pnode);
	void inorder(huffmannode<T>* pnode);
	void lastorder(huffmannode<T>* pnode);
	void destroy(huffmannode<T>* pnode);
	void print(huffmannode<T>* pnode);
	huffmannode<T>* root;//哈夫曼树的根结点
	huffmannode<T>* forest[30];//用数组来储存森林中的根结点
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
	for (int i = 0; i < size; i++)//每个节点都作为一个森林
	{
		huffmannode<T>* ptr = new huffmannode<T>(a[i], nullptr, nullptr);//构造一个哈夫曼树节点
		forest[i] = ptr;//双向队列加入一个元素
	}
	for (int i = 0; i < size - 1; i++)
	{
		//排序选出权值比较小的两棵树
		my_sort(size + k);
		for (int j = 0;; j++)
		{
			if (forest[j]->flag != 1 && forest[j + 1]->flag != 1)
			{
				//构造新结点??
				huffmannode<T>* node = new huffmannode<T>(forest[j]->m_data + forest[j + 1]->m_data, forest[j], forest[j + 1]);
				//新结点加入森林中
				forest[size + k] = node;
				k++;
				//删除两棵权值最小的数
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
		cout << "当前结点；" << pnode->m_data << ".";
		if (pnode->m_left != nullptr)
			cout << "它的左结点为：" << pnode->m_left->m_data << ".";
		else
			cout << "它没有左结点：";
		if (pnode->m_right != nullptr)
			cout << " 它的右结点为：" << pnode->m_right->m_data << ".";
		else
			cout << "他没有右结点";
		cout << endl;
		print(pnode->m_left);
		print(pnode->m_right);
	}
}
