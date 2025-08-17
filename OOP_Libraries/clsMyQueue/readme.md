# clsMyQueue - Custom Queue Implementation

A C++ queue implementation using composition with a doubly linked list. Demonstrates OOP principles while providing standard queue operations with additional flexibility.

## Key Features
- **Core Queue Operations**:
  - `Push()`: Add item to back (enqueue)
  - `Pop()`: Remove item from front (dequeue)
  - `Front()`/`Back()`: Access first/last elements
  - `IsEmpty()`/`Size()`: Queue status checks

- **Extended Functionality**:
  - `InsertAfter()`: Insert at specific position
  - `Reverse()`: Reverse queue order
  - `InsertAtFront()`/`InsertAtBack()`: Flexible additions
  - `UpdateItem()`: Modify existing items
  - `Clear()`: Reset queue

## Implementation Highlights
- Built using **composition** with `clsDblLinkedList`
- Maintains FIFO (First-In-First-Out) principle
- Provides O(1) for core operations
- Templated for any data type
