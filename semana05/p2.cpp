#include<iostream>
using namespace std;
struct Libro{
    char* titulo;
    char* autor;
    int anio;
    float precio;
};
int main(){
    const int num_libros=2;
    Libro* lib=new Libro[num_libros];
    for(int i=0;i<num_libros;i++){
        cout<<"Ingrese el titulo: ";
        (*(lib+i)).titulo=new char[20];
        cin.getline((lib+i)->titulo,20);
        cout<<"Ingrese el autor: ";
        (*(lib+i)).autor=new char[20];
        cin.getline((lib+i)->autor,20);
        cout<<"Anio: ";
        cin>>(*(lib+i)).anio;
        cout<<"Precio: ";
        cin>>(*(lib+i)).precio;
        cin.ignore(1000,'\n');
    }
    cout<<"\n---Datos de los libros---\n";
    for(int i=0;i<num_libros;i++){
        cout<<"Titulo: "<<(*(lib+i)).titulo<<endl;
        cout<<"Autor: "<<(*(lib+i)).autor<<endl;
        cout<<"Anio: "<<(*(lib+i)).anio<<endl;
        cout<<"Precio: "<<(*(lib+i)).precio<<endl;
    }
    float suma=0;
    for(int i=0;i<num_libros;i++){
        suma=suma+(*(lib+i)).precio;
    }
    float promedio=suma/num_libros;
    cout<<"Promedio: "<<promedio;
    for(int i=0;i<num_libros;i++){
        delete[] lib[i].titulo;
        delete[] lib[i].autor;
    }
    delete[] lib;
    return 0;
}