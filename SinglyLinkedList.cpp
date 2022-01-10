#include "SinglyLinkedList.h"

void SinglyLinkedList::createNewNode(int data)
{
    Node* tempNode = new Node();
    tempNode->data = data;
    tempNode->nextNode = nullptr;

    // case of an empty list
    if (m_head == nullptr)
    {
        m_head = tempNode;
        m_tail = tempNode;
        tempNode = nullptr; // not needed anymore
        return;
    }

    // tempNode behind tailNode
    m_tail->nextNode = tempNode;
    // tailNode behind tempNode
    m_tail = m_tail->nextNode;
}
