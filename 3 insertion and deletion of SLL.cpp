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
void insertathead(node* &head,int d){
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}
void insertattail(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}
void insertatposition(node* &head, int position, int d){
    node* ptr=head;
    for(int i=1;i<position-1;i++){
        ptr=ptr->next;
    }
    node* temp=new node(d);
    temp->next=ptr->next;
    ptr->next=temp;
}

void print(node* &head){
    node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void deleteatposition(int position, node* &head){
    if(position==1){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* curr=head;
        node* prev=NULL;
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main(){
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
    insertathead(head,6);
    insertattail(tail,9);
    insertatposition(tail,head,2,10);
    //deleteatposition(2,head);
    print(head);
    return 0;
}