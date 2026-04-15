#pragma once

    #include <iostream>
    #include <vector>
    #include <string>
    #include "node.hpp"
    
    template<typename T>
    class Tree
    {
    private:
        int size = 0;
        std::unique_ptr<Node<T>> node;
        void removeInternal(std::unique_ptr<Node<T>>& head, T key);
        void preOrderInternal(Node<T>*) const;
        void inOrderInternal(Node<T>*) const;
        void postOrderInternal(Node<T>*) const;
        void insertInternal(T, std::unique_ptr<Node<T>>&);
        void printOperatorInternal(std::ostream& os, Node<T>* current) const;
    public:
        void preOrder() const;
        void inOrder() const;
        void postOrder() const;
        bool contains(T) const;
        void insert(T);
        void remove(T);
        int getSize(void) const;

        bool operator<(const Tree<T>& other) const;
        bool operator>(const Tree<T>& other) const;
        bool operator==(const Tree<T>& other) const;
    };
    
    #include "../src/tree.tpp"