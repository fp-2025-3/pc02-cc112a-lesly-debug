#include "vehiculos.h"
#include<string>
Vehiculo::Vehiculo(){
    cout<<"Llamando al constructor por defecto.\n";
}
Vehiculo::Vehiculo(string p,string m,int a,double pv){
    placa=p;
    marca=m;
    anio=a;
    precioVenta=pv;
}
Vehiculo::~Vehiculo(){};
Automovil::Automovil(){
    cout<<"Llamando al constructor por defecto.\n";
}
Automovil::Automovil(string p,string m,int a,double pv,int np):Vehiculo(p,m,a,pv){
    numeroPuertas=np;
}
void Automovil::aumentarPrecio(){
    precioVenta=precioVenta*1.05;
}
void Automovil::mostrarInfo(){
    cout<<"Placa: "<<placa<<endl;
    cout<<"Marca: "<<marca<<endl;
    cout<<"Anio: "<<anio<<endl;
    cout<<"Precio de Venta: "<<precioVenta<<endl;
    cout<<"Numero de puertas: "<<numeroPuertas<<endl; 
}
Automovil::~Automovil(){};
Camion::Camion(){
    cout<<"Llamando al constructor por defecto.\n";
}
Camion::Camion(string p,string m,int a,double pv,double c):Vehiculo(p,m,a,pv){
    capacidad=c;
}
void Camion::aumentarPrecio(){
    precioVenta=precioVenta*1.12;
}
void Camion::mostrarInfo(){
    cout<<"Placa: "<<placa<<endl;
    cout<<"Marca: "<<marca<<endl;
    cout<<"Anio: "<<anio<<endl;
    cout<<"Precio de Venta: "<<precioVenta<<endl;
    cout<<"Capacidad: "<<capacidad<<endl;
}
Camion::~Camion(){};
Motocicleta::Motocicleta(){
    cout<<"Llamando al constructor por defecto.\n";
}
Motocicleta::Motocicleta(string p,string m,int a,double pv,double pt):Vehiculo(p,m,a,pv){
    potencia=pt;
}
void Motocicleta::aumentarPrecio(){
    precioVenta=precioVenta*1.03;
}
void Motocicleta::mostrarInfo(){
    cout<<"Placa: "<<placa<<endl;
    cout<<"Marca: "<<marca<<endl;
    cout<<"Anio: "<<anio<<endl;
    cout<<"Precio de Venta: "<<precioVenta<<endl;
    cout<<"Potencia: "<<potencia<<endl; 
}
Motocicleta::~Motocicleta(){};
