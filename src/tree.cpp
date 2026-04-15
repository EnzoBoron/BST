#include "../include/tree.hpp"

void Tree::insert(int v)
{
    if (!this->node) {
        node = std::make_unique<Node>(v);
        size++;
        return;
    }

    Node* current = node.get();

    while (true) {
        if (current->value < v) {
            if (!current->right) {
                current->right = std::make_unique<Node>(v);
                this->size++;
                return;
            }
            current = current->right.get();
        } else if (current->value > v) {
            if (!current->left) {
                current->left = std::make_unique<Node>(v);
                this->size++;
                return;
            }
            current = current->left.get();
        } else {
            return;
        }
    }
}

void Tree::preOrderInternal(Node* current) const
{ 
    if (!current)
        return;

    std::cout << current->value << std::endl;

    preOrderInternal(current->left.get());
    preOrderInternal(current->right.get());
}

void Tree::inOrderInternal(Node* current) const
{ 
    if (!current)
        return;

    inOrderInternal(current->left.get());
    std::cout << current->value << std::endl;
    inOrderInternal(current->right.get());
}

void Tree::postOrderInternal(Node* current) const
{
    if (!current)
        return;

    postOrderInternal(current->left.get());
    postOrderInternal(current->right.get());
    std::cout << current->value << std::endl;
}

void Tree::preOrder() const
{
    preOrderInternal(node.get());
}

void Tree::inOrder() const
{
    inOrderInternal(node.get());
}

void Tree::postOrder() const
{
    postOrderInternal(node.get());
}

bool Tree::contains(int key) const
{
    Node* current = node.get();

    while(current) {
        if (key == current->value)
            return true;
        if (key > current->value)
            current = current->right.get();
        else
            current = current->left.get();
    }

    return false;
}

int Tree::getSize(void) const
{
    return size;
}

void Tree::remove(int key)
{
    removeInternal(node, key);
}

void Tree::removeInternal(std::unique_ptr<Node>& current, int key)
{
    if (!current)
        return;

    if (key < current->value) {
        removeInternal(current->left, key);
    }
    else if (key > current->value) {
        removeInternal(current->right, key);
    }
    else {
        if (!current->left && !current->right) {
            current.reset();
            size--;
        }
        else if (!current->left) {
            current = std::move(current->right);
            size--;
        }
        else if (!current->right) {
            current = std::move(current->left);
            size--;
        } else {
            Node* succ = current->right.get();
            while (succ->left)
                succ = succ->left.get();
    
            current->value = succ->value;
            removeInternal(current->right, succ->value);
        }
    }
}