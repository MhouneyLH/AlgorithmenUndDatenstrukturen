#ifndef SINGLYLINKEDLIST_H9CEDF55D8AF1402EACC7650BA7F8F921
#define SINGLYLINKEDLIST_H9CEDF55D8AF1402EACC7650BA7F8F921

struct Node
{
    int data;
    Node* nextNode;
};

class SinglyLinkedList
{
public:
    void createNewNode(int data);
    void displayAllNodesSimplified();

private:
    Node* m_head = nullptr; // beginning of SLL
    Node* m_tail = nullptr; // end of SLL
};

#endif // SINGLYLINKEDLIST_H9CEDF55D8AF1402EACC7650BA7F8F921
