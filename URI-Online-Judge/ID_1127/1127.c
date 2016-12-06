#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* preencheVetor(char* notas) {
    int* notasConvertidas = (int*) malloc(300001*sizeof(int));

    int i = 0;
    int j = 1;
    char nota = notas[i];
    char proximaNota;
    while (nota != '\0') {
        switch (nota) {
            case 'C':
                notasConvertidas[j] = 0;
                break;
            case 'D':
                notasConvertidas[j] = 2;
                break;
            case 'E':
                notasConvertidas[j] = 4;
                break;
            case 'F':
                notasConvertidas[j] = 5;
                break;
            case 'G':
                notasConvertidas[j] = 7;
                break;
            case 'A':
                notasConvertidas[j] = 9;
                break;
            case 'B':
                notasConvertidas[j] = 11;
                break;
        }
        proximaNota = notas[i+1];
        if (proximaNota == ' ') {
            i++;
        }
        if (proximaNota == 'b') {
            notasConvertidas[j]--;
            i = i + 2;
        }
        if (proximaNota == '#') {
            notasConvertidas[j]++;
            i = i + 2;
        }
        if (notasConvertidas[j] == 12) {
            notasConvertidas[j] = 0;
        }
        if (notasConvertidas[j] == -1) {
            notasConvertidas[j] = 11;
        }
        i++;
        j++;
        nota = notas[i];
    }
    return notasConvertidas;
}

char KMP_matcher(int distanciasMusica[300001], int distanciasTrecho[300001], int n, int m, int tabelaPrefixos[30001]) {
    int q = 0;
    int i = 1;
    for (; i<= n; i++) {
        while (q>0 && distanciasTrecho[q+1] != distanciasMusica[i]) {
            q = tabelaPrefixos[q];
        }
        if (distanciasTrecho[q+1] == distanciasMusica[i]) {
            q = q + 1;
        }
        if (q == m) {
            return 'S';
        }
    }
    return 'N';
}

int* computarPrefixo(int distanciasTrecho[300001], int m) {
    int* tabelaPrefixos = (int*) malloc(30001*sizeof(int));
    tabelaPrefixos[1] = 0;
    int k = 0;
    int q = 2;

    for (; q <= m; q++) {
        while (k > 0 && distanciasTrecho[k+1] != distanciasTrecho[q]) {
            k = tabelaPrefixos[k];
        }
        if (distanciasTrecho[k+1] == distanciasTrecho[q]) {
            k = k + 1;
        }
        tabelaPrefixos[q] = k;
    }
    return tabelaPrefixos;
}

int* calcularDistancias(int vetor[300001], int tamanho) {
    int *distancia = (int*) malloc(300001*sizeof(int));

    int i = 1;
    for (; i<tamanho; i++) {
        distancia[i] = vetor[i+1] - vetor[i];
        if (distancia[i] < 0){
            distancia[i] = distancia[i] + 12;
        }
    }

    return distancia;
}


int main() {
    int tamanhoMusica, tamanhoTrecho;
    int* notasMusicaFinal;
    int* notasTrechoFinal;
    int* tabelaPrefixos;
    int* distanciasMusica;
    int* distanciasTrecho;
    char entradaTamanho[20];

    char* notasMusica = (char*) malloc(300001*sizeof(char));
    char* notasTrecho = (char*) malloc(300001*sizeof(char));

    while (1) {
        fgets(entradaTamanho, 20, stdin);
        sscanf(entradaTamanho, "%d %d", &tamanhoMusica, &tamanhoTrecho);
        if (tamanhoMusica == 0 && tamanhoTrecho == 0) {
            free(notasMusica);
            free(notasTrecho);
            return 0;
        }
        fgets(notasMusica, 300001, stdin);
        fgets(notasTrecho, 300001, stdin);

        notasMusicaFinal = preencheVetor(notasMusica);
        notasTrechoFinal = preencheVetor(notasTrecho);

        distanciasMusica = calcularDistancias(notasMusicaFinal, tamanhoMusica);
        distanciasTrecho = calcularDistancias(notasTrechoFinal, tamanhoTrecho);
        tabelaPrefixos = computarPrefixo(distanciasTrecho, tamanhoTrecho-1);
        char resultado = KMP_matcher(distanciasMusica, distanciasTrecho, tamanhoMusica-1, tamanhoTrecho-1, tabelaPrefixos);
        printf("%c\n", resultado);  
        free(tabelaPrefixos);
        free(distanciasMusica);
        free(distanciasTrecho);
        free(notasMusicaFinal);
        free(notasTrechoFinal);
    }
    free(notasMusica);
    free(notasTrecho);

    return 0;
}