#include<iostream>
#include<string>
using namespace std;
struct Pagina{
    string URL;
    string titulo;
    string fecha;
    string hora;
    int ID;
};
void agregarEntrada(Pagina& p,int id){
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
void mostrarHistorial(Pagina p[],int n){
    if(n==0){
        cout<<"Historial vacio.\n";
        return;
    }
    cout<<"---Historial de navegacion---\n";
    for(int i=0;i<n;i++){
        cout<<"ID: "<<p[i].ID<<" | URL: "<<p[i].URL<<" | Titulo: "<<p[i].titulo<<" | Fecha: "<<p[i].fecha<<" | Hora: "<<p[i].hora<<endl;
    }
}
void eliminarPorID(Pagina p[],int& n,int idBuscado){
    for(int i=0;i<n;i++){
        if(p[i].ID==idBuscado){
            for(int j=i;j<n-1;j++){
                p[j]=p[j+1];
            }
            n=n-1;
            cout<<"Entrada eliminada exitosamente.\n";
            return;
        }
    }
    cout<<"ID no encontrado.\n";
}
void buscarVisitasPorURL(Pagina p[],int n,string URLBuscado){
    for(int i=0;i<n;i++){
        if(p[i].URL==URLBuscado){
            cout<<"Resultados encontrados:\n";
            cout<<"ID: "<<p[i].ID<<" | "<<"Titulo: "<<p[i].titulo<<" | "<<"Fecha: "<<p[i].fecha<<" | Hora: "<<p[i].hora<<endl;
            return;
        }
    }
    cout<<"URL no encontrado.\n";
}
void limpiarHistorial(int& n){
    n=0;
    cout<<">>>Historial limpiado correctamente.\n";
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
                cin.ignore();
                agregarEntrada(p[n],id);
                n=n+1;
                id=id+1;
                break;
            }
            case 2:{
                mostrarHistorial(p,n);
                break;
            }
            case 3:{
                int idBuscado;
                cout<<"Ingrese el ID de la entrada a eliminar: ";
                cin>>idBuscado;
                eliminarPorID(p,n,idBuscado);
                break;
            }
            case 4:{
                cin.ignore();
                string URLBuscado;
                cout<<"Ingrese el URL a buscar: ";
                getline(cin,URLBuscado);
                buscarVisitasPorURL(p,n,URLBuscado);
                break;
            }
            case 5:{
                char r;
                cout<<"¿Estas seguro que deseas borrar todo el historial?(s/n): ";
                cin>>r;
                if(r=='s'){
                    limpiarHistorial(n);
                }
                break;
            }
            case 0:{
                cout<<"Saliendo del sistema...";
                break;
            }
        }
    }while(opcion!=0);
    return 0;
}