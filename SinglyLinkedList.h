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
    // displays the nodes in the format: "Node [data] --> nextNode [data] --> ..."
    void displayAllNodesSimplified();
    // returns the length of the singlyLinkedList
    unsigned int getLength() const;
    // deletes the singlyLinkedList
    void deleteList();
    // clears the values of the singlyLinkedList
    void clearList();

    /////////////////////////////////////////////////
    /// CREATION OF NEW NODES
    /////////////////////////////////////////////////
    // creates a new node of the singlyLinkedList
    void createNewNode(const int data);
    // creates "numberOfNodes" new nodes of the singlyLinkedList and adds for every index a different value based on a QVector
    void createMultipleNewNodes(const QVector<int> data);
    // creates "numberOfNodes" new nodes of the singlyLinkedList and give it the data "data"
    void createMultipleNewNodesWithTheSameData(const unsigned int numberOfNewNodes, const int data);

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
    // replaces multiple nodes of the singlyLinkedList and adds for every index a different value based on a QVector
    void replaceMultipleNodes(const unsigned int startIndex, const unsigned int endIndex, const QVector<int> data);
    // replaces multiple nodes of the singlyLinkedList and give it the data "data"
    void replaceMultipleNodesWithTheSameData(const unsigned int startIndex, const unsigned int endIndex, const int data);

    /////////////////////////////////////////////////
    /// FINDING OF NODES
    /////////////////////////////////////////////////
    // finds the first node with specific data in the singlyLinkedList
    // IMPORTANT: if return-value = getLength() + 1, then no node with this data was found
    // @TODO: better control of this case
    unsigned int findFirstNodeWithSpecificData(const int data);
    // finds all nodes with specific data in the singlyLinkedList
    QVector<int> findAllNodesWithSpecificData(const int data);
    // finds the first nodeDataPattern in the singlyLinkedList
    // a nodeDataPattern is a pattern of data
    // example: SinglyLinkedList is 0 1 2 3 4 5 6, so e.g. 1 2 3 is a nodeDataPattern
    QVector<int> findFirstNodeDataPattern(const QVector<int> dataPattern);
    // finds all nodeDataPatterns in the singlyLinkedList
    QVector<QVector<int>> findAllNodesDataPatterns(const QVector<int> dataPattern);

private:
    Node* m_headNode = nullptr; // beginning of singlyLinkedList
    Node* m_tailNode = nullptr; // end of singlyLinkedList
};

#endif // SINGLYLINKEDLIST_H9CEDF55D8AF1402EACC7650BA7F8F921
