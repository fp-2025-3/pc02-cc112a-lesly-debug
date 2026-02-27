#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(){
    ofstream archivo;
    archivo.open("grafico.txt");
    for(int i=0;i<22;i++){
        for(int j=0;j<81;j++){
            if(j==0){
                archivo<<"|"<<endl;
            }
            if(i==10){
                archivo<<"-";
            }
        }
    }
    return 0;
}