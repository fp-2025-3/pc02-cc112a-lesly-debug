#include<iostream>
using namespace std;
struct Producto{
    int codigo;
    float precio;
    Producto* sig;
};
int main(){
    Producto* cabeza=nullptr;
    for(int i=0;i<2;i++){
        Producto* nuevo=new Producto;
        cout<<"Ingrese codigo: ";
        cin>>nuevo->codigo;
        cout<<"Ingrese precio: ";
        cin>>nuevo->precio;
        nuevo->sig=cabeza;
        cabeza=nuevo;
    }
    Producto* aux=cabeza;
    while(aux!=nullptr){
        cout<<aux->codigo<<" | "<<aux->precio<<endl;
        aux=aux->sig;
    }
    while(cabeza!=nullptr){
        Producto* temp=cabeza;
        cabeza=cabeza->sig;
        delete temp;
    }
    return 0;
}