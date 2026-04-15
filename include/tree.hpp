#pragma once

    #include <iostream>
    #include <vector>
    #include <string>
    #include "node.hpp"
    
    class Tree
    {
    private:
        int size = 0;
        std::unique_ptr<Node> node;
        void removeInternal(std::unique_ptr<Node>& head, int key);
        void preOrderInternal(Node*) const;
        void inOrderInternal(Node*) const;
        void postOrderInternal(Node*) const;
        void insertInternal(int, std::unique_ptr<Node>&);
    public:
        void preOrder() const;
        void inOrder() const;
        void postOrder() const;
        bool contains(int) const;
        void insert(int);
        void remove(int);
        int getSize(void) const;
    };
    