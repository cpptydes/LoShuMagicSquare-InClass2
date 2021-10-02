#include <stdlib.h>
#include <time.h>

int const row = 3;
int const column = 3;

int squareSample[row][column] = {
    {4,9,2},
    {3,5,7},
    {8,1,6}
}; 

int isMagicSquare(int** matrix, int len) 
{
    int sum = 0; // row sum
    for (int i = 0; i < len; i++) {
        int rowSum = 0;
        for (int j = 0; j < len; j++) {
            rowSum += matrix[i][j];
        }
        if (sum == 0) {
            sum = rowSum;
        } else {
            if (rowSum != sum) {
                return 0;
            }
        }
    }

    for (int i = 0; i < len; i++) {
        int columnSum = 0; // column sum
        for (int j = 0; j < len; j++) {
            columnSum += matrix[j][i];
        }
        if (columnSum != sum) {
            return 0;
        }
    }

    int diagSum = 0; // main diagonal sum
    for (int i = 0; i < len; i++) {
        diagSum += matrix[i][i];
    }
    if (diagSum != sum) {
        return 0;
    }

    diagSum = 0; // reversed diagonal sum
    for (int i = 0; i < len; i++) {
        diagSum += matrix[i][len - 1 - i];
    }
    if (diagSum != sum) {
        return 0;
    }
    return 1;
}

void printMatrix(int **matrix, int len) {
    for (int i = 0; i < len; i++) 
    {
        printf("[")
        for (int j = 0; j < len; j++) {
            printf("%d ", matrix[i][j])
        }
    printf("]\n");
    }
    return 0;
}

void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main() {
    
    int size = 3;
    int values[] = {1,2,3,4,5,6,7,8,9};
    int *valPtr;
    valPtr = values;
    int matrix[3, 3];
    for(int rw =0; rw < 3; rw++){
        for(int colm=0; colm < 3; colm++){
            matrix[rw][colm] = *valPtr;
        }
    }

    printMatrix(matrix, size);
    if(isMagicSquare(matrix, size) == 1) {
        printf("Matrix is a magic square\n");
    } else {
        printf("Matrix is not a magic square\n");
    }

    
    int timesTried = 0;
//    while(isMagicSquare(matrix, size) != 1){
//        timesTried++;
//        shuffle(values, 9);
//        //generate matricies using the shuffled data
//    }
    return 0;
}