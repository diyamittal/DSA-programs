#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* kreverse(node* &head,int k){
    if(head==NULL){
        return NULL;
    }
    node* forward=NULL;
    node* curr=head;
    node* prev=NULL;
    int count=0;
    while(curr!=NULL && count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL){
        head->next=kreverse(forward,k);
    }
    head=prev;
    return prev;
}
void insertattail(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}

void print(node* &head){
    node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
    insertattail(tail,6);
    insertattail(tail,9);
    insertattail(tail,2);
    insertattail(tail,5);
    insertattail(tail,1);
    print(head);
    kreverse(head,3);
    cout<<endl;
    cout<<"reversed linked list"<<endl;
    print(head);
    return 0;
}