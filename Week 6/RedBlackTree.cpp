#include<bits/stdc++.h>
using namespace std;

enum  Color{
    RED,BLACK
};

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Color color;
        Node* parent;

        Node(int data){
            this->data = data;
            left = nullptr;
            right = nullptr;
            color = Color::RED;
            parent = nullptr;
        }
};

class RedBlackTree{
    public:
        Node* root;

        RedBlackTree(){
            root = nullptr;
        }

        void leftRotation(Node* temp){
            Node* y = temp->right;
            temp->right = y->left;

            if(y->left != nullptr){
                y->left->parent = temp;
            }
            y->parent = temp->parent;
            if(temp->parent == nullptr){
                root = y;
            }
            else if(temp == temp->parent->left){
                temp->parent->left = y;
            }
            else{

            }
            y->left = temp;
            temp->parent = y;
        }

        void rightRotation(Node* temp){
            Node* y = temp->left;
            temp->left = y->right;

            if(y->right != nullptr){
                y->right->parent = temp;
            }
            y->parent = temp->parent;
            if(temp->parent == nullptr){
                root = y;
            }
            else if(temp = temp->parent->right){
                temp->parent->right = y;
            }
            else{
                temp->parent->left = y;
            }

            y->right = temp;
            temp->parent = y;
        }

        void fixInsertOperation(Node* temp){
            Node* sibling;

            while(temp->parent && temp->parent->color == RED){
                if(temp->parent == temp->parent->parent->left){ // if newnode's parent is left of its grandparent
                    sibling = temp->parent->parent->right;

                    if(sibling && sibling->color == RED){

                    }
                    else{  // sibling is Black or Nil
                        if(temp == temp->parent->right){
                            temp = temp->parent;
                            leftRotation(temp);
                        }

                        temp->parent->color = BLACK;
                        temp->parent->parent->color = RED;
                        rightRotation(temp->parent->parent);
                    }
                }   
                else{                                           // if newnode's parent is right of ist grandparent
                    sibling = temp->parent->parent->left;
                    if(sibling->color == RED && sibling){
                        temp->parent->color = BLACK;
                        sibling->color = BLACK;
                        temp->parent->parent->color = RED;
                        temp = temp->parent->parent;
                    }
                    else{
                        // temp is left child of its parent
                        if(temp == temp->parent->left){
                            temp = temp->parent;
                            rightRotation(temp);
                        }

                        // tempp is the right child of its parent
                    }
                }
            }
            
            root->color = BLACK;
            
        }

        void insert(int data){
            Node* newnode = new Node(data);
            Node* y =nullptr;
            Node* x = root;

            while(x != nullptr){
                y = x;
                if(newnode->data < x->data ){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }

            newnode->parent = y ;
            if(y == NULL){
                root = newnode;
            }
            else if(newnode->data < y->data){
                y->left = newnode;
            }
            else{
                y->right = newnode;
            }

            fixInsertOperation(newnode);
        }
};




int main(){
    
    return 0;
}