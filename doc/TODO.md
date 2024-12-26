***0.1: in gate.c , need to update apply_rotation_gate for arbitrary inputs, it currently working on only x y and z axis***

***0.2:GATE.H APPLY_CNOT_GATE FUNCTION NEED TO BE MORE GENERAL. RIGHT NOW IT ONLY USED IN 0 AND 1 TARGET STATES.***



***0.3: QUBIT.C LINE 65 CREATE_MULTIQUBIT_STATE FUNCTION, NEED TO UPDATE THE FUNCTION TO CREATE A QUBIT WITH A GIVEN STATE***
# TODO

## 1. Features to Implement

### Core Features
- [ ] **Gate Implementations**
    - Single-Qubit Gates:
        - [x] Pauli Gates (X, Y, Z)
        - [x] Phase Gates (S, T, custom phase gate with θ parameter)
        - [x] Hadamard Gate (H)
        - [ ] Identity Gate (I)
    - Multi-Qubit Gates:
        - [ ] Controlled Gates (CNOT, Toffoli, etc.)
        - [ ] SWAP Gate
        - [ ] Controlled Phase Gates (CRZ, CRY, CRX, CU1, CU2, CU3)
        - [ ] Multi-Control Gates (e.g., Multi-controlled Toffoli)
    - Universal Gates:
        - [ ] Arbitrary unitary matrices as gates (user-defined).
    - Noise Models:
        - [ ] Depolarizing channel.
        - [ ] Amplitude and phase damping.

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
### Low-Level API
- [ ] Provide access to:
    - Tensor product functionality for manual multi-qubit state construction.
    - Direct gate application to raw `Qubit` structures.

### Visualization and Interaction
- [ ] Add visualization for:
    - Quantum states (as vectors or Bloch spheres).
    - Circuit diagrams (ASCII art or graphical).
- [ ] Allow live interaction:
    - Users can create and modify circuits via a scripting interface.

---

## 3. Optimization Tasks
- [ ] Optimize tensor product calculations for large systems.
- [ ] Refactor memory allocation in gate application functions.
- [ ] Introduce caching for frequently-used operations (e.g., repeated gates or tensor products).
- [ ] Ensure compatibility with parallel computation (e.g., OpenMP or GPU-based libraries).

---

## 4. Testing
- [ ] Write unit tests for:
    - Gate functions (single and multi-qubit).
    - Tensor product functionality for correctness.
    - Measurement logic for probabilistic outcomes.
    - Quantum circuits with complex sequences of gates.
- [ ] Test edge cases:
    - Invalid states or gate parameters.
    - Tensor products with null/empty states.
    - Precision issues with floating-point operations.
- [ ] Validate results against known quantum simulators like Qiskit or Cirq.

---

## 5. Documentation
- [ ] Update **README.md**:
    - Add project overview and key features.
    - Provide installation and usage instructions.
    - Include examples of:
        - Initializing quantum circuits.
        - Applying gates and measurements.
        - Visualizing results.
- [ ] Write a comprehensive API guide:
    - Explain the high-level API for building circuits.
    - Document low-level functions for advanced users.
- [ ] Include step-by-step tutorials:
    - Quantum basics (e.g., superposition, entanglement).
    - Using the library to simulate specific algorithms (e.g., Grover's, Shor's).
    - Visualization techniques for states and circuits.

---

## 6. Advanced Features to Add
- [ ] **Custom Gates**
    - Allow users to define their own unitary matrices as gates.
    - Validate custom gates for unitarity.
- [ ] **Noise Simulation**
    - Add basic noise models (e.g., depolarizing, amplitude damping).
    - Simulate noisy quantum circuits and compare results with noiseless runs.
- [ ] **Integration**
    - Export circuits to OpenQASM or other quantum circuit formats.
    - Add bindings for Python to provide scripting capabilities.

---

## 7. Visualization
- [ ] Circuit Diagram Generator
    - Create ASCII or graphical circuit diagrams.
    - Include gate names, qubits, and measurements.
- [ ] State Representation
    - Add visualizations for:
        - Probability amplitudes of states.
        - Bloch sphere for single-qubit states.

---

## 8. Milestones

### Phase 1: Core Functionality
- Implement single-qubit gates and basic measurements.
- Finalize tensor product functionality.

### Phase 2: Circuit and API Development
- Create `QuantumCircuit` class.
- Add support for multi-qubit gates and measurement chaining.

### Phase 3: Advanced Features and Optimization
- Add custom gate support and noisy simulations.
- Optimize memory and computation for large systems.

### Phase 4: Visualization and Documentation
- Complete visualization features for states and circuits.
- Finalize API documentation and tutorials.