#include<iostream>
using namespace std;
class Libro{
private:
    string titulo;
    string autor;
    int paginas;
public:
    Libro(string t,string a,int p):titulo(t),autor(a),paginas(p){//Lista de inicializadores;
        cout<<"Se inicializo el contructor con parametros.\n";
    }
    Libro(){
        cout<<"Constructor por defecto.";
    }
    ~Libro(){
        cout<<"Llamando al destructor\n";
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
class LibroDigital:public Libro{
private:
    string formato;
public:
    LibroDigital(string t,string a,int p,string f):Libro(t,a,p),formato(f){}
    void mostrarInfoDigital(){
        mostrarInfo();
        cout<<"Formato digital "<<formato<<endl;
    }
};
int main(){
    LibroDigital ld("Cien anios de soledad","Marquez",400,"PDF");
    ld.mostrarInfoDigital();
    return 0;
}