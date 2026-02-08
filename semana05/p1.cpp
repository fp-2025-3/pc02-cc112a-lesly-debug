#include<iostream>
using namespace std;
struct Producto{
    int codigo;
    char* descripcion;
    float precio;
    int stock;
};
int main(){
    Producto p1,p2;
    cout<<"Ingrese el codigo: ";
    cin>>p1.codigo;
    cout<<"Ingrese la descripcion: ";
    cin.ignore();
    p1.descripcion=new char[50];
    cin.getline(p1.descripcion,50);
    cout<<"Precio: ";
    cin>>p1.precio;
    cout<<"Stock: ";
    cin>>p1.stock;
    cout<<"Ingrese el codigo: ";
    cin>>p2.codigo;
    cout<<"Ingrese la descripcion: ";
    cin.ignore();
    p2.descripcion=new char[50];
    cin.getline(p2.descripcion,50);
    cout<<"Precio: ";
    cin>>p2.precio;
    cout<<"Stock: ";
    cin>>p2.stock;
    cout<<"Producto con mayor precio:\n";
    if(p1.precio<p2.precio){
        cout<<"Codigo: "<<p2.codigo<<" Descripcion: "<<p2.descripcion<<" Precio: "<<p2.precio<<" Stock: "<<p2.stock;
    }else{
        cout<<"Codigo: "<<p2.codigo<<" Descripcion: "<<p2.descripcion<<" Precio: "<<p2.precio<<" Stock: "<<p2.stock;
    }
    delete[] p1.descripcion;
    delete[] p2.descripcion;
    return 0;
}