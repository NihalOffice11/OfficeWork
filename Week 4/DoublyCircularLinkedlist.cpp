#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int data){
        this->data = data;
    }
};

class DoublyCircularLinkedList{
    public:
        Node*head;
    DoublyCircularLinkedList(){
        head = nullptr;
    }

    void insertAtBegin(int data){
        Node* newnode = new Node(data);
        if(head == NULL){
            head = newnode;
            head->next = head;
            head->prev = head;
        }
        else{
            Node* tail = head->prev;
            newnode->next = head;
            newnode->prev = tail;
            head->prev = newnode;
            tail->next = newnode;
            head = newnode;
        
        }
        cout<<"Node Added At Begin"<<endl;
    }

    void insertAtEnd(int data){
        Node* newnode = new Node(data);
        if(head == NULL){
            head = newnode ;
            head->next = head;
            head->prev = head;

        }
        else{
            Node* tail = head->prev;
            newnode->prev = tail;
            newnode->next = head;
            tail->next = newnode;
            head ->prev = newnode;
            
        }
        cout<<"Node inserted At End "<<endl;
    }

    void insertAtPosition(int pos ,int data){
        
    }



    void display(){
        Node* temp = head;
        do{
            cout<<temp->data<<" <==> ";
            temp = temp->next;
        }while(temp != head);
        cout<<head->data<<endl;
    }
}; 
int main(){
    int ch;
    int data;
    char choice;
    int pos;
    DoublyCircularLinkedList DCLL;

    cout<<"********************Main Menu***************************"<<endl;
    cout<<"1. INSERT AT BEGIN "<<endl;
    cout<<"2. INSERT AT END "<<endl;
    cout<<"7. DISPLAY "<<endl;
    
    do{
        cout<<"Enter the choice from main menu "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the data you want to Insert At begin "<<endl;
                cin>>data;
                DCLL.insertAtBegin(data);
                break;
            
            case 2:
                cout<<"Enter the data you want to insert At End "<<endl;
                cin>>data;
                DCLL.insertAtEnd(data);
                break;
            
            case 3:
                cout<<"Enter the position and data where you want to insert Node "<<endl;
                cin>>pos>>data;
                DCLL.insertAtPosition(pos,data);
                break;
            
            case 7:
                DCLL.display();
                break;
        }
        cout<<"Do you want to continue "<<endl;
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
    return 0;
}