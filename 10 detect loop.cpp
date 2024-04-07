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
bool iscircularlist(node* head){
    if(head==NULL){
        return true;
    }
    node* temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;
}
bool detectloop(node* head){
    if(head==NULL){
        return false;
    }
    map <node*, bool> visited;
    node* temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<"Present on element"<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
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
    iscircularlist(head);
    if(detectloop(head)){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"no cycle"<<endl;
    }
    return 0;
}