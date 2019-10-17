#include"cycle queue.h"
int main()
{
queue<int> obj;
obj.insert(10);
obj.insert(9);
obj.insert(8);
obj.insert(7);
cout << obj.getfront() << endl;;
cout << obj.length() << endl;;
cout<<obj.isfull()<<endl;
cout<<obj.isempty()<<endl;
//obj.clear();
return 0;
} 