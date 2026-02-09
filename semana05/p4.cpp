#include<iostream>
#include<string>
using namespace std;
struct Producto{
    int codigo;
    string nombre;
    float precio;
    int cantidad;
};
int main(){
    Producto productos[5]={{101,"Mesa",120.5,3},{102,"Caja",150.0,20},{103,"Parlante",70.75,6},{104,"Abanico",15.0,100},{105,"Bala",90.0,1}};
    int codigoBuscado;
    cout<<"Ingrese el codigo: ";
    cin>>codigoBuscado;
    float valorTotal=0;
    bool encontrado=false;
    cout<<"--- Resultado de la busqueda ---\n";
    for(int i=0;i<5;i++){
        if(productos[i].codigo==codigoBuscado){
            cout<<"Producto encontrado:"<<endl;
            cout<<"Nombre: "<<productos[i].nombre<<endl;
            cout<<"Precio: "<<productos[i].precio<<endl;
            cout<<"Cantidad: "<<productos[i].cantidad<<endl;
            encontrado=true;
        }
        valorTotal=valorTotal+((productos[i].precio)*(productos[i].cantidad));
    }
    if(!encontrado){
        cout<<"No se encontro un producto con ese codigo.";
    }
    cout<<"\n--- Productos con stock menor a 10 ---\n";
    for(int i=0;i<5;i++){
        if(productos[i].cantidad<10){
            cout<<"Codigo: "<<productos[i].codigo<<" | Nombre: "<<productos[i].nombre<<" | Cantidad: "<<productos[i].cantidad<<endl;
        }
    }
    cout<<"\nValor total del inventario: "<<valorTotal;
    return 0;
}