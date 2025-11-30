#include<iostream>
#include<vector>
using namespace std;

class Node{
public:   
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left= right= NULL;
    }

};

Node* insertBST(Node*root , int val){
    if(root==NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left = insertBST(root->left,val);
    } else{
        root->right = insertBST(root->right,val);
    }
    return root;
}

Node* buildBST(vector<int> arr){
    Node* root = NULL;
    for(int val:arr){
        root = insertBST(root,val);
    }
    return root;
}

bool Search(Node* root, int key){
    if(root==NULL){
        return false;
    }

    if(root->data ==key){
        return true;
    } else if(root->data>key){
        return Search(root->left,key);
    } else{
        return Search(root->right,key);
    }

    return false;
}

Node * getInorderSuccesor(Node*root){
    while(root !=NULL && root->left !=NULL){
        root =root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root==NULL){
        return NULL;
    }

    if(key<root->data){
        root->left = deleteNode(root->left,key);
    } else if(key>root->data){
        root->right = deleteNode(root->right,key);
    } else {
        if(root->left==NULL){
            Node* temp = root->right;
            delete(root);
            return temp;
        } else if(root->right==NULL){
             Node* temp = root->left;
            delete(root);
            return temp;
        } else{
            Node * IS = getInorderSuccesor(root->right);
            root->data = IS->data;
            root->right= deleteNode(root->right,IS->data);
        }
        
    }
    return root;
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node*root){
    if(root==NULL){
        return;
    }
     inOrder(root->left);
     cout<<root->data<<" ";
     inOrder(root->right);
    
}
void postOrder(Node * root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main(){
    vector<int> arr = { 3,2,1,5,6,4};
    Node* root = buildBST(arr);
    inOrder(root);
    cout<<endl;
    deleteNode(root,7);
    inOrder(root);
    cout<<endl;
    
    

   cout<< Search(root,7);
}