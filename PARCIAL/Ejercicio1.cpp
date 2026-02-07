#include<iostream>
using namespace std;
int costoMaximo(int* arr,int n,int pos){
    if(pos==n){
        return 0;
    }
    int maximo=0;
    int producto=1;
    for(int i=pos;i<n;i++){
        producto=producto*arr[i];
        int costo=producto+costoMaximo(arr,n,i+1);
        if(maximo<costo){
            maximo=costo;
        }
    }
    return maximo;
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
    cout<<"Costo maximo: "<<costoMaximo(arr,n,0);
    return 0;
}
//b) Sea A=[2,1,3], n=3
//pos=3 retorna 0

//costoMaximo(pos=2)
//particion: [3]
//producto=3
//costo=3+0
//retorna 3

//costoMaximo(pos=1)
//particiones:
//[1]-[3]   costo=1+3=4
//[1,3]     costo=(1*3)=3
//retorna 4

//costoMaximo(pos=0)
//particiones:
//[2]-[1]-[3]   costo=2+4=6
//[1,3]         costo=(2*1)+3=5
//[2,1,3]       costo=(2*1*3)+0=6
//retorna 6
