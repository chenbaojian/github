#include"huffman tree.h"
using namespace std;
int main()
{
	huffman<int>huff;
	int a[] = { 10,20,30,40 };
	huff.creat(a, 4);
	huff.print();
	return 0;
}