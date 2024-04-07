#include<iostream>
using namespace std;
class Hero{
    private:
        int health;
    public:
        int level;
        Hero(){
            cout<<"constuctor called";
        }
        Hero(int health){
            cout<<"this->"<<this<<endl;
            this->health=health;
        }
        Hero(int health, char level){
            this->level=level;
            this->health=health;
        }
};
int main(){
    Hero ramesh(10);
    cout<<"address is "<<&ramesh<<endl;
    ramesh.gethealth();
    Hero*h=new Hero(11);
}