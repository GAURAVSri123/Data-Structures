#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node*left;
    Node*right;
    int height;

    Node(int val){
        data = val;
        left=right = NULL;
    }
};

int height(Node* N){
    if(N==NULL){
        return 0;
    }
    return N->height;
}

int updateheight(Node* N){
    if(N==NULL){
        return 0;
    }
    return max(N->left->height,N->right->height) + 1;
}

int balanceFactor(Node *N){
    if(N==NULL){
        return 0;
    }
    return (N->left->height - N->right->height) +1;
}

// left--left case
Node* rightrotation(Node* y){
    Node * x = y->left;
    Node*z = x->right;

    //rotate
    x->right = y;
    y->left = z;
    updateheight(y);
    updateheight(x);
    return x;
}
//right-right
Node* leftrotation(Node* x){
    Node * y = x->right;
    Node*z = y->left;

    //rotate
    y->left = x;
    x->right = z;
    updateheight(x);
    updateheight(y);
    return y;
}

Node* insert(Node* node, int val){
    if(node==NULL){
        return new Node(val);
    }

    if(val<node->data){
        node->left = insert(node->left,val);
    } else{
        node->right = insert(node->right,val);
    }
    return node;

    updateheight(node);
    int fd = balanceFactor(node);

    // left -left case
    if(fd>1 && val<node->left->data){
        return rightrotation(node);
    }
    // right-right case
    if(fd<-1 && val>node->right->data){
        return leftrotation(node);
    }
    //left - right case
    if(fd > 1 && val > node->left->data){
        node->left = leftrotation(node);
        return rightrotation(node);
    }
    // right - left case
     if(fd < -1 && val < node->right->data){
        node->right = rightrotation(node);
        return leftrotation(node);
    }

    return node;


}

void inOrder(Node*root){
    if(root!=NULL){
        inOrder(root->left) ;
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main(){
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    inOrder(root);
}
