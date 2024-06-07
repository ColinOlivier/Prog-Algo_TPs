#include "binaryTree"

void BinaryTree::insert(int value){
    if(!root)
        root = create_smart_node(value);
    else
        root.insert(value);
}

bool BinaryTree::remove(int value){
    return remove(root, value);
}

void BinaryTree::clear(){
    root.release();
}

size_t BinaryTree::height() const{
    return root.height();
}