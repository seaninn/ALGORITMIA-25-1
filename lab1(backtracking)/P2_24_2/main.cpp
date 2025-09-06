#include <iostream>
#define N 4
#define M 5
using namespace std;

int productos[N]={2,3,1,4};
int ubicaciones[M]={3,2,5,1,3};
int solucion[M]{};
bool colocarProductos(int x) {
    if (x==N) {
        return true;
    }
    for (int i=0;i<M;i++) {
        if (ubicaciones[i]>=productos[x]) {
            solucion[i]+=productos[x];
            ubicaciones[i]-=productos[x];
            if (colocarProductos(x+1)) {
                return true;
            }
            solucion[i]-=productos[x];
            ubicaciones[i]+=productos[x];
        }
    }
    return false;
}
void colocarProductos2(int x) {
    if (x==N) {
        for (int i=0;i<M;i++) {
            cout<<solucion[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for (int i=0;i<M;i++) {
        if (ubicaciones[i]>=productos[x]) {
            solucion[i]+=productos[x];
            ubicaciones[i]-=productos[x];
            colocarProductos2(x+1);
            solucion[i]-=productos[x];
            ubicaciones[i]+=productos[x];
        }
    }
}
int main() {
    //pregunta 1: imprimir una sola solucion
    // if (colocarProductos(0)) {
    //     for (int i = 0; i < M; i++) {cout<<solucion[i]<<' ';}
    // }
    // cout<<endl;
    colocarProductos2(0);
    return 0;
}