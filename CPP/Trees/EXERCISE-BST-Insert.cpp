#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;

public:
    BinarySearchTree() { root = nullptr; }

    // ---------------------------------------------------
    //  Below is a helper function used by the destructor
    //  Deletes all nodes in BST
    //  Similar to DFS PostOrder in Tree Traversal section
    // ---------------------------------------------------
    void destroy(Node *currentNode)
    {
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTree() { destroy(root); }

    bool insert(int value)
    {
        // Create a new node with the given value
        Node *newNode = new Node(value);

        // If the tree is empty, set the new node as the root and return true
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }

        // Start from the root and find the correct position for the new node
        Node *temp = root;
        while (true)
        {
            // If the new node's value already exists in the tree, return false
            if (newNode->value == temp->value)
                return false;

            // If the new node's value is less than the current node's value, go left
            if (newNode->value < temp->value)
            {
                // If left child is null, insert here and return true
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                // Move to the left child
                temp = temp->left;
            }
            else // If the new node's value is greater than the current node's value, go right
            {
                // If right child is null, insert here and return true
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                // Move to the right child
                temp = temp->right;
            }
        }
    }
};

int main()
{

    BinarySearchTree *myBST = new BinarySearchTree();

    myBST->insert(2);
    myBST->insert(1);
    myBST->insert(3);

    /*
        THE LINES ABOVE CREATE THIS TREE:
                     2
                    / \
                   1   3
    */

    // ROOT MUST BE PUBLIC FOR THESE LINES TO WORK
    cout << "Root: " << myBST->root->value;
    cout << "\n\nRoot->Left: " << myBST->root->left->value;
    cout << "\n\nRoot->Right: " << myBST->root->right->value;

    /*
        EXPECTED OUTPUT:
        ----------------
        Root: 2

        Root->Left: 1

        Root->Right: 3

    */
}
