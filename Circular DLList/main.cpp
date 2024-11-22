#include "Circular DLList.h"
int main()
{
	try
	{
		CircularDLList<int> c;
		/*c.addToTail(10);
		c.addToTail(28);
		c.addToTail(34);
		c.addToTail(42);*/
		c.addToTail(10);
		c.showList();
		cout << "\n";
		cout << c.deleteNthNode(1);
		cout << "\n";
		c.showList();
	}
	catch (const char* p)
	{
		cout << p;
	}
}