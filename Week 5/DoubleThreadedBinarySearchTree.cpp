#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    bool isrightThreaded;
    bool isleftThreaded;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        isrightThreaded = false;
        isrightThreaded = false;
    }
};

class DoubleThreadedBinarySearchTree
{
public:
    Node *root;

    DoubleThreadedBinarySearchTree()
    {
        root = nullptr;
    }

    void insertNode(int val)
    {
        Node *newnode = new Node(val);
        if (!root)
        {
            root = newnode;
            return;
        }

        Node* curr = root;
        Node* temparent = NULL;

        while(curr != NULL){
            temparent = curr;
            if(curr->data > val){
                if(curr->left == NULL){
                    break;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->right == NULL || curr->isrightThreaded){
                    break;
                }
                else{
                    curr = curr->right;
                }
            }
        }

        if(temparent->data > val){
            temparent->left = newnode;
            newnode->right = temparent;
            newnode->isrightThreaded = true;
        }
        else{
            if(temparent->isrightThreaded){
                newnode->right = temparent->right;
                temparent->isrightThreaded = false;
                newnode->left = temparent
            }
            temparent->right = newnode;
            newnode->left = temparent;
            newnode->isleftThreaded = true;
        }
    }
};

int main()
{

    return 0;
}