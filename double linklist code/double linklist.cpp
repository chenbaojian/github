#include"double linklist.h"
int main()
{
	dlinklist<int>dlist{ 10,11 };
	dlist.display();
	dlist.insert(8,5);
	dlist.display();
	dlist.insert(8,5);
	dlist.display();
	dlist.Delete(1);
	dlist.Delete(1);
	dlist.display();
	cout << dlist.count1() << endl;
	cout << dlist.find(5) << endl;
    system("pause");
	return 0;
	}
