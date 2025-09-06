#include <iostream>
using namespace std;
int sudoku[9][9] = {
    {0, 2, 0, 0, 0, 0, 0, 9, 0},
    {3, 0, 1, 9, 0, 6, 5, 0, 2},
    {0, 0, 0, 8, 0, 4, 0, 0, 0},
    {0, 9, 0, 0, 0, 0, 0, 5, 0},
    {5, 0, 0, 2, 0, 3, 0, 0, 6},
    {0, 7, 0, 0, 0, 0, 0, 2, 0},
    {0, 0, 0, 4, 0, 7, 0, 0, 0},
    {8, 0, 2, 5, 0, 1, 7, 0, 3},
    {0, 5, 0, 0, 0, 0, 0, 8, 0}
};
void imprimirTablero() {
    int ver=0;
    int hor=1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout<<sudoku[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"------------------------------------------"<<endl;
}
bool esTableroLleno() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) return false;
        }
    }
    return true;
}
bool esSeguroColocar(int x,int y,int num) {
    for (int i = 0; i < 9; i++) {
        if (i==y)continue;
        if (sudoku[x][i]==num) return false;
    }
    for (int i=0;i<9;i++) {
        if (i==x)continue;
        if (sudoku[i][y]==num) return false;
    }
    int bloqueFila = 3 * (x / 3);
    int bloqueColumna = 3 * (y / 3);

    for (int i = bloqueFila; i < bloqueFila + 3; i++) {
        for (int j = bloqueColumna; j < bloqueColumna + 3; j++) {
            if (i == x && j == y) continue; // Saltar la celda actual
            if (sudoku[i][j] == num) return false;
        }
    }
    return true;
}

bool rellenarSudoku(int x ,int y) {
    if (x==9) {
        imprimirTablero();
        return true;
    }
    if (sudoku[x][y]!=0) {
        if (y==8) {
            return rellenarSudoku(x+1,0);
        }else {
            return rellenarSudoku(x,y+1);
        }
    }else {
        bool solucion;
        for (int i=1; i<=9; i++) {
            if (esSeguroColocar(x,y,i)) {
                sudoku[x][y]=i;
                if (y==8) {
                    solucion=rellenarSudoku(x+1,0);
                }else {
                    solucion=rellenarSudoku(x,y+1);
                }
                if (solucion)return true;
                sudoku[x][y]=0;
            }
        }
    }
    return false;
}
int main() {
    if (rellenarSudoku(0,0)){cout<<"AHI TIENES TU SOLUCION"<<endl;}
    return 0;
}