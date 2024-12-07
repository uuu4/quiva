#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
double** matrix_multiply(const double* m1[], const double* m2[], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("Matrix multiplication not possible\n");
        return NULL;
    }

    double** result = (double**)malloc(r1 * sizeof(double*));
    for (int i = 0; i < r1; i++) {
        result[i] = (double*)malloc(c2 * sizeof(double));
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return result;
}

void free_matrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

double radians_to_degrees(double radians) {
    return radians * 180 / 3.14159265358979323846;
}

double degrees_to_radians(double degrees) {
    return degrees * 3.14159265358979323846 / 180;
}
double** transpose_matrix(const double* matrix[], int rows, int cols) {
    double** result = (double**)malloc(cols * sizeof(double*));
    for (int i = 0; i < cols; i++) {
        result[i] = (double*)malloc(rows * sizeof(double));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}
