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
    BinaryTree();
    ~BinaryTree();

    void createNewNode(const int data);

private:
    Node* m_rootNode = nullptr;
};

#endif // BINARYTREE_HFF9A3BCAB8CB4554B280D13439C41715
