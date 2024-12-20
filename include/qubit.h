#ifndef QUBIT_H
#define QUBIT_H
#include <stdbool.h>

// qubit structure definition
typedef struct Qubit {
    double real[2];
    double imag[2];
} Qubit;

typedef struct MultiQubitState {
    int num_qubits;
    double* real;          // real parts of the state vector e.g alpha1,alpha2...
    double* imag;          // imaginary parts of the state vector e.g beta1,beta2...
} MultiQubitState;



void init_qubit(Qubit* qb); // initializes a qubit to |0⟩
void init_custom_qubit(Qubit* qb, double real0, double imag0, double real1, double imag1);
void print_qubit(const Qubit* qb);
void normalize_qubit(Qubit* qb);
bool validate_qubit(const Qubit* qb);
double** qubit_to_matrix(Qubit* qb);

MultiQubitState* initialize_multi_qubit_state(int num_qubits); // redundant since tensor product is in math.c but still might b useful
MultiQubitState* tensor_product(Qubit* qubits, int num_qubits);
void free_multi_qubit_state(MultiQubitState* state);
void print_multi_qubit_state(const MultiQubitState* state);
#endif
