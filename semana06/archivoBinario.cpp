#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream out("datos.dat",ios::binary);
    if(!out.is_open()){
        cout<<"Error al crear el archivo.\n";
        return 1;
    }
    int num=10;
    out.write(reinterpret_cast<char*>(&num),sizeof(num));
    out.close();
    cout<<"Dato escrito correctamente en el archivo binario.\n";
    ifstream in("datos.dat",ios::binary);
    if(!in.is_open()){
        cout<<"Error al abrir el archivo.\n";
        return 1;
    }
    int numeroLeido;
    in.read(reinterpret_cast<char*>(&numeroLeido),sizeof(numeroLeido));
    in.close();
    cout<<"Dato leido desde el archivo: "<<numeroLeido<<endl;
    return 0;
}