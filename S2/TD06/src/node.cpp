#include <algorithm>
#include <iostream>
#include "node.hpp"

Node* Node::create_node(int value) {
    return new Node{ value };
}

bool Node::is_leaf() const {
    return this->right == nullptr && this->right == nullptr;
}

void Node::insert(int value) {
    if (this->value > value)
        if (this->left == nullptr)
            this->left = create_node(value);
        else
            this->left->insert(value);
    else
        if (this->right == nullptr)
            this->right = create_node(value);
        else
            this->right->insert(value);
}

int Node::height() const {
    if (is_leaf())
        return 1;

    int leftHeight{ 0 };
    int rightHeight{ 0 };

    if (left != nullptr)
        leftHeight = left->height();
    if (right != nullptr)
        rightHeight = right->height();

    return std::max(leftHeight, rightHeight) + 1;
}

void Node::delete_childs() {
    if (left != nullptr) {
        left->delete_childs();
        delete left;
    }
    if (right != nullptr) {
        right->delete_childs();
        delete right;
    }
}

void Node::display_infixe() const {
    if (left != nullptr)
        left->display_infixe();
    std::cout << value << " ";
    if (right != nullptr)
        right->display_infixe();
}

std::vector<Node const*> Node::prefixe() const {
    std::vector<Node const*> vec{ this };
    std::vector<Node const*> vecChild;
    if (left != nullptr) {
        vecChild = left->prefixe();
        vec.insert(vec.end(), vecChild.begin(), vecChild.end());
    }
    if (right != nullptr) {
        vecChild = right->prefixe();
        vec.insert(vec.end(), vecChild.begin(), vecChild.end());
    }

    return vec;
}

std::vector<Node const*> Node::postfixe() const {
    std::vector<Node const*> vec;
    std::vector<Node const*> vecChild;

    if (left != nullptr) {
        vecChild = left->prefixe();
        vec.insert(vec.end(), vecChild.begin(), vecChild.end());
    }
    if (right != nullptr) {
        vecChild = right->prefixe();
        vec.insert(vec.end(), vecChild.begin(), vecChild.end());
    }
    vec.push_back(this);

    return vec;
}

Node*& most_left(Node*& node) {
    if (node->left != nullptr)
        return most_left(node->left);
    return node;
}

bool remove(Node*& node, int value) {
    if (node->value == value) {
        if (node->is_leaf()) {
            delete node;
            node = nullptr;
            return true;
        }
        else if (node->left != nullptr && node->right == nullptr)
        {
            Node* childNode = node->left;
            delete node;
            node = childNode;
            return true;
        }
        else if (node->right != nullptr && node->left == nullptr)
        {
            Node* childNode = node->right;
            delete node;
            node = childNode;
            return true;
        }
        else {
            Node*& mostLeftRightNode = most_left(node->right);
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

void delete_tree(Node* node) {
    node->delete_childs();
    delete node;
}

int min(Node* node) {
    return most_left(node)->value;
}

int max(Node* node) {
    if (node->right != nullptr)
        return max(node->right);
    return node->value;
}