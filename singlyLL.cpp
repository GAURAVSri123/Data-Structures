
#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int data;
  Node*next;
};

class singlylinkedlist{
public:  
  Node* head;

  singlylinkedlist(){
    head = NULL;
  }

  Node*insertAtbegining(int val){
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = head;
    head = newnode;
  }

  Node*insertatEnd(int val){
    Node* newnode = new Node();
    Node*temp = head;
    if(head ==NULL){
      newnode = head; 
    }
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->data = val;
    newnode->next = NULL;
  }
  Node* insertatspecificpos(int val,int key){
    Node* newnode = new Node();
    newnode->data = val;
    Node*temp =head;
    if(head==NULL){
      head = newnode;

    } else{
       while(temp->data!=key){
        temp=temp->next;
       }
       newnode->next = temp->next;
       temp->next = newnode; 
    }
  }

  void pop_front(){
    if(head==NULL){
      cout<<"linkedlist is empty"<<endl;
    }
    Node*temp = head;
    head = head->next;
    delete temp;
  }

  void pop_back(){
    if(head==NULL){
      cout<<"linkedlist is empty"<<endl;
    }
    Node*temp =head;
    while(temp->next->next !=NULL){
      temp= temp->next;
    }

    delete (temp->next);
    temp->next = NULL;
  }
  void popatspecificpos(int key) {
    if(head ==NULL){
      cout<<"list is empty"<<endl;
    }
    Node*temp = head;
    for (int i = 0; temp != nullptr && i < key - 1; i++) {
            temp = temp->next;
        }

        // If position is out of range
        if (temp == nullptr || temp->next == nullptr) return;

   
    temp->next = temp->next->next;
    
    delete (temp->next);
  }

  Node*reverseLL(){
    Node* curr = head;
    Node*prev = NULL;
    if(head== NULL){
      cout<<"cant be reverse.."<<endl;

    }
    while(curr!=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head=prev;
    return head;
  }

  void printLinkedlist(){
    Node*temp = head;
    while(temp!= NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
};



int main(){
  singlylinkedlist list;
  list.insertAtbegining(40);
  list.insertAtbegining(30);
  list.insertAtbegining(20);
  list.insertAtbegining(10);
  //list.insertatEnd(50);

  list.printLinkedlist();
  //list.insertatspecificpos(60,20);
 // list.pop_front();
 //list.pop_back();
 //list.popatspecificpos(30);
 list.reverseLL();
  list.printLinkedlist();
}

// vector<int>nums = {1,3,5,6};
// cout<<nums.size();

