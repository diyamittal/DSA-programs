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
void print(node* &head){
    node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
node* uniquesortedlist(node* head){
    if(head==NULL){
        return NULL;
    }
    node* curr=head;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->data==curr->next->data){
            node* next_next=curr->next->next;
            node* nodetodelete=curr->next;
            delete(nodetodelete);
            curr->next=next_next;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}
int main(){
    node* node1=new node(6);
    node* head=node1;
    node* tail=node1;
    insertathead(head,3);
    insertathead(head,3);
    insertathead(head,2);
    uniquesortedlist(head);
    print(head);
    return 0;
}