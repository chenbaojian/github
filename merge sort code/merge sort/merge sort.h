#include <iostream>
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

//����һ����ģ��

template<typename T> class mergesort
{
public:
	mergesort(T newdata[]);
	mergesort() = default;
	~mergesort() = default;
	void swap(T& a, T& b);
	void merge_sort(T* data, T* result, int left, int right);
	friend ostream& operator <<(ostream& out, const mergesort& c);
	void merge(T* data, T* result, int left, int right);
private:
	T data;
};
template<typename T>mergesort<T>::mergesort(T  newdata[])
{
	for (int k = 0; k < size(newdata); k++)
		data[k] = newdata[k];
	return;
}

//����һ����������ģ��
template<typename T> void mergesort<T>::swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
//����һ������ĺ�������
template<typename T>ostream& operator <<(ostream& out, mergesort<T>& c)
{
	int a[];
	int n = sizeof(a);
	out << c.display(a, n);
	return out;
}
template <typename T>void mergesort<T>::merge_sort(T* data, T* result, int left, int right)
{
	if (right - left == 0)//ֻ��һ��Ԫ�أ���������
		return;
	else if (right - left == 1)//ֻ������Ԫ�أ��������Ԫ�ؽ�������
	{

		if (data[left] > data[right])
			swap(data[left], data[right]);
		return;
	}
	else
	{
		//�ݹ黮��������
		merge_sort(data, result, left, (right - left + 1) / 2 + left);
		merge_sort(data, result, (right - left + 1) / 2 + left + 1, right);
		//�鲢����������
		merge(data, result, left, right);
		//��resultָ�����ź�������ݸ�ֵ��ԭ����dataָ����
		for (int k = left; k < right + 1; k++)
			data[k] = result[k];
	}
}
template <typename T>void mergesort<T>::merge(T* data, T* result, int left, int right)
{
	int leftlength = (right - left + 1) / 2 + 1;
	int leftindex = left;
	int rightindex = left + leftlength;
	int resultindex = left;
	while (leftindex < left + leftlength && rightindex < right + 1)
	{
		if (data[leftindex] <= data[rightindex])
			result[resultindex++] = data[leftindex++];
		else
			result[resultindex++] = data[rightindex++];
	}
	while (leftindex < left + leftlength)
		result[resultindex++] = data[leftindex++];
	while (rightindex < right + 1)
		result[resultindex++] = data[rightindex++];
}
