#ifndef SINGLYLINKEDLIST_H9CEDF55D8AF1402EACC7650BA7F8F921
#define SINGLYLINKEDLIST_H9CEDF55D8AF1402EACC7650BA7F8F921

#include <QVector>

// nodes are the individual components of the singlyLinkedList
struct Node
{
    int data;
    Node* nextNode;
};

// the SinglyLinkedList is a list, which contain nodes,
// which contain a piece of data and the address of the next node of the list
class SinglyLinkedList
{
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    /////////////////////////////////////////////////
    /// GENERAL METHODS
    /////////////////////////////////////////////////
    // creates a new node of the singlyLinkedList
    void createNewNode(const int data);
    // displays the nodes in the format: "Node [data] --> nextNode [data] --> ..."
    void displayAllNodesSimplified();
    // returns the length of the singlyLinkedList
    unsigned int getLength() const;
    // deletes the singlyLinkedList
    void deleteList();
    // clears the values of the singlyLinkedList
    void clearList();

    /////////////////////////////////////////////////
    /// INSERTION OF NEW NODES
    /////////////////////////////////////////////////
    // creates a new node at the begining of the singlyLinkedList
    void insertNewNodeAtBeginning(const int data);
    // creates a new node at the end of the singlyLinkedList
    void insertNewNodeAtEnd(const int data);
    // creates a new node at a specific position of the singlyLinkedList
    void insertNewNodeAtPosition(const unsigned int index, const int data);

    /////////////////////////////////////////////////
    /// REPLACING OF NODES
    /////////////////////////////////////////////////
    // replaces a single node of the singlyLinkedList
    void replaceSingleNode(const unsigned int index, const int data);
    // replaces multiple nodes of the singlyLinkedList and add for every index a different value based on a QVector
    void replaceMultipleNodes(const unsigned int startIndex, const unsigned int endIndex, const QVector<int> data);

private:
    Node* m_headNode = nullptr; // beginning of singlyLinkedList
    Node* m_tailNode = nullptr; // end of singlyLinkedList
};

#endif // SINGLYLINKEDLIST_H9CEDF55D8AF1402EACC7650BA7F8F921
