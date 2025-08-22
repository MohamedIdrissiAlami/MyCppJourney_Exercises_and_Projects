#pragma once 
#include "clsDynamicArray.h"
template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T> _MyList;
public:
	void Push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}
	void Pop()
	{
		_MyList.DeleteFirstItem();
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

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int Index, T NewValue)
	{
		_MyList.SetItem(Index, NewValue);
	}

	void InsertAfter(int Index, T Value)
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