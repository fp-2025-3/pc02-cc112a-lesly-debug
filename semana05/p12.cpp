#include<iostream>
#include<string>
using namespace std;
struct Empleado{
    string nombre;
    string cargo;
    float sueldo;
    int anio;
};
void leerEmpleado(Empleado E[],int n){
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Empleado "<<i+1<<endl;
        cout<<"Nombre: ";
        getline(cin,E[i].nombre);
        cout<<"Cargo: ";
        getline(cin,E[i].cargo);
        cout<<"Sueldo: ";
        cin>>E[i].sueldo;
        cout<<"Fecha: ";
        cin>>E[i].anio;
    }
}
void mostrarMayorAntiguedad(const Empleado E[],int n){
    int indMax=0;
    for(int i=1;i<n;i++){
        if(E[i].anio<E[indMax].anio){
            indMax=i;
        }
    }
    cout<<"Empleado con mayor antiguedad:\n";
    cout<<"Nombre: "<<E[indMax].nombre<<endl;
    cout<<"Cargo: "<<E[indMax].cargo<<endl;
    cout<<"Sueldo: "<<E[indMax].sueldo<<endl;
    cout<<"Anio de ingreso: "<<E[indMax].anio<<endl;
}
float calcularSueldoPromedio(const Empleado E[],int n){
    float suma=0;
    for(int i=0;i<n;i++){
        suma=suma+E[i].sueldo;
    }
    return suma/n;
}
int busquedaPorAnio(const Empleado E[],int n,int anioBuscado){
    for(int i=0;i<n;i++){
        if(E[i].anio==anioBuscado){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"ingrese el numero de empleados: ";
    cin>>n;
    Empleado* E=new Empleado[n];
    leerEmpleado(E,n);
    mostrarMayorAntiguedad(E,n);
    float prom=calcularSueldoPromedio(E,n);
    cout<<"Sueldo promedio: "<<prom<<endl;
    int anio;
    cout<<"Ingrese el anio de ingreso a buscar: ";
    cin>>anio;
    int pos=busquedaPorAnio(E,n,anio);
    if(pos!=-1){
        cout<<"Empleado encontrado"<<endl;
        cout<<"Nombre: "<<E[pos].nombre<<endl;
        cout<<"Cargo: "<<E[pos].cargo<<endl;
        cout<<"Sueldo: "<<E[pos].sueldo<<endl;
        cout<<"Fecha: "<<E[pos].anio<<endl;
    }else{
        cout<<"No se encuentra un empleado ingresado en ese anio"<<endl;
    }
    delete[] E;
    return 0;
}