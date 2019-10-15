#include<iostream>
#include<stdio.h>

using namespace std;
template<typename T>class dlinklist;//前项引用说明

template<typename T>class dlinklistnode //定义一个节点类
{
	friend class dlinklist<T>;//定义其为dlinklistnode的友元
public:
	//构造函数
	dlinklistnode() :m_data(0), next(nullptr),last(nullptr){}
	dlinklistnode(const T& val) :m_data(val) 
	{
		next = last = nullptr;
	}
	const T& data()const//返回数据域
	  {
		return m_data;
	  }
	dlinklistnode* next1()//返回下一个指针
	  {
		return next;
	  }
	dlinklistnode* last1()//返回上一个指针
	  {
	 	return last;
	  }
	~dlinklistnode() = default;//析构函数
private:
	dlinklistnode<T>* next ;//指向下一个节点的指针
	dlinklistnode<T>* last ;//指向上一个节点的指针
	T m_data;//数据域
};


template<typename T>class dlinklist//定义一个双向链表类
{
public:
	dlinklist() ;//默认构造函数
	dlinklist( T elem);//构造函数
	dlinklist(int n, T elem);//重载的构造函数
	bool insert(int position,T val);//输入一个节点
	void Delete( int position);//删除双向链表
	bool find( T val);//查找一个链表数据域
	int count1();//返回链表的节点个数
	void display();//打印链表的数据域
	T* gethead()
	{
		return head;
	}
	T* gettail()
	{
		return tail;
	}
private:
	dlinklistnode<T>* head;
	dlinklistnode<T>* tail;
		static int count;
};
template<typename T>dlinklist<T>::dlinklist()
{
	
	head = nullptr;
	tail = nullptr;
}
template<typename T>dlinklist<T>::dlinklist(T elem):dlinklist()
{
	insert(1, elem);
	count++;
}
template<typename T>dlinklist<T>::dlinklist(int n, T elem):dlinklist()
{
	for (int i = 1; i < n+1; i++)
	{
		insert(i,elem);
		//count++;
	}
}
template<typename T> bool dlinklist<T>::insert(  int position,T elem)
{
	dlinklistnode<T>* newnode = new dlinklistnode<T>(elem);
	   if (newnode != nullptr)
	   {
		cout << "创建新节点成功" << endl;
	   }
	   else
	   {
		return false;
	   }

    if (position<1 || position>count+1)
     { 
		cout << "插入的位置有错" << endl;
     }

	else if (position == 1)//节点放在第一个位置
	{
		if (head != nullptr)
		{
			head->last= newnode;
			newnode->next = head;
			
			head = newnode;
			head->last = nullptr;
		}
		else
		{
			tail = newnode;
			head = newnode;
			tail->next = nullptr;
			head->last = nullptr;
		}
		count++;
		//return true;
	 }

	else if (position == count + 1)//节点放在最后的一个位置
	 {
		//dlinklistnode<T>* newnode = new dlinklistnode<T>(elem)
	      if(tail != nullptr)
		   {
			 tail->next = newnode ;
			 newnode->last = tail;
			 tail = newnode;
			 tail->next = nullptr;
			}
		  /*else
		  {
			head = newnode;
			tail = newnode;
		  }*/
	      count++;
	      //return true;
	 }
	else
	{
	 static	int m = 1;
	 dlinklistnode<T>*temp2 = nullptr;
	 dlinklistnode<T>*temp1 = nullptr;
	  temp1 = head;
	 //dlinklistnode<T>* newnode = new dlinklistnode<T>(elem)
		while (position > 1 && position < count+1 && temp1!=tail )
		{
			temp1 = temp1->next;
			m++;
			if (m == position)
		    break;
		}
		temp2 = temp1->last;
		newnode->next = temp1;
		newnode->last = temp2;
		temp2->next = newnode;
		temp1->last = newnode;
		count++;
		/*if (temp1->next != nullptr)
		{
			newnode = temp1->next->last;
		}
		temp1->next = newnode;*/
		//return true;
	}
	return true;

}
template<typename T> void dlinklist<T>::Delete(int position)
{
	dlinklistnode<T>* temp1=nullptr;
	dlinklistnode<T>* temp=nullptr;
	dlinklistnode<T>* temp2=nullptr;
	temp1 = head;
	int k = 1;
	if (head == nullptr)
	{
		cout << "dlinklist is empty" << endl;
		return;
	}
	else if (position == 1)//删除头指针
	{
			head = head->next;
		if (head != nullptr)
			head->last = nullptr;
		delete temp1;
		count--;
		return;
	}
	//删除中间的某个节点
	else if (position > 1 && position < count + 1 && temp1->next != nullptr)
	{
		while (position > 1 && position < count + 1 && temp1->next != nullptr)
		{
			temp1 = temp1->next;
			k++;
			if (k == position)
			{
				break;
			}
		}
		temp2 = temp1->last;
		temp2->next = temp1->next;
		temp1->next->last = temp2;
		delete temp1;
		count--;
		/*if (temp1->next != nullptr)
		{
				temp1->next->last = temp2;
				delete temp1;
		}
			*/
	}
	else //(position = count)
	{
		temp1 = tail;
		tail = tail->last;
		tail->next = nullptr;
		delete temp1;
		count--;
	}
}


template<typename T>bool dlinklist<T>::find( T val)
{
	int k = 1;
	dlinklistnode<T>* temp;
	temp = head;
	while (temp != tail)
	{
		if (temp->m_data == val)
		{
			cout << "the sit of"<< val<<" is at" << k << endl;
			//return true;
		}
		else
		{
			cout << "第" << k << "个位置没有" << val << "的值" << endl;
		//	return false;
		}
		temp = temp->next;
		k++;
	}
	if(tail->m_data==val)
		cout << "the sit of" << val << " is at" << k << endl;
	else
		cout << "第" << k << "个位置没有" << val << "的值" << endl;
	return 1;
}
template<typename T>int dlinklist<T>::count1()
{
	return count;
}
template<typename T>void dlinklist<T>::display()
{

	dlinklistnode<T>* temp;
	temp =head;
	while (temp!= tail)
	{
		cout << temp->m_data<<"  ";
		temp = temp->next;
	}
	cout << tail->m_data;
	cout << endl;
}
template<typename T>int dlinklist<T>::count = 0;











