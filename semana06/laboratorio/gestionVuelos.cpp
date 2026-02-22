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
struct RegistroBinario{
    int dni;
    char nombre[50];
    int asiento;
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
int my_strlen(const char* cadena){
    int contador=0;
    while(*cadena!='\0'){
        cadena=cadena+1;
        contador=contador+1;
    }
    return contador;
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
void cancelarReservar(Vuelo& vuelo){
    int dni;
    cout<<"Ingrese el DNI: ";
    cin>>dni;
    NodoReserva* aux=vuelo.listaReservas;
    NodoReserva* padre=nullptr;
    while(aux!=nullptr){
        if(aux->pasajero.dni==dni){//Mientras no coincide, padre sigue el aux, aux avanza
            break;
        }
        padre=aux;
        aux=aux->siguiente;//si nunca coincide aux=nullptr y el bucle termina
    }
    if(aux==nullptr){
        cout<<"Reserva no encontrada.\n";
        return;
    }
    delete vuelo.asientos[aux->numeroAsiento-1].pasajero;
    vuelo.asientos[aux->numeroAsiento-1].pasajero=nullptr;
    vuelo.asientos[aux->numeroAsiento-1].reservado=false;
    if(padre==nullptr){
        vuelo.listaReservas=aux->siguiente;
    }else{
        padre->siguiente=aux->siguiente;
    }
    delete aux;
}
void mostrarListaPasajero(Vuelo& vuelo){
    NodoReserva* aux=vuelo.listaReservas;
    if(aux==nullptr){
        cout<<"No hay reservas.\n";
        return;
    }
    cout<<"\n---LISTA DE PASAJEROS-----\n";
    while(aux!=nullptr){
        cout<<"DNI: "<<aux->pasajero.dni<<" - Nombre: "<<aux->pasajero.nombre<<" - Asiento: "<<aux->numeroAsiento<<endl;
        aux=aux->siguiente;
    }
}
void mostrarEstadisticas(Vuelo& vuelo){
    int contadorOcupados=0,contadorLibres=0;
    for(int i=0;i<vuelo.capacidad;i++){
        if(vuelo.asientos[i].reservado){
            contadorOcupados=contadorOcupados+1;
        }else{
            contadorLibres=contadorLibres+1;
        }
    }
    double ocupacion=(contadorOcupados*100.0)/vuelo.capacidad;
    cout<<"-----ESTADISTICAS DEL VUELO-----\n";
    cout<<"Total de asientos: "<<vuelo.capacidad<<endl;
    cout<<"Asientos ocupados: "<<contadorOcupados<<endl;
    cout<<"Asientos libres: "<<contadorLibres<<endl;
    cout<<"Porcentaje de ocupacion: "<<ocupacion<<"%"<<endl;
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
    vuelo.listaReservas=nullptr;
    vuelo.asientos=nullptr;
}
void generarReporte(Vuelo& vuelo){
    char nombreArchivo[50]="reporte_";
    my_strcpy(nombreArchivo+8,vuelo.codigo);
    my_strcpy(nombreArchivo+8+my_strlen(vuelo.codigo),".txt");
    ofstream archivo(nombreArchivo);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    int contadorOcupados=0;
    for(int i=0;i<vuelo.capacidad;i++){
        if(vuelo.asientos[i].reservado){
            contadorOcupados=contadorOcupados+1;
        }
    }
    int libres=vuelo.capacidad-contadorOcupados;
    double ocupacion=(contadorOcupados*100.0)/vuelo.capacidad;
    archivo<<"***REPORTE DE VUELO***\n";
    archivo<<"Codigo: "<<vuelo.codigo<<endl;
    archivo<<"Destino: "<<vuelo.destino<<endl;
    archivo<<"Capacidad: "<<vuelo.capacidad<<endl;
    archivo<<"Ocupados: "<<contadorOcupados<<endl;
    archivo<<"Libres: "<<libres<<endl;
    archivo<<"Porcentaje: "<<ocupacion<<endl;
    archivo.close();
    cout<<"Reporte generado correctamente.\n";
}
void generarReporteBinario(Vuelo& vuelo){
    char nombreArchivo[50]="reservas_";
    my_strcpy(nombreArchivo+9,vuelo.codigo);
    my_strcpy(nombreArchivo+9+my_strlen(vuelo.codigo),".dat");
    fstream archivo;
    archivo.open(nombreArchivo,ios::binary|ios::out);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    RegistroBinario registro;
    for(int i=0;i<vuelo.capacidad;i++){
        if(vuelo.asientos[i].reservado){
            registro.dni=vuelo.asientos[i].pasajero->dni;
            my_strcpy(registro.nombre,vuelo.asientos[i].pasajero->nombre);
            registro.asiento=vuelo.asientos[i].numero;
            archivo.write((char*)&registro,sizeof(RegistroBinario));
        }
    }
    archivo.close();
    cout<<"Reporte binario generado correctamente.\n";
}
int main(){
    Vuelo vuelo;
    crearVuelo(vuelo);
    int opcion;
    do{
        cout<<"\n=====MENU=====\n";
        cout<<"1. Reservar asiento.\n";
        cout<<"2. Cancelar reserva.\n";
        cout<<"3. Mostrar mapa de asientos\n";
        cout<<"4. Mostrar estadisticas.\n";
        cout<<"5. Generar reporte txt.\n";
        cout<<"6. Generar reporte bin.\n";
        cout<<"7. Salir.\n";
        cin>>opcion;
        cin.ignore();
        switch(opcion){
            case 1:{
                reservarAsiento(vuelo);
                break;
            }
            case 2:{
                cancelarReservar(vuelo);
                break;
            }
            case 3:{
                mostrarMapaAsientos(vuelo);
                break;
            }
            case 4:{
                mostrarEstadisticas(vuelo);
                break;
            }
            case 5:{
                generarReporte(vuelo);
                break;
            }
            case 6:{
                generarReporteBinario(vuelo);
                break;
            }
            case 7:{
                cout<<"Saliendo del programa...\n";
                break;
            }
        }
    }while(opcion!=7);
    liberarMemoria(vuelo);
    return 0;
}