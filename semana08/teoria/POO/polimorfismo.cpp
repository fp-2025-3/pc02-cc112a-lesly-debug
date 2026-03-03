#include<iostream>
using namespace std;
class Animal{
    public:
    virtual void id(){
        cout<<"animal\n";
    }
    virtual ~Animal(){
        cout<<"Destructor animal.\n";
    }
};
class Cat:public Animal{
    public:
    void id(){
        cout<<"cat\n";
    }
};
class Dog:public Animal{
    public:
    void id(){
        cout<<"dog\n";
    }
};
int main(){
    Animal *pA[]={new Animal,new Dog,new Cat};
    for(int k=0;k<3;k++){
        pA[k]->id();
    }
    return 0;
}