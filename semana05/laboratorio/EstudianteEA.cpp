#include<iostream>
#include<string>
using namespace std;
struct Estudiante{
    int codigo;
    string nombre;
    float promedio;
    Estudiante* sig;
};
void insertarEstudiantes(Estudiante*& cabeza){
    Estudiante* nuevo=new Estudiante;
    cout<<"Codigo: ";
    cin>>nuevo->codigo;
    cin.ignore();
    cout<<"Nombre: ";
    getline(cin,nuevo->nombre);
    cout<<"Promedio: ";
    cin>>nuevo->promedio;
    nuevo->sig=cabeza;
    cabeza=nuevo;
}
void mostrarEstudiantes(Estudiante* cabeza){
    Estudiante* aux=cabeza;
    while(aux!=nullptr){
        cout<<aux->codigo<<" | "<<aux->nombre<<" | "<<aux->promedio<<endl;
        aux=aux->sig;
    }
}
void liberarLista(Estudiante*& cabeza){
    while(cabeza!=nullptr){
       Estudiante* temp=cabeza;
       cabeza=cabeza->sig;
       delete temp; 
    }
}
int main(){
    Estudiante* cabeza=nullptr;
    int n;
    cout<<"Ingrese la cantidad de estudiantes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        insertarEstudiantes(cabeza);
    }
    mostrarEstudiantes(cabeza);
    liberarLista(cabeza);
    return 0;
}