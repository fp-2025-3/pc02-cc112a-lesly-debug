#include<iostream>
using namespace std;
void agregarEstudiante(int*& codigos,float*& promedios,int& n,int& capacidad,int codigo,float promedio){
    if(n==capacidad){
        int nuevaCapacidad=capacidad*2;
        int* nuevosCodigos=new int[nuevaCapacidad];
        float* nuevosPromedios=new float[nuevaCapacidad];
        for(int i=0;i<n;i++){//Copia de datos antiguos;
            nuevosCodigos[i]=codigos[i];
            nuevosPromedios[i]=promedios[i];
        }
        delete[] codigos;
        delete[] promedios;
        //Apuntando a los nuevos arreglos;
        codigos=nuevosCodigos;
        promedios=nuevosPromedios;
        capacidad=nuevaCapacidad;
    }
    codigos[n]=codigo;
    promedios[n]=promedio;
    n=n+1;
}
void filtrarAprobados(int*& codigos,float*& promedios,int& n){
    int contador=0;
    for(int i=0;i<n;i++){
        if(*(promedios+i)>=10){
            contador=contador+1;
        }
    }
    int* codigosAprobados=new int[contador];
    float* promedioAprobados=new float[contador];
    int j=0;
    for(int i=0;i<n;i++){
        if(promedios[i]>=10){
            codigosAprobados[j]=codigos[i];
            promedioAprobados[j]=promedios[i];
            j=j+1;
        }
    }
    delete[] codigos;
    delete[] promedios;
    n=contador;//Total aprobados, sin actualizar se recorreria posiciones que no existen;
    codigos=codigosAprobados;
    promedios=promedioAprobados;
}
int main(){
    int capacidad=3;
    int n=0;
    int* codigos=new int[capacidad];
    float* promedios=new float[capacidad];
    agregarEstudiante(codigos,promedios,n,capacidad,101,14.5);
    agregarEstudiante(codigos,promedios,n,capacidad,102,8.0);
    agregarEstudiante(codigos,promedios,n,capacidad,103,16.2);
    agregarEstudiante(codigos,promedios,n,capacidad,104,9.5);
    agregarEstudiante(codigos,promedios,n,capacidad,105,12.3);
    cout<<"Estudiantes registrados:\n";
    for(int i=0;i<n;i++){
        cout<<"Codigo: "<<codigos[i]<<" Promedio: "<<promedios[i]<<endl;
    }
    cout<<"\nFiltrando estudiantes desaprobados...\n";
    filtrarAprobados(codigos,promedios,n);
    cout<<"Estudiantes aprobados:\n";
    for(int i=0;i<n;i++){
        cout<<"Codigo: "<<codigos[i]<<" Promedio: "<<promedios[i]<<endl;
    }
    delete[] codigos;
    delete[] promedios;
    return 0;
}