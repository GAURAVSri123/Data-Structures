#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node*prev;
};


class DoublyLL{
public:
    Node*head;

    DoublyLL(){
        head = NULL;
    }

    Node* push_front(int val){
        Node* newnode = new Node();
        newnode->data = val;
        if(head==NULL){
            head = newnode;
            
        }
        else{
            newnode->next = head;
            head->prev  =newnode;
            head = newnode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"DLL is empty"<<endl;
        }
        Node*temp = head;
        head= head->next;
        if(head !=NULL){
            head->prev =NULL;
        }
        temp->next = NULL;
        delete(temp);
    }
    
    void push_back(int val){
        Node*temp = head;
        Node * newnode = new Node();
        newnode->data = val;
        if(head==NULL){
            head  = newnode;
        }
        else{
            
            while(temp->next!=NULL){
                temp = temp->next;
            }
            newnode->prev = temp;
            temp->next = newnode;
            
        }
        
    }

    void pop_back(){
        Node*temp = head;
        if(head==NULL){
            cout<<"DLL is empty";
            return;
        }
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        if(head->next !=NULL){
            Node* temp2 = temp->next;
            temp->next = NULL;
            temp2->prev = NULL;
            delete(temp2);
        }
        
    }

    void printDLL(){
        Node*temp  = head;
        while(temp !=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    DoublyLL DLL;

    DLL.push_front(1);
    DLL.push_front(2);
    DLL.push_front(3);
    DLL.push_back(4);
    //DLL.pop_front();
    DLL.pop_back();

    DLL.printDLL();
}