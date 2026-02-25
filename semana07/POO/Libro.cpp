#include"Libro.h"
#include<iostream>
Libro::Libro():titulo("Desconocido"),autor("Desconocido"),paginas(0){}//Lista de inicializacion
Libro::Libro(const string& t,const string& a,int p):titulo(t),autor(a),paginas(p){}
Libro::~Libro(){}
//Métodos getters: Devuelven los valores de los atributos privados, no modifican el objeto
string Libro::getTitulo() const{
    return titulo;
}
string Libro::getAutor() const{
    return autor;
}
int Libro::getPaginas() const{
    return paginas;
}
//Métodos setters: Permiten modificar los atributos privados
void Libro::setTitulo(string& t){
    titulo=t;
}
void Libro::setAutor(string& a){
    autor=a;
}
void Libro::setPaginas(int p){
    paginas=p;
}
void Libro::mostrarInfo() const{
    cout<<"Titulo: "<<titulo<<", Autor: "<<autor<<", Paginas: "<<paginas<<endl;
}