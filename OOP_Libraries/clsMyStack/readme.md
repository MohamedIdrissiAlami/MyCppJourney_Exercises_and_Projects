# clsMyStack - C++ Stack Implementation

Minimalist stack implementation via inheritance from `clsMyQueue`. Provides LIFO operations with O(1) complexity and extended list functionality.

## Features
- **Core Stack Ops**: `Push()`, `Pop()`, `Top()`, `Bottom()`
- **Extended Functionality**:
  - Index access (`GetItem()`, `UpdateItem()`)
  - Insertions (`InsertAfter()`, `InsertAtFront()`, `InsertAtBack()`)
  - List operations (`Reverse()`, `Clear()`, `Print()`)
- **Templated**: Supports any data type

## Usage
```cpp
#include "clsMyStack.h"

int main() {
    clsMyStack<string> Stack;
    
    Stack.Push("Ctrl");
    Stack.Push("Alt");
    Stack.Push("Del");  // Stack: Del ⇨ Alt ⇨ Ctrl
    
    cout << "Top: " << Stack.Top();  // "Del"
    Stack.Pop();
    
    Stack.InsertAfter(0, "Shift");  // Now: Alt ⇨ Shift ⇨ Ctrl
}
``` 
## Complexity

| Operation    | Complexity | Notes              |
|--------------|------------|--------------------|
| `Push()`     | O(1)       | Insert at head     |
| `Pop()`      | O(1)       | Remove from head   |
| `Top()`      | O(1)       | Head access        |
| `Bottom()`   | O(1)       | Tail access        |
| `GetItem()`  | O(n)       | Index traversal    |

## Design Highlights
- **Inherits from `clsMyQueue`** ➔ 90% code reuse  
- **Overrides only stack-specific methods**  
- **Maintains base class functionality**  
- **Header-only** (single include)  

### Deepest Gratitude  
Dr. Abu-Hadhood - your 28 years of industry mastery transformed coding from theory to career superpower. Those "practical secrets" tripled my professional value overnight!
## Author :  
MOHAMED IDRISSI ALAMI 