#include <iostream>
using namespace std;
void derivadaK(double* coef,int grado, int k,double* res,int& gradoRes){
    for(int i=k;i<=grado;i++){
        double p=*(coef+i);
        double factor=1.0;
        for(int j=0;j<k;j++){
            factor=factor*(i-j);
        }
        *(coef+i-k)=factor*p;
    }
    for(int i=grado-k+1;i<=grado;i++){
        *(res+i)=0;
    }
    gradoRes=grado-k;
}
void imprimirPolinomio(double* p, int grado){
    for(int i=0;i<=grado;i++){
        if(*(p+i)!=0){
            cout<<*(p+i);
            if(i>0){
                cout<<"x"<<i;
            }
            if(i<grado){
                cout<<"+";
            }
        }
    }
}

int main() {
    double coef[] = {2, 3, -1, 4};
    int grado = 3;

    double resultado[10];
    int gradoResultado;

    int k = 2;
    cout<<"Polinomio original: "<<endl;
    imprimirPolinomio(&coef[0],grado);
    cout<<endl;
    derivadaK(coef,grado,k,resultado,gradoResultado);
    cout<<"Derivada de orden "<<k<<": "<<endl;
    imprimirPolinomio(&coef[0],gradoResultado);
    return 0;
}