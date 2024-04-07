#include<iostream>
#include<stack>
using namespace std;
class Stack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top1=-1;
        top2=size;
    }
    void push1(int element){
        if(top2-top1>1){
            top1++;
            arr[top1]=element;
            }
            else{
                cout<<"Stack is full"<<endl;
            }
    }
    void push2(int element){
        if(top2-top1>1){
            top2--;
            arr[top2]=element;
            }
            else{
                cout<<"Stack is full"<<endl;
            }
    }
    void pop1(){
        if(top1>=0){
            top1--;
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }
    void pop2(){
        if(top2<size){
            top2++;
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }
    int peek1(){
        if(top1>=0){
            return arr[top1];
        }
        else{
            return -1;
        }
    }
    int peek2(){
        if(top2<size){
            return arr[top2];
        }
        else{
            return -1;
        }
    }
};
int main(){
    Stack st(5);
    st.push1(2);
    st.push1(3);
    st.push1(4);
    cout<<st.peek1();
    st.pop1();
    cout<<st.peek1();
    cout<<st.peek2();
}