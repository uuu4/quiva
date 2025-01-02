#ifndef QUBIT_H
#define QUBIT_H
#include <stdbool.h>


typedef struct{
  double real;
  double imag;
}Complex;

// qubit structure definition
typedef struct Qubit {
    Complex state[2]; // state vector of the qubit
} Qubit;




void init_qubit(Qubit* qb); // initializes a qubit to |0⟩
void init_custom_qubit(Qubit* qb, double real0, double imag0, double real1, double imag1);
void print_qubit(const Qubit* qb);
void normalize_qubit(Qubit* qb, int measurement); /* Say we measure the 1st qubit to be a 1, let 41) be
                                                        the state after the measurement
                                                        We get rid of all the states that don't have a 1 in
                                                      the first qubit and then normalize the rest of the states*/
bool validate_qubit(const Qubit* qb);
double** qubit_to_matrix(Qubit* qb);
/*
MultiQubitState* initialize_multi_qubit_state(int num_qubits); // it should be used in entangled qubit states [-]
MultiQubitState* tensor_product(Qubit* qubits, int num_qubits);
MultiQubitState* create_multi_qubit_state(int num_qubits);
void free_multi_qubit_state(MultiQubitState* state);
void print_multi_qubit_state(const MultiQubitState* state);*/
#endif
