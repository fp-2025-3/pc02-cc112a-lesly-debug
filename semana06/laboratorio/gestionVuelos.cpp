#include<iostream>
#include<fstream>
using namespace std;
struct Pasajero{
    int dni;
    char nombre[50];
};
struct Asiento{
    int numero;
    bool reservado;
    Pasajero* pasajero;
};
struct NodoReserva{
    Pasajero pasajero;
    int numeroAsiento;
    NodoReserva* siguiente;
};
struct Vuelo{
    char codigo[10];
    char destino[50];
    int capacidad;
    Asiento* asientos;
    NodoReserva* listaReservas;
};
void my_strcpy(char* destino,const char* origen){
    while(*origen!='\0'){
        *destino=*origen;
        destino=destino+1;
        origen=origen+1;
    }
    *destino='\0';
}
int my_strcmp(const char* a,const char* b){
    while(*a!='\0'&&*b!='\0'&&*a==*b){
        a=a+1;
        b=b+1;
    }
    return *a-*b;
}
void crearVuelo(Vuelo& vuelo){
    cout<<"Ingrese el codigo del vuelo: ";
    cin.getline(vuelo.codigo,10);
    cout<<"Ingrese el destino: ";
    cin.getline(vuelo.destino,50);
    cout<<"Ingrese la capacidad: ";
    cin>>vuelo.capacidad;
    vuelo.asientos=new Asiento[vuelo.capacidad];
    for(int i=0;i<vuelo.capacidad;i++){
        vuelo.asientos[i].numero=i+1;
        vuelo.asientos[i].reservado=false;
        vuelo.asientos[i].pasajero=nullptr;
    }
    vuelo.listaReservas=nullptr;
}
void mostrarMapaAsientos(Vuelo& vuelo){
    cout<<"Vuelo: "<<vuelo.codigo<<" - "<<vuelo.destino<<endl;
    cout<<"Asientos:\n";
    for(int i=0;i<vuelo.capacidad;i++){
        cout<<vuelo.asientos[i].numero<<" ";
        if(vuelo.asientos[i].reservado){
            cout<<"[X]"<<endl;
        }else{
            cout<<"[ ]"<<endl;
        }
    }
}
void reservarAsiento(Vuelo& vuelo){
    int dni,numAsiento;
    char nombre[50];
    cout<<"Ingrese el DNI: ";
    cin>>dni;
    cout<<"Ingrese el nombre: ";
    cin.ignore();
    cin.getline(nombre,50);
    cout<<"Ingrese el numero de asiento: ";
    cin>>numAsiento;
    if(numAsiento<1||numAsiento>vuelo.capacidad){
        cout<<"Numero de asiento invalido.\n";
        return;
    }
    if(vuelo.asientos[numAsiento-1].reservado){
        cout<<"Asiento ocupado.\n";
        return;
    }
    NodoReserva* aux=vuelo.listaReservas;
    while(aux!=nullptr){
        if(aux->pasajero.dni==dni||my_strcmp(aux->pasajero.nombre,nombre)==0){
            cout<<"Pasajero ya registrado.\n";
            return;
        }
        aux=aux->siguiente;
    }
    vuelo.asientos[numAsiento-1].pasajero=new Pasajero;
    vuelo.asientos[numAsiento-1].pasajero->dni=dni;
    my_strcpy(vuelo.asientos[numAsiento-1].pasajero->nombre,nombre);
    vuelo.asientos[numAsiento-1].reservado=true;
    NodoReserva* nuevo=new NodoReserva;
    nuevo->numeroAsiento=numAsiento;
    nuevo->pasajero.dni=dni;
    my_strcpy(nuevo->pasajero.nombre,nombre);
    nuevo->siguiente=vuelo.listaReservas;
    vuelo.listaReservas=nuevo;
    cout<<"Reserva realizada correctamente.\n";
}
void liberarMemoria(Vuelo& vuelo){
    for(int i=0;i<vuelo.capacidad;i++){
        if(vuelo.asientos[i].pasajero!=nullptr){
            delete vuelo.asientos[i].pasajero;
        }
    }
    NodoReserva* actual=vuelo.listaReservas;
    while(actual!=nullptr){
        NodoReserva* temp=actual;
        actual=actual->siguiente;
        delete temp;
    }
    delete[] vuelo.asientos;
}
int main(){
    Vuelo vuelo;
    crearVuelo(vuelo);
    reservarAsiento(vuelo);
    mostrarMapaAsientos(vuelo);
    liberarMemoria(vuelo);
    return 0;
}