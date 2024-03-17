#include <stdio.h>
// M ALIEF ALFARIDZI

#define SIZE 8

void koboImaginaryChess(int i, int j, int (*chessBoard)[SIZE]){
    // Inisialisasi array dengan nilai 0
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            chessBoard[x][y] = 0;
        }
    }
    
    // Pergerakan bidak kuda
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    // Menandai posisi yang dapat dicapai oleh bidak kuda
    for(int k = 0; k < 8; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        
        if(x >= 0 && x < SIZE && y >= 0 && y < SIZE){
            chessBoard[x][y] = 1;
        }
    }
}

int main(){
    int i, j;
    scanf("%d %d", &i, &j);
    
    int chessBoard[SIZE][SIZE];
    
    koboImaginaryChess(i, j, chessBoard);
    
    // Menampilkan hasil simulasi
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            printf("%d", chessBoard[x][y]);
        }
        printf("\n");
    }
    
    return 0;
}