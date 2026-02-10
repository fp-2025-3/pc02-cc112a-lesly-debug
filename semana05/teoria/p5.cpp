#include<iostream>
#include<string>
using namespace std;
struct Direccion{
    string calle;
    string ciudad;
    string pais;
};
struct Cliente{
    string nombre;
    char* numero;
    Direccion d;
};
int main(){
    Cliente c1;
    cout<<"===Registro del cliente===\n";
    cout<<"Nombre: ";
    getline(cin,c1.nombre);
    cout<<"Numero: ";
    c1.numero=new char[10];
    cin>>c1.numero;
    cin.ignore();
    cout<<"Direccion"<<endl;
    cout<<"Calle: ";
    getline(cin,c1.d.calle);
    cout<<"Ciudad: ";
    getline(cin,c1.d.ciudad);
    cout<<"Pais: ";
    getline(cin,c1.d.pais);
    cout<<"Direccion completa:"<<endl;
    cout<<c1.d.calle<<", "<<c1.d.ciudad<<", "<<c1.d.pais;
    delete[] c1.numero;
    return 0;
}