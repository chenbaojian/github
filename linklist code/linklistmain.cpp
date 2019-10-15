//²âÊÔ´úÂë²¿·Ö 
#include"linklist.h"
using namespace std;
int main()
{
	linklistcy<string>list{ 10,"haha" };
	list.insert(5, "wangkuan");
	list.Delete(1);
	cout << list.length() << endl;
	cout << list.locateelem("wangkuan") << endl;
	cout << list.getelem(1) << endl;
	list.display();
	system("pause");
	return 0;
}