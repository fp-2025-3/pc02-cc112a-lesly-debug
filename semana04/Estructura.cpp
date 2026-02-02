#include<iostream>
using namespace std;
struct Persona{
    string nombre;
    int edad;
};
int main(){
    Persona* p=new Persona;
    cout<<"Nombre: ";
    getline(cin,p->nombre);
    cout<<"Edad: ";
    cin>>p->edad;
    cout<<"Datos: "<<p->nombre<<","<<p->edad;
    delete p;
    p=nullptr;
    return 0;
}