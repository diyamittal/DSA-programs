#include<iostream>
#include<map>
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
void insertatposition(node* &tail, node* &head, int position, int d){
    if(position==1){
        insertathead(head,d);
        return;
    }
    node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }
    node* nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
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
node* floyddetectloop(node* head){
    if(head==NULL){
        return NULL;
    }
    node* slow=head;
    node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            cout<<"present at"<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}
node* getstartingnode(node* head){
    if(head==NULL){
        return NULL;
    }
    node* intersection=floyddetectloop(head);
    if(intersection==NULL){
        return NULL;
    }
    node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
node* removeloop(node* head){
    if(head==NULL){
        return NULL;
    }
    node* startofloop=getstartingnode(head);
    if(startofloop==NULL){
        return head;
    }
    node* temp=startofloop;
    while(temp->next!=startofloop){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
int main(){
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
    insertathead(head,6);
    insertattail(tail,9);
    insertatposition(tail,head,2,10);
    tail->next=head->next;
    //deleteatposition(2,head);
    //print(head);
    if(floyddetectloop(head)){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"no cycle"<<endl;
    }
    node* loop=getstartingnode(head);
    cout<<"Starting loop is "<<loop->data<<endl;
    removeloop(head);
    print(head);
    return 0;
}