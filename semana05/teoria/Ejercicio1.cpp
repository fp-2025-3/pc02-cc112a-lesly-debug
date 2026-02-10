#include<iostream>
using namespace std;
struct Estudiante{
    int codigo;
    float promedio;
};
void leerDatos(Estudiante e[],int n){
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Codigo: ";
        cin>>e[i].codigo;
        cout<<"Promedio: ";
        cin>>e[i].promedio;
    }
}
void mostrarAprobados(Estudiante e[],int n){
    cout<<"===APROBADOS===\n";
    for(int i=0;i<n;i++){
        if(e[i].promedio>=10){
            cout<<"Codigo: "<<e[i].codigo<<" | Promedio: "<<e[i].promedio<<endl;
        }
    }
}
int main(){
    int n;
    cout<<"Ingrese la cantidad de estudiantes: ";
    cin>>n;
    Estudiante* estudiantes=new Estudiante[n];
    leerDatos(estudiantes,n);
    mostrarAprobados(estudiantes,n);
    delete[] estudiantes;
    return 0;
}