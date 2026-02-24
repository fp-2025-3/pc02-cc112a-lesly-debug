#include<iostream>
#include<string>
using namespace std;
class Libro{
private:
    string titulo;
    string autor;
    int paginas;
public:
    Libro(string t,string a,int p):titulo(t),autor(a),paginas(p){//Lista de inicializadores;
        cout<<"Se ejecuto el constructor con parametros.\n";
    }
    Libro(){
        cout<<"Constructor por defecto";
    }
    ~Libro(){
        cout<<"Llamando al destructor";
    }
    void mostrarInfo(){
        cout<<"Titulo: "<<titulo<<", Autor: "<<autor<<", Paginas: "<<paginas<<endl;
    }
    string getTitulo(){//getter: solo lee, no modifica;
        return titulo;
    }
    void setTitulo(string t){//No devuelve nada pero inicializa;
        titulo=t;
    }
};
int main(){
    Libro libro1("El principito","Antoine",100);
    Libro libro2("Don Quijote","Cervantes",800);
    libro1.mostrarInfo();
    libro2.mostrarInfo();
    libro1.setTitulo("El Principito - Nueva edicion");
    cout<<"Despues de cambiar el titulo:\n";
    libro1.mostrarInfo();
    libro2.mostrarInfo();
    return 0;
}