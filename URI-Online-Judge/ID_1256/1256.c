#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int quantidadeTestes;
    int tamanhoEnderecos;
    int tamanhoChaves;

    scanf("%d", &quantidadeTestes);
    while (quantidadeTestes > 0) {
        scanf("%d %d", &tamanhoEnderecos, &tamanhoChaves);
        int chaves[tamanhoChaves];
        int colisoes[tamanhoEnderecos][tamanhoChaves];
        // Inicializando matriz colisoes
        int x = 0;
        int y;
        for (; x < tamanhoEnderecos; x++) {
            y=0;
            for (; y < tamanhoChaves; y++) {
                colisoes[x][y] = -1;
            }
        }
        int tabela[tamanhoEnderecos][1];
        // Inicializando matriz tabela
        x = 0;
        for (; x < tamanhoEnderecos; x++) {
            y = 0;
            for (; y < 1; y++) {
                tabela[x][y] = -1;
            }
        }
        // Armazenando chaves
        int i = 0;
        for (; i < tamanhoChaves; i++) {
            scanf("%d", &chaves[i]);
        }
        // Hashing
        i=0;
        for (; i < tamanhoChaves; i++) {
            int posicao = chaves[i]%tamanhoEnderecos;
    
            if (tabela[posicao][0] == -1) {
                tabela[posicao][0] = chaves[i];
            }else {
                int j = 0;
                while (colisoes[posicao][j] != -1) {
                    j++;
                }
                colisoes[posicao][j] = chaves[i];
            }
        }
        // Saida
        i=0;
        for (; i<tamanhoEnderecos; i++) {
            // Imprime indice
            printf("%d -> ", i);
            // Se nao tiver na tabela
            if (tabela[i][0] == -1) {
                // Se for o ultimo endereco e nao for o ultimo teste
                if (i == tamanhoEnderecos-1 && quantidadeTestes-1 != 0) {
                    printf("\\\n\n");
                }else {
                    printf("\\\n");
                }
            }else {
                // Imprime endereco da tabela
                printf("%d -> ", tabela[i][0]);
                int j = 0;
                // Procura por colisoes
                while (colisoes[i][j] != -1 && j<tamanhoChaves) {
                    printf("%d -> ", colisoes[i][j]);
                    j++;
                }
                // Se for o ultimo endereco e nao for o ultimo teste
                if (i == tamanhoEnderecos-1 && quantidadeTestes-1 != 0) {
                    printf("\\\n\n");
                }else {
                    printf("\\\n");
                }
            }
        }
        quantidadeTestes--;
    }
    return 0;
}
