#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    ifstream archivoEntrada("input/notas.txt");
    if(!archivoEntrada){
        cerr<<"Error al abrir el archivo notas.txt\n";
        return 1;
    }
    ofstream archivoSalida("output/reporte.txt");
    if(!archivoSalida){
        cerr<<"Error al crear el archivo reporte.txt\n";
        return 1;
    }
    double nota;
    int contarNotas=0;
    double suma=0.0;
    double mayorNota=0,menorNota=0;
    int aprobados=0,desaprobados=0;
    while(archivoEntrada>>nota){
        contarNotas=contarNotas+1;
        suma=suma+nota;
        if(contarNotas==1){
            mayorNota=menorNota=nota;
        }else{
            if(nota>mayorNota){
                mayorNota=nota;
            }
            if(nota<menorNota){
                menorNota=nota;
            }
        }
        if(nota>=10){
            aprobados=aprobados+1;
        }else{
            desaprobados=desaprobados+1;
        }
    }
    if(contarNotas==0){
        cout<<"El archivo esta vacio.\n";
        return 1;
    }
    double promedio=suma/contarNotas;
    archivoSalida<<"REPORTE GENERAL"<<endl;
    archivoSalida<<"------------------------"<<endl;
    archivoSalida<<"Total de estudiantes: "<<contarNotas<<endl;
    archivoSalida<<"Promedio: "<<promedio<<endl;
    archivoSalida<<"Mayor nota: "<<mayorNota<<endl;
    archivoSalida<<"Menor nota: "<<menorNota<<endl;
    archivoSalida<<"Aprobados: "<<aprobados<<endl;
    archivoSalida<<"Desaprobados: "<<desaprobados<<endl;
    archivoEntrada.close();
    archivoSalida.close();
}