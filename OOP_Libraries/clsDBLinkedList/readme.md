# clsDblLinkedList - C++ Doubly Linked List Template

Header-only templated doubly linked list implementation.

## Features
- Insert/delete at head/tail
- Find nodes by value
- Reverse list in-place
- Index-based access
- Automatic memory management
- Templated for any data type

## Quick Start
```cpp
#include "clsDblLinkedList.h"

int main() {
    clsDblLinkedList<string> names;
    
    names.InsertAtEnd("Ali");
    names.InsertAtBeginning("Samia");
    names.InsertAfter(0, "John");
    
    names.PrintList();  // Output: Samia John Ali
    names.Reverse();    // Now: Ali John Samia
}
Key Methods
Method	Description	Complexity
InsertAtBeginning(T)	Add item to head	O(1)
InsertAtEnd(T)	Add item to tail	O(n)
InsertAfter(Node*, T)	Insert after node	O(1)
DeleteNode(Node*)	Delete target node	O(1)
Find(T)	Find first matching node	O(n)
Reverse()	Reverse list in-place	O(n)
GetItem(short)	Get value by index (0-based)	O(n)
Size()	Get current item count	O(1)
Clear()	Delete all nodes	O(n)  

Requirements
C++11 or newer

Single header file (#include "clsDblLinkedList.h")