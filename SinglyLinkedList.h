#ifndef SINGLYLINKEDLIST_H9CEDF55D8AF1402EACC7650BA7F8F921
#define SINGLYLINKEDLIST_H9CEDF55D8AF1402EACC7650BA7F8F921

/// TO ADD: replacing, deleting, insert

struct Node
{
    int data;
    Node* nextNode;
};

class SinglyLinkedList
{
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void createNewNode(const int data);
    void displayAllNodesSimplified();
    void insertNewNodeAtBeginning(const int data);
    void insertNewNodeAtEnd(const int data);
    void insertNewNodeAtPosition(const unsigned int position, const int data);
    unsigned int length() const;

private:
    Node* m_headNode = nullptr; // beginning of SLL
    Node* m_tailNode = nullptr; // end of SLL
};

#endif // SINGLYLINKEDLIST_H9CEDF55D8AF1402EACC7650BA7F8F921
