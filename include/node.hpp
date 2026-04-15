#pragma once

#include <memory>

struct Node
{
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int v) : value(v) {};
};
