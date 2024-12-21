#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <stdint.h>
#include "qubit.h"

typedef struct {
    uint16_t num_qubits;
    Qubit** qubits;
} QuantumCircuit;


QuantumCircuit* create_circuit(uint16_t num_qubits);

/**
 * @param gate_func Function pointer to the single-qubit gate (e.g., apply_hadamard_gate).
 * @param target Index of the target qubit in the circuit.
 * @return 0 if successful, -1 if an error occurs.
 */
int apply_single_qubit_gate(QuantumCircuit* circuit, Qubit* (*gate_func)(Qubit*), uint16_t target);

/**
 * @brief Applies a two-qubit gate to a control and target qubit.
 * @return 0 if successful, -1 if an error occurs.
 */
int apply_two_qubit_gate(QuantumCircuit* circuit, Qubit* (*gate_func)(Qubit*, Qubit*), uint16_t control, uint16_t target);
void free_circuit(QuantumCircuit* circuit);

#endif // CIRCUIT_H

