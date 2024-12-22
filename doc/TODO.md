***0.1: in gate.c , need to update apply_rotation_gate for arbitrary inputs, it currently working on only x y and z axis***

# TODO

## 1. Features to Implement

### Core Features
- [ ] **Gate Implementations**
    - Add support for common gates:
        - [x] Pauli Gates (X, Y, Z)
        - [x] Phase Gates (S, T)
        - [ ] Hadamard Gate
        - [ ] Controlled Gates (CNOT, Toffoli, etc.)
        - [ ] SWAP Gate
        - [ ] Universal Gate Sets (arbitrary unitary operations).
    - Ensure gates work seamlessly with \( n \)-qubit systems.
    - Add ability to chain gates into a "quantum circuit."

- [ ] **Quantum Measurement**
    - Implement measurement for \( n \)-qubit systems:
        - Collapse states probabilistically.
        - Return measurement results in binary format (e.g., |01⟩, |11⟩).
    - Add repeated measurement functionality to simulate experiment outcomes.

- [ ] **Tensor Product**
    - Add functionality for computing tensor products of arbitrary numbers of qubits.
    - Optimize for \( n \)-qubit systems by using sparse representations where possible.
- [ ] **State Initialization**
    - Provide user-friendly API to initialize quantum states:
        - [ ] Single-qubit states.
        - [ ] Multi-qubit states (e.g., |00⟩, |ψ+⟩).
        - [ ] Randomized pure or mixed states.
- [ ] **Simulation Backend**
    - Enable step-by-step simulation of quantum circuits:
        - Apply gates sequentially.
        - Visualize intermediate states.
    - Add support for time evolution of quantum systems.
---

## 2. **API Design**

### High-Level API
- [ ] **Object-Oriented Quantum Circuit Interface**
    - Create a `QuantumCircuit` class to represent circuits.
        - Methods to:
            - Add gates (`add_gate()` or `apply_gate()`).
            - Add measurements (`measure()`).
            - Visualize circuit structure (`show_circuit()`).
        - Support serialization (e.g., export to JSON or OpenQASM).
    - Example usage:
      ```c
      QuantumCircuit* qc = create_circuit(2);  // Create a 2-qubit circuit
      add_gate(qc, HADAMARD, 0);              // Apply H gate to qubit 0
      add_gate(qc, CNOT, 0, 1);               // Apply CNOT gate
      measure(qc, 1);                         // Measure qubit 1
      ```
3.2 Encourage Extensibility: Design the API so users can extend it by:
Adding custom gates.
Creating new visualization methods (e.g., custom Bloch sphere styles).
Defining unique simulation behaviors (e.g., noise models for quantum error correction).
---
4.Emphasize Visualization

Manim’s strength lies in its stunning visuals. Your project can similarly provide intuitive visualizations for quantum states and processes.
Visualization Ideas:

Bloch Sphere:
Show live visualization of a qubit’s state evolving on the Bloch sphere.
Allow users to export visualizations (e.g., as .png or .mp4).
Quantum Circuit Diagrams:
Create diagrams like this:
    
    Qubit 0: ──H──X──M──

You can store these as text-based visuals, or use a library like Graphviz or matplotlib for better rendering.

Time Evolution:
Show animations of wavefunctions or qubit state amplitudes evolving in time.
For example:
Qubit |0>: (0.707 + 0.707i) |0⟩ + 0 |1⟩

Integration with 3D Graphics:
If feasible, integrate with OpenGL or similar for interactive 3D visualizations.