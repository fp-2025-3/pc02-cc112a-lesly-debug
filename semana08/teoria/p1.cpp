#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
class CuentaBancaria{
    private:
    string titular;
    double saldo;
    int numeroCuenta;
    int transaccionesDelDia;
    static const int LIMITE_RETIROS=3;
    public:
    CuentaBancaria(string t,int num,double s){
        titular=t;
        numeroCuenta=num;
        if(s>=0){
            saldo=s;
        }else{
            saldo=0;
        }
        transaccionesDelDia=0;
    }
    void depositar(double monto){
        if(monto<=0){
            cout<<"[Error] El monto debe ser mayor que cero.\n";
        }else{
            saldo=saldo+monto;
            cout<<fixed<<setprecision(2);
            cout<<"[Deposito] Se deposito "<<monto<<". Saldo actual: "<<saldo<<endl;
        }
    }
    void retirar(double monto){
        if(monto<=0){
            cout<<"[Error] El monto debe ser mayor que cero.\n";
        }else{
            if(transaccionesDelDia>=LIMITE_RETIROS){
                cout<<"[Error] Ha alcanzado el limite de 3 retiros diarios.\n";
            }else{
                if(monto>saldo){
                    cout<<"[Error] Fondos insuficientes.\n";
                }else{
                    saldo=saldo-monto;
                    transaccionesDelDia=transaccionesDelDia+1;
                    cout<<fixed<<setprecision(2);
                    cout<<"[Retiro] Se retiro "<<monto<<". Saldo actual: "<<saldo<<endl;
                }
            }
        }
    }
    void mostrarSaldo()const{
        cout<<fixed<<setprecision(2);
        cout<<"Resumen de la cuenta:\n";
        cout<<"Titular: "<<titular<<endl;
        cout<<"Numero de cuenta: "<<numeroCuenta<<endl;
        cout<<"Saldo actual: "<<saldo<<endl;
        cout<<"Retiros realizados hoy: "<<transaccionesDelDia<<" de 3 permitidos"<<endl;
    }
    void resetearTransacciones(){
        transaccionesDelDia=0;
    }
};
int main(){
    CuentaBancaria cuenta("Carlos Garcia",123456,500.00);
    cuenta.mostrarSaldo();
    cout<<endl;
    cuenta.depositar(200);
    cuenta.retirar(100);
    cuenta.retirar(250);
    cuenta.retirar(50);
    cuenta.retirar(20);
    return 0;
}