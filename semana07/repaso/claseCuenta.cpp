#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Cuenta{
    private:
    int numero;
    char titular[50];
    double saldo;
    bool bloqueada;
    double saldoMinimo=100.0;
    void actualizarEstado(){
        if(saldo<saldoMinimo){
            bloqueada=true;
        }else{
            bloqueada=false;
        }
    }
    public:
    Cuenta(int n=0,const char* t="",double s=0.0){
        saldoMinimo=100.0;
        if(n<=0||s<0){
            numero=0;
            saldo=0;
            bloqueada=false;
            strcpy(titular,"INVALIDA");
            return;
        }else{
            numero=n;
        saldo=s;
        strncpy(titular,t,49);
        titular[49]='\0';
        actualizarEstado();
        }
    }
    int getNumero(){
        return numero;
    }
    bool depositar(double monto){
        if(monto<=0){
            return false;
        }
        saldo=saldo+monto;
        actualizarEstado();
        return true;
    }
    bool retirar(double monto){
        if(bloqueada){
            return false;
        }
        if(monto<=0){
            return false;
        }
        if(saldo<monto){
            return false;
        }
        saldo=saldo-monto;
        actualizarEstado();
        return true;
    }
    bool transferir(Cuenta &destino,double monto) {
        if(numero==destino.numero){
            return false;
        }
        if(!retirar(monto)){
            return false;
        }
        if(!destino.depositar(monto)){
            depositar(monto);
            return false;
        }
        return true;
    }
    void aplicarInteres(double tasa){
        if(tasa<=0){
            return;
        }
        saldo=saldo+(saldo*tasa);
        actualizarEstado();
    }
    void mostrar(){
        cout<<"Cuenta: "<<numero<<endl;
        cout<<"Titular: "<<titular<<endl;
        cout<<"Saldo: "<<saldo<<endl;
        cout<<"Estado: ";
        if(bloqueada){
            cout<<"BLOQUEADA\n\n";
        }else{
            cout<<"ACTIVA\n\n";
        }
    }
};
long buscarCuenta(fstream &archivo,int num){
    archivo.clear();
    archivo.seekg(0, ios::beg);
    Cuenta c;
    while(true){
        long pos=archivo.tellg();
        if(!archivo.read((char*)&c,sizeof(Cuenta))){
            break;
        }
        if(c.getNumero()==num){
            return pos/sizeof(Cuenta);
        }
    }
    return -1;
}
int main(){
    fstream archivo("cuentas.bin",ios::in|ios::out|ios::binary);
    if(!archivo){
        ofstream crear("cuentas.bin",ios::binary);
        crear.close();
        archivo.open("cuentas.bin",ios::in|ios::out|ios::binary);
    }
    int opcion;
    do{
        cout<<"----- MENU -----\n";
        cout<<"1. Crear cuenta\n";
        cout<<"2. Depositar\n";
        cout<<"3. Retirar\n";
        cout<<"4. Mostrar cuenta\n";
        cout<<"5. Transferir\n";
        cout<<"6. Aplicar interes\n";
        cout<<"7. Salir\n";
        cin>>opcion;
        int num,num2;
        char nombre[50];
        double monto,tasa;
        switch(opcion){
            case 1:{
                cout<<"Numero: ";
                cin>>num;
                cout<<"Nombre: ";
                cin.ignore();
                cin.getline(nombre,50);
                cout<<"Saldo inicial: ";
                cin>>monto;
                Cuenta nueva(num,nombre,monto);
                if(buscarCuenta(archivo,num)!=-1){
                    cout<<"Cuenta ya existe\n\n";
                    break;
                }
                if(nueva.getNumero()==0){
                    cout<<"Datos invalidos\n\n";
                    break;
                }
                ofstream out("cuentas.bin",ios::binary|ios::app);
                out.write((char*)&nueva,sizeof(Cuenta));
                out.close();
                cout<<"Cuenta creada\n\n";
                break;
            }
            case 2:{
                cout<<"Numero: ";
                cin>>num;
                cout<<"Monto: ";
                cin>>monto;
                long pos=buscarCuenta(archivo,num);
                archivo.clear();
                if(pos==-1){
                cout<<"No existe\n"; 
                break; 
                }
                Cuenta c;
                archivo.seekg(pos*sizeof(Cuenta));
                archivo.read((char*)&c,sizeof(Cuenta));
                if(!c.depositar(monto)){
                cout<<"Operacion invalida\n";
                break;
                }
                archivo.seekp(pos*sizeof(Cuenta));
                archivo.write((char*)&c,sizeof(Cuenta));
                cout<<"Deposito exitoso\n";
                break;
            }
            case 3:{
                cout<<"Numero: ";
                cin>>num;
                cout<<"Monto: ";
                cin>>monto;
                long pos=buscarCuenta(archivo,num);
                archivo.clear();
                if(pos==-1){
                cout<<"La cuenta no existe\n\n"; 
                break; 
                }
                Cuenta c;
                archivo.seekg(pos*sizeof(Cuenta));
                archivo.read((char*)&c,sizeof(Cuenta));
                if(!c.retirar(monto)){
                cout<<"Operacion invalida\n";
                break;
                }
                archivo.seekp(pos*sizeof(Cuenta));
                archivo.write((char*)&c,sizeof(Cuenta));
                cout<<"Retiro exitoso\n";
                break;
            }
            case 4:{
                cout<<"Numero: ";
                cin>>num;
                long pos=buscarCuenta(archivo,num);
                archivo.clear();
                if(pos==-1){
                cout<<"La cuenta no existe\n";
                break;
                }
                Cuenta c;
                archivo.seekg(pos*sizeof(Cuenta));
                archivo.read((char*)&c,sizeof(Cuenta));
                c.mostrar();
                break;
            }
            case 5:{
                cout<<"Origen: ";
                cin>>num;
                cout<<"Destino: ";
                cin>>num2;
                cout<<"Monto: ";
                cin>>monto;
                long pos1=buscarCuenta(archivo,num);
                long pos2=buscarCuenta(archivo,num2);
                archivo.clear();
                if(pos1==-1||pos2==-1){
                    cout<<"Cuenta inexistente\n";
                    break;
                }
                Cuenta c1,c2;
                archivo.seekg(pos1*sizeof(Cuenta));
                archivo.read((char*)&c1,sizeof(Cuenta));
                archivo.seekg(pos2*sizeof(Cuenta));
                archivo.read((char*)&c2,sizeof(Cuenta));
                if(!c1.transferir(c2,monto)){
                    cout<<"Transferencia invalida\n";
                    break;
                }
                archivo.seekp(pos1*sizeof(Cuenta));
                archivo.write((char*)&c1,sizeof(Cuenta));
                archivo.seekp(pos2*sizeof(Cuenta));
                archivo.write((char*)&c2,sizeof(Cuenta));
                cout<<"Transferencia exitosa\n";
                break;
            }
            case 6:{
                cout<<"Tasa: ";
                cin>>tasa;
                archivo.seekg(0,ios::beg);
                Cuenta c;
                long pos=0;
                while(archivo.read((char*)&c,sizeof(Cuenta))){
                    c.aplicarInteres(tasa);
                    archivo.seekp(pos*sizeof(Cuenta));
                    archivo.write((char*)&c,sizeof(Cuenta));
                    archivo.seekg((pos+1)*sizeof(Cuenta));
                    pos=pos+1;
                }
                cout<<"Interes aplicado\n";
                break;
            }
        }
    }while(opcion!=7);
    archivo.close();
    return 0;
}