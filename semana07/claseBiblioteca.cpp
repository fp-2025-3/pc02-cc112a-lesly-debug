#include<iostream>
#include<string>
using namespace std;
class Biblioteca{
    private:
    int codigo;
    string titulo;
    bool prestado;
    public:
    Biblioteca(int c=0,const string& t=""){
        if(c<0){
            cout<<"Codigo invalido\n";
            c=0;
        }
        codigo=c;
        titulo=t;
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
class LibroDigital:public Biblioteca{
    private:
    double tamanioMB;
    public:
    LibroDigital(int c,const string& t,double tam):Biblioteca(c,t){
        tamanioMB=tam;
    }
    void mostrarDigital(){
        mostrar();
        cout<<"Tamanio: "<<tamanioMB<<" MB\n";
    }
};
int main(){
    Biblioteca lib(1,"El Principito");
    lib.mostrar();
    LibroDigital ebook(2,"Los viajes de Gulliver",5.4);
    ebook.mostrarDigital();
    return 0;
}