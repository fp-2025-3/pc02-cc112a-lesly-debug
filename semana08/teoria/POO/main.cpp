#include "vehiculos.h"
#include<iostream>
using namespace std;
int main(){
    Vehiculo *v[3];
    v[0]=new Automovil("ABC123","Toyota",1999,1200.25,4);
    v[1]=new Camion("DEF456","Cascadia",1980,40678.89,540.70);
    v[2]=new Motocicleta("GHI789","Yamaha",2006,180789.645,78.45);
    v[0]->aumentarPrecio();
    v[0]->mostrarInfo();
    v[1]->aumentarPrecio();
    v[1]->mostrarInfo();
    v[2]->aumentarPrecio();
    v[2]->mostrarInfo();
    for(int i=0;i<3;i++){
        delete v[i];
    }
    return 0;
}