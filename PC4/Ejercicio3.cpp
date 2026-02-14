#include<iostream>
using namespace std;
struct Producto{
    int codigo;
    char* nombre;
    double precio;
    int stock;
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
Producto crearProducto(int codigo,const char* nombre,double precio,int stock){
    Producto p;
    p.codigo=codigo;
    p.nombre=new char[my_strlen(nombre)+1];
    my_strcpy(p.nombre,nombre);
    p.precio=precio;
    p.stock=stock;
    return p;
}
Producto* crearInventario(int n){
    Producto* p=new Producto[n];
    const char* nombres[]={"Teclado","Mouse","Monitor","Laptop","Impresora"};
    for(int i=0;i<n;i++){
        p[i]=crearProducto(100+i,nombres[i],10.5*(1+i),5*(i+1));
    }
    return p;
}
Producto* buscarProducto(Producto* inventario,int n,int codigoBuscado){
    for(int i=0;i<n;i++){
        if(inventario[i].codigo==codigoBuscado){
            return inventario+i;
        }
    }
    return nullptr;
}
void liberarInventario(Producto* inventario,int n){
    for(int i=0;i<n;i++){
        delete[] inventario[i].nombre;
    }
    delete[] inventario;
}
int main(){
    Producto* inventario=crearInventario(5);
    cout<<"INVENTARIO:\n";
    for(int i=0;i<5;i++){
        cout<<"Codigo: "<<inventario[i].codigo<<" | Nombre: "<<inventario[i].nombre<<" | Precio: "<<inventario[i].precio<<" | Stock: "<<inventario[i].stock<<endl;
    }
    cout<<endl;
    cout<<"Buscando producto con codigo 102...";
    Producto* pBuscado=buscarProducto(inventario,5,102);
    if(pBuscado!=nullptr){
        cout<<"\nProducto encontrado: "<<pBuscado->nombre<<" | Precio: "<<pBuscado->precio;
    }else{
        cout<<"Producto no encontrado";
    }
    liberarInventario(inventario,5);
    return 0;
}