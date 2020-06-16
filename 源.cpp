#include<iostream>
#include<vector>
using namespace std;
template<class T> T temp_count(vector<T> b)
{
	int count = 0;
	int value = 7;
	const int k = 10;
	vector<T>a(k);
	for (int i = 0; i < k; i++)
	{
		 a[i]=b[i];
	}
	for (int i = 0; i < k; i++)
	{
		if (a[i] == value)
		{
			count++;
		}
	}
	cout << count << endl;
	return count;
}
int main()
{
	vector<int>b = {1,2,3,7,7,7,4,4,4,5};
	temp_count(b);
	return 0;
}
