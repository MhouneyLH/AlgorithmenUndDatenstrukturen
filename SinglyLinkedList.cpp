#include "SinglyLinkedList.h"
#include <QDebug>

void SinglyLinkedList::createNewNode(const int data)
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

void SinglyLinkedList::displayAllNodesSimplified()
{
    Node* tempNode = new Node();
    tempNode = m_head;

    QString debugMessage = "";

    while (tempNode != nullptr)
    {
        if (tempNode == m_head)
        {
            debugMessage += "Node " + QString::number(tempNode->data);
        }
        else
        {
            debugMessage += " --> Node " + QString::number(tempNode->data);
        }

        tempNode = tempNode->nextNode;
    }

    // print the notes in one line
    qDebug().noquote() << debugMessage;
}

void SinglyLinkedList::insertNewNodeAtBeginning(const int data)
{
    Node* tempNode = new Node();
    tempNode->data = data;
    tempNode->nextNode = m_head;

    m_head = tempNode;
}

void SinglyLinkedList::insertNewNodeAtEnd(const int data)
{
    createNewNode(data);
}
