#include<iostream>
using namespace std;
struct Producto{
    int codigo;
    float precio;
    Producto* sig;
};
int main(){
    Producto cabeza=nullptr;
    for(int i=0;i<2;i++){
        Producto* nuevo=new Producto;
        cout<<"Ingrese codigo: ";
        cin>>nuevo->codigo;
        cout<<"Ingrese precio: ";
        cin>>nuevo->precio;
        nuevo->sig=cabeza;
        cabeza=nuevo;
    }
    return 0;
}