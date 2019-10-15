#include<iostream>
#include <initializer_list>
#ifndef M
#define M
//7.2.3
template<typename T>
struct Less {
	bool operator()(const T& a, const T& b) {
		return a < b;
	}
};

template<typename T, size_t N>
class Array {
private:
	T m_ele[N];
public:
	Array() {}
	Array(const std::initializer_list<T>&);
	T& operator[](size_t i);
	constexpr size_t size() { return N; }


	template<typename F = Less<T> >
	void selectionSort(F f = F());

	template<typename F = Less<T> >
	void insertionSort(F f = F());

	
	template<typename F = Less<T> >
	void bubbleSort(F f = F());

	void quicksort(int left,int right);

	int binarySearch(const T&, int left = 0, int right = N - 1);

private:
	void swap(int i, int j) {
		T t = m_ele[i];
		m_ele[i] = m_ele[j];
		m_ele[j] = t;
	}
};
#endif