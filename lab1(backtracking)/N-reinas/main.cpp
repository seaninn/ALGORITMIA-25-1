#include <iostream>
#define M 8
using namespace std;
void imprimirTablero(int tablero[][8],int m) {
    static int i=1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout<<tablero[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"Solucion: "<<i<<endl;
    i++;
    cout<<"----------------------------------------------------"<<endl;
}
bool analizaVertical(int tablero [][8],int x,int y) {
    if (y==M)return true;
    if (tablero[x][y]==1) return false;
    return analizaVertical(tablero,x,y+1);
}
bool analizaHorizontal(int tablero [][8],int y,int x) {
    if (x==M)return true;
    if (tablero[x][y]==1) return false;
    return analizaHorizontal(tablero,y,x+1);
}
bool analizaDiagonalIzq(int tablero[][8],int y,int x) {
    for (int i=x, j=y;i>=0 and j>=0;i--,j--) {
        if (tablero[i][j]==1) return false;
    }
    for (int i=x, j=y;i<M and j<M;i++,j++) {
        if (tablero[i][j]==1) return false;
    }
    return true;
}
bool analizaDiagonalDer(int tablero[][8],int y,int x) {
    for (int i=x, j=y;i<M and j>=0;i++,j--) {
        if (tablero[i][j]==1) return false;
    }
    for (int i=x, j=y;i>=0 and j<M;i--,j++) {
        if (tablero[i][j]==1) return false;
    }
    return true;
}
bool esSeguro(int tablero [][8], int y,int x) {
    if (analizaVertical(tablero,x,0)) {
        if (analizaHorizontal(tablero,y,0)) {
            if (analizaDiagonalIzq(tablero,y,x)) {
                if (analizaDiagonalDer(tablero,y,x)) {
                    return true;
                }
            }
        }
    }
    return false;
}
void colocarReina(int tablero[][M],int posx,int lim) {
    if (posx==lim) {imprimirTablero(tablero,lim);return;}
    for (int i=0;i<lim;i++) {
        if (esSeguro(tablero,i,posx)) {
            tablero[posx][i]=1;
            colocarReina(tablero,posx+1,lim);
            tablero[posx][i]=0;
        }
    }
}
int main() {
    int tablero[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    imprimirTablero(tablero,M);
    colocarReina(tablero,0,M);
    return 0;
}