
#include"merge sort.h"
int main()
{
	mergesort<int>object;
	int newdata[12] = { 1,2,1,3,7,6,4,9,10,0,11,5 };
	const int length = 12;
	int result[length];
	cout << "排序之前的数组序列为：" << endl;
	for (int i = 0; i < length; ++i)
		cout << newdata[i] << " ";
	cout << endl;
	object.merge_sort(newdata, result, 0, length - 1);
	cout << "排序之后的数组序列为:" << endl;
	for (int i = 0; i < length; ++i)
		cout << newdata[i] << "  ";
	cout << endl;
	return 0;
	system("pause");
}