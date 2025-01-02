#include "../../include/gate.h"
#include "../../include/utils.h"
#include "../../include/qubit.h"
#include <stdlib.h>
#include <math.h>
#define SQRT_2_INV 0.7071067811865476 // 1/sqrt(2)


Qubit* apply_pauli_x_gate(Qubit* qb) {
    if (!qb) return NULL;

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (!result_qb) return NULL;

    result_qb->state[0].real = qb->state[1].real;
    result_qb->state[0].imag = qb->state[1].imag;
    result_qb->state[1].real = qb->state[0].real;
    result_qb->state[1].imag = qb->state[0].imag;

    return result_qb;
}



Qubit* apply_pauli_z_gate(Qubit* qb) {
    if (!qb) return NULL;

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (!result_qb) return NULL;

    result_qb->state[0].real = qb->state[0].real;
    result_qb->state[0].imag = qb->state[0].imag;
    result_qb->state[1].real = -1 * qb->state[0].real;
    result_qb->state[1].imag = -1 * qb->state[0].imag;

    return result_qb;
}


Qubit* apply_custom_gate(Qubit* qb, const double input[2][2]) { // TO DO: gotta change fixed sizes
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

    result_qb->state[0].real = matrix_result[0][0];
    result_qb->state[0].imag = matrix_result[1][0];
    result_qb->state[1].real = matrix_result[0][1];
    result_qb->state[1].imag = matrix_result[1][1];

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

    result_qb->state[0].real = SQRT_2_INV * (qb->state[0].real + qb->state[1].real);
    result_qb->state[0].imag = SQRT_2_INV * (qb->state[0].imag + qb->state[1].imag);
    result_qb->state[1].real = SQRT_2_INV * (qb->state[0].real - qb->state[1].real);
    result_qb->state[1].imag = SQRT_2_INV * (qb->state[0].imag - qb->state[1].imag);

    return result_qb;
}

Qubit* apply_pauli_y_gate(Qubit* qb) {
    if (!qb) return NULL;

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (!result_qb) return NULL;

    // Y = [0 -i; i 0] // might done matrix multiplication gotta check one more
    result_qb->state[0].real = qb->state[1].imag;
    result_qb->state[0].imag = -1 * qb->state[1].real;
    result_qb->state[1].real = qb->state[0].imag;
    result_qb->state[1].imag = -1 * qb->state[0].real;

    return result_qb;
}
Qubit* apply_phase_gate(Qubit* qb, double theta) {
    if (!qb) return NULL;

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (!result_qb) return NULL;

    // P = [0 1; 0 e^i*theta] // might done matrix multiplication gotta check one more
    result_qb->state[0].real = qb->state[0].real;
    result_qb->state[0].imag = qb->state[0].imag;
    result_qb->state[1].real = (qb->state[1].real)*cos(theta)-(qb->state[1].imag)*sin(theta);
    result_qb->state[1].imag = (qb->state[1].real)*sin(theta)+(qb->state[1].imag)*cos(theta);

    return result_qb;
}
Qubit* apply_T_gate(Qubit* qb) {
    return apply_phase_gate(qb, M_PI/4);
}
Qubit* apply_S_gate(Qubit* qb) {
    return apply_phase_gate(qb, M_PI/2);
}
Qubit* apply_rotation_gate(Qubit* qb, char axis, double theta) { // need to update for arbitrary axis
    if (!qb) return NULL;

    Qubit* result_qb = (Qubit*)malloc(sizeof(Qubit));
    if (!result_qb) return NULL;

    // Rx = [cos(theta/2), -i*sin(theta/2); -i*sin(theta/2), cos(theta/2)]
    // Ry = [cos(theta/2), -sin(theta/2); sin(theta/2), cos(theta/2)]
    // Rz = [e^(-i*theta/2), 0; 0, e^(i*theta/2)]
    switch (axis) {
        case 'x':
        result_qb->state[0].real = qb->state[0].real * cos(theta / 2) + qb->state[1].imag * sin(theta / 2);
        result_qb->state[0].imag = qb->state[0].imag * cos(theta / 2) - qb->state[1].real * sin(theta / 2);
        result_qb->state[1].real = qb->state[1].real * cos(theta / 2) + qb->state[0].imag * sin(theta / 2);
        result_qb->state[1].imag = qb->state[1].imag * cos(theta / 2) - qb->state[1].real * sin(theta / 2);
        break;
        case 'y':
        result_qb->state[0].real = qb->state[1].real * cos(theta / 2) - qb->state[1].real * sin(theta / 2);
        result_qb->state[0].imag = qb->state[0].imag * cos(theta / 2) - qb->state[1].imag * sin(theta / 2);
        result_qb->state[1].real = qb->state[1].real * cos(theta / 2) + qb->state[0].real * sin(theta / 2);
        result_qb->state[1].imag = qb->state[1].imag * cos(theta / 2) + qb->state[0].imag * sin(theta / 2);
        break;
        case 'z':
        result_qb->state[0].real = qb->state[0].real * cos(-1 * theta / 2) - qb->state[0].imag * sin(-1 * theta / 2);
        result_qb->state[0].imag = qb->state[0].real * sin(-1* theta / 2) + qb->state[0].imag * cos(-1 * theta / 2);
        result_qb->state[1].real = qb->state[1].real * cos(theta / 2) - qb->state[1].imag * sin(theta / 2);
        result_qb->state[1].imag = qb->state[1].real * sin(theta / 2) + qb->state[1].imag * cos(theta / 2);
        break;
        default:
          free(result_qb);
          return NULL;
    }
    return result_qb;
}

Qubit* apply_CNOT_gate(Qubit* qubits[], int control_index, int target_index, int num_qubits) {
    if (!qubits || control_index >= num_qubits || target_index >= num_qubits) return NULL;

    Qubit* control = qubits[control_index];
    Qubit* target = qubits[target_index];

    if (!control || !target) return NULL;

    if (control->state[1].real == 1 && control->state[1].imag == 0) {
        // flip the target qubit
        if (target->state[0].real == 1 && target->state[0].imag == 0) { // target is in |0⟩
            target->state[0].real = 0;
            target->state[0].imag = 0;
            target->state[1].real = 1;
            target->state[1].imag = 0;
        } else if (target->state[1].real == 1 && target->state[1].imag == 0) { // target is in |1⟩
            target->state[0].real = 1;
            target->state[0].imag = 0;
            target->state[1].real = 0;
            target->state[1].imag = 0;
        }
        return target;
    }
}

