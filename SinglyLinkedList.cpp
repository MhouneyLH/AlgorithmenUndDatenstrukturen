#include "SinglyLinkedList.h"
#include <QDebug>

SinglyLinkedList::SinglyLinkedList()
{
    m_headNode = nullptr;
    m_tailNode = nullptr;
}

SinglyLinkedList::~SinglyLinkedList()
{
    m_headNode = nullptr;
    m_tailNode = nullptr;

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
    Node* tempNode = m_headNode;

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

void SinglyLinkedList::insertNewNodeAtPosition(const unsigned int index, const int data)
{
    Node* tempNode = new Node();
    Node* currentNode = m_headNode;
    Node* previousNode = new Node();

    for (unsigned int i = 0U /* m_head will be skipped */; i < index; i++)
    {
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    // insert the tempNode in between the previous and the current Node
    tempNode->data = data;
    tempNode->nextNode = currentNode;
    previousNode->nextNode = tempNode;
}

void SinglyLinkedList::replaceSingleNode(const unsigned int index, const int data)
{
    Node* tempNode = new Node();
    Node* currentNode = m_headNode;
    Node* previousNode = new Node();

    for (unsigned i = 0U; i < index; i++)
    {
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    tempNode->data = data;
    tempNode->nextNode = currentNode->nextNode;
    previousNode->nextNode = tempNode;
}

void SinglyLinkedList::replaceMultipleNodes(const unsigned int startIndex, const unsigned int endIndex, const QVector<int> data)
{
    for (unsigned int currentIndex = startIndex; currentIndex < endIndex + 1 /* +1, as the endIndex also has to be replaced */; currentIndex++)
    {
        replaceSingleNode(currentIndex, data.at(currentIndex - startIndex));
    }
}

unsigned int SinglyLinkedList::getLength() const
{
    Node* tempNode = m_headNode;
    unsigned int nodeCount = 0U;

    while (tempNode != nullptr)
    {
        nodeCount++;
        tempNode = tempNode->nextNode;
    }

    return nodeCount;
}

void SinglyLinkedList::deleteList()
{
    this->~SinglyLinkedList();
}

void SinglyLinkedList::clearList()
{
    Node* tempNode = m_headNode;

    while (tempNode != nullptr)
    {
        tempNode->data = 0;
        tempNode = tempNode->nextNode;
    }
}
