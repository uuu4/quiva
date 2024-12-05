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

