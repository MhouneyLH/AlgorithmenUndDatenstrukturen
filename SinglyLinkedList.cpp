#include "SinglyLinkedList.h"
#include <QDebug>

SinglyLinkedList::SinglyLinkedList()
{
    m_headNode = nullptr;
    m_tailNode = nullptr;
}

SinglyLinkedList::~SinglyLinkedList()
{
    delete m_headNode;
    delete m_tailNode;
}

void SinglyLinkedList::createNewNode(const int data)
{
    Node* tempNode = new Node();
    tempNode->data = data;
    tempNode->nextNode = nullptr;

    // case of an empty list
    if (m_headNode == nullptr)
    {
        m_headNode = tempNode;
        m_tailNode = tempNode;
        tempNode = nullptr; // not needed anymore
        return;
    }

    // tempNode behind tailNode
    m_tailNode->nextNode = tempNode;
    // tailNode behind tempNode
    m_tailNode = m_tailNode->nextNode;
}

void SinglyLinkedList::displayAllNodesSimplified()
{
    Node* tempNode = new Node();
    tempNode = m_headNode;

    QString debugMessage = "";

    while (tempNode != nullptr)
    {
        if (tempNode == m_headNode)
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
    tempNode->nextNode = m_headNode;
    m_headNode = tempNode;
}

void SinglyLinkedList::insertNewNodeAtEnd(const int data)
{
    createNewNode(data);
}

void SinglyLinkedList::insertNewNodeAtPosition(const unsigned int position, const int data)
{
    Node* tempNode = new Node();
    Node* currentNode = new Node();
    Node* previousNode = new Node();

    currentNode = m_headNode;

    for (unsigned int i = 0U /* m_head will be skipped */; i < position; i++)
    {
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    tempNode->data = data;
    tempNode->nextNode = currentNode;
    previousNode->nextNode = tempNode;
}
