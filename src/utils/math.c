#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
double** matrix_multiply(double** m1, double** m2, int r1, int c1, int r2, int c2) {
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
double dot_product(const double* vec1, const double* vec2, int length) {
    if (vec1 == NULL || vec2 == NULL || length <= 0) {
        printf("Invalid input to dot_product function.\n");
        return 0.0;
    }

    double result = 0.0;
    for (int i = 0; i < length; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}
MultiQubitState* tensor_product(Qubit* qb1, Qubit* qb2) {
    if (!qb1 || !qb2) return NULL;

    MultiQubitState* result = (MultiQubitState*)malloc(sizeof(MultiQubitState));
    if (!result) return NULL;

    result->num_qubits = 2;
    result->real = (double*)malloc(4 * sizeof(double));
    result->imag = (double*)malloc(4 * sizeof(double));

    if (!result->real || !result->imag) {
        free(result);
        return NULL;
    }

    // Tensor product calculation
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int idx = i * 2 + j; // Combined index
            result->real[idx] = qb1->real[i] * qb2->real[j] - qb1->imag[i] * qb2->imag[j];
            result->imag[idx] = qb1->real[i] * qb2->imag[j] + qb1->imag[i] * qb2->real[j];
        }
    }

    return result;
}


