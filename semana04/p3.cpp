#include<iostream>
using namespace std;
void leerMediciones(float* med,int n){
    for(int i=0;i<n;i++){
        cin>>*(med+i);
    }
}
void registro(float* nuevo,float* med,int n);
void ordenar(float* med,int n);
int main(){
    float med[100];
    int n;
    cout<<"Ingrese numero de mediciones: ";
    cin>>n;
    return 0;
}