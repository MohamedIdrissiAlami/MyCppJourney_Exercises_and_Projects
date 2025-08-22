# clsMyQueueArr - C++ Queue Implementation (Array-Based)

A queue data structure built on top of `clsDynamicArray`, providing FIFO operations with array-backed storage.

## Features
- **Standard Queue Operations**: Push, Pop, Front, Back
- **Extended Functionality**: Reverse, InsertAt, UpdateItem
- **Array-Backed**: Uses dynamic array for storage
- **Templated**: Works with any data type

## Core Queue Operations
| Method | Description | Complexity |
|--------|-------------|------------|
| `Push()` | Add to back | O(1) |
| `Pop()` | Remove from front | O(n) |
| `Front()` | Get first element | O(1) |
| `Back()` | Get last element | O(1) |
| `IsEmpty()` | Check if empty | O(1) |

## Extended Operations
- `GetItem()` - Access by index
- `Reverse()` - Reverse queue order
- `UpdateItem()` - Modify by index
- `InsertAtFront/Back()` - Flexible insertion
- `Clear()` - Remove all elements

## Usage Example
```cpp
clsMyQueueArr<string> Queue;
Queue.Push("Client 1");
Queue.Push("Client 2");
Queue.Pop(); // Removes "Client 1"

cout << "Next: " << Queue.Front(); // "Client 2"  
```  
____  

## Design Notes  
* Built on clsDynamicArray for storage

* Maintains same interface as clsMyQueue (linked list version)

* Suitable for scenarios where array performance is preferred

* Part of consistent data structure series

___***Note:***___
```
Array-based implementation provides O(1) access but O(n) removal  
complexity compared to linked list's O(1) operations.  
```