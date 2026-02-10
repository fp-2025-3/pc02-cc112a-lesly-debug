#include<iostream>
using namespace std;
struct Estudiante{
    int codigo;
    float promedio;
    char sexo;
};
void mostrar(Estudiante e1){
    cout<<e1.codigo;
}
void aumentarPromedio(Estudiante& e1){
    e1.promedio=e1.promedio+1;
}
float calcularPromedio(Estudiante e1[],int n){
    float suma=0;
    for(int i=0;i<n;i++){
        suma=suma+e1[i].promedio;
    }
    return suma/n;
}
int main(){
    Estudiante A[3];
    for(int i=0;i<3;i++){
        cout<<"Alumno "<<i+1<<endl;
        cout<<"Codigo: ";
        cin>>A[i].codigo;
        cout<<"Promedio: ";
        cin>>A[i].promedio;
        cout<<"Sexo: ";
        cin>>A[i].sexo;
    }
    Estudiante e6={123,14.5,'F'};
    Estudiante* ptr;
    ptr=&e6;
    cout<<"Codigo: "<<ptr->codigo<<endl;
    cout<<"Promedio: "<<ptr->promedio<<endl;
    cout<<"Sexo: "<<ptr->sexo<<endl;
    return 0;
}