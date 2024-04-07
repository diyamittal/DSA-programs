#include<iostream>
#include<cmath>
using namespace std;
class Point{
    int x,y;
    public:
    void setcoordinates(int a, int b){
        x=a;
        y=b;
    }
    friend Point distance(Point m, Point n);
    void displayPoint(){
        cout<<"The point is ("<<x<<","<<y<<")"<<endl;
    }
};
Point distance(Point m, Point n){
        float c;
        c=sqrt((m.x - n.x)*(m.x - n.x)+(m.y - n.y)*(m.y - n.y));
        cout<<"Distance is "<< c<<endl;

    }
int main(){
    Point p,q;
    p.setcoordinates(0,1);
    p.displayPoint();
    q.setcoordinates(0,6);
    q.displayPoint();
    distance(p,q);
    return 0;
}