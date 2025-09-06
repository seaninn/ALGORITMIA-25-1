#include <iostream>
#define M 8
using namespace std;

int tablero[M][M]{};
int movimientos[8][2]={{-1,-1},{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1}};
void imprimir() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}
bool esPosibleMoverse(int x,int y) {
    if (x>=0 and x<M and y>=0 and y<M) {
        if (tablero[x][y]!=0)return false;
        else return true;
    }
    return false;
}
bool movimientoDelRey(int x,int y,int num) {
    if (num==M*M) {
        tablero[x][y]=num;
        return true;
    }
    for (int i=0; i<M; i++) {
        int n_x=movimientos[i][0]+x;
        int n_y=movimientos[i][1]+y;
        if (esPosibleMoverse(n_x,n_y)) {
            tablero[x][y]=num;
            if (movimientoDelRey(n_x,n_y,num+1)) {
                return true;
            }
            tablero[x][y]=0;
        }
    }
    return false;
}
int main() {
    if (movimientoDelRey(4,4,1))imprimir();
    else cout<<"NO HAY SOLUCION"<<endl;
    return 0;
}