#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
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
    node* temp=NULL;
    while(curr!=NULL){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
        }
        if(temp!=NULL){
            head=temp->prev;
        }
    }
}
void insertattail(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
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