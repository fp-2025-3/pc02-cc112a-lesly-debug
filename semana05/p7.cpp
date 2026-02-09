#include<iostream>
using namespace std;
struct Rectangulo{
    float base;
    float altura;
};
int main(){
    Rectangulo* r=new Rectangulo;
    r->base=5.0;
    r->altura=4.0;
    cout<<"Area: "<<((r->base)*(r->altura))<<endl;
    cout<<"Perimetro: "<<(2*(r->base+r->altura));
    delete r;
    return 0;
}