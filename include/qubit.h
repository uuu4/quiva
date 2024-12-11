#ifndef QUBIT_H
#define QUBIT_H
#include <stdbool.h>

// qubit structure definition
typedef struct {
    double real[2];
    double imag[2];
} Qubit;


void init_qubit(Qubit* qb); // initializes a qubit to |0⟩
void init_custom_qubit(Qubit* qb, double real0, double imag0, double real1, double imag1);
void print_qubit(const Qubit* qb);
void normalize_qubit(Qubit* qb);
bool validate_qubit(const Qubit* qb);
double** qubit_to_matrix(Qubit* qb);

#endif
