#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "qubit.h"
void plot_bloch_sphere(Qubit* qb);
void calculate_bloch_coordinates(Qubit* qb, double* theta, double* phi);
void visualize_qubit_state(Qubit* qb);
//void plot_quantum_circuit(Qubit* qubits[], int num_qubits, Gate gates[], int num_gates);
//void draw_single_qubit_gate(int qubit_index, Gate g);
//void draw_two_qubit_gate(int qubit_index1, int qubit_index2, Gate g);
//void animate_circuit_execution(Qubit* qubits[], int num_qubits, Gate gates[], int num_gates);
void visualize_density_matrix(const double* matrix[], int size);
void visualize_quantum_state_3D(Qubit* qubits[], int num_qubits);
void plot_state_heatmap(const double* matrix[], int size);
void plot_live_quantum_data(Qubit* qubits[], int num_qubits, double time);
void create_control_panel();
void save_visualization_state(const char* filename);
void load_visualization_state(const char* filename);
void enable_interactive_controls();
void clear_plot();
void refresh_plot();
void close_plot();    


#endif //VISUALIZATION_H
