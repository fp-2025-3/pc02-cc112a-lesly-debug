#include<iostream>
#include<fstream>
using namespace std;
int my_strcmp(const char* a,const char* b){
    while(*a!='\0'&&*b!='\0'&&*a==*b){
        a=a+1;
        b=b+1;
    }
    return *a-*b;
}
int my_strlen(const char* cadena){
    int contador=0;
    while(*cadena!='\0'){
        contador=contador+1;
        cadena=cadena+1;
    }
    return contador;
}
int main(){
    ifstream i1("input/input1.txt");
    ifstream i2("input/input2.txt");
    if(!i1||!i2){
        cerr<<"Error al abrir el archivo.\n";
        return 1;
    }
    char linea1[101];
    char linea2[101];
    int linea=0;
    while(i1.getline(linea1,101)){
        if(i2.getline(linea2,101)){
            if(my_strcmp(linea1,linea2)!=0){
                int columna=-1;
                int i=0;
                while(i<my_strlen(linea1)&&i<my_strlen(linea2)&&columna==-1){
                    if(linea1[i]!=linea2[i]){
                        columna=i;
                    }
                    i=i+1;
                }
                if(columna==-1){
                    if(my_strlen(linea1)>my_strlen(linea2)){
                        columna=my_strlen(linea2);
                    }else if(my_strlen(linea2)>my_strlen(linea1)){
                        columna=my_strlen(linea1);
                    }
                }
                cout<<"Diferencia en la linea "<<linea<<" columna "<<columna<<endl;
            }
        }else{
            cout<<"Diferencia en la linea "<<linea<<" columna 0"<<endl;
        }
        linea=linea+1;
    }
    return 0;
}