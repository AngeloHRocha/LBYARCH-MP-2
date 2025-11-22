#include <stdio.h>
#include <stdlib.h>

int main(){
    int height, width;

    // Read height and width
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
    for (int i=0; i<matrixSize; i++){
        scanf("%lf", &input[i]);
    } 

    // (function call to be inserted here)

    // Print output 
    for (int i=0; i<height; i++) {
        for (int j= 0; j<width; j++) {
            printf("%d", output[i*width + j]);
            if (j < width - 1)
                printf(", ");
        }
        printf("\n");
    }


    return 0;
}