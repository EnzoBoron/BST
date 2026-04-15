# Binary Search Tree (BST) in C++

Simple implementation of a **Binary Search Tree (BST)** in C++.

## ⚙️ Installation

To compile the project, ensure you have **make** and **g++** installed.
Navigate to the project directory and run:

```bash
make
./bst
```

## 🚀 Example Usage

```cpp
#include "../include/tree.hpp"

int main()
{
    Tree tree;

    // Adding elements
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(8);

    std::cout << "Tree size: " << tree.getSize() << std::endl;
    tree.inOrder(); // Expected: 5 8 10 20

    // Removing an element
    tree.remove(8);

    std::cout << "Tree size: " << tree.getSize() << std::endl;
    tree.inOrder(); // Expected: 5 10 20

    if (tree.contains(10)) {
      std::cout << "Value found" << std::endl;
    } else {
      std::cout << "Value not found" << std::endl;
    }

    return 0;
}
```

## 🛠️ Roadmap

- [X] Make the insert function recursive
- [X] Use a template
- [X] Add operator overloading (printing and comparisons)

## 📜 License

Free to use for educational purposes.
