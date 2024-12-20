#include "qubit.h"
#include <stdbool.h>
#include <math.h>
void init_qubit(Qubit* qb){ //initializes a qubit to |0⟩
  qb->real[0] = 1;
  qb->real[1] = 0;
  qb->imag[0] = 0;
  qb->imag[1] = 0;
}

void init_custom_qubit(Qubit* qb, double real0, double imag0, double real1, double imag1){ //initializes a qubit to custom state
  qb->real[0] = real0;
  qb->real[1] = real1
  qb->imag[0] = imag0;
  qb->imag[1] = imag1;
}

void print_qubit(const Qubit* qb){
  printf("|%.2f + %.2fi⟩\n", qb->real[0], qb->imag[0]);
  printf("|%.2f + %.2fi⟩\n", qb->real[1], qb->imag[1]);
}

void normalize_qubit(Qubit* qb){
  double magnitude = sqrt(pow(qb->real[0], 2) + pow(qb->imag[0], 2) + pow(qb->real[1], 2) + pow(qb->imag[1], 2));
  double epsilon = 1e-9; // Tolerance for floating-point comparison
  if (fabs(magnitude) < epsilon) {
    init_qubit(qb);
    return;
  }
  if (fabs(magnitude - 1) < epsilon) {
    printf("Qubit is already normalized.\n");
    return;
  }
    qb->real[0] = qb->real[0]/magnitude;
    qb->real[1] = qb->real[1]/magnitude;
    qb->imag[0] = qb->imag[0]/magnitude;
    qb->imag[1] = qb->imag[1]/magnitude;
}

bool validate_qubit(const Qubit* qb) {
  double result0 = pow(qb->real[0], 2) + pow(qb->imag[0], 2);
  double result1 = pow(qb->real[1], 2) + pow(qb->imag[1], 2);
  double epsilon = 1e-9; // Tolerance for floating-point comparison

  if (fabs(result0 + result1 - 1) < epsilon) {
    return true;
  } else {
    return false;
  }
}
double** qubit_to_matrix(Qubit* qb) {
  double** matrix = (double**)malloc(2 * sizeof(double*));
  for (int i = 0; i < 2; i++) {
    matrix[i] = (double*)malloc(2 * sizeof(double));
  }
  matrix[0][0] = qb->real[0];
  matrix[0][1] = qb->imag[0];
  matrix[1][0] = qb->real[1];
  matrix[1][1] = qb->imag[1];
  return matrix;
}

MultiQubitState* tensorProduct(Qubit* qubits, int num_qubits) { // was too damn hard to implement this
  int size = (int)pow(2, num_qubits);  // 2^n total size of the vector
  MultiQubitState* result = createMultiQubitState(num_qubits);

  // to build tensor product iteratively, start with the first qubit
  result->real[0] = qubits[0].real[0];
  result->imag[0] = qubits[0].imag[0];
  result->real[1] = qubits[0].real[1];
  result->imag[1] = qubits[0].imag[1];

  // iteratively compute the tensor product for the remaining qubits
  for (int n = 1; n < num_qubits; n++) {
    int prev_size = (int)pow(2, n);
    Qubit* current_qubit = &qubits[n];
    int new_size = prev_size * 2;

    double* new_real = (double*)calloc(new_size, sizeof(double));
    double* new_imag = (double*)calloc(new_size, sizeof(double));

    if (new_real == NULL || new_imag == NULL) {
      perror("Memory allocation failed for tensor product");
      freeMultiQubitState(result);
      exit(EXIT_FAILURE);
    }

    // perform the tensor product with the current qubit
    for (int i = 0; i < prev_size; i++) {
      // replace the old values with the new values
      new_real[i * 2] = result->real[i] * current_qubit->real[0] - result->imag[i] * current_qubit->imag[0];
      new_imag[i * 2] = result->real[i] * current_qubit->imag[0] + result->imag[i] * current_qubit->real[0];


      new_real[i * 2 + 1] = result->real[i] * current_qubit->real[1] - result->imag[i] * current_qubit->imag[1];
      new_imag[i * 2 + 1] = result->real[i] * current_qubit->imag[1] + result->imag[i] * current_qubit->real[1];
    }
    free(result->real);
    free(result->imag);
    result->real = new_real;
    result->imag = new_imag;
  }

  return result;
}

void freeMultiQubitState(MultiQubitState* state) {
  if (state) {
    free(state->real);
    free(state->imag);
    free(state);
  }
}
