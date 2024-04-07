#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* minval(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* maxval(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
Node* insertatBST(Node* &root, int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertatBST(root->right, d);
    }
    else{
        root->left=insertatBST(root->left, d);
    }
    return root;
}
void takeinput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        insertatBST(root, data);
        cin>>data;
    }
}
Node* deletefromBST(Node* root, int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right!=NULL){
            int mini=minval(root->right)->data;
            root->data=mini;
            root->right=deletefromBST(root->right, mini);
            return root;
        }
        else if(root->data>val){
            root->left=deletefromBST(root->left, val);
            return root;
        }
        else{
            root->right=deletefromBST(root->right, val);
            return root;
        }
    }
}
int main(){
    Node* root=NULL;
    cout<<"Enter data"<<endl;
    takeinput(root);
    root= deletefromBST(root, 5);
    levelordertraversal(root);
    cout<<minval(root)->data<<endl;
    cout<<maxval(root)->data<<endl;
}