#pragma once

#include <memory>

template<typename T> 
struct Node
{
    T value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(T v) : value(v) {};
};
