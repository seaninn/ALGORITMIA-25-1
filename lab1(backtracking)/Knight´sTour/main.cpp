#include <iomanip>
#include <iostream>
#define M 7
using namespace std;
int tablero[M][M]{};
int movimientos[8][2]={{2,1},{2,-1},{-2,-1},{-2,1},{1,2},{1,-2},{-1,-2},{-1,2}};
bool solucion=false;
void imprimirTablero() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(2) << tablero[i][j] << " ";
        }
        cout << endl;
    }

    cout << "--------------" << endl;
}
bool esTableroLleno() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (tablero[i][j] == 0) return false;
        }
    }
    return true;
}
bool mePuedoMover(int x,int y) {
    //Si me puedo mover
    //cout<<"x: "<<x<<" y: "<<y<<endl;
    return (x >= 0 && x < M && y >= 0 && y < M && tablero[x][y] == 0);

}
void recorridoCaballo(int x,int y,int num) {
    tablero[x][y]=num;
    if (num==M*M) {
        imprimirTablero();
        solucion=true;
        return;
    }
    for (int i=0;i<8;i++) {
        int n_x=x+movimientos[i][0];
        int n_y=y+movimientos[i][1];
        if (mePuedoMover(n_x,n_y) and !solucion) {
            recorridoCaballo(n_x,n_y,num+1);
        }
    }
    if (!solucion) {
        tablero[x][y]=0;
    }

}
int main() {
    recorridoCaballo(0,0,1);
    return 0;
}