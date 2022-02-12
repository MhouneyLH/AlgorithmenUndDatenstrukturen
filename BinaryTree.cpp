#include "BinaryTree.h"
#include <QDebug>

void BinaryTree::create(const int data)
{
    Node* tempNode = new Node();

    tempNode->data = data;
    tempNode->leftNode = nullptr;
    tempNode->rightNode = nullptr;
}

void BinaryTree::destroy(Node* leaf)
{
    if (leaf != nullptr)
    {
        destroy(leaf->leftNode);
        destroy(leaf->rightNode);
        delete leaf;
    }
}
