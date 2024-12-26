#include <stdio.h>
#include "../include/qubit.h"
#include "../include/gate.h"
int main() {
    Qubit control = {{0, 1}, {0, 0}}; // |1⟩
    Qubit target = {{0, 1}, {0, 0}};  // |0⟩

    Qubit* qubits[2] = {&control, &target};

    apply_CNOT_gate(qubits, 0, 1, 2);

    printf("Target qubit state after CNOT:\n");
    printf("|0⟩: %f + %fi\n", qubits[1]->real[0], qubits[1]->imag[0]);
    printf("|1⟩: %f + %fi\n", qubits[1]->real[1], qubits[1]->imag[1]);

    return 0;
}
