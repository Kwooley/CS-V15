#include "DLL.hpp"
#include <iostream>
using namespace std;

void printList(DLList<int> *);
void printListReverse(DLList<int> *);

int main()
{
	const int N = 5;
	DLList<int> *dlist = new DLList<int>;
	int num[N] = {10, 20, 30, 40, 50};
	for (int i = 0; i < N; i++)
		dlist->addNode(num[i]);
	printList(dlist);
	printListReverse(dlist);

	dlist->deleteNode(num[2]); // delete a node 30
	printList(dlist);
	dlist->deleteNode(num[0]); // delete the head node
	printList(dlist);
	dlist->deleteNode(num[4]); // delete the tail node
	printList(dlist);
	dlist->deleteNode(num[1]);
	dlist->deleteNode(num[3]); // delete the last one node
	printList(dlist);

	for (int i = 0; i < N; i++)
		dlist->addNode(num[i]);
	dlist->deleteHeadNode();
	printList(dlist);
	dlist->deleteTailNode();
	printList(dlist);
}

void printList(DLList<int> *dlist)
{
	DLLNode<int> *ptr;

	if (dlist->isEmpty())
	{
		cout << " List is empty\n";
		return;
	}
	ptr = dlist->getHead();
	while (ptr)
	{
		cout << ptr->getData() << "\t";
		ptr = ptr->getNext();
	}
	cout << endl;
}
void printListReverse(DLList<int> *dlist)
{
	DLLNode<int> *ptr;

	if (dlist->isEmpty())
	{
		cout << " List is empty\n";
		return;
	}
	ptr = dlist->getTail();
	while (ptr)
	{
		cout << ptr->getData() << "\t";
		ptr = ptr->getPrev();
	}
	cout << endl;
}