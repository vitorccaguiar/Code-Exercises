#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char enunciado[52];

    int i = 0;
    int countLetra = 0;
    int letraTotal = 0;
    while (gets(enunciado) != NULL) {
        int palavraTotal = 0;
        int valido = 1;
        while (1) {
            if(isalpha(enunciado[i])) {
                countLetra++;
            }else {
                if(isdigit(enunciado[i])) {
                    valido = 0;
                }else {
                    if(isblank(enunciado[i])) {
                        if (valido) {
                            letraTotal += countLetra;
                            countLetra = 0;
                            if (i != 0) {
                            if (!isblank(enunciado[i-1])) {
                                palavraTotal++;
                            }
                            }
                        }else {
                            countLetra = 0;
                            valido = 1;
                        }
                    }
                    if (enunciado[i] == '.') {
                        if (isblank(enunciado[i+1]) || enunciado[i+1] == '\0' || enunciado[i+1] == EOF) {
                            
                        }else {
                            valido = 0;
                        }
                    }
                    if (enunciado[i] == '\0' || enunciado[i] == EOF) {  
                        if (i != 0) {   
                        if (valido && !isblank(enunciado[i-1])) {
                            letraTotal += countLetra;
                            countLetra = 0;
                            palavraTotal++;
                        }
                        }
                        break;
                    }
                }
            }
            i++;
        }
        int media;
        

        if (palavraTotal == 0) {
            media = 0;
        }else {
            media = letraTotal/palavraTotal;
        }

        if (media <= 3) {
            printf("%s\n", "250");
        }
        if (media == 4 || media == 5) {
            printf("%s\n", "500");
        }
        if (media > 5) {
            printf("%s\n", "1000");
        }
        
        countLetra = 0;
        letraTotal = 0;
        i=0;
        
    }
    return 0;
}