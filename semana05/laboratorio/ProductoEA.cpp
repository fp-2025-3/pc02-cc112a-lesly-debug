#include<iostream>
using namespace std;
struct Producto{
    int codigo;
    float precio;
    Producto* sig;
};
void eliminarProducto(Producto*& cabeza,int cod){
    Producto* aux=cabeza;
    Producto* ant=nullptr;
    while(aux!=nullptr&&aux->codigo!=cod){
        ant=aux;
        aux=aux->sig;
    }
    if(aux==nullptr){
        cout<<"Producto no encontrado.";
        return;
    }
    if(ant==nullptr){
        cabeza=aux->sig;
    }else{
        ant->sig=aux->sig;
    }
    delete aux;
    cout<<"Producto eliminado"<<endl;
}
void mostrarLista(Producto* cabeza){
    Producto* aux=cabeza;
    while(aux!=nullptr){
        cout<<aux->codigo<<"|"<<aux->precio<<endl;
        aux=aux->sig;
    }
}
void liberarLista(Producto*& cabeza){
    while(cabeza!=nullptr){
        Producto* temp=cabeza;
        cabeza=cabeza->sig;
        delete temp;
    }
}
int main(){
    Producto* p1=new Producto{101,10.5,nullptr};
    Producto* p2=new Producto{102,20.0,nullptr};
    Producto* p3=new Producto{103,30.75,nullptr};
    p1->sig=p2;
    p2->sig=p3;
    Producto* cabeza=p1;
    cout<<"Lista original:\n";
    mostrarLista(cabeza);
    cout<<"\nEliminando producto con codigo 102...\n";
    eliminarProducto(cabeza,102);
    cout<<"\nLista despues de eliminar:\n";
    mostrarLista(cabeza);
    liberarLista(cabeza);
    return 0;
}