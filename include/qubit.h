// qubit.h

#ifndef QUBIT_H
#define QUBIT_H

typedef struct {
    double amplitude0;
    double amplitude1;
} Qubit;

void init_qubit(Qubit* qb); // create qubit and set amplitudes to 0
void print_qubit(Qubit* qb); // print qubit amplitudes
int measure_qubit(Qubit* qb); // measure qubit and return 0 or 1


#endif // QUBIT_H
