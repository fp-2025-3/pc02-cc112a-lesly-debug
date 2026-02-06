#include<iostream>
#include<climits>
using namespace std;
int costoMinimo(int arr[],int n,int pos){
    if(pos==n){
        return 0;
    }
    int minimo=INT_MAX;//mayor valor que puede almacenar un int
    int producto=1;
    for(int i=pos;i<n;i++){
        producto=producto*arr[i];
        int costo=producto+costoMinimo(arr,n,i+1);
        if(costo<minimo){
            minimo=costo;
        }
    }
    return minimo;
}
// Hojas del árbol
// [1]-[2]-[3]
// [1]-[2,3]
// [1,2]-[3]
// [1,2,3]
int main(){
    int A[]={1,2,3};
    int n=sizeof(A)/sizeof(A[0]);
    cout<<"Costo minimo: "<<costoMinimo(A,n,0)<<endl;
    return 0;
}
