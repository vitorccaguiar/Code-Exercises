#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numeroLinhas;
    int numeroColunas;
    int numeroMinas;
    int totalCobertos;
    int posX,posY;

    scanf("%d %d %d\n", &numeroLinhas, &numeroColunas, &numeroMinas);

    while (numeroLinhas != 0 && numeroColunas != 0 && numeroMinas != 0) {
        int countMina = 0;
        char campo[numeroLinhas][numeroColunas];
        char matrizFinal[numeroLinhas][numeroColunas];
        memset(campo, 0, sizeof(char) * numeroLinhas * numeroColunas);
        memset(matrizFinal, 0, sizeof(char) * numeroLinhas * numeroColunas);
        totalCobertos = 0;

        // Preenchendo campo
        int i = 0;
        while (i < numeroLinhas) {
            int j = 0;
            while (j < numeroColunas) {
                scanf("%c", &campo[i][j]);
                if (campo[i][j] == '.') {
                    totalCobertos++;
                }
                matrizFinal[i][j] = campo[i][j];
                j++;
            }
            scanf("\n");
            i++;
        }

        i = 0;
        while (i < numeroMinas) {
            scanf("%d %d\n", &posX, &posY);
            matrizFinal[(posX - 1)][posY - 1] = '*';
            i++;
        } 

        // Analisando campo
        int dica;
        int mudou = 1;
        while (mudou == 1) {
            mudou = 0;
            i = 0;
            while (i < numeroLinhas) {
                int j = 0;
                while (j < numeroColunas) {
                    // . = coberto
                    // * = mina
                    if (campo[i][j] != '.' && campo[i][j] != '*') {
                        int numeroCoberto = 0;
                        int numeroSinalizado = 0;
                        int indices[8][2];
                        int x;
                        x = 0;
                        if (i-1 >= 0 && j-1 >= 0) {
                            if (campo[i-1][j-1] == '.') {
                                numeroCoberto++;
                                indices[x][0] = i-1;
                                indices[x][1] = j-1;
                                x++;
                            }
                            if (campo[i-1][j-1] == '*') {
                                numeroSinalizado++;
                            }
                        }
                        if (i-1 >= 0) {
                            if (campo[i-1][j] == '.') {
                                numeroCoberto++;
                                indices[x][0] = i-1;
                                indices[x][1] = j;
                                x++;
                            }
                            if (campo[i-1][j] == '*') {
                                numeroSinalizado++;
                            }
                        }
                        if (i-1 >= 0 && j+1 < numeroColunas) {
                            if (campo[i-1][j+1] == '.') {
                                numeroCoberto++;
                                indices[x][0] = i-1;
                                indices[x][1] = j+1;
                                x++;
                            }
                            if (campo[i-1][j+1] == '*') {
                                numeroSinalizado++;
                            }
                        }
                        if (j-1 >= 0) {
                            if (campo[i][j-1] == '.') {
                                numeroCoberto++;
                                indices[x][0] = i;
                                indices[x][1] = j-1;
                                x++;
                            }
                            if (campo[i][j-1] == '*') {
                                numeroSinalizado++;
                            }
                        }
                        if (j+1 < numeroColunas) {
                            if (campo[i][j+1] == '.') {
                                indices[x][0] = i;
                                indices[x][1] = j+1;
                                x++;
                                numeroCoberto++;
                            }
                            if (campo[i][j+1] == '*') {
                                numeroSinalizado++;
                            }
                        }
                        if (i+1 < numeroLinhas && j-1 >= 0) {
                            if (campo[i+1][j-1] == '.') {
                                indices[x][0] = i+1;
                                indices[x][1] = j-1;
                                x++;
                                numeroCoberto++;
                            }
                            if (campo[i+1][j-1] == '*') {
                                numeroSinalizado++;
                            }
                        }
                        if (i+1 < numeroLinhas) {
                            if (campo[i+1][j] == '.') {
                                indices[x][0] = i+1;
                                indices[x][1] = j;
                                x++;
                                numeroCoberto++;
                            }
                            if (campo[i+1][j] == '*') {
                                numeroSinalizado++;
                            }
                        }
                        if (i+1 < numeroLinhas && j+1 < numeroColunas) {
                            if (campo[i+1][j+1] == '.') {
                                indices[x][0] = i+1;
                                indices[x][1] = j+1;
                                x++;
                                numeroCoberto++;
                            }
                            if (campo[i+1][j+1] == '*') {
                                numeroSinalizado++;
                            }
                        }
                        dica = campo[i][j] - '0';
                        // Verifica condicoes
                        if (numeroCoberto + numeroSinalizado == dica) {
                            if (numeroCoberto > 0) {
                                mudou = 1;
                            }
                            int count = 0;
                            for (; count < numeroCoberto; count++) {
                                campo[indices[count][0]][indices[count][1]] = '*';
                            }
                        }else {
                            if (numeroSinalizado == dica) {
                                if (numeroCoberto > 0) {
                                    mudou = 1;
                                }
                                int count = 0;
                                for (; count < numeroCoberto; count++) {
                                    int a = indices[count][0];
                                    int b = indices[count][1];
                                    int valor = 0;
                                    if (a-1 >= 0 && b-1 >= 0) {
                                        if (matrizFinal[a-1][b-1] == '*') {
                                            valor++;
                                        }
                                    }
                                    if (a-1 >= 0) {
                                        if (matrizFinal[a-1][b] == '*') {
                                            valor++;
                                        }
                                    }
                                    if (a-1 >= 0 && b+1 < numeroColunas) {
                                        if (matrizFinal[a-1][b+1] == '*') {
                                            valor++;
                                        }
                                    }
                                    if (b-1 >= 0) {
                                        if (matrizFinal[a][b-1] == '*') {
                                            valor++;
                                        }
                                    }
                                    if (b+1 < numeroColunas) {
                                        if (matrizFinal[a][b+1] == '*') {
                                            valor++;
                                        }
                                    }
                                    if (a+1 < numeroLinhas && b-1 >= 0) {
                                        if (matrizFinal[a+1][b-1] == '*') {
                                            valor++;
                                        }
                                    }
                                    if (a+1 < numeroLinhas) {
                                        if (matrizFinal[a+1][b] == '*') {
                                            valor++;
                                        }
                                    }
                                    if (a+1 < numeroLinhas && b+1 < numeroColunas) {
                                        if (matrizFinal[a+1][b+1] == '*') {
                                            valor++;
                                        }
                                    }
                                    campo[a][b] = valor + '0';
                                }
                            }else {

                            }
                        }
                        j++;
                    }else {
                        j++;
                    }
                }
                i++;
            }
        }

        i = 0;
        for (; i < numeroLinhas; i++) {
            int j = 0;
            for (; j < numeroColunas; j++) {
                if (campo[i][j] == '*') {
                    countMina++;
                }
            }
        }
        if (countMina == numeroMinas) {
            printf("Possivel\n");
        }else {
            printf("Impossivel\n");
        }

        scanf("%d %d %d\n", &numeroLinhas, &numeroColunas, &numeroMinas);
    }
    return 0;
}