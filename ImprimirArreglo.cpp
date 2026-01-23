#include<iostream>
using namespace std;
void imprimir(int (*inicio)[3],int (*fin)[3]);
int main(){
    int A[2][3];
    int (*inicio)[3]=&A[0];
    int (*fin)[3]=&A[3];
    imprimir(inicio,fin);
    return 0;
}
void imprimir(int (*inicio)[3],int (*fin)[3]){
    for(int (*fila)[3]=inicio;fila<fin;fila++){
        int* colInicio=*fila;
        int* colFin=colInicio+3;
        for(int* col=colInicio;col<colFin;col++){
            cout<<*col;
        }
        cout<<endl;
    }
}