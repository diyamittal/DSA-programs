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
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};
void insertatlast(node* &head,int d){
    node* temp=new node(d);
    node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    temp->next=NULL;
    ptr->next=temp;
    temp->prev=ptr;
}
void search(int n,node* &head){
    node* temp=head;
    int count=1;
    while(temp!=NULL){
        if(temp->data==n){
            cout<<"found at"<<count;
            break;
        }
        else{
            count++;
            temp=temp->next;
        }
    }
}
int main(){
    node* node1=new node(10);
    node* head=node1;
    insertatlast(head,9);
    insertatlast(head,1);
    insertatlast(head,2);
    insertatlast(head,6);
    insertatlast(head,3);
    search(6,head);
    return 0;
}