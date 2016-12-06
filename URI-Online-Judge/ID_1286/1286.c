#include <stdio.h>
 
typedef struct {
    int tempo;
    int numeroPizzas;
}Pedido;

int max(int a, int b) {
    if (a > b) {
        return a;
    }else {
        return b;
    }
}
 
int main() {
    int n, p;
    Pedido array[21];
    int matriz[21][31];
    
    scanf("%d", &n);
    while(n != 0){
        scanf("%d", &p);
        int i;
        for(i = 1; i <= n; i++) {
            scanf("%d %d", &array[i].tempo, &array[i].numeroPizzas);
        }
        for(i = 0; i <= n; i++) {
            int j;
            for(j = 0; j <= p; j++) {
                if(i == 0 || j == 0)
                    matriz[i][j] = 0;
                else{
                    if(array[i].numeroPizzas > j) {
                        matriz[i][j] = matriz[i - 1][j];
                    }
                    else {
                        int maior = max(matriz[i - 1][j - array[i].numeroPizzas] + array[i].tempo, matriz[i - 1][j]);
                        matriz[i][j] = maior;
                    }
                }
            }
        }
        printf("%d min.\n", matriz[n][p]);
        scanf("%d", &n);
    }
    return 0;
}