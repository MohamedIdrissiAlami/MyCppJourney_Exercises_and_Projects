#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
protected :
	short _Size = 0;
public:
	class Node
	{
	public:
		T Value;
		Node* Prev, * Next;
	};
	Node* Head = nullptr;

	void InsertAtBeginning(T Value)
	{
		Node* NewNode = new  Node();
		NewNode->Value = Value;
		NewNode->Prev = nullptr;
		NewNode->Next = Head;
		if (Head != nullptr)
			Head->Prev = NewNode;
		Head = NewNode;
		++this->_Size;
	}

	void InsertAtEnd(T Value)
	{
		Node* NewNode = new Node();
		NewNode->Value = Value;
		NewNode->Next = nullptr;
		if (Head == nullptr)
		{
			NewNode->Prev = nullptr;
			Head = NewNode;
		}
		else
		{
			Node* LastNode = Head;
			while (LastNode->Next != nullptr)
			{
				LastNode = LastNode->Next;
			}
			LastNode->Next = NewNode;
			NewNode->Prev = LastNode;
		}
		++this->_Size;

	}

	Node* Find(T Value)
	{
		Node* Current = Head;
		while (Current != nullptr)
		{
			if (Current->Value = Value)
				return Current;
			Current = Current->Next;
		}
		return nullptr;
	}

	void InsertAfter(Node* Current, T Value)
	{
		Node* NewNode = new Node();
		NewNode->Value = Value;
		NewNode->Prev = Current;
		NewNode->Next = Current->Next;
		if (Current->Next != nullptr)
		{
			Current->Next->Prev = NewNode;
		}
		Current->Next = NewNode;
		++this->_Size;

	}

	bool InsertAfter(short Index, T Value)
	{
		Node* ItemNode = GetNode(Index);
		if (ItemNode != nullptr)
		{
			InsertAfter(ItemNode, Value);
			return true;
		}
		return false;
	}

	void DeleteNode(Node* NodeToDelete)
	{
		if (Head == nullptr || NodeToDelete == nullptr)
			return;

		if (NodeToDelete == Head)
			Head = Head->Next;

		if (NodeToDelete->Prev!= nullptr)
			NodeToDelete->Prev->Next = NodeToDelete->Next;

		if (NodeToDelete->Next != nullptr)
			NodeToDelete->Next->Prev = NodeToDelete->Prev;

		delete NodeToDelete;
		--this->_Size;

	}

	void DeleteFirstNode()
	{
		if (Head != nullptr)
		{
			Node* FirstNode = Head;
			if (Head->Next != nullptr)
				Head->Next->Prev = nullptr;
			Head = Head->Next;
			delete FirstNode;
			--this->_Size;

		}
	}

	void DeleteLastNode()
	{
		if (Head != nullptr)
		{
			Node* LastNode = Head;
			while (LastNode->Next != nullptr)
				LastNode = LastNode->Next;
			if (LastNode->Prev == nullptr)
				Head = nullptr;
			else
				LastNode->Prev->Next = nullptr;
			delete LastNode;
			--this->_Size;
		}
	}


	void PrintList()
	{
		if (Head == nullptr)
		{
			cout << "\nempty list (nullptr).";
			return;
		}
		Node* Current = Head;
		while (Current != nullptr)
		{
			cout << Current->Value << " ";
			Current = Current->Next;
		}
	}

	short Size()
	{
		return this->_Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void Clear()
	{
		while (this->_Size > 0)
			DeleteLastNode();
	}

	void Reverse()
	{
		Node* Current = Head;
		Node* temp = nullptr;
		while (Current != nullptr)
		{
			temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = temp;
			Current = Current->Prev;
		}
		if (temp != nullptr)
			Head = temp->Prev;
	}

	Node* GetNode(short Index)
	{
		if (Index>=0 && Index<=_Size-1)
		{
			short CurrentIndex = 0;
			Node* Current = Head;
			while (Current != nullptr)
			{
				if (CurrentIndex++ == Index)
					return Current;
				Current = Current->Next;
			}
		}
		return nullptr;
	}
	T GetItem(short Index)
	{
		Node* N = GetNode(Index);
		return N != nullptr ? N->Value :nullptr;
	}
	bool UpdateItem(short Index, T NewValue)
	{
		Node* CurrentNode = GetNode(Index);
		if (CurrentNode != nullptr)
		{
			CurrentNode->Value = NewValue;
			return true;
		}
		else
			return false;
	}

};

