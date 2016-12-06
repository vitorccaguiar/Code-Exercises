#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DFS(int grafo[101][101], int indice, int quantidadeCidades, char vertices[101][6]) {
    int i;
    strcpy(vertices[indice], "GRAY");
    for (i = 0; i < quantidadeCidades; i++) {
        if(grafo[indice][i] == 1 && strcmp(vertices[i], "WHITE") == 0) {
            DFS(grafo, i, quantidadeCidades, vertices);
        }
    } 
}

void verificaRotas(int grafo[101][101], int numeroCidades, char vertices[101][6]) {
    int count = 0;
    int i;
    for (i = 0; i < numeroCidades; i++) {
        if (strcmp(vertices[i], "WHITE") == 0) {
            DFS(grafo, i, numeroCidades, vertices);
            count++;
        }
    }
    printf("%d\n", !count ? count : count-1);
}

int main() {
    int numeroTestes;
    int numeroCidades, numeroRotas;

    int arestas[101][101];
    char vertices[101][6];
    scanf("%d", &numeroTestes);
    int i = 0;
    while (i < numeroTestes) {
        scanf("%d %d", &numeroCidades, &numeroRotas);
        int k, j;
        for (k = 0; k < numeroCidades; k++) {
            for (j = 0; j < numeroCidades; j++) {
                arestas[k][j] = 1;
            }
        }

        k = 0;
        while (k < numeroRotas) {
            int x, y;
            scanf("%d %d", &x, &y);
            arestas[x][y] = 0;
            arestas[y][x] = 0;
            k++;
        }
        k = 0;
        while (k < numeroCidades) {
            strcpy(vertices[k], "WHITE");
            k++;
        }
        verificaRotas(arestas, numeroCidades, vertices);
        i++;
    }
    
    return 0;
}