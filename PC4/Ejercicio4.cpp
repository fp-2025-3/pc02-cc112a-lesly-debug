#include<iostream>
using namespace std;
struct Item{
    char* descripcion;
    int cantidad;
    double precioUnitario;
};
struct Pedido{
    int numeroPedido;
    char* nombreCliente;
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
    while(*origen!='\0'){
        *destino=*origen;
        destino=destino+1;
        origen=origen+1;
    }
    *destino='\0';
}
Item crearItem(const char* d,int c,double p){
    Item i;
    i.descripcion=new char[my_strlen(d)+1];
    my_strcpy(i.descripcion,d);
    i.cantidad=c;
    i.precioUnitario=p;
    return i;
}
Pedido* crearPedido(int numero,const char* cliente,int cantidadItems){
    Pedido* p=new Pedido;
    p->numeroPedido=numero;
    p->nombreCliente=new char[my_strlen(cliente)+1];
    my_strcpy(p->nombreCliente,cliente);
    p->items=new Item[cantidadItems];
    p->cantidadItems=cantidadItems;
    p->items[0]=crearItem("Laptop",1,100);
    p->items[1]=crearItem("Mouse",2,200);
    p->items[2]=crearItem("Teclado",3,300);
    return p;
}
double calcularTotal(const Pedido* p){
    double total=0;
    for(int i=0;i<(p->cantidadItems);i++){
        total=total+(p->items[i].cantidad*p->items[i].precioUnitario);
    }
    return total;
}
Item* itemMasCaro(Pedido* p){
    int ind=0;
    for(int i=1;i<(p->cantidadItems);i++){
        if(p->items[i].precioUnitario>p->items[ind].precioUnitario){
            ind=i;
        }
    }
    return p->items+ind;
}
void liberarPedido(Pedido* p){
    for(int i=0;i<(p->cantidadItems);i++){
        delete[] p->items[i].descripcion;
    }
    delete[] p->items;
    delete[] p->nombreCliente;
    delete p;
}
int main(){
    Pedido* p=crearPedido(101,"Carlos Perez",3);
    cout<<"Pedido Nº:"<<p->numeroPedido<<endl;
    cout<<"Cliente: "<<p->nombreCliente<<endl;
    cout<<"Items:\n";
    for(int i=0;i<(p->cantidadItems);i++){
        cout<<"-"<<p->items[i].descripcion<<" | Cant: "<<p->items[i].cantidad<<" | Precio: "<<p->items[i].precioUnitario<<endl;
    }
    cout<<"Total: "<<calcularTotal(p)<<endl;
    Item* caro=itemMasCaro(p);
    cout<<"Item mas caro: "<<caro->descripcion<<" | Precio: "<<caro->precioUnitario<<endl;
    liberarPedido(p);
    return 0;
}