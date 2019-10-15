#include<iostream>
#include<stdio.h>

using namespace std;
template<typename T>class dlinklist;//ǰ������˵��

template<typename T>class dlinklistnode //����һ���ڵ���
{
	friend class dlinklist<T>;//������Ϊdlinklistnode����Ԫ
public:
	//���캯��
	dlinklistnode() :m_data(0), next(nullptr),last(nullptr){}
	dlinklistnode(const T& val) :m_data(val) 
	{
		next = last = nullptr;
	}
	const T& data()const//����������
	  {
		return m_data;
	  }
	dlinklistnode* next1()//������һ��ָ��
	  {
		return next;
	  }
	dlinklistnode* last1()//������һ��ָ��
	  {
	 	return last;
	  }
	~dlinklistnode() = default;//��������
private:
	dlinklistnode<T>* next ;//ָ����һ���ڵ��ָ��
	dlinklistnode<T>* last ;//ָ����һ���ڵ��ָ��
	T m_data;//������
};


template<typename T>class dlinklist//����һ��˫��������
{
public:
	dlinklist() ;//Ĭ�Ϲ��캯��
	dlinklist( T elem);//���캯��
	dlinklist(int n, T elem);//���صĹ��캯��
	bool insert(int position,T val);//����һ���ڵ�
	void Delete( int position);//ɾ��˫������
	bool find( T val);//����һ������������
	int count1();//��������Ľڵ����
	void display();//��ӡ�����������
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
		cout << "�����½ڵ�ɹ�" << endl;
	   }
	   else
	   {
		return false;
	   }

    if (position<1 || position>count+1)
     { 
		cout << "�����λ���д�" << endl;
     }

	else if (position == 1)//�ڵ���ڵ�һ��λ��
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

	else if (position == count + 1)//�ڵ��������һ��λ��
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
	else if (position == 1)//ɾ��ͷָ��
	{
			head = head->next;
		if (head != nullptr)
			head->last = nullptr;
		delete temp1;
		count--;
		return;
	}
	//ɾ���м��ĳ���ڵ�
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
			cout << "��" << k << "��λ��û��" << val << "��ֵ" << endl;
		//	return false;
		}
		temp = temp->next;
		k++;
	}
	if(tail->m_data==val)
		cout << "the sit of" << val << " is at" << k << endl;
	else
		cout << "��" << k << "��λ��û��" << val << "��ֵ" << endl;
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











