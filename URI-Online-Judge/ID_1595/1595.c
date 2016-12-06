#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(float*)a - *(float*)b );
}

int main() {
    int numberTest;
    int totalDistance, pathsRunning, addSpeed;

    scanf("%d", &numberTest);
    int i = 0;
    while (i < numberTest) {
        scanf("%d %d %d", &totalDistance, &pathsRunning, &addSpeed);
        if (pathsRunning == 0) {
            int j = 0;
            float totalTime = 0.00;
            while (j < totalDistance) {
                float speed = 0.00;
                scanf("%f", &speed);
                totalTime += (1/speed);
                j++;
            }
            printf("%.2f\n", totalTime);
        }else {
            float arrayTotalDistance[totalDistance];
            int j = 0;
            // Coloca valores no vetor
            while (j < totalDistance) {
                scanf("%f", &arrayTotalDistance[j]);
                j++;
            }
            qsort(arrayTotalDistance, totalDistance, sizeof(float), cmpfunc);
            float totalTime = 0.00;
            float speed;
            int count = 0;
            j = 0;
            while (j < totalDistance) {
                // Pega os 'C' valores minimos e soma velocidade
                if (count < pathsRunning) {
                    speed = arrayTotalDistance[j] + addSpeed;
                    count++;
                }else {
                    speed = arrayTotalDistance[j];
                }
                totalTime += (1/speed);
                j++;
            }
            printf("%.2f\n", totalTime);
        }
        i++;
    }
    return 0;
}