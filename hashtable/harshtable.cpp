#include<iostream>
#include<stdlib.h>
#define max ~(1<<(sizeof(int)*8-1))//1个字节占8位二进制，左移一位，求反
using namespace std;
static enum status
{
	failture = -1, success = 0
}flag;

int initialhashtable(int* hashtable, int length);

int  hashfunction(int key, int length);
int hashinsert(int* hashtable, int key, int length);


int initialhashtable(int* hashtable, int length)
{
	if (hashtable == nullptr || length <= 0)
		return -1;
	for (int index = 0; index != length; index++)
		hashtable[index] = max;
	return 0;
}

int hashfunction(int key, int length)//返回地址
{
	if (key == max || length <= 0)
		return -1;
	return key % length;//除留余数
}
int hashinsert(int* hashtable, int  key, int length)
{
	if (hashtable == nullptr || length <= 0)
		return -1;
	int hashaddress = hashfunction(key, length);
	if (hashaddress == -1)
		return -1;
	for (int index = 0; index != length; index++)//循环最大的哈希表长度
	{
		if (hashtable[hashaddress] != max)//产生冲突
			hashaddress = (hashaddress + 1) % 12;//开放定址法的线性探测，查找下一个存放数据的空间
		else
			break;
	}
	if(hashtable[hashaddress] == max)
	{
		hashtable[hashaddress] = key;
		return 0;
	}
	return -1;
}
int hashsearch(int* hashtable, int key, int length)
{
	flag = success;
	if (hashtable == nullptr || length <= 0)
	{
		flag = failture;
		return -1;
	}
	int hashaddress = hashfunction(key, length);
	while (key != hashtable[hashaddress])
	{
		hashaddress = (hashaddress + 1) % length;
		if (hashtable[hashaddress] == max || hashaddress == hashfunction(key, length))//如果探测到下一个地址为空，还没有找到，或者循环找了一遍又回到了最初的地方
		{
			flag = failture;
			return -1;
		}
	}
	return hashaddress;
}
void test()
{
	int arr[12] = { 12,67,56,16,25,37,22,29,15,47,48,34 };
	int* hashtable = new int[12]();//创建一个12个动态储存空间
	int res = initialhashtable(hashtable, 12);
	if (res == (-1))
		cout << "initialhashtable fail" << endl;
	cout << "哈希表大四插入的元素：";
	for (int index = 0; index != 12; index++)
	{
		cout << arr[index] << "  ";
		hashinsert(hashtable, arr[index], 12);
	}
	cout << endl;
	cout << "哈希表：";
	for (int index = 0; index != 12; index++)
	{
		cout << hashtable[index] << "  ";
	}
	cout << endl;
	cout << "对应插入元素序列在哈希表查找元素：";
	for (int index = 0; index != 12; index++)
	{
		int ret = hashsearch(hashtable, arr[index], 12);
		if (ret == -1 && flag == failture)
		{
			cout << "search" << arr[index] << "fail" << endl;
		}
		cout << hashtable[ret] << "  ";
	}
	cout << "查找1：" << endl;
	int rett = hashsearch(hashtable, 1, 12);
	if (rett == (-1) && flag == failture)
	{
		cout << "search" << 1 << "fail" << endl;
		return ;
	}
	cout << hashtable[rett] << endl;
}
int main()
{
	test();
	system("pause");
}