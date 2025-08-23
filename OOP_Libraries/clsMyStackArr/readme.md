# clsMyStackArr - C++ Stack Implementation (Array-Based)

A stack data structure built on top of `clsMyQueueArr`, providing LIFO operations with array-backed storage through intelligent inheritance.

## Features
- **Standard Stack Operations**: Push, Pop, Top, Bottom
- **Array-Backed Storage**: Uses dynamic array implementation
- **Inheritance-Based**: Extends `clsMyQueueArr` with minimal overrides
- **Templated**: Works with any data type

## Core Stack Operations
| Method | Description | Complexity |
|--------|-------------|------------|
| `Push()` | Add to top | O(n)* |
| `Pop()` | Remove from top | O(n)* |
| `Top()` | Get top element | O(1) |
| `Bottom()` | Get bottom element | O(1) |

*Note: Array implementation has O(n) push/pop complexity due to shifting

## Inherited Functionality
- `Print()`, `Size()`, `IsEmpty()`
- `GetItem()`, `Reverse()`, `UpdateItem()`
- `InsertAtFront/Back()`, `Clear()`

## Usage Example
```cpp
clsMyStackArr<int> Stack;
Stack.Push(10);  // Becomes top
Stack.Push(20);  // New top
Stack.Push(30);  // New top

cout << "Top: " << Stack.Top();  // 30
Stack.Pop();  // Removes 30  
```  
____  

## Design Notes
* Inherits from clsMyQueueArr with strategic method overrides

* Maintains identical interface to clsMyStack (linked list version)

* Demonstrates effective OOP inheritance principles

* Part of consistent data structure series

* Perfect for educational purposes and scenarios where array performance characteristics are acceptable.
  
## Author   
___Mohamed Idrissi Alami___