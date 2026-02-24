#include<iostream>
#include<fstream>
using namespace std;
const int MAX_LIBROS=7;
struct Libro{
    int codigo;
    char titulo[50];
    bool prestado;
};
struct Usuario{
    int codigo;
    string nombres;
    int prestamos;
};
int my_strcmp(char* a,const char* b){
    while(*a='\0'&&*b!='\0'){
        a=a+1;
        b=b+1;
    }
    return *a-*b;
}
void registrarLibro(Libro& libro,int& n){//(Libro libros[],int& n)
    if(n>=MAX_LIBROS){
        cout<<"Capacidad maxima alcanzada.";
        return;
    }
    cout<<"-----REGISTRO DE LIBRO-----\n";
    cout<<"Codigo: ";
    cin>>libro.codigo;
    cout<<"Titulo: ";
    cin.ignore();
    cin.getline(libro.titulo,50);
    libro.prestado=false;
    n=n+1;
}
int buscarLibro(Libro libros[],int n,int codigo){
    for(int i=0;i<n;i++){
        if(libros[i].codigo==codigo){
            if(!libros[i].prestado){
                return i;
            }
        }
    }
    return -1;
}
int encontrarLibro(Libro libros[],int n,int codigo){
    for(int i=0;i<n;i++){
        if(libros[i].codigo==codigo){
            return i;
        }
    }
    return -1;
}
void prestarLibro(Libro libro[],int n,int codigo){//(Libro libros[],int& n)
    int pos=buscarLibro(libro,n,codigo);
    if(pos!=-1){
        cout<<"Libro: "<<libro[pos].titulo<<" | Estado: ";
        if(!libro[pos].prestado){
            libro[pos].prestado=true;
            cout<<"DISPONIBLE\n";
            cout<<"Libro prestado correctamente.\n";
        }
    }else{
        cout<<"PRESTADO: Libro no disponible.\n";
    }
}
void devolverLibro(Libro libros[],int n){
    int cod;
    char nombre[50];
    cout<<"Ingrese el codigo: ";
    cin>>cod;
    cout<<"Ingrese el titulo: ";
    cin.ignore();
    cin.getline(nombre,50);
    for(int i=0;i<n;i++){
        if(libros[i].prestado){
            if(libros[i].codigo==cod&&my_strcmp(libros[i].titulo,nombre)>0){
                libros[i].prestado=false;
                cout<<"Libro devuelto correctamente.\n";
                return;
            }
        }
    }
    cout<<"Libro no registrado.\n";
}
void guardarEnArchivo(Libro libros[],int n);
void cargarDesdeArchivo(Libro libros[],int n);
int main(){
    Libro libros[MAX_LIBROS];
    int cantidad=0;
    int codigo;
    int opcion;
    do{
        cout<<"====== MENU DE OPCIONES ======\n";
        cout<<"1. Registrar libro."<<endl;
        cout<<"2. Prestar libro."<<endl;
        cout<<"3. Devolver libro."<<endl;
        cout<<"4. Buscar libro."<<endl;
        cout<<"5. Mostrar libros."<<endl;
        cout<<"6. Salir."<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:{
                registrarLibro(libros[cantidad],cantidad);
                break;
            }
            case 2:{
                cout<<"Ingrese el codigo: ";
                cin>>codigo;
                if(encontrarLibro(libros,cantidad,codigo)!=-1){
                    prestarLibro(libros,cantidad,codigo);
                }else{
                    cout<<"Libro no registrado.\n";
                }
                break;
            }
            case 3:{
                devolverLibro(libros,cantidad);
                break;
            }
            case 6:{
                cout<<"Saliendo...";
                break;
            }
        }
    }while(opcion!=6);
    return 0;
}