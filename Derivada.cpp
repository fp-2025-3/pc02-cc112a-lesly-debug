#include<iostream>
using namespace std;
int main(){
    int A[100];
    int n,k;
    int* p=&A[0];
    cout<<"Ingrese el grado del polinomio=";
    cin>>n;
    for(int i=0;i<=n;i++){
        cout<<"A["<<i<<"]=";
        cin>>*(p+i);
    }
    cout<<endl;
    cout<<"Ingrese k=";
    cin>>k;
    for(int i=k;i<=n;i++){
        int coef=*(p+i);
        int factor=1;
        for(int j=0;j<k;j++){
            factor=factor*(i-j);
        }
        *(p+i-k)=factor*coef;
    }
    for(int i=n-k+1;i<=n;i++){
        *(p+i)=0;
    }
    cout<<"La derivada k-esima: "<<endl;
    for(int i=0;i<=n-k;i++){
        if(*(p+i)!=0){
            cout<<*(p+i);
            if(i>0){
                cout<<"x"<<i;
            }
            if(i<n-k){
                cout<<"+";
            }
        }
    }
    return 0;
}