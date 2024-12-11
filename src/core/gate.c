#include "qubit.h"
#include "gate.h"
#include "utils.h"
#include "qubit.h"
#include <stdlib.h>


Qubit* apply_pauli_x_gate(Qubit* qb) {
    double** pauli_x = (double**)malloc(2 * sizeof(double*));
    for (int i = 0; i < 2; i++) {
        pauli_x[i] = (double*)malloc(2 * sizeof(double));
    }
    pauli_x[0][0] = 0; pauli_x[0][1] = 1;
    pauli_x[1][0] = 1; pauli_x[1][1] = 0;

    double** qb_matrix = qubit_to_matrix(qb);

    double** matrix_result = matrix_multiply(pauli_x, qb_matrix, 2, 2, 2, 1);
    if (matrix_result == NULL) {
        for (int i = 0; i < 2; i++) {
            free(pauli_x[i]);
        }
        free(pauli_x);
        free(qb_matrix);
        return NULL;
    }

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (result_qb == NULL) {
        for (int i = 0; i < 2; i++) {
            free(pauli_x[i]);
            free(qb_matrix[i]);
            free(matrix_result[i]);
        }
        free(pauli_x);
        free(qb_matrix);
        free(matrix_result);
        return NULL;
    }

    result_qb->real[0] = matrix_result[0][0];
    result_qb->imag[0] = matrix_result[1][0];
    result_qb->real[1] = matrix_result[0][1];
    result_qb->imag[1] = matrix_result[1][1];

    for (int i = 0; i < 2; i++) {
        free(pauli_x[i]);
        free(qb_matrix[i]);
        free(matrix_result[i]);
    }
    free(pauli_x);
    free(qb_matrix);
    free(matrix_result);

    return result_qb;
}