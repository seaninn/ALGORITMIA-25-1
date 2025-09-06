#include <iostream>
#include <vector>
using namespace std;
int main() {
    for (int i=0;i<5;i++) {
        vector <bool> solucion=buscarSolucion(i);
        for (int j=0;j<solucion.size();j++) {
            if (solucion[j]==true) {
                cout<<"R"<<i+1<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}