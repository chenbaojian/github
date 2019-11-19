#include<iostream>
#include<stdlib.h>
#define max ~(1<<(sizeof(int)*8-1))//1���ֽ�ռ8λ�����ƣ�����һλ����
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

int hashfunction(int key, int length)//���ص�ַ
{
	if (key == max || length <= 0)
		return -1;
	return key % length;//��������
}
int hashinsert(int* hashtable, int  key, int length)
{
	if (hashtable == nullptr || length <= 0)
		return -1;
	int hashaddress = hashfunction(key, length);
	if (hashaddress == -1)
		return -1;
	for (int index = 0; index != length; index++)//ѭ�����Ĺ�ϣ����
	{
		if (hashtable[hashaddress] != max)//������ͻ
			hashaddress = (hashaddress + 1) % 12;//���Ŷ�ַ��������̽�⣬������һ��������ݵĿռ�
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
		if (hashtable[hashaddress] == max || hashaddress == hashfunction(key, length))//���̽�⵽��һ����ַΪ�գ���û���ҵ�������ѭ������һ���ֻص�������ĵط�
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
	int* hashtable = new int[12]();//����һ��12����̬����ռ�
	int res = initialhashtable(hashtable, 12);
	if (res == (-1))
		cout << "initialhashtable fail" << endl;
	cout << "��ϣ����Ĳ����Ԫ�أ�";
	for (int index = 0; index != 12; index++)
	{
		cout << arr[index] << "  ";
		hashinsert(hashtable, arr[index], 12);
	}
	cout << endl;
	cout << "��ϣ��";
	for (int index = 0; index != 12; index++)
	{
		cout << hashtable[index] << "  ";
	}
	cout << endl;
	cout << "��Ӧ����Ԫ�������ڹ�ϣ�����Ԫ�أ�";
	for (int index = 0; index != 12; index++)
	{
		int ret = hashsearch(hashtable, arr[index], 12);
		if (ret == -1 && flag == failture)
		{
			cout << "search" << arr[index] << "fail" << endl;
		}
		cout << hashtable[ret] << "  ";
	}
	cout << "����1��" << endl;
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