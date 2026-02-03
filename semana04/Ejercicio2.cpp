#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int n=2;
const int m=3;
int** matrizDinamica(int n,int m){
    int** M=new int*[n];
    for(int i=0;i<n;i++){
        *(M+i)=new int[m]
    }
    return M;
}
void llenarMatriz(int** M,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            *(*(M+i)+j)=rand()%10;
        }
    }
}
bool validarFilas(int** M,int n,int m){
    for(int i=0;i<n;i++){
        int suma=0;
        for(int j=0;j<m;j++){
            suma=suma+*(*(M+i)+j);
        }
        if(suma%2!=0){
            return false;
        }
    }
    return true;
}
bool validarColumnas(int** M,int n,int m){
    for(int i=0;i<n;i++){
        int max=M[i][0];
        for(int j=0;j<m;j++){
            if(max<M[i][j]){
                max=M[i][j];
                if(M[i][j]>0){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    int** M=matrizDinamica(n,m);
    llenarMatriz(M,n,m);
    
    return 0;
}