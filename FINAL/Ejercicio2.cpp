#include<iostream>
#include<cmath>
using namespace std;
struct  Punto{
    double x;
    double y;
};
void leerPunto(Punto* p){
    cin>>p->x>>p->y;
}
double distanciaOrigen(const Punto* p){
    return sqrt((p->x)*(p->x)+(p->y)*(p->y));
}
Punto* masLejano(Punto* p1,Punto* p2){
    if(distanciaOrigen(p1)>distanciaOrigen(p2)){
        return p1;
    }
    return p2;
}
int main(){
    Punto* p1=new Punto;
    Punto* p2=new Punto;
    cout<<"Punto 1: ";
    leerPunto(p1);
    cout<<"Punto 2: ";
    leerPunto(p2);
    Punto* p3=masLejano(p1,p2);
    cout<<"Punto mas lejano: ("<<p3->x<<";"<<p3->y<<")"<<endl;
    delete p1;
    delete p2;
    return 0;
}