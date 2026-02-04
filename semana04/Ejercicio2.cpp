#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int** matrizDinamica(int n,int m){
    int** M=new int*[n];
    for(int i=0;i<n;i++){
        *(M+i)=new int[m];
    }
    return M;
}
void llenarMatriz(int** M,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            *(*(M+i)+j)=rand()%10-5;//para generar negativos
        }
    }
}
void validarFilas(int** M,int n,int m,bool* filasValidas){
    for(int i=0;i<n;i++){
        int suma=0;
        for(int j=0;j<m;j++){
            suma=suma+*(*(M+i)+j);
        }
        if(suma%2==0){
            filasValidas[i]=true;
        }else{
            filasValidas[i]=false;
        }
    }
}
void validarColumnas(int** M,int n,int m,bool* colValidas){
    for(int i=0;i<m;i++){
        int max=M[0][i];
        for(int j=1;j<n;j++){
            if(max<M[j][i]){
                max=M[j][i];
            }
        }
        //max es el mayor valor de la columna
        if(max>0){
            colValidas[i]=true;
        }else{
            colValidas[i]=false;
        }
    }
}
void imprimirMatriz(int** M,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<*(*(M+i)+j)<<" ";
        }
        cout<<endl;
    }
}
int contadorFilasValidas(bool* filas,int n){
    int c=0;
    for(int i=0;i<n;i++){
        if(filas[i]){
            c=c+1;
        }
    }
    return c;
}
int contadorColumnasValidas(bool* col,int m){
    int c=0;
    for(int i=0;i<m;i++){
        if(col[i]){
            c=c+1;
        }
    }
    return c;
}
int** construirNuevaMatriz(int** M,int n,int m,bool* filasValidas,bool* colValidas,int& nuevoN,int& nuevoM){
    nuevoN=contadorFilasValidas(filasValidas,n);
    nuevoM=contadorColumnasValidas(colValidas,m);
    int** N=matrizDinamica(nuevoN,nuevoM);
    int i2=0;
    for(int i=0;i<n;i++){
        if(filasValidas[i]){
            int j2=0;
            for(int j=0;j<m;j++){
                if(colValidas[j]){
                    N[i2][j2]=M[i][j];
                    j2=j2+1;
                }
            }
            i2=i2+1;
        }
    }
    return N;
}
int main(){
    srand(time(NULL));
    int n=4;
    int m=6;
    int** M=matrizDinamica(n,m);
    llenarMatriz(M,n,m);
    cout<<"Matriz original:\n";
    imprimirMatriz(M,n,m);
    bool* filasValidas=new bool[n];
    bool* colValidas=new bool[m];
    validarFilas(M,n,m,filasValidas);
    validarColumnas(M,n,m,colValidas);
    int nuevoN,nuevoM;
    int** N=construirNuevaMatriz(M,n,m,filasValidas,colValidas,nuevoN,nuevoM);
    cout<<"\nMatriz filtrada:\n";
    imprimirMatriz(N,nuevoN,nuevoM);
    return 0;
}