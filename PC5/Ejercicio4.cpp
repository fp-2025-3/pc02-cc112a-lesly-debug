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
    archivo.open("ventas.dat",ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return -1;
    }
    Venta venta;
    int numero=0;
    while(archivo.read((char*)&venta,sizeof(Venta))){
        numero=numero+1;
    }
    Venta ventas;
    double montoTotal=0;
    const int MAX=1000;
    double totalVendedor[MAX]={0};
    int totalProducto[MAX]={0};
    archivo.clear();
    archivo.seekg(0);
    while(archivo.read((char*)&ventas,sizeof(Venta))){
        montoTotal=montoTotal+(ventas.cantidad*ventas.precioUnitario);
        totalVendedor[ventas.idVendedor]=totalVendedor[ventas.idVendedor]+(ventas.cantidad*ventas.precioUnitario);
        totalProducto[ventas.idProducto]=totalProducto[ventas.idProducto]+ventas.cantidad;
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
    archivo.clear();
    archivo.seekg(0);
    while(archivo.read((char*)&ventas,sizeof(Venta))){
        if(ventas.cantidad>100){
            reporte<<"ID Venta: "<<ventas.idVenta<<" | ID Vendedor: "<<ventas.idVendedor<<" | ID Producto: "<<ventas.idProducto<<" | Cantidad: "<<ventas.cantidad<<endl;
        }
    }
    archivo.close();
    reporte.close();
    return 0;
}