# Binary Search Tree (BST) in C++

## Overview

This project contains a simple implementation of a **Binary Search Tree (BST)** written in C++.
The goal of this repository is educational: understanding how trees work internally by implementing them manually without relying on STL containers.

The tree supports:

* Node insertion
* Tree traversal (preorder, inorder, postorder)
* Recursive memory cleanup
* Basic tree structure manipulation

This implementation focuses on **clarity of algorithms and recursion** rather than advanced optimizations.

---

## Structure

Typical project structure:

```
.
├─ include/
│  └─ Tree.hpp
├─ src/
│  └─ Tree.cpp
└─ README.md
```

* `Tree.hpp`
  Contains the declaration of the `Tree` class and the `Node` structure.

* `Tree.cpp`
  Contains the implementation of all tree operations.

---

## Binary Search Tree Rule

For each node in the tree:

```
left subtree  < node value
right subtree >= node value
```

Insertion respects this rule by recursively descending the tree until a free position is found.

---

## Traversal Methods

### Inorder

```
left → node → right
```

In a Binary Search Tree this traversal prints values **in sorted order**.

### Preorder

```
node → left → right
```

Useful for copying or serializing a tree.

### Postorder

```
left → right → node
```

Often used to safely delete an entire tree.

---

## Memory Management

Tree destruction is handled using a **postorder traversal** so that children are deleted before their parent.

Conceptually:

```
free(left)
free(right)
delete(node)
```

This avoids accessing freed memory during destruction.

---

## Example Usage

Example of how the class could be used in another file:

```cpp
#include "Tree.hpp"

int main()
{
    Tree tree;

    tree.addNode(10);
    tree.addNode(5);
    tree.addNode(20);
    tree.addNode(8);

    tree.inOrder(tree.getNode());

    return 0;
}
```

Expected output:

```
5
8
10
20
```

---

## Compilation Example

Using `g++`:

```
g++ src/Tree.cpp main.cpp -o tree
```

Run:

```
./tree
```

---

## Learning Goals

This project demonstrates:

* pointer manipulation
* recursive algorithms
* tree traversal strategies
* manual memory management in C++

---

## License

Free to use for educational purposes.
