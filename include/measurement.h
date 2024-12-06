#ifndef MEASUREMENT_H
#define MEASUREMENT_H
#include "qubit.h"


int measure_qubit(Qubit* qb); // measure the qubit then return its classical bit state (0 or 1)
void multiple_measure_qubits(Qubit* qubits[], int num_qubits, int* results);

int probabilistic_measurement(const Qubit* qb); // measure the qubit probabilistically

double calculate_probability_of_0(const Qubit* qb); // calculate the probability of the qubit being 0
double calculate_probability_of_1(const Qubit* qb); // calculate the probability of the qubit being 1
#endif //MEASUREMENT_H
