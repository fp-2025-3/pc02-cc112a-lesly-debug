#include<iostream>
#include<fstream>
using namespace std;
struct Cuenta{
    int numero;
    char titular[50];
    double saldo;
};
void my_strcpy(char* destino,const char* origen){
    while(*origen!='\0'){
        *destino=*origen;
        origen=origen+1;
        destino=destino+1;
    }
    *destino='\0';
}
int buscarCuenta(const char* nombreArchivo,int numBuscado){
    ifstream archivo;
    archivo.open(nombreArchivo,ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return -1;
    }
    Cuenta c;
    int posicion=0;
    while(archivo.read((char*)&c,sizeof(Cuenta))){
        if(c.numero==numBuscado){
            archivo.close();
            return posicion;
        }
        posicion=posicion+1;
    }
    archivo.close();
    return -2;
}
void crearCuenta(const char* nombreArchivo,int num,const char* nombre,double saldoInicial){
    if(saldoInicial<0){
        cout<<"Saldo inicial invalido.\n";
        return;
    }
    Cuenta c;
    c.numero=num;
    my_strcpy(c.titular,nombre);
    c.saldo=saldoInicial;
    ofstream archivo;
    archivo.open(nombreArchivo,ios::binary|ios::app);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    int posicion=buscarCuenta(nombreArchivo,num);
    if(posicion>=0){
        cout<<"La cuenta ya existe.\n";
        return;
    }
    archivo.write((char*)&c,sizeof(Cuenta));
    archivo.close();
    cout<<"Cuenta creada correctamente.\n";
}
void depositar(const char* nombreArchivo,int numero,double monto){
    if(monto<=0){
        cout<<"Monto invalido.\n";
        return;
    }
    int posicion=buscarCuenta(nombreArchivo,numero);
    if(posicion==-2){
        cout<<"La cuenta no existe.\n";
        return;
    }
    if(posicion==-1){
        cout<<"Error al abrir el archivo.\n";
        return;
    }
    fstream archivo;
    archivo.open(nombreArchivo,ios::binary|ios::out|ios::in);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    Cuenta c;
    archivo.seekg(posicion*sizeof(Cuenta),ios::beg);
    archivo.read((char*)&c,sizeof(Cuenta));
    c.saldo=c.saldo+monto;
    archivo.seekp(posicion*sizeof(Cuenta),ios::beg);
    archivo.write((char*)&c,sizeof(Cuenta));
    archivo.close();
    cout<<"Deposito realizado correctamente.\n";
}
void retirar(const char* nombreArchivo,int numero,double monto){
    if(monto<=0){
        cout<<"Monto invalido.\n";
        return;
    }
    int posicion=buscarCuenta(nombreArchivo,numero);
    if(posicion==-2){
        cout<<"La cuenta no existe.\n";
        return;
    }
    if(posicion==-1){
        cout<<"Error al abrir el archivo.\n";
        return;
    }
    fstream archivo;
    archivo.open(nombreArchivo,ios::binary|ios::out|ios::in);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    Cuenta c;
    archivo.seekg(posicion*sizeof(Cuenta),ios::beg);
    archivo.read((char*)&c,sizeof(Cuenta));
    if(c.saldo<monto){
        cout<<"Fondos insuficientes.\n";
        return;
    }
    c.saldo=c.saldo-monto;
    archivo.seekp(posicion*sizeof(Cuenta),ios::beg);
    archivo.write((char*)&c,sizeof(Cuenta));
    archivo.close();
    cout<<"Retiro realizado correctamente.\n";
}
void mostrarCuentas(const char* nombreArchivo){
    ifstream archivo;
    archivo.open(nombreArchivo,ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    Cuenta c;
    cout<<"----- CUENTAS REGISTRADAS -----\n\n";
    while(archivo.read((char*)&c,sizeof(Cuenta))){
        cout<<"Cuenta: "<<c.numero<<endl;
        cout<<"Titular: "<<c.titular<<endl;
        cout<<"Saldo: "<<c.saldo<<endl;
        cout<<endl;
    }
    archivo.close();
}
int main(){
    int opcion;
    const char* nombreArchivo="cuentas.dat";
    do{
        cout<<"==== MENU DE OPCIONES ====\n";
        cout<<"1. Crear cuenta.\n";
        cout<<"2. Depositar.\n";
        cout<<"3. Retirar.\n";
        cout<<"4. Mostar cuentas.\n";
        cout<<"5. Salir.\n";
        cin>>opcion;
        int num;
        char nombre[50];
        double saldo;
        double monto;
        switch(opcion){
            case 1:{
                cout<<"--- REGISTRO ---\n";
                cout<<"Numero: ";
                cin>>num;
                cout<<"Nombre: ";
                cin.ignore();
                cin.getline(nombre,50);
                cout<<"Saldo inicial: ";
                cin>>saldo;
                crearCuenta(nombreArchivo,num,nombre,saldo);
                break;
            }
            case 2:{
                cout<<"--- DEPOSITO ---\n";
                cout<<"Numero: ";
                cin>>num;
                cout<<"Monto: ";
                cin>>monto;
                depositar(nombreArchivo,num,monto);
                break;
            }
            case 3:{
                cout<<"--- RETIRO ---\n";
                cout<<"Numero: ";
                cin>>num;
                cout<<"Monto: ";
                cin>>monto;
                retirar(nombreArchivo,num,monto);
                break;
            }
            case 4:{
                mostrarCuentas(nombreArchivo);
                break;
            }
            case 5:{
                cout<<"Saliendo...";
            }
        }
    }while(opcion!=5);
    return 0;
}
//1. Falla porque no valida fondos. El saldo queda negativo.
//2. No existe ninguna validación para el saldo.
//3. La cuenta tendria valores indefinidos y el saldo seria basura.
//4. Sí, porque es una variable global.
//5. El programa solo maneja una cuenta global, no funcionaría