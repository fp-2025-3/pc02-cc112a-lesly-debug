#include<iostream>
#include<fstream>
using namespace std;
struct Venta{
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};
int main(){
    ifstream archivo;
    archivo.open("input/ventas.dat",ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return -1;
    }
    int numero;
    archivo.read((char*)&numero,sizeof(int));
    cout<<"Numero total de registros: "<<numero<<endl;
    Venta* v=new Venta[numero];
    archivo.read((char*)v,numero*sizeof(Venta));
    double suma=0;
    for(int i=0;i<numero;i++){
        suma=suma+((double)v[i].cantidad*v[i].precioUnitario);
    }
    cout<<"MONTO TOTAL VENDIDO:\nS/."<<suma<<endl;
    return 0;
}