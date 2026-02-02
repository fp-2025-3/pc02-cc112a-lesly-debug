#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int x=3,y=4,z=5;
    //Reserva de memoria dinámica para cada componente de un arreglo de 3D
    int*** A;
    A=new int**[x];
    for(int i=0;i<x;i++){
        *(A+i)=new int*[y];
        for(int j=0;j<y;j++){
            *(*(A+i)+j)=new int[z];
        }
    }

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                *(*(*(A+i)+j)+k)=rand()%10;
            }
        }
    }

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                cout<<*(*(*(A+i)+j)+k);
            }
            cout<<endl;
        }
        cout<<endl;
    }
    //Liberar memoria
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            delete[] A[i][j];
        }
        delete[] A[i];
    }
    delete[] A;
    return 0;
}