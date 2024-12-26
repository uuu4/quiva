#ifndef GATE_H
#define GATE_H

#include "qubit.h"
// one qubit gates
Qubit* apply_hadamard_gate(Qubit* qb);
Qubit* apply_pauli_x_gate(Qubit* qb);
Qubit* apply_pauli_y_gate(Qubit* qb);
Qubit* apply_pauli_z_gate(Qubit* qb);
Qubit* apply_phase_gate(Qubit* qb,double theta);
Qubit* apply_T_gate(Qubit* qb); // not necessary but will work
Qubit* apply_S_gate(Qubit* qb); // not necessary but will work

//parametric one qubic gates
Qubit* apply_rotation_gate(Qubit* qb, char axis, double theta); // Check TODO.MD

//multi qubit gates
Qubit* apply_CNOT_gate(Qubit* qubits[], int control_index, int target_index, int num_qubits);
Qubit* apply_CZ_gate(Qubit* control, Qubit* target); // [-]
Qubit* apply_CY_gate(Qubit* control, Qubit* target); // [-]
Qubit* apply_SWAP_gate(Qubit* qb1, Qubit* qb2); // [-]
Qubit* apply_CCNOT_gate(Qubit* qb1, Qubit* qb2, Qubit* qb3); // [-]

//parametric multi qubit gates
Qubit* apply_CRz_gate(Qubit* control, Qubit* target, double theta); // [-]

//custom gates
Qubit* apply_custom_gate(Qubit* qb, const double input[2][2]);
Qubit* apply_custom_multi_qubit_gate(Qubit* qbs[], int num_qubits, const double* matrix); // [-]

// extra functions
Qubit* validate_qubits(Qubit* qbs[], int num_qubits); //checks if qubits are valid (NULL or not) [-]
Qubit* print_gate_info(const char* gate_name); // [-]

#endif // GATE_H
