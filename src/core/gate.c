#include "qubit.h"
#include "gate.h"
#include "utils.h"
#include "qubit.h"
#include <stdlib.h>


Qubit* apply_pauli_x_gate(Qubit* qb) {
    double** pauli_x = (double**)malloc(2 * sizeof(double*));
    if (!pauli_x) return NULL;

    for (int i = 0; i < 2; i++) {
        pauli_x[i] = (double*)malloc(2 * sizeof(double));
        if (!pauli_x[i]) {
            for (int j = 0; j < i; j++) free(pauli_x[j]);
            free(pauli_x);
            return NULL;
        }
    }
    pauli_x[0][0] = 0; pauli_x[0][1] = 1;
    pauli_x[1][0] = 1; pauli_x[1][1] = 0;

    double** qb_matrix = qubit_to_matrix(qb);
    if (!qb_matrix) {
        for (int i = 0; i < 2; i++) free(pauli_x[i]);
        free(pauli_x);
        return NULL;
    }

    double** matrix_result = matrix_multiply(pauli_x, qb_matrix, 2, 2, 2, 1);
    if (!matrix_result) {
        for (int i = 0; i < 2; i++) {
            free(pauli_x[i]);
            free(qb_matrix[i]);
        }
        free(pauli_x);
        free(qb_matrix);
        return NULL;
    }

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (!result_qb) {
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


Qubit* apply_pauli_z_gate(Qubit* qb) {
    double** pauli_z = (double**)malloc(2 * sizeof(double*));
    if (!pauli_z) return NULL;

    for (int i = 0; i < 2; i++) {
        pauli_z[i] = (double*)malloc(2 * sizeof(double));
        if (!pauli_z[i]) {
            for (int j = 0; j < i; j++) free(pauli_z[j]);
            free(pauli_z);
            return NULL;
        }
    }
    pauli_z[0][0] = 1; pauli_z[0][1] = 0;
    pauli_z[1][0] = 0; pauli_z[1][1] = -1;

    double** qb_matrix = qubit_to_matrix(qb);
    if (!qb_matrix) {
        for (int i = 0; i < 2; i++) free(pauli_z[i]);
        free(pauli_z);
        return NULL;
    }

    double** matrix_result = matrix_multiply(pauli_z, qb_matrix, 2, 2, 2, 1);
    if (!matrix_result) {
        for (int i = 0; i < 2; i++) {
            free(pauli_z[i]);
            free(qb_matrix[i]);
        }
        free(pauli_z);
        free(qb_matrix);
        return NULL;
    }

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (!result_qb) {
        for (int i = 0; i < 2; i++) {
            free(pauli_z[i]);
            free(qb_matrix[i]);
            free(matrix_result[i]);
        }
        free(pauli_z);
        free(qb_matrix);
        free(matrix_result);
        return NULL;
    }

    result_qb->real[0] = matrix_result[0][0];
    result_qb->imag[0] = matrix_result[1][0];
    result_qb->real[1] = matrix_result[0][1];
    result_qb->imag[1] = matrix_result[1][1];

    for (int i = 0; i < 2; i++) {
        free(pauli_z[i]);
        free(qb_matrix[i]);
        free(matrix_result[i]);
    }
    free(pauli_z);
    free(qb_matrix);
    free(matrix_result);

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

