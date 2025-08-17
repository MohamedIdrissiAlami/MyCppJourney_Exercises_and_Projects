#pragma once 
#include "../clsDBLinkedList/clsDblLinkedList.h"

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList<T> _MyList;
public:
	void Push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}
	void Pop()
	{
		_MyList.DeleteFirstNode();
	}
	void Print()
	{
		_MyList.PrintList();
	}
	int Size()
	{
		return _MyList.Size();
	}
	T Front()
	{
		return _MyList.GetItem(0);
	}
	T Back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T GetItem(short Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(short Index, T NewValue)
	{
		_MyList.UpdateItem(Index, NewValue);
	}

	void InsertAfter(short Index, T Value)
	{
		_MyList.InsertAfter(Index, Value);
	}

	void InsertAtFront(T NewValue)
	{
		_MyList.InsertAtBeginning(NewValue);
	}

	void InsertAtBack(T NewValue)
	{
		_MyList.InsertAtEnd(NewValue);
	}

	void Clear()
	{
		_MyList.Clear();
	}
};