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
void reverselinkedlist(node* &head){
    if(head==NULL || head->next==NULL){
    }
    else{
    node* curr=head;
    node* prev=NULL;
    node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
    }
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
    print(head);
    reverselinkedlist(head);
    cout<<endl;
    cout<<"reversed linked list"<<endl;
    print(head);
    return 0;
}