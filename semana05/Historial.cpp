#include<iostream>
#include<iostream>
using namespace std;
struct Pagina{
    string URL;
    string titulo;
    string fecha;
    string hora;
    int ID;
};
void agregarEntrada(Pagina& p,int id){
    cin.ignore();
    cout<<"Ingrese la URL: ";
    getline(cin,p.URL);
    cout<<"Titulo de la pagina: ";
    getline(cin,p.titulo);
    cout<<"Fecha (dd/mm/aaaa): ";
    getline(cin,p.fecha);
    cout<<"Hora (hh:mm): ";
    getline(cin,p.hora);
    p.ID=id;
    cout<<">>Entrada agregada con ID: "<<p.ID<<endl;
}
int main(){
    int opcion;
    Pagina p[100];
    int n=0,id=1;
    do{
        cout<<"---HISTORIAL DE NAVEGACION WEB---\n";
        cout<<"1. Agregar entrada al historial"<<endl;
        cout<<"2. Mostrar historial completo"<<endl;
        cout<<"3. Eliminar una entrada por ID"<<endl;
        cout<<"4. Buscar visitas por URL"<<endl;
        cout<<"5. Limpiar historial completo"<<endl;
        cout<<"0. Salir\n";
        cin>>opcion;
        switch(opcion){
            case 1:{
                agregarEntrada(p[n],id);
                n=n+1;
                break;
            };
        }
    }while(opcion!=0);
    return 0;
}