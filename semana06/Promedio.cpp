#include<iostream>
#include<fstream>
using namespace std;
float calcularPromedio(float* notas,int n){
    float suma=0;
    for(int i=0;i<n;i++){
        suma=suma+notas[i];
    }
    return suma/n;
}
int main(){
    int n;
    cin>>n;
    float* notas=new(nothrow)float[n];
    if(notas==nullptr){
        cout<<"No se pudo asignar memoria.\n";
        return 1;
    }
    ifstream in("notas.txt");
    if(!in.is_open()){
        cout<<"Error al abrir el archivo.\n";
        delete[] notas;
        return 1;
    }
    for(int i=0;i<n;i++){
        in>>notas[i];//se ignora los espacios y saltos de linea
        if(in.fail()){//detecta error de lectura, escritura
            cout<<"Error de lectura.\n";
            delete[] notas;
            in.close();
            return 1;
        }
    }
    in.close();
    cout<<"\nNotas leidas:\n";
    for(int i=0;i<n;i++){
        cout<<notas[i]<<" ";
    }
    float prom=calcularPromedio(notas,n);
    cout<<"\nPromedio: "<<prom;
    delete[] notas;
    notas=nullptr;
    return 0;
}