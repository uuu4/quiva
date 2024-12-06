#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include "qubit.h"

//random number generator
double generate_random_number();


//math utils
double dot_product(const double* vec1, const double* vec2, int length);
double** matrix_multiply(const double* m1[], const double* m2[], int r1, int c1, int r2, int c2);
void free_matrix(double** matrix, int rows);
double** transpose_matrix(const double* matrix[], int rows, int cols);

//angle conversion
double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);

//config handling
void load_config(const char* config_file);
void export_config(const Config* config, const char* filename);
void reset_config(Config* config);
void print_config();
void save_config(const char* config_file);
#endif
