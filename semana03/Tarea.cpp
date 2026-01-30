#include<iostream>
using namespace std;
int my_strlen(const char* cadena){
    int contador=0;
    while(*cadena!='\0'){
        contador=contador+1;
        cadena=cadena+1;
    }
    return contador;
}
int contarMayorQuePromedio(const char* cadena[],int n){
    int suma=0;
    for(int i=0;i<n;i++){
        suma=suma+my_strlen(cadena[i]);
    }
    double promedio=(double)suma/n;
    int contadorMayor=0;
    for(int i=0;i<n;i++){
        if(my_strlen(cadena[i])>promedio){
            contadorMayor=contadorMayor+1;
        }
    }
    return contadorMayor;
}
int main(){
    const char* cadena[]={"fundamentos","de","programacion"};
    int n=sizeof(cadena)/sizeof(cadena[0]);
    int resultado=contarMayorQuePromedio(cadena,n);
    cout<<"Cantidad de cadenas con mayor longitud que la longitud promedio: "<<resultado;
    return 0;
}