#include<iostream>
using namespace std;
struct Alumno{
    float n1;
    float n2;
    float n3;
};
void leerAlumno(Alumno A[],int cantidad){
    for(int i=0;i<cantidad;i++){
        cout<<"Alumno "<<i+1<<" :\n";
        cout<<"Nota 1: ";
        cin>>A[i].n1;
        cout<<"Nota 2: ";
        cin>>A[i].n2;
        cout<<"Nota 3: ";
        cin>>A[i].n3;
    }
}
float calcularPromedio(const Alumno& A){
    return (A.n1+A.n2+A.n3)/3;
}
void mostrarAlumno(const Alumno A[],int cantidad){
    for(int i=0;i<cantidad;i++){
        cout<<"Alumno "<<i+1<<" :\n";
        cout<<"Nota 1: "<<A[i].n1<<endl;
        cout<<"Nota 2: "<<A[i].n2<<endl;
        cout<<"Nota 3: "<<A[i].n3<<endl;
        cout<<"Promedio: "<<calcularPromedio(A[i])<<endl;
    }
}
int main(){
    int numAlumnos;
    cout<<"Ingrese el numero de alumnos: ";
    cin>>numAlumnos;
    Alumno* alumnos=new Alumno[numAlumnos];
    leerAlumno(alumnos,numAlumnos);
    cout<<"===REGISTRO DE NOTAS===\n";
    mostrarAlumno(alumnos,numAlumnos);
    delete[] alumnos;
    return 0;
}