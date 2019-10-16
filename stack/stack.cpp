#include"stack.h"
int main()
{
	stack<int> obj(8, 5);
	obj.display();
	obj.push(10);
	obj.display();
	obj.pop();
	obj.clear();
	//obj.display();
	return 0;
}
