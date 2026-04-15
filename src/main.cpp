#include "../include/tree.hpp"

int main()
{
    Tree tree;
    Tree tree2;

    // Adding elements
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(8);

    tree2.insert(30);

    // std::cout << tree;

    if (tree == tree2)
      std::cout << "tree est egale a tree2";

    /* std::cout << "Tree size: " << tree.getSize() << std::endl;
    tree.inOrder(); // Expected: 5 8 10 20

    // Removing an element
    tree.remove(8);

    std::cout << "Tree size: " << tree.getSize() << std::endl;
    tree.inOrder(); // Expected: 5 10 20

    if (tree.contains(10)) {
      std::cout << "Value found" << std::endl;
    } else {
      std::cout << "Value not found" << std::endl;
    } */

    return 0;
}