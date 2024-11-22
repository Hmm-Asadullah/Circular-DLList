#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	T data;
	Node* next;
	Node* prev;
	Node(T d, Node<T>* n = nullptr , Node<T>* p = nullptr)
	{
		data = d;
		next = n;
		prev = p;
	}
};
template<typename T>
class CircularDLList
{
	Node<T>* curr;
public:
	CircularDLList()
	{
		curr = nullptr;
	}
	bool isEmpty()
	{
		return curr == nullptr ? true : false;
	}
	void addToTail(T e)
	{
		if (isEmpty())
		{
			curr = new Node<T>(e);
			curr->next = curr;
			curr->prev = curr;
		}
		else
		{
			curr->next = new Node<T>(e, curr->next, curr);
			curr = curr->next;
			curr->next->prev = curr;
		}
	}
	void addToHead(T e)
	{
		if (isEmpty())
		{
			curr = new Node<T>(e);
			curr->next = curr;
			curr->prev = curr;
		}
		else
		{
			curr->next = new Node<T>(e, curr->next, curr);
			curr->next->next->prev = curr->next;
		}
	}
	T deleteFromTail()
	{
		if (!isEmpty())
		{
			T e = curr->data;
			if (curr == curr->next)
			{
				delete curr;
				curr = nullptr;
				return e;
			}
			Node<T>* temp = curr;
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			curr = curr->prev;
			delete temp;
			temp = nullptr;
			return e;
		}
		throw "\nList is Empty";
		
	}
	T deleteFromHead()
	{
		if (!isEmpty())
		{
			T e = curr->next->data;
			if (curr == curr->next)
			{
				delete curr;
				curr = nullptr;
				return e;
			}
			Node<T>* temp = curr->next;
			curr->next = temp->next;
			temp->next->prev = curr;
			delete temp;
			return e;
		}
		throw "\nList is Empty";
	}
	bool deleteNode(T e)
	{
		if (!isEmpty())
		{
			if (e == curr->data)
			{
				deleteFromTail();
				return true;
			}
			Node<T>* iter = curr->next;
			while (iter->data != e && iter != curr)
			{
				iter = iter->next;
			}
			if (iter != curr)
			{
				iter->next->prev = iter->prev;
				iter->prev->next = iter->next;
				delete iter;
				return true;
			}
			return false;
		}
		throw "\nList is Empty";
	}
	bool deleteNthNode(int n)
	{
		if (!isEmpty())
		{
			Node<T>* iter = curr->next;
			int i = 1;
			if (i == n)
			{
				deleteFromHead();
				return true;
			}
			while (iter != curr && i != n)
			{
				iter = iter->next;
				i++;
			}
			if (i == n)
			{
				deleteFromTail();
				return true;
			}
			if (iter != curr)
			{
				iter->next->prev = iter->prev;
				iter->prev->next = iter->next;
				delete iter;
				return true;
			}
			return false;
		}
		throw "\nList is Empty";
	}
	void showList()
	{
		if (!isEmpty())
		{
			Node<T>* iter = curr->next;
			do
			{
				cout << iter->data << " ";
				iter = iter->next;
			} while (iter != curr->next);
		}
		else
		{
			throw "\nList is Empty";
		}
	}
	~CircularDLList()
	{
		if (isEmpty())
		{
			return;
		}
		if (curr == curr->next)
		{
			delete curr;
			curr = nullptr;
			return;
		}
		Node<T>* iter = curr->next;
		Node<T>* iter2 = iter;
		do
		{
			iter2 = iter->next;
			delete iter;
			iter = iter2;
		} while (iter != curr);
		delete curr;
		curr = iter = iter2 = nullptr;
	}
};