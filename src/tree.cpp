#include "../include/tree.hpp"

Tree::Tree()
{
    this->node = new Node;
    this->node->left = nullptr;
    this->node->right = nullptr;
    this->node->value = 0;
}

Tree::~Tree()
{
    freeTree(this->node);
}

void Tree::freeTree(Node* loop)
{
    if (!loop)
        return;

    freeTree(loop->left);
    freeTree(loop->right);
    delete(loop);
}

Node* Tree::getNode(void)
{
    return (Node*)node;
}

void Tree::addFirstNode(int v)
{
    if (!this->node->left && !this->node->right) {
        this->node->value = v;
    }

    this->size++;
}

Node* Tree::initialisationRight(Node* loop, int v)
{
    loop->right = new Node;
    loop->right->left = nullptr;
    loop->right->right = nullptr;
    loop->right->value = v;
    this->size++;

    return loop;
}

Node* Tree::initialisationLeft(Node* loop, int v)
{
    loop->left = new Node;
    loop->left->left = nullptr;
    loop->left->right = nullptr;
    loop->left->value = v;
    this->size++;

    return loop;
}

void Tree::addNode(int v)
{
    Node *loop = this->node;
    
    if (this->size == 0) {
        addFirstNode(v);
        return;
    }

    while (loop && this->size > 0) {
        if (loop->value <= v) {
            if (loop->right) {
                loop = loop->right;
            } else {
                loop = initialisationRight(loop, v);
                return;
            }
        } else if (loop->value > v) {
            if (loop->left) {
                loop = loop->left;
            } else {
                loop = initialisationLeft(loop, v);
                return;
            }
        }
    }
}

void Tree::preOrder(Node* loop)
{ 
    if (!loop)
        return;

    std::cout << loop->value << std::endl;

    preOrder(loop->left);
    preOrder(loop->right);
}

void Tree::inOrder(Node* loop)
{ 
    if (!loop)
        return;

    inOrder(loop->left);
    std::cout << loop->value << std::endl;
    inOrder(loop->right);
}

void Tree::postOrder(Node* loop)
{
    if (!loop)
        return;

    postOrder(loop->left);
    postOrder(loop->right);
    std::cout << loop->value << std::endl;
}
