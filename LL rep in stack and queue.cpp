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
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};
void insertStack(node* &head,int d){
    node* temp=new node(d);
    node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    temp->next=NULL;
    ptr->next=temp;
}
void insertQueue(node* &head,int d){
    node* temp=new node(d);
    node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    temp->next=NULL;
    ptr->next=temp;
}
void print(node* head){
    node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void deleteQueue(node* &head){
    node* ptr=head;
    head=head->next;
    ptr->next=NULL;
    delete ptr;
}
void deleteStack(node* &head){
    node* ptr1= head;
    node* ptr2=head;
    while(ptr1->next!= NULL){
        ptr2=ptr1;
        ptr1 = ptr1->next;
    }
    ptr2->next=NULL;
    delete ptr1;
}
int main(){
    node* node1=new node(10);
    node* head1=node1;
    insertStack(head1,9);
    insertStack(head1,1);
    insertStack(head1,6);
    insertStack(head1,3);
    deleteStack(head1);
    deleteStack(head1);
    print(head1);
    cout<<endl;
    node* node2=new node(10);
    node* head2=node2;
    insertQueue(head2,9);
    insertQueue(head2,1);
    insertQueue(head2,6);
    insertQueue(head2,3);
    deleteQueue(head2);
    deleteQueue(head2);
    print(head2);
    cout<<endl;
    return 0;
}