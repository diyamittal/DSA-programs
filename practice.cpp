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
        this->prev=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};
void insert(node* &head, int element, int d){
    if(head==NULL){
        node* newnode=new node(d);
        head=newnode;
        newnode->next=newnode;
    }
    else{
        node* curr=head;
        while(curr->data!=element){
            curr=curr->next;
        }
        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void deletion(node* &head, int d){
    if(head==NULL){
        return;
    }
    else{
        node* prev=head;
        node* curr=prev->next;
        while(curr->data!=d){
            curr=curr->next;
            prev=prev->next;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(node* &head){
    node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
    insert(head,10,12);
    insert(head,10,11);
    insert(head,12,13);
    deletion(head, 12);
    print(head);
    return 0;
}