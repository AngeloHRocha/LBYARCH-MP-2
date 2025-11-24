#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern void imgCvtGrayDoubleToInt(double *input, int *output, int matrixSize);

void CimgCvtGrayDoubleToInt(double *input, int *output, int matrixSize){
    int i;
    for (i = 0; i < matrixSize; i++){
        output[i] = (int)(input[i] * 255.0);
    }
}
int main(){
    int height, width;
    int i, j;

    // Read height and width
    scanf("%d %d", &height, &width);

    int matrixSize = height * width;

    // Allocate memory
    double *input = (double *)malloc(matrixSize * sizeof(double));
    int *output  = (int *)malloc(matrixSize * sizeof(int));

    if (!input || !output){
        printf("Memory Allocation failed.\n");
        return 1;
    }

    // Initialize matrix with random numbers (for testing)
    srand((unsigned int)time(NULL));
    for (i = 0; i < matrixSize; i++){
        input[i] = (double)rand() / RAND_MAX;
    }

    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
    QueryPerformanceFrequency(&frequency);

    // Time the ASM function 30 times
    int runs = 30;
    double totalTime = 0.0;

    // Time ASM implementation
    for (i = 0; i < runs; i++){
        QueryPerformanceCounter(&start);

        imgCvtGrayDoubleToInt(input, output, matrixSize);

        QueryPerformanceCounter(&end);

        double elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
        totalTime += elapsed;
    }

    // Display average execution time for ASM
    printf("ASM average execution time over %d runs: %.9f seconds\n", runs, totalTime / runs);

    // Print first 5x5 of the output for verification
    printf("ASM Correctness Check:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d", output[i * width + j]);
            if (j < 4)
                printf(", ");
        }
        printf("\n");
    }

    printf("\n");

    // Time C implementation
    for (i = 0; i < runs; i++){
        QueryPerformanceCounter(&start);

        CimgCvtGrayDoubleToInt(input, output, matrixSize);

        QueryPerformanceCounter(&end);

        double elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
        totalTime += elapsed;
    }

    // Display average execution time for ASM
    printf("C average execution time over %d runs: %.9f seconds\n", runs, totalTime / runs);

    // Print first 5x5 of the output for verification
    printf("C Correctness Check:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d", output[i * width + j]);
            if (j < 4)
                printf(", ");
        }
        printf("\n");
    }

    return 0;
}
