#include<iostream>
#include<assert.h>
using namespace std;
template<typename T, int size = 10>class queue
{
	int front, rear, count;
	T list[size];
public:
	queue() :front(0), rear(0), count(0) {}
	void insert(const T& elem);
	T remove();
	const T& getfront()const { return list[front]; }
	int length() { return count; }
	bool isempty() { return count == 0; }
	bool isfull() { return count == size; }
	void clear();
	
};
template<typename T, int size>void queue<T, size>::insert(const T& elem)
{
	assert(count != size);
	count++;
	list[rear] = elem;//
	rear = (rear + 1) % size;//��βԪ����1����ȡ������ʵ�ֶ���ѭ��
}
template<typename T,int size>T queue<T, size>::remove()
{
	assert(count != 0);
	int p = front;
	count--;
	front = (front + 1) % size;//����ָ����1��ʵ�ֶ���ѭ��
	return list[p];//������Ԫ�ص�ֵ
}
template<typename T, int size> void queue<T, size>::clear()
{
	count = 0;
	front = 0;
	rear = 0;
}