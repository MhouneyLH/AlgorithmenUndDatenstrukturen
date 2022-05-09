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

void SinglyLinkedList::createMultipleNewNodes(const QVector<int> data)
{
    for (unsigned int i = 0U; i < data.length(); i++)
    {
        createNewNode(data.at(i));
    }
}

void SinglyLinkedList::createMultipleNewNodesWithTheSameData(const unsigned int numberOfNewNodes, const int data)
{
    for (unsigned int i = 0U; i < numberOfNewNodes; i++)
    {
        createNewNode(data);
    }
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

void SinglyLinkedList::replaceMultipleNodesWithTheSameData(const unsigned int startIndex, const unsigned int endIndex, const int data)
{
    for (unsigned int currentIndex = startIndex; currentIndex < endIndex + 1 /* +1, as the endIndex also has to be replaced */; currentIndex++)
    {
        replaceSingleNode(currentIndex, data);
    }
}

unsigned int SinglyLinkedList::findFirstNodeWithSpecificData(const int data)
{
    Node* tempNode = m_headNode;
    unsigned int index = 0U;

    while (tempNode != nullptr && tempNode->data != data)
    {
        tempNode = tempNode->nextNode;
        index++;
    }

    // no node with the searched data was found
    if (tempNode == nullptr)
    {
        return getLength() + 1;
    }

    return index;
}

QVector<int> SinglyLinkedList::findAllNodesWithSpecificData(const int data)
{
    Node* tempNode = m_headNode;
    QVector<int> indexes;

    for (int currentIndex = 0; tempNode != nullptr; currentIndex++)
    {
        if (tempNode->data == data)
        {
            indexes.push_back(currentIndex);
        }

        tempNode = tempNode->nextNode;
    }

    return indexes;
}

QVector<int> SinglyLinkedList::findFirstNodeDataPattern(const QVector<int> dataPattern)
{
    Node* tempNode = m_headNode;
    Node* saveNode = m_headNode;
    QVector<int> indexes;

    // the whole singlyLinkedList
    for (int currentIndex = 0; tempNode != nullptr; currentIndex++)
    {
        unsigned int nodeDataIsSameAsDataPatternDataCount = 0U;
        saveNode = tempNode;

        // check of the single patterns
        for (int i = 0; i < dataPattern.length() && tempNode != nullptr; i++)
        {
            if (tempNode->data != dataPattern.at(i))
            {
                tempNode = tempNode->nextNode;
                continue;
            }

            nodeDataIsSameAsDataPatternDataCount++;
            tempNode = tempNode->nextNode;
        }

        // every data is the same as the data from the dataPattern
        if (nodeDataIsSameAsDataPatternDataCount == dataPattern.length())
        {
            for (int i = 0; i < dataPattern.length(); i++)
            {
                indexes.push_back(currentIndex + i);
            }
            return indexes;
        }

        tempNode = saveNode;
        tempNode = tempNode->nextNode;
    }

    return indexes;
}

// @TODO: add this funtction only when needed in the future
//QVector<QVector<int>> SinglyLinkedList::findAllNodesDataPatterns(const QVector<int> dataPattern)
//{
//}

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
