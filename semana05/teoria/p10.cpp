#include<iostream>
#include<string>
using namespace std;
struct Libro{
    string ISBN;
    string titulo;
    string autor;
    int anio;
    string estado;
};
void prestarLibro(Libro& libro){
    libro.estado="prestado";
}
void devolverLibro(Libro& libro){
    libro.estado="disponible";
}
void mostrarLibros(const Libro libros[],int cantidad){
    for(int i=0;i<cantidad;i++){
        cout<<"Libro "<<i+1<<endl;
        cout<<"ISBN: "<<libros[i].ISBN<<endl;
        cout<<"Titulo: "<<libros[i].titulo<<endl;
        cout<<"Autor: "<<libros[i].autor<<endl;
        cout<<"Anio: "<<libros[i].anio<<endl;
        cout<<"Estado: "<<libros[i].estado<<endl;
        cout<<endl;
    }
}
int contarLibrosPrestados(const Libro libros[],int cantidad){
    int contador=0;
    for(int i=0;i<cantidad;i++){
        if(libros[i].estado=="prestado"){
            contador=contador+1;
        }
    }
    return contador;
}
int main(){
    const int TAM=5;
    Libro libros[TAM]={{"978-01","Cien años de soledad","Gabriel Garcia Marquez",1967,"disponible"},{"978-02", "Don Quijote", "Miguel de Cervantes", 1605, "disponible"},{"978-03", "La ciudad y los perros", "Mario Vargas Llosa", 1963, "disponible"},{"978-04", "El principito", "Antoine de Saint-Exupery", 1943, "disponible"},{"978-05", "1984", "George Orwell", 1949, "disponible"}};
    cout<<"---Mostrando libros---\n";
    prestarLibro(libros[1]);
    prestarLibro(libros[2]);
    devolverLibro(libros[2]);
    mostrarLibros(libros,TAM);
    int libPrestados=contarLibrosPrestados(libros,TAM);
    cout<<"Numero de libros prestados: "<<libPrestados;
    return 0;
}