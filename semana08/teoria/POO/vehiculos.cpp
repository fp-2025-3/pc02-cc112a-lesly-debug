#include "vehiculos.h"
void escribirString(ofstream& out,const string& s){
    int n=s.size();
    out.write((char*)&n,sizeof(n));
    out.write(s.c_str(),n);
}
void leerString(ifstream& in,string& s){
    int n;
    in.read((char*)&n,sizeof(n));
    char* buffer=new char[n+1];
    in.read(buffer,n);
    buffer[n]='\0';
    s=buffer;
    delete[] buffer;
}
Vehiculo::Vehiculo(){
    cout<<"Llamando al constructor por defecto.\n";
}
Vehiculo::Vehiculo(string p,string m,int a,double pv){
    placa=p;
    marca=m;
    anio=a;
    precioVenta=pv;
}
Vehiculo::~Vehiculo(){}
void Vehiculo::mostrar() const{
    cout<<"Tipo: "<<getNombreTipo()<<endl;
    cout<<"Placa: "<<placa<<endl;
    cout<<"Marca: "<<marca<<endl;
    cout<<"Anio: "<<anio<<endl;
    cout<<"Precio Base: "<<precioVenta<<endl;
}
Automovil::Automovil(){}
Automovil::Automovil(string p,string m,int a,double pv,int np):Vehiculo(p,m,a,pv){
    numeroPuertas=np;
}
Automovil::~Automovil(){}
double Automovil::calcularPrecioFinal() const{
    return precioVenta*1.05;
}
int Automovil::getTipo() const{
    return 1;
}
string Automovil::getNombreTipo() const{
    return "Automovil";
}
void Automovil::mostrar() const{
    Vehiculo::mostrar();
    cout<<"Puertas: "<<numeroPuertas<<endl;
    cout<<"Precio Final: "<<calcularPrecioFinal()<<endl;
}
void Automovil::guardar(ofstream& out) const{
    escribirString(out,placa);
    escribirString(out,marca);
    out.write((char*)&anio,sizeof(anio));
    out.write((char*)&precioVenta,sizeof(precioVenta));
    out.write((char*)&numeroPuertas,sizeof(numeroPuertas));
}
void Automovil::cargar(ifstream& in){
    leerString(in,placa);
    leerString(in,marca);
    in.read((char*)&anio,sizeof(anio));
    in.read((char*)&precioVenta,sizeof(precioVenta));
    in.read((char*)&numeroPuertas,sizeof(numeroPuertas));
}
Camion::Camion(){};
Camion::Camion(string p,string m,int a,double pv,double cp):Vehiculo(p,m,a,pv){
    capacidad=cp;
}
Camion::~Camion(){};
double Camion::calcularPrecioFinal() const{
    return precioVenta*1.12;
}
int Camion::getTipo() const{
    return 2;
}
string Camion::getNombreTipo() const{
    return "Camion";
}
void Camion::mostrar() const{
    Vehiculo::mostrar();
    cout<<"Capacidad: "<<capacidad<<endl;
    cout<<"Precio Final: "<<calcularPrecioFinal()<<endl;
}
void Camion::guardar(ofstream& out) const{
    escribirString(out,placa);
    escribirString(out,marca);
    out.write((char*)&anio,sizeof(anio));
    out.write((char*)&precioVenta,sizeof(precioVenta));
    out.write((char*)&capacidad,sizeof(capacidad));
}
void Camion::cargar(ifstream& in){
    leerString(in,placa);
    leerString(in,marca);
    in.read((char*)&anio,sizeof(anio));
    in.read((char*)&precioVenta,sizeof(precioVenta));
    in.read((char*)&capacidad,sizeof(capacidad));
}
Motocicleta::Motocicleta(){}
Motocicleta::Motocicleta(string p,string m,int a,double pv,double pt):Vehiculo(p,m,a,pv){
    potencia = pt;
}
Motocicleta::~Motocicleta(){}
double Motocicleta::calcularPrecioFinal() const{
    return precioVenta*1.03;
}
int Motocicleta::getTipo() const{
    return 3;
}
string Motocicleta::getNombreTipo() const{
    return "Motocicleta";
}
void Motocicleta::mostrar() const{
    Vehiculo::mostrar();
    cout<<"Potencia: "<<potencia<<endl;
    cout<<"Precio Final: "<<calcularPrecioFinal()<<endl;
}
void Motocicleta::guardar(ofstream& out) const{
    escribirString(out,placa);
    escribirString(out,marca);
    out.write((char*)&anio,sizeof(anio));
    out.write((char*)&precioVenta,sizeof(precioVenta));
    out.write((char*)&potencia,sizeof(potencia));
}
void Motocicleta::cargar(ifstream& in){
    leerString(in,placa);
    leerString(in,marca);
    in.read((char*)&anio,sizeof(anio));
    in.read((char*)&precioVenta,sizeof(precioVenta));
    in.read((char*)&potencia,sizeof(potencia));
}