#include<iostream>
#include<fstream>
#include<iomanip>
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
    Venta* ventas=new Venta[numero];
    archivo.read((char*)ventas,numero*sizeof(Venta));
    double montoTotal=0;
    const int MAX=1000;
    double totalVendedor[MAX]={0};
    int totalProducto[MAX]={0};
    for(int i=0;i<numero;i++){
        montoTotal=montoTotal+(ventas[i].cantidad*ventas[i].precioUnitario);
        totalVendedor[ventas[i].idVendedor]=totalVendedor[ventas[i].idVendedor]+(ventas[i].cantidad*ventas[i].precioUnitario);
        totalProducto[ventas[i].idProducto]=totalProducto[ventas[i].idProducto]+ventas[i].cantidad;
    }
    int mejorVendedor=-1;
    double mayorMonto=0;
    for(int i=0;i<MAX;i++) {
        if(totalVendedor[i]>mayorMonto) {
            mayorMonto=totalVendedor[i];
            mejorVendedor=i;
        }
    }
    int mejorProducto=-1;
    int mayorCantidad=0;
    for(int i=0;i<MAX;i++) {
        if(totalProducto[i]>mayorCantidad) {
            mayorCantidad=totalProducto[i];
            mejorProducto=i;
        }
    }
    ofstream reporte("reporte.txt");
    reporte<<fixed<<setprecision(2);
    reporte<<"--- REPORTE GENERAL DE VENTAS ----"<<endl;
    reporte<<"Total de registros: "<<numero<<endl;
    reporte<<"MONTO TOTAL VENDIDO:"<<endl;
    reporte<<"S/. " <<montoTotal<<endl;
    reporte<<"---------------------------------------"<<endl;
    reporte<<"VENDEDOR CON MAYOR RECAUDACIÓN:"<<endl;
    reporte<<"ID Vendedor: "<<mejorVendedor<<endl;
    reporte<<"Total vendido: S/. "<<mayorMonto<<endl;
    reporte<<"---------------------------------------"<<endl;
    reporte<<"PRODUCTO MÁS VENDIDO:\n";
    reporte<<"ID Producto: "<<mejorProducto<<endl;
    reporte<<"Total unidades: "<<mayorCantidad<<endl;
    reporte<<"---------------------------------------"<<endl;
    reporte<<"VENTAS SOSPECHOSAS (cantidad>100):"<<endl;
    for(int i=0;i<numero;i++){
        if(ventas[i].cantidad>100){
            reporte<<"ID Venta: "<<ventas[i].idVenta<<" | ID Vendedor: "<<ventas[i].idVendedor<<" | ID Producto: "<<ventas[i].idProducto<<" | Cantidad: "<<ventas[i].cantidad<<endl;
        }
    }
    archivo.close();
    delete[] ventas;
    return 0;
}