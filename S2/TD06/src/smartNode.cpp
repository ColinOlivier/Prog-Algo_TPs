#include <algorithm>
#include <iostream>
#include "smartNode.hpp"

std::unique_ptr<SmartNode> create_smart_node(int value) {
    return std::make_unique<SmartNode>(SmartNode{value});
}

bool SmartNode::is_leaf() const {
    return !this->right && !this->right;
}

void SmartNode::insert(int value) {
    if (this->value > value)
        if (!this->left)
            this->left = create_smart_node(value);
        else
            this->left->insert(value);
    else
        if (!this->right)
            this->right = create_smart_node(value);
        else
            this->right->insert(value);
}

size_t SmartNode::height() const {
    if (is_leaf())
        return 1;

    int leftHeight{ 0 };
    int rightHeight{ 0 };

    if (left)
        leftHeight = left->height();
    if (right)
        rightHeight = right->height();

    return std::max(leftHeight, rightHeight) + 1;
}

std::unique_ptr<SmartNode>& most_left(std::unique_ptr<SmartNode>& node){
    if (node->left)
        return most_left(node->left);
    return node;
}

bool remove(std::unique_ptr<SmartNode>& node, int value){    
    if (node->value == value) {
        if (node->is_leaf()) {
            node.release();
            return true;
        }
        else if (node->left && !node->right)
        {
            node.reset(node->left.get());
            return true;
        }
        else if (node->right && !node->left)
        {
            node.reset(node->right.get());
            return true;
        }
        else {
            std::unique_ptr<SmartNode>& mostLeftRightNode = most_left(node->right);
            int futurValue = mostLeftRightNode->value;
            remove(node, futurValue);
            node->value = futurValue;
            return true;
        }
    }
    else {
        if (node->value > value)
            return remove(node->left, value);
        else
            return remove(node->right, value);
    }
}


int SmartNode::min() const {
    if (left)
        return left->min();
    return value;
}

int SmartNode::max() const{
    if (right)
        return right->max();
    return value;
}