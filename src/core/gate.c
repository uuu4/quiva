#include "qubit.h"
#include "gate.h"
#include "utils.h"
#include "qubit.h"
#include <stdlib.h>
#include <math.h>
#define SQRT_2_INV 0.7071067811865476 // 1/sqrt(2)


Qubit* apply_pauli_x_gate(Qubit* qb) {
    if (!qb) return NULL;

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (!result_qb) return NULL;

    result_qb->real[0] = qb->real[1];
    result_qb->imag[0] = qb->imag[1];
    result_qb->real[1] = qb->real[0];
    result_qb->imag[1] = qb->imag[0];

    return result_qb;
}



Qubit* apply_pauli_z_gate(Qubit* qb) {
    if (!qb) return NULL;

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (!result_qb) return NULL;

    result_qb->real[0] = qb->real[0];
    result_qb->imag[0] = qb->imag[0];
    result_qb->real[1] = -qb->real[1];
    result_qb->imag[1] = -qb->imag[1];

    return result_qb;
}


Qubit* apply_custom_gate(Qubit* qb, const double input[2][2]) {
    double** qb_matrix = qubit_to_matrix(qb);
    if (!qb_matrix) {
        return NULL;
    }

    double** custom_matrix = (double**)malloc(2 * sizeof(double*));
    if (!custom_matrix) {
        free(qb_matrix);
        return NULL;
    }
    for (int i = 0; i < 2; i++) {
        custom_matrix[i] = (double*)malloc(2 * sizeof(double));
        if (!custom_matrix[i]) {
            for (int j = 0; j < i; j++) free(custom_matrix[j]);
            free(custom_matrix);
            free(qb_matrix);
            return NULL;
        }
        custom_matrix[i][0] = input[i][0];
        custom_matrix[i][1] = input[i][1];
    }

    double** matrix_result = matrix_multiply(custom_matrix, qb_matrix, 2, 2, 2, 1);
    if (!matrix_result) {
        for (int i = 0; i < 2; i++) {
            free(custom_matrix[i]);
            free(qb_matrix[i]);
        }
        free(custom_matrix);
        free(qb_matrix);
        return NULL;
    }

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (!result_qb) {
        for (int i = 0; i < 2; i++) {
            free(custom_matrix[i]);
            free(qb_matrix[i]);
            free(matrix_result[i]);
        }
        free(custom_matrix);
        free(qb_matrix);
        free(matrix_result);
        return NULL;
    }

    result_qb->real[0] = matrix_result[0][0];
    result_qb->imag[0] = matrix_result[1][0];
    result_qb->real[1] = matrix_result[0][1];
    result_qb->imag[1] = matrix_result[1][1];

    for (int i = 0; i < 2; i++) {
        free(custom_matrix[i]);
        free(qb_matrix[i]);
        free(matrix_result[i]);
    }
    free(custom_matrix);
    free(qb_matrix);
    free(matrix_result);

    return result_qb;
}

Qubit* apply_hadamard_gate(Qubit* qb) {
    if (!qb) return NULL;

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (!result_qb) return NULL;

    result_qb->real[0] = SQRT_2_INV * (qb->real[0] + qb->real[1]);
    result_qb->imag[0] = SQRT_2_INV * (qb->imag[0] + qb->imag[1]);
    result_qb->real[1] = SQRT_2_INV * (qb->real[0] - qb->real[1]);
    result_qb->imag[1] = SQRT_2_INV * (qb->imag[0] - qb->imag[1]);

    return result_qb;
}



