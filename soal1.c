/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 5
 *   Hari dan Tanggal    : Senin, 11 Mei 2026
 *   Nama (NIM)          : Celvin Ello X. Silitonga (13224107)
 *   Nama File           : tunnelmap.c
 *   Deskripsi           : Program memiliki beberapa fitur, yakni 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_MAX 10


void addEdge(int mat[N_MAX][N_MAX], int i, int j);
void displayMatrix(int mat[N_MAX][N_MAX], int* length);
void loadMatrix(int mat[N_MAX][N_MAX], int* num);

int main(void){
    int tunnel[N_MAX][N_MAX];
    int length;

    loadMatrix(tunnel, &length);
    displayMatrix(tunnel, &length);
    
    return 0;
}

void addEdge(int mat[N_MAX][N_MAX], int i, int j) {
    mat[i][j] = 1;
    mat[j][i] = 1; // Since the graph is undirected
}

void loadMatrix(int mat[N_MAX][N_MAX], int* num){
    scanf("%d ", num);

    for (int i = 0; i < *num; i++)
    {
        for (int j = 0; j < *num; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

/**void displayMatrix(int mat[N_MAX][N_MAX], int* length) {

    for (int row = 0; row < *length; row++)
    {
        printf("DEGREE %d ", row);
        int degree=0;
        for (int col = 0; col < *length; col++)
        {
            if(mat[row][col]==1){
                degree++;
            }
        }
        printf("%d\n", degree);
    }
}*/

void displayMatrix(int mat[N_MAX][N_MAX], int* length) {
    int max_vertex;
    int isolated[N_MAX];
    int numOfIsolated=0;

    int max_degree = 0;
    for (int row = 0; row < *length; row++)
    {
        printf("DEGREE %d ", row);
        int degree=0;
        for (int col = 0; col < *length; col++)
        {
            if(mat[row][col]==1){
                degree++;
            }
        }
        printf("%d\n", degree);

        //check max degree of each vertex
        if(degree>max_degree){
            max_degree = degree;
            max_vertex = row;
        }

        if(degree==0){
            isolated[numOfIsolated++] = row; //masukkan data isolated nodes
        }
    }

    printf("MAX_VERTEX %d\n", max_vertex);

    printf("ISOLATED ");
    if(numOfIsolated==0){ //jikalaut tidak ada isolated
        printf("NONE\n");
    } else{
        for (int i = 0; i < numOfIsolated; i++)
        {
            printf("%d", isolated[i]);
            if(i<numOfIsolated-1) printf(" ");
        }
    }

    
}
