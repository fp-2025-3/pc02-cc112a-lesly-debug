#include<iostream>
#include<fstream>
using namespace std;
struct CuentaBancaria{
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};
void crearArchivo(int N){
    fstream archivo("cuentas.dat",ios::binary|ios::in|ios::out);
    if(!archivo){
        archivo.open("cuentas.dat",ios::out|ios::binary);
        archivo.close();
        archivo.open("cuentas.dat",ios::binary|ios::in|ios::out);
    }
    CuentaBancaria cuenta;
    for(int i=0;i<N;i++){
        cout<<"Numero de cuenta "<<i+1<<endl;
        cin>>cuenta.numeroCuenta;
        int posicion=(cuenta.numeroCuenta-1)*sizeof(CuentaBancaria);
        archivo.seekg(posicion,ios::beg);
        CuentaBancaria temp;
        archivo.read((char*)&temp,sizeof(CuentaBancaria));
        if(archivo){
            cout<<"Ya existe una cuenta con este numero.\n";
            i=i-1;
        }else{
            archivo.clear();
            archivo.seekp(posicion,ios::beg);
            cout<<"Titular: ";
            cin.ignore();
            cin.getline(cuenta.titular,40);
            cout<<"Saldo: ";
            cin>>cuenta.saldo;
            cuenta.activa=true;
            archivo.write((char*)&cuenta,sizeof(CuentaBancaria));
        }
    }
    archivo.close();
}
bool buscarCuenta(int numero,CuentaBancaria& cuenta){
    ifstream archivo("cuentas.dat",ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return false;
    }
    int posicion=(numero-1)*sizeof(CuentaBancaria);
    archivo.seekg(posicion,ios::beg);
    archivo.read((char*)&cuenta,sizeof(CuentaBancaria));
    if(!archivo){
        archivo.close();
        return false;
    }
    if(cuenta.numeroCuenta==numero){
        archivo.close();
        return true;
    }
    archivo.close();
    return false;
}
void depositarCuenta(int numero,CuentaBancaria& cuenta,double monto){
    if(monto<=0){
        cout<<"[Error] El monto debe ser mayor que cero.\n";
        return;
    }
    fstream archivo("cuentas.dat",ios::binary|ios::in|ios::out);
    if(!archivo){
        cout<<"Error al abrir el archivo.\n";
        return;
    }
    if(buscarCuenta(numero,cuenta)){
        if(!cuenta.activa){
            cout<<"Cuenta inactiva.\n";
            archivo.close();
            return;
        }
        int posicion=(numero-1)*sizeof(CuentaBancaria);
        cuenta.saldo=cuenta.saldo+monto;
        archivo.seekp(posicion,ios::beg);
        archivo.write((char*)&cuenta,sizeof(CuentaBancaria));
        cout<<"[Deposito] Se deposito S/."<<monto<<".Saldo actual: "<<cuenta.saldo<<endl;
        archivo.close();
    }else{
        cout<<"Numero de cuenta incorrecto.\n";
        archivo.close();
        return;
    }
}
void retirarCuenta(int numero,CuentaBancaria& cuenta,double monto){
    if(monto<=0){
        cout<<"[Error] El monto debe ser mayor que cero.\n";
    }
    fstream archivo("cuentas.dat",ios::binary|ios::in|ios::out);
    if(!archivo){
        cout<<"Error al abrir el archivo.\n";
        return;
    }
    if(buscarCuenta(numero,cuenta)){
        if(!cuenta.activa){
            cout<<"Cuenta inactiva.\n";
            archivo.close();
            return;
        }
        if(cuenta.saldo<monto){
            cout<<"Fondos insuficientes.\n";
            archivo.close();
            return;
        }else{
            int posicion=(numero-1)*sizeof(CuentaBancaria);
            cuenta.saldo=cuenta.saldo-monto;
            archivo.seekp(posicion,ios::beg);
            archivo.write((char*)&cuenta,sizeof(CuentaBancaria));
            cout<<"[Retiro] Se retiro S/."<<monto<<". Saldo actual: "<<cuenta.saldo<<endl;
            archivo.close();
        }
    }else{
        cout<<"Numero de cuenta incorrecto.\n";
        archivo.close();
        return;
    }
}
void desactivarCuenta(int numero,CuentaBancaria& cuenta){
    fstream archivo("cuentas.dat",ios::binary|ios::in|ios::out);
    if(!archivo){
        cout<<"Error al abrir el archivo.\n";
        return;
    }
    if(buscarCuenta(numero,cuenta)){
        int posicion=(numero-1)*sizeof(CuentaBancaria);
        if(!cuenta.activa){
            cout<<"La cuenta ya esta inactiva.\n";
            archivo.close();
            return;
        }
        cuenta.activa=false;
        archivo.seekp(posicion,ios::beg);
        archivo.write((char*)&cuenta,sizeof(CuentaBancaria));
        cout<<"Cuenta desactivada correctamente.\n";
        archivo.close();
    }else{
        cout<<"Numero de cuenta incorrecto.\n";
        archivo.close();
        return;
    }
}
void mostrarCuentasActivas(){
    ifstream archivo("cuentas.dat",ios::binary);
    if(!archivo){
        cout<<"Error al abrir el archivo.\n";
        return;
    }
    CuentaBancaria cuenta;
    cout<<"\nCUENTAS ACTIVAS\n";
    while(archivo.read((char*)&cuenta,sizeof(CuentaBancaria))){
        if(cuenta.activa){
            cout<<"Numero de cuenta: "<<cuenta.numeroCuenta<<endl;
            cout<<"Titular: "<<cuenta.titular<<endl;
            cout<<"Saldo: "<<cuenta.saldo<<endl;
            cout<<"-----------------------\n";
        }
    }
    archivo.close();
}

int main(){
    int N=2;
    crearArchivo(N);
    CuentaBancaria cuenta;
    depositarCuenta(1,cuenta,100);
    retirarCuenta(1,cuenta,50);
    desactivarCuenta(1,cuenta);
    mostrarCuentasActivas();
    return 0;
}