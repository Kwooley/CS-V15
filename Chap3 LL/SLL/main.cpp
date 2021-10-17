#include "SLL.hpp"
#include <iostream>

int main()
{
	SLList slist;

	slist.addtoHead(10);
	slist.addtoHead(20);
	slist.addtoHead(30);
	slist.addtoHead(40);
	slist.addtoHead(50);

	slist.deleteNode(20);
	slist.deleteNode(10);
	slist.deleteNode(50);

	SLLNode *ptr = slist.getHead();
	while (ptr != nullptr)
	{
		cout << ptr->getData() << "\t";
		ptr = ptr->getNext();
	}
	cout << endl;

	slist.addtoTail(70);
	slist.addtoTail(80);
	slist.addtoHead(90);

	ptr = slist.getHead();
	while (ptr != nullptr)
	{
		cout << ptr->getData() << "\t";
		ptr = ptr->getNext();
	}
	cout << endl;
}