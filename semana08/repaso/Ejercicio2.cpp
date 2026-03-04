#include<iostream>
#include<fstream>
using namespace std;
struct CuentaBancaria{
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};
void crearArchivo(const char* nombreArchivo,int n){
    fstream archivo;
    archivo.open(nombreArchivo,ios::binary|ios::in|ios::out);
    if(!archivo){
        archivo.open(nombreArchivo,ios::out|ios::binary);
        archivo.close();
        archivo.open(nombreArchivo,ios::binary|ios::in|ios::out);
    }
    CuentaBancaria cuenta;
    for(int i=0;i<n;i++){
        cout<<"Numero de cuenta "<<i+1<<endl;
        cuenta.numeroCuenta=i+1;
        int posicion=sizeof(CuentaBancaria)*(cuenta.numeroCuenta-1);
        archivo.seekg(posicion);
        CuentaBancaria temp;
        archivo.read((char*)&temp,sizeof(CuentaBancaria));
        if(archivo){
            cout<<"Ya existe una cuenta con este numero.\n";
            i=i-1;
        }else{
            archivo.clear();
            cout<<"Titular: ";
            cin.ignore();
            cin.getline(cuenta.titular,40);
            cout<<"Saldo: ";
            cin>>cuenta.saldo;
            cuenta.activa=true;
            archivo.write((char*)&cuenta,sizeof(CuentaBancaria));
        }
    }
    for(int i=0;i<n;i++){
        archivo.read((char*)&cuenta,sizeof(CuentaBancaria));
        for(int j=0;j<n;j++){
            archivo.read((char*)&cuenta,sizeof(CuentaBancaria));
            CuentaBancaria temp=cuenta;
            if(cuenta.numeroCuenta>temp.numeroCuenta){
                archivo.write((char*)&temp,sizeof(CuentaBancaria));
            }else{
                archivo.write((char*)&cuenta,sizeof(CuentaBancaria));
            }
        }
    }
    archivo.close();
}
int main(){
    int n;
    cout<<"Ingrese N=";
    cin>>n;
    crearArchivo("cuentas.dat",n);
    return 0;
}