#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DFS(int grafo[60][60], int indice, int quantidadeCidades, char vertices[60][6], int *count) {
    int i;
    strcpy(vertices[indice], "GRAY");
    for (i = 1; i <= quantidadeCidades; i++) {
        if(grafo[indice][i] == 1 && strcmp(vertices[i], "WHITE") == 0) {
            *count = *count + 1;
            DFS(grafo, i, quantidadeCidades, vertices, count);
        }
    } 
    strcpy(vertices[indice], "BLACK");
}

void verificaPontes(int grafo[60][60], int quantidadeCidades, char vertices[60][6]) {
    int *count = (int*)malloc(sizeof(int));
    *count = 0;
    int numeroPontes = 0;
    int i, j;
    for (i = 1; i <= quantidadeCidades; i++) {
        for (j = 1; j <= quantidadeCidades; j++) {
            if (grafo[i][j] == 1) {
                grafo[i][j] = 0;
                grafo[j][i] = 0;
                *count = *count + 1;
                DFS(grafo, 1, quantidadeCidades, vertices, count);
                if (*count != quantidadeCidades) {
                    numeroPontes++;
                }
                grafo[i][j] = 1;
                grafo[j][i] = 1;
                *count = 0;
                int k = 0;
                while (k <= quantidadeCidades) {
                    strcpy(vertices[k], "WHITE");
                    k++;
                }
            }
        }
    }
    printf("%d\n", numeroPontes/2);
    free(count);
}

int main() {
    int quantidadeCidades;
    int quantidadePontes;
    
    scanf("%d %d", &quantidadeCidades, &quantidadePontes);
    while (!feof(stdin)) {
        int arestas[60][60];
        char vertices[60][6];
        // Inicializa grafo
        int i, j;
        for (i = 0; i <= quantidadeCidades; i++) {
            for (j = 0; j <= quantidadeCidades; j++) {
                arestas[i][j] = 0;
            }
        }
        i = 0;
        // Constroi grafo
        while (i < quantidadePontes) {
            int x, y;
            scanf("%d %d", &x, &y);
            arestas[x][y] = 1;
            arestas[y][x] = 1;
            strcpy(vertices[x], "WHITE");
            strcpy(vertices[y], "WHITE");
            i++;
        }   
        
        verificaPontes(arestas, quantidadeCidades, vertices);
        scanf("%d %d", &quantidadeCidades, &quantidadePontes);

    }

    return 0;
}
