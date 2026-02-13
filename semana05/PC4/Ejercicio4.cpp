#include<iostream>
using namespace std;
struct Item{
    char* descripcion;
    int cantidad;
    double precioUnitario;
};
struct Pedido{
    int numeroPedido;
    char* nombreCLiente;
    Item* items;
    int cantidadItems;
};
int my_strlen(const char* cadena){
    int contador=0;
    while(*cadena!='\0'){
        contador=contador+1;
        cadena=cadena+1;
    }
    return contador;
}
void my_strcpy(char* destino,const char* origen){
    while(*destino!='\0'){
        *destino=*origen;
        destino=destino+1;
        origen=origen+1;
    }
    *destino='\0';
}
Pedido* crearPedido(int numero,const char* cliente,int cantidadItems){
    Pedido* p=new Pedido;
    p.nombre=new char[my_strlen(cliente)+1];
    my_strcpy(p.nombre,cliente);
    p.items=new Item[cantidadItems]
}
int main(){
    return 0;
}