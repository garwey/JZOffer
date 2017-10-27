#include <iostream>
using namespace std;
struct Node
{
	int value;
	Node* next;
};

void AddToTail(Node* pHead, int value)
{
	if (pHead == nullptr)
		return;
	Node* p = pHead;
	while (p->next != nullptr)
		p = p->next;
	Node *n =new Node();
	n->value = value;
	p->next = n;
}

void RemoveNode(Node* pHead, int value)
{
	if (pHead == nullptr)
		return;
	Node* pre = pHead;
	Node* p = pre->next;
	while (p!=nullptr)
	{
		if (p->value == value)
		{
			pre->next = p->next;
			delete p;
			return;
		}
		pre = p;
		p = p->next;
	}
}

void PrintList(Node* pHead)
{
	if (pHead == nullptr)
		return;
	Node* p = pHead->next;
	while (p != nullptr){
		cout << p->value << ' ';
		p = p->next;
	}
}

void RemoveList(Node* pHead)
{
	while (pHead != nullptr)
	{
		Node* p = pHead;
		pHead = pHead->next;
		delete p;
	}
}

void PrintListReversingly(Node* pHead)
{
	if (pHead == nullptr)
		return;
	Node* new_list = new Node();
	Node* p = pHead->next;
	while (p != nullptr)
	{
		Node* temp = new Node();
		temp->value = p->value;
		temp->next = new_list->next;
		new_list->next = temp;
		p = p->next;
	}
	PrintList(new_list);
	RemoveList(new_list);
}

