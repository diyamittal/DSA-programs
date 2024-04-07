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
void insertathead(node* &head,int d){
    node* temp=new node(d);
    head->prev=temp;
    temp->next=head;
    head=temp;
}
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
void insertatposition(node* &head, int position, int d){
    node* ptr=head;
    for(int i=1;i<position-1;i++){
        ptr=ptr->next;
    }
    node* temp=new node(d);
    temp->next=ptr->next;
    ptr->next->prev=temp;
    temp->prev=ptr;
    ptr->next=temp;
}
void print(node* head){
    node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void deleteatfront(node* &head){
    node* ptr=head;
    head=head->next;
    ptr->next=NULL;
    head->prev=NULL;
    delete ptr;
}
void deleteatend(node* &head){
    node* ptr1= head;
    node* ptr2=head;
    while(ptr1->next!= NULL){
        ptr2=ptr1;
        ptr1 = ptr1->next;
    }
    ptr2->next=NULL;
    ptr1->prev=NULL;
    delete ptr1;
}
void deleteatposition(int position, node* &head){
    node* ptr=head ;
    node* ptr1=head;
    for(int i=1;i<position;i++){
        ptr1=ptr;
        ptr =ptr->next;
    }
    ptr->prev=NULL;
    ptr1->next=ptr->next;
    ptr->next=NULL;
    delete ptr;
}

int main(){
    node* node1=new node(10);
    node* head=node1;
    insertathead(head,6);
    insertatlast(head,9);
    insertatposition(head,2,7);
    insertathead(head,3);
    insertatlast(head,1);
    print(head);
    cout<<endl;
    deleteatfront(head);
    deleteatend(head);
    deleteatposition(2,head);
    print(head);
    cout<<endl;
    return 0;
}