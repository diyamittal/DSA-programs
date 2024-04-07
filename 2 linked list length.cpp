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
void insert(node* &head, int d){
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}
int gcount(node* &head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,5);
    insert(head,8);
    insert(head,9);
    insert(head,3);
    insert(head,2);
    insert(head,6);
    cout<< "length is"<<gcount(head);
    return 0;
}