#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula *Apontador;

typedef struct Celula {
    int dado;
    Apontador Prox;
}TCelula;

typedef struct {
    Apontador Fundo;
    Apontador Topo;
    int Tamanho;
}TPilha;

typedef struct {
    Apontador Frente;
    Apontador Tras;
}TFila;

int compar(const void* p1, const void* p2) {
    if (*(int*)p1 < *(int*)p2) {
        return -1;
    }else {
        return 1;
    }
}

void FPVazia(TPilha *Pilha) {
    Pilha->Topo = malloc(sizeof(TCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
} 

int VaziaP(TPilha Pilha) {
    return (Pilha.Topo == Pilha.Fundo);
} 

void Empilha(int x, TPilha *Pilha) {
    Apontador Aux = malloc(sizeof(TCelula));
    Pilha->Topo->dado = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
} 

int Desempilha(TPilha *Pilha) {
    int dado;
    if (VaziaP(*Pilha)) {
        return 0;
    }
    Apontador q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    dado = q->Prox->dado;
    free(q);
    Pilha->Tamanho--;
    return dado;
} 

void FFVazia(TFila *Fila) {
    Fila->Frente = malloc(sizeof(TCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
} 

int VaziaF(TFila Fila) {
    return (Fila.Frente == Fila.Tras);
} 

void Enfileira(int x, TFila *Fila) {
    Fila->Tras->Prox = malloc(sizeof(TCelula));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->dado = x;
    Fila->Tras->Prox = NULL;
} 

int Desenfileira(TFila *Fila) {
    int dado;
    if (VaziaF(*Fila)) {
        return 0;
    }
    Apontador q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    dado = Fila->Frente->dado;
    free(q);
    return dado;
} 

int main() {
    int tamanhoOperacoes;
    int operacao;
    int resultado;
    int flagPilha;
    int flagFila;
    int flagFilaP;

    scanf("%d", &tamanhoOperacoes);
    while (!feof(stdin)) {
        TPilha *pilha = (TPilha*) malloc(sizeof(TPilha));
        TFila *fila = (TFila*) malloc(sizeof(TFila));
        int filaP[1000];
        int tamanhoFilaP = 0;
        FPVazia(pilha);
        FFVazia(fila);
        flagPilha = 1;
        flagFila = 1;
        flagFilaP = 1;

        int i = 0;
        while (i < tamanhoOperacoes) {
            scanf("%d %d", &operacao, &resultado);

            if (operacao == 1) {
                Empilha(resultado, pilha);
                Enfileira(resultado, fila);
                filaP[tamanhoFilaP] = resultado;
                tamanhoFilaP++;
                qsort(filaP, tamanhoFilaP, sizeof(int), compar);
            }else {
                int valor = 0;
                // Pilha
                valor = Desempilha(pilha);
                if (valor != resultado) {
                    flagPilha = 0;
                }
                // Fila
                valor = Desenfileira(fila);
                if (valor != resultado) {
                    flagFila = 0;
                }
                // Fila P
                tamanhoFilaP--;
                valor = filaP[tamanhoFilaP];
                if (valor != resultado) {
                    flagFilaP = 0;
                }
                filaP[tamanhoFilaP] = 0;
                qsort(filaP, tamanhoFilaP, sizeof(int), compar);
            }
            i++;
        }

        if (flagPilha == 1 && flagFila == 0 && flagFilaP == 0) {
            printf("stack\n");
        }
        if (flagPilha == 0 && flagFila == 1 && flagFilaP == 0) {
            printf("queue\n");
        }
        if (flagPilha == 0 && flagFila == 0 && flagFilaP == 1) {
            printf("priority queue\n");
        }
        if (flagPilha == 0 && flagFila == 0 && flagFilaP == 0) {
            printf("impossible\n");
        }
        if (flagPilha == 1 && flagFila == 1 && flagFilaP == 0) {
            printf("not sure\n");
        }
        if (flagPilha == 1 && flagFila == 0 && flagFilaP == 1) {
            printf("not sure\n");
        }
        if (flagPilha == 0 && flagFila == 1 && flagFilaP == 1) {
            printf("not sure\n");
        }
        if (flagPilha == 1 && flagFila == 1 && flagFilaP == 1) {
            printf("not sure\n");
        }
        free(pilha);
        free(fila);
        scanf("%d", &tamanhoOperacoes);
    }
    return 0;
}