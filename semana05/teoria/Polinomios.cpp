#include<iostream>
using namespace std;
struct Termino{
    float coeficiente;
    int exponente;
};
void leerDatos(Termino t[],int n){
    for(int i=0;i<n;i++){
        cout<<"Ingrese coeficiente y exponente del termino "<<i+1<<" :";
        cin>>t[i].coeficiente>>t[i].exponente;
    }
}
void mostrarPolinomio(Termino t[],int n){
    for(int i=0;i<n;i++){
        cout<<t[i].coeficiente;
        if(t[i].exponente!=0){
            cout<<"x^"<<t[i].exponente;
        }
        if(i<(n-1)){
            cout<<"+";
        }
    }
}
int gradoSumaPolinomios(Termino tA[],Termino tB[],int n,int m,Termino Suma[]){
    int i=0,j=0,k=0;
    while(i<n&&j<m){
        if(tA[i].exponente==tB[j].exponente){
            Suma[k].coeficiente=tA[i].coeficiente+tB[j].coeficiente;
            Suma[k].exponente=tA[i].exponente;
            k=k+1;
            i=i+1;
            j=j+1;
        }else if(tA[i].exponente>tB[j].exponente){
            Suma[k].coeficiente=tA[i].coeficiente;
            Suma[k].exponente=tA[i].exponente;
            k=k+1;
            i=i+1;
        }else{
            Suma[k].coeficiente=tB[j].coeficiente;
            Suma[k].exponente=tB[j].exponente;
            k=k+1;
            j=j+1;
        }
    }
    while(i<n){
        Suma[k]=tA[i];
        k=k+1;
        i=i+1;
    }
    while(j<m){
        Suma[k]=tB[j];
        k=k+1;
        j=j+1;
    }
    return k;
}
int gradoProductoPolinomios(Termino tA[],Termino tB[],int n,int m,Termino producto[]){
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            producto[k].coeficiente=tA[i].coeficiente*tB[j].coeficiente;
            producto[k].exponente=tA[i].exponente+tB[j].exponente;
            k=k+1;
        }
    }
    int r=0;
    for(int i=0;i<k;i++){
        bool repetido=false;
        for(int j=0;j<r;j++){
            if(producto[j].exponente==producto[i].exponente){
                producto[j].coeficiente=producto[j].coeficiente+producto[i].coeficiente;
                repetido=true;
                break;
            }
        }
        if(!repetido){
            producto[r].exponente=producto[i].exponente;
            producto[r].coeficiente=producto[i].coeficiente;
            r=r+1;
        }
    }
    return r;
}
int main(){
    Termino terminosA[20];
    Termino terminosB[20];
    int n,m;
    cout<<"Ingrese el numero de terminos del primer polinomio: ";
    cin>>n;
    leerDatos(terminosA,n);
    cout<<"Ingrese el numero de terminos del segundo polinomio: ";
    cin>>m;
    leerDatos(terminosB,m);
    cout<<"Primer polinomio: ";
    mostrarPolinomio(terminosA,n);
    cout<<"\nSegundo polinomio: ";
    mostrarPolinomio(terminosB,m);
    Termino sumaPolinomio[20];
    int totalSuma=gradoSumaPolinomios(terminosA,terminosB,n,m,sumaPolinomio);
    cout<<"\nSuma:";
    mostrarPolinomio(sumaPolinomio,totalSuma);
    Termino productoPolinomio[20];
    int totalProducto=gradoProductoPolinomios(terminosA,terminosB,n,m,productoPolinomio);
    cout<<"\nProducto:";
    mostrarPolinomio(productoPolinomio,totalProducto);
    return 0;
}