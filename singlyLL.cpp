// #include<iostream>
// using namespace std;
// int main(){
//     int n =5;
    
//     for(int i=0;i<n;i++){
//       for(int j=0;j<(i+1);j++){
//         cout<<char(i+65);
        
//       }
//          cout<<endl;  
//     }
 

//     return 0;
// }


// #include<iostream>
// #include<vector>
// using namespace std;

// int main() {
//   vector<int> nums = {1,2,2,2,2,1,1,};
//   int n= nums.size();

//   cout<<*(nums.rbegin())<<endl;
//   cout<<*(nums.rend())<<endl;  // pointing to before vec.begin and retun garbage values..

//   return 0;
// }


// #include<iostream>
// #include<vector>
// using namespace std;

// struct Node {
//   int data;
//   Node*next;

//    Node(int val){
//       data = val;
//       next = nullptr;
//    }
// };

// class Singlylinkedlist {

//   private:
//     Node*head;

//   public:
//     Singlylinkedlist(){
//       head = nullptr;
//     }

//       Node* Firstnode(int value){
//       Node* head = new Node(value);
//       head ->data = value;
//       head ->next = nullptr;
//     }

//     Node *Addnode(int value) {
//       Node *newnode = Firstnode(value);
//       newnode ->next = head;
//       head = newnode;
      
//     }

//     void display(){
//       Node*temp = head;
//       while(temp !=nullptr){
//         cout<<temp->data<<" "<<endl;
//         temp=temp->next ;
//       }
//     }

// };

// int main(){
//   Singlylinkedlist l1;
  
//   l1.Addnode(10);
//   l1.Addnode(15);
//   l1.Addnode(16);
//   l1.display();
// }


// #include <iostream>
// #include <algorithm> // for reverse
// #include <string>
// using namespace std;

// bool isPalindrome(string s){
//    string rev(s.rbegin(),s.rend());

//    if(rev==s) return true;

//    else return false;
// }

// int main() {
//   string s = "raja";
//   cout<<isPalindrome(s);
// }





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
