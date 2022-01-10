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
    void createNewNode(const int data);
    void displayAllNodesSimplified();
    void insertNewNodeAtBeginning(const int data);

private:
    Node* m_head = nullptr; // beginning of SLL
    Node* m_tail = nullptr; // end of SLL
};

#endif // SINGLYLINKEDLIST_H9CEDF55D8AF1402EACC7650BA7F8F921
