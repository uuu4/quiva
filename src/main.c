#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Qubit structure
typedef struct {
    double real[2];
    double imag[2];
} Qubit;

void apply_CNOT_gate_n(Qubit* qubits[], int control_index, int target_index, int num_qubits);

int main() {
    // Initialize control and target qubits
    Qubit control = {{0, 1}, {0, 0}}; // |1⟩
    Qubit target = {{0, 1}, {0, 0}};  // |0⟩

    // Create an array of qubits
    Qubit* qubits[2] = {&control, &target};

    // Apply CNOT gate
    apply_CNOT_gate_n(qubits, 0, 1, 2);

    // Print target qubit state after CNOT
    printf("Target qubit state after CNOT:\n");
    printf("|0⟩: %f + %fi\n", qubits[1]->real[0], qubits[1]->imag[0]);
    printf("|1⟩: %f + %fi\n", qubits[1]->real[1], qubits[1]->imag[1]);

    return 0;
}


void apply_CNOT_gate_n(Qubit* qubits[], int control_index, int target_index, int num_qubits) {
    if (!qubits || control_index >= num_qubits || target_index >= num_qubits) return;

    Qubit* control = qubits[control_index];
    Qubit* target = qubits[target_index];

    if (!control || !target) return;

    // Check if the control qubit is in the |1⟩ state
    if (control->real[1] == 1 && control->imag[1] == 0) {
        // Flip the target qubit
        if (target->real[0] == 1 && target->imag[0] == 0) { // Target is in |0⟩
            target->real[0] = 0;
            target->imag[0] = 0;
            target->real[1] = 1;
            target->imag[1] = 0;
        } else if (target->real[1] == 1 && target->imag[1] == 0) { // Target is in |1⟩
            target->real[0] = 1;
            target->imag[0] = 0;
            target->real[1] = 0;
            target->imag[1] = 0;
        }
    }
}
