#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
    
};


class CircularLL{
public:
    Node*head;
    Node*  tail;

    CircularLL(){
        head = tail= NULL;
    }

    Node* push_front(int val){
        Node* newnode = new Node();
        newnode->data = val;
        if(head==NULL){
            head =tail = newnode;
            
        }
        else{
            newnode->next = head;
            head = newnode;
            tail->next = head;
        
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"CLL is empty"<<endl;
        }
        Node*temp = head;
        
        if(head ==tail){
            delete(head);
            head = NULL;
            tail=NULL;
           return;
        }
        head= head->next;
        tail->next = head;
        temp->next = NULL;
        delete(temp);
    }
    
    void push_back(int val){
        Node*temp = head;
        Node * newnode = new Node();
        newnode->data = val;
        if(head==NULL){
            head  =tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
        
    }

    void pop_back(){
        Node*temp = tail;
        if(head==NULL){
            cout<<"CLL is empty";
            return;
        }
        if(head==tail){
            delete(head);
            head=tail= NULL;
            return;
        }
        Node*prev = head;
        while(prev->next!=tail){
            prev = prev->next;
        }
        tail = prev;
        tail->next = head;
        temp->next = NULL;
        delete(temp);
    }

    Node* findAtspecificpos(int x){
        Node*temp = head;
        while(temp->data!=x){
            temp= temp->next;
        }
        cout<< temp;
    }

    void printDLL(){
        Node*temp  = head;
        cout<<temp->data<<" ";
        temp = temp->next;
        while(temp !=head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data;
        cout<<endl;
    }

};

int main(){
   CircularLL CLL;

    CLL.push_front(1);
    CLL.push_front(2);
    CLL.push_front(3);
    CLL.push_back(4);
    //CLL.pop_front();
    //CLL.pop_back();
    CLL.printDLL();
     CLL.findAtspecificpos(2);
}