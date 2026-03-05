#include "rectangulo.h"
#include<iostream>
using namespace std;
int main(){
    Rectangulo r1(0,0,6,0,6,4,0,4);
    Rectangulo r2(4,4);
    cout<<"Rectangulo 1:\n";
    r1.mostrarDatos();
    cout<<"Rectangulo 2:\n";
    r2.mostrarDatos();
    return 0;
}