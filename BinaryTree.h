#ifndef BINARYTREE_HFF9A3BCAB8CB4554B280D13439C41715
#define BINARYTREE_HFF9A3BCAB8CB4554B280D13439C41715

struct Node
{
    int data;
    Node* leftNode;
    Node* rightNode;

    Node(const int value)
    {
        data = value;
        leftNode = nullptr;
        rightNode = nullptr;
    }
};

class BinaryTree
{
public:
    // creates a new Node in the binary tree
    void create(const int data);
    // displays all nodes in form of a tree --> @TODO: adding this function after we had this in the course (recursive is easier i would guess)
    //void display(Node* rootNode);
    // destroys the tree
    void destroy(Node* leaf);
};

#endif // BINARYTREE_HFF9A3BCAB8CB4554B280D13439C41715
