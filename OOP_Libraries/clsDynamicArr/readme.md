# clsDynamicArray - C++ Dynamic Array Template

A flexible templated dynamic array implementation with automatic resizing, designed as a foundation for stack/queue data structures.

## Features
- **Dynamic Resizing**: Automatic expansion/contraction
- **Full CRUD Operations**: Insert, delete, update, and access elements
- **Memory Safe**: Automatic cleanup with destructor
- **Templated**: Works with any data type

## Core Methods
- `SetItem()`, `GetItem()` - O(1) access
- `InsertAt()`, `DeleteItemAt()` - O(n) operations  
- `Resize()` - O(n) size adjustment
- `Find()`, `Reverse()` - O(n) utilities
- `Clear()` - O(1) cleanup

## Quick Start
```cpp
clsDynamicArray<int> arr(3);
arr.SetItem(0, 10);
arr.InsertAtEnd(20);
arr.DeleteItemAt(0);
arr.PrintList();  // Output: 20   
```
## Design  
* Header-only implementation

* Protected _Size member for inheritance

* Consistent interface with clsDblLinkedList

* Ideal for building stacks/queues
## Author   
__Mohamed Idrissi Alami__