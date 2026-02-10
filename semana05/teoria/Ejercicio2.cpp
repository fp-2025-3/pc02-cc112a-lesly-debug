#include<iostream>
using namespace std;
struct TFecha{
    int dia;
    int mes;
    int anio;
};
struct Contacto{
    char* nombre;
    TFecha fecha;
};
void leerDatos(Contacto c[],int n){
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Contacto "<<i+1<<": ";
        cout<<"Nombre: ";
        c[i].nombre=new char[20];
        cin.getline(c[i].nombre,20);
        cout<<"Fecha:\n";
        cout<<"Dia: ";
        cin>>c[i].fecha.dia;
        cout<<"Mes: ";
        cin>>c[i].fecha.mes;
        cout<<"Anio: ";
        cin>>c[i].fecha.anio;
        cin.ignore();
    }
}
int busquedaPorAnio(Contacto c[],int n,int anioBuscado){
    for(int i=0;i<n;i++){
        if(c[i].fecha.anio==anioBuscado){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Ingrese la cantidad de contactos: ";
    cin>>n;
    Contacto* contactos=new Contacto[n];
    leerDatos(contactos,n);
    int anioBuscado;
    cout<<"Ingrese el anio: ";
    cin>>anioBuscado;
    int pos=busquedaPorAnio(contactos,n,anioBuscado);
    if(pos!=-1){
        cout<<"Contactos nacidos en "<<anioBuscado<<":"<<endl;
        cout<<"Nombre: "<<contactos[pos].nombre<<" | "<<endl;
        cout<<"Fecha: "<<contactos[pos].fecha.dia<<"/"<<contactos[pos].fecha.mes<<"/"<<contactos[pos].fecha.anio<<endl;
    }else{
        cout<<"NO se encontarron nacidos en ese anio.";
    }
    return 0;
}