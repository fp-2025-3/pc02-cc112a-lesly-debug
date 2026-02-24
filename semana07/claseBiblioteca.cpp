#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class Biblioteca{//Implementar herencia a esta clase
    private:
    int codigo;
    string titulo;
    bool prestado;
    public:
    Libro(int c=0,char* t=" "){
        if(c<0){
            cout<<"Codigo invalido\n";
        }
        codigo=c;
        strcpy(titulo,t);
        prestado=false;
    }
    bool prestar(){
        if(prestado){
            cout<<"El libro ya fue prestado.\n";
            return false;
        }
        prestado=true;
        return true;
    }
    void mostrar(){
        cout<<codigo<<" - "<<titulo<<" - ";
        if(prestado){
            cout<<"Prestado.\n";
        }else{
            cout<<"Disponible.\n";
        }
    }
};