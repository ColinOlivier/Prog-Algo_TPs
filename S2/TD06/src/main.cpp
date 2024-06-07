#include <iostream>
#include <cstdlib>
#include <numeric>
#include "node.hpp"
#include "smartNode.hpp"
#include "view.hpp"

int main() {

    Node* rootNode = new Node{ 5 };
    rootNode->insert(3);
    rootNode->insert(7);
    rootNode->insert(2);
    rootNode->insert(4);
    rootNode->insert(6);
    rootNode->insert(8);
    rootNode->insert(1);
    rootNode->insert(9);
    rootNode->insert(0);

    rootNode->display_infixe();
    std::cout << std::endl;

    std::cout << "Min : " << min(rootNode) << std::endl;
    std::cout << "Max : " << max(rootNode) << std::endl;

    int prefixeSum{ 0 };
    for (Node const* node : rootNode->prefixe())
    {
        prefixeSum += node->value;
    }
    std::cout << "Sum : " << prefixeSum << std::endl;

    std::cout << "Height : " << rootNode->height()<< std::endl;

 // ---------------------
    SmartNode rootSmartNode = SmartNode{ 5 };
    rootSmartNode.insert(3);
    rootSmartNode.insert(7);
    rootSmartNode.insert(2);
    rootSmartNode.insert(4);
    rootSmartNode.insert(6);
    rootSmartNode.insert(8);
    rootSmartNode.insert(1);
    rootSmartNode.insert(9);
    rootSmartNode.insert(0);
    std::cout << "Min : " << rootSmartNode.min() << std::endl;
    std::cout << "Max : " << rootSmartNode.max() << std::endl;
   

    return 0;
}