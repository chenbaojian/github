#include"quicksort.h"
using namespace std;
template<typename T, size_t N>
Array<T, N>::Array(const std::initializer_list<T>& l) :m_ele{ T() } {
	size_t m = l.size() < N ? l.size() : N;
	for (size_t i = 0; i < m; ++i) {
		m_ele[i] = *(l.begin() + i);
	}
}
template<typename T, size_t N>
T& Array<T, N>::operator[](size_t i) {
	return m_ele[i];
}

// 7.3.1 节
template<typename T, size_t N>
template<typename F >
void  Array<T, N>::selectionSort(F f) {
	for (int i = 0; i < N - 1; ++i) {
		int min = i;  // record the position of the smallest
		for (int j = i + 1; j < N; ++j) {
			// update min when finding a smaller element
			if (f(m_ele[j], m_ele[min]))
				min = j;
		}
		// put the smallest element at position i
		swap(i, min);
	}
}

// 7.3.1 节
template<typename T, size_t N>
template<typename F >
void  Array<T, N>::insertionSort(F f) {
	for (int i = 1, j; i < N; ++i) {
		// a temporary copy of the current element
		T t = m_ele[i];

		// find the position for insertion
		for (j = i; j > 0; --j) {
			if (f(m_ele[j - 1], t))
				break;
			// shift the sorted part to right
			m_ele[j] = m_ele[j - 1];
		}

		// insert the current element
		m_ele[j] = t;
	}
}

// 7.3.1 节
template<typename T, size_t N>
template<typename F >
void  Array<T, N>::bubbleSort(F f) {
	for (int i = N - 1; i >= 0; --i) {
		// bubble up
		for (int j = 0; j <= i - 1; ++j)
		{
			if (f(m_ele[j + 1], m_ele[j]))
				swap(j, j + 1);
		}
	}
}

//7.3.1节
template<typename T, size_t N>
void Array<T,N>::quicksort(int left,int right)
{
		if (left > right)
	{
		cout << " 这个数组不存在" << endl;
	}
	else if (right - left = 0)
	{
		cout << "数组只有一个元素不需要排序，且数组的元素为：" << m_ele[left] << endl;
	}
	else if (right - left = 1)
	{
		cout << "该数组里面有两个元素" << endl;
		if (m_ele[left] > m_ele[right])
			swap(left, right);
	}
	else 
	{
		T key = m_ele[left];
		int i = left;
		int j= right;
		while (i != j)
		{ 
			while (m_ele[j] < key && i < j)
				j--;
		   while (m_ele[i] > key && i < j)
			    i++;
		   if (i < j)
			   swap(j,i);
		}
		m_ele[left] = m_ele[j];
		m_ele[i] = key;
		quicksort(left, i - 1);
		quicksort(i + 1, right);
	 }
}

// 7.3.2 节
template<typename T, size_t N>
int Array<T, N>::binarySearch(const T& value, int left, int right) {
	while (left <= right) {
		int middle = (left + right) / 2;
		if (m_ele[middle] == value)
			return middle;
		else if (m_ele[middle] > value)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return -1;
}
