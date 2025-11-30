#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
public:
    Node* head;
    Node*tail;

    Queue(){
        head = tail = NULL;
    }

    void push(int val){
        Node* newnode = new Node(val);
        if(isempty()){
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        
    }

    void pop(){
        if(isempty()){
            cout<<"LL is empty"<<endl;
            return;
        }
        Node*temp = head;
        head = head->next;
        delete(temp);
    }

    int front(){
        if(isempty()){
            cout<<"LL is empty"<<endl;
            return 0;
        }
        return head->data;
    }

    bool isempty(){
        return head == NULL;
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    while(!q.isempty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
