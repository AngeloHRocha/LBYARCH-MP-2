#include <stdio.h>
#include <stdlib.h>

extern void imgCvtGrayDoubleToInt(double *input, int *output, int matrixSize);

int main(){
    int height, width;

    // Read height and width
    printf("Input: \n");
    scanf("%d %d", &height, &width);

    int matrixSize = height*width;

    // Allocate memory
    double *input = (double *)malloc(matrixSize * sizeof(double));
    int *output = (int *)malloc(matrixSize * sizeof(int));

    if (!input || !output){
        printf("Memory Allocation failed.\n");
        return 1;
    }

    // Read matrix input
    int i, j;
    for (i=0; i<matrixSize; i++){
        scanf("%lf", &input[i]);
    } 

    imgCvtGrayDoubleToInt(input, output, matrixSize);

    // Print output 
    printf("\nOutput: \n");
    for (i=0; i<height; i++) {
        for (j= 0; j<width; j++) {
            printf("%d", output[i*width + j]);
            if (j < width - 1)
                printf(", ");
        }
        printf("\n");
    }

    return 0;
}