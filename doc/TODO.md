0.1: in gate.c , need to update apply_rotation_gate for arbitrary inputs, it currently working on only x y and z axis

1: Ensure minimal coupling between modules by defining clear APIs between them


2: Provide docstrings for functions (with parameter and return descriptions).
Write markdown guides in the doc/ directory explaining:
How the library works.
Examples of constructing and running quantum circuits.
Make usage intuitive for users who aren’t experts in this codebase.

---
3.1:Define a Simple API for Circuits: A user should be able to build a circuit and simulate it in a few lines:
```c
Qubit* qb = initialize_qubit(0, 0);  // Initialize |0⟩ state
Circuit* qc = create_circuit(1);    // 1-qubit circuit
add_gate(qc, H_GATE, 0);            // Add Hadamard gate to qubit 0
add_gate(qc, X_GATE, 0);            // Add Pauli-X gate
simulate(qc, qb);                   // Simulate the circuit
measure(qb);                        // Perform measurement
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