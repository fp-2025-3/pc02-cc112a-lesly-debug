#include<iostream>
using namespace std;
void leerEstudiantes(int& n){
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>n;
}
float* reservarMemoria(int n){
    return new float[n];
}
void leerNotas(float* notas,int n){
    for(int i=0;i<n;i++){
        cout<<"Ingrese la nota "<<i+1<<" :";
        cin>>notas[i];
    }
}
float calculoPromedio(float* notas,int n){
    float suma=0;
    for(int i=0;i<n;i++){
        suma=suma+notas[i];
    }
    return suma/n;
}
void calculoMinMax(float* notas,int n,float& maxi,float& mini){
    mini=notas[0];
    maxi=notas[0];
    for(int i=0;i<n;i++){
        if(notas[i]<mini){
            mini=notas[i];
        }
        if(maxi<notas[i]){
            maxi=notas[i];
        }
    }
}
void redimensionar(float*& notas,int n,int k){
    float* nuevo=new float[n+k];
    for(int i=0;i<n;i++){
        nuevo[i]=notas[i];
    }
    delete[] notas;
    notas=nuevo;
    n=n+k;
}
void liberarMemoria(float*& notas){
    delete[] notas;
    notas=nullptr;
}
int main(){
    int n;
    float* notas=nullptr;
    leerEstudiantes(n);
    notas=reservarMemoria(n);
    leerNotas(notas,n);
    cout<<"Promedio inicial: "<<calculoPromedio(notas,n)<<endl;
    float maxi,mini;
    calculoMinMax(notas,n,mini,maxi);
    int k;
    cout<<"Ingrese la cantidad de estudiante a agregar: ";
    cin>>k;
    redimensionar(notas,n,k);
    leerNotas(notas+n-k,k);//lee notas despues de la posicion n, notas tiene tamaño de n+k;
    cout<<"Promedio final: "<<calculoPromedio(notas,n)<<endl;
    calculoMinMax(notas,n,maxi,mini);
    cout<<"Nota minima "<<mini<<endl;
    cout<<"Nota maxima: "<<maxi<<endl;
    liberarMemoria(notas);
    return 0;
}