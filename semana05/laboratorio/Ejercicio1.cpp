#include<iostream>
using namespace std;
struct Estudiante{
    char* nombre;
    float nota;
};
void leerDatos(Estudiante* e,int n){
    for(int i=0;i<n;i++){
        cout<<"Ingrese el nombre del estudiante "<<i+1<<" :";
        e[i].nombre=new char[20];
        cin.getline(e[i].nombre,20);
        cout<<"Ingrese la nota del estudiante "<<i+1<<" :";
        cin>>e[i].nota;
        cin.ignore();
    }
}
int indMayorNota(Estudiante* e,int n){
    int indMax=0;
    for(int i=1;i<n;i++){
        if(e[i].nota>e[indMax].nota){
            indMax=i;
        }
    }
    return indMax;
}
int main(){
    int n;
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>n;
    cin.ignore();
    Estudiante* estudiantes=new Estudiante[n];
    leerDatos(estudiantes,n);
    int pos=indMayorNota(estudiantes,n);
    cout<<"El estudiante con la mayor nota es: "<<estudiantes[pos].nombre<<" Nota: "<<estudiantes[pos].nota;
    for(int i=0;i<n;i++){
        delete[] estudiantes[i].nombre;
    }
    delete[] estudiantes;
    return 0;
}