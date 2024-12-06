#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include "qubit.h"
#include <math.h>


//random number generator
void generate_random_number();


//math utils
void matrix_multiply(double* result, const double*mat1,const double*mat2, int row1,int col1,int row2,int col2);
double dot_product(const double* vec1, const double* vec2, int length);

//angle conversion
double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);

//config handling
void load_config(const char* config_file);
void print_config();

//time tracking(for performance testing)
void start_timer();
double stop_timer();
#endif
