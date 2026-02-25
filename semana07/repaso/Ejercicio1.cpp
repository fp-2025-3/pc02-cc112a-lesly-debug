#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file1,file2;
    file1.open("input/archivo1.txt");
    file2.open("input/archivo2.txt");
    if(!file1){
        cerr<<"Error al abrir el archivo 1\n";
        return 1;
    }
    if(!file2){
        cerr<<"Error al abrir el archivo 2\n";
        return 1;
    }
    int dato1,dato2;
    file1>>dato1;
    file2>>dato2;
    ofstream file3;
    file3.open("output/nombreM");
    if(!file3){
        cerr<<"Error al crear el archivo.\n";
        return 1;
    }
    while(dato1!=-1&&dato2!=-1){
        if(dato1<dato2){
            file3<<dato1;
            file1>>dato1;
        }else{
            file3<<dato2;
            file2>>dato2;
        }
    }
    while(dato1!=-1){
        file3<<dato1;
        file1>>dato1;
    }
    while(dato2!=-1){
        file3<<dato2;
        file2>>dato2;
    }
    file1.close();
    file2.close();
    file3.close();
    return 0;
}