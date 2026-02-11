#include<iostream>
using namespace std;
struct Nota{
    float valor;
    Nota* sig;
};
int contarNodos(Nota* cabeza){
    int c=0;
    while(cabeza!=nullptr){
        c=c+1;
        cabeza=cabeza->sig;
    }
    return c;
}
float promedioNotas(Nota* cabeza){
    Nota* aux=cabeza;
    float suma=0;
    int n=contarNodos(aux);
    while(aux!=nullptr){
        suma=suma+(aux->valor);
    }
    return suma/n;
}
void mostrarNotas(Nota*& cabeza){
    Nota* aux=cabeza;
    while(aux!=nullptr){
        cout<<"Nota: "<<aux->valor<<endl;
        aux=aux->sig;
    }
}
void liberarNotas(Nota*& cabeza){
    while(cabeza!=nullptr){
        Nota* temp=cabeza;
        cabeza=cabeza->sig;
        delete temp;
    }
}
int main(){
    Nota* n1=new Nota{14,nullptr};
    Nota* n2=new Nota{15,nullptr};
    Nota* n3=new Nota{19,nullptr};
    n1->sig=n2;
    n2->sig=n3;
    Nota* cabeza=n1;
    mostrarNotas(cabeza);
    float prom=promedioNotas(cabeza);
    cout<<"Promedio: "<<prom;
    liberarNotas(cabeza);
    return 0;
}