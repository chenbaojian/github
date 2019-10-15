#include <iostream>
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

//定义一个类模板

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

//定义一个交换函数模板
template<typename T> void mergesort<T>::swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
//定义一个《类的函数重载
template<typename T>ostream& operator <<(ostream& out, mergesort<T>& c)
{
	int a[];
	int n = sizeof(a);
	out << c.display(a, n);
	return out;
}
template <typename T>void mergesort<T>::merge_sort(T* data, T* result, int left, int right)
{
	if (right - left == 0)//只有一个元素，不用排序
		return;
	else if (right - left == 1)//只有两个元素，则对两个元素进行排序
	{

		if (data[left] > data[right])
			swap(data[left], data[right]);
		return;
	}
	else
	{
		//递归划分子区间
		merge_sort(data, result, left, (right - left + 1) / 2 + left);
		merge_sort(data, result, (right - left + 1) / 2 + left + 1, right);
		//归并并排序数据
		merge(data, result, left, right);
		//把result指针中排好序的数据赋值到原来的data指针中
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
