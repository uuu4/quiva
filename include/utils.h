#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include "qubit.h"

//random utils
double generate_random_number();
void init_random_seed();
Qubit* generate_random_qubit();
void random_complex_number(double* real, double* imag);
void random_matrix(double** matrix, int rows, int cols); // matrix range: [-1, 1]
int random_int(int min, int max);
double random_double(double min, double max);
void random_spherical_vector(double* r, double* theta, double* phi);




//math utils
double dot_product(const double* vec1, const double* vec2, int length);
double** matrix_multiply(const double* m1[], const double* m2[], int r1, int c1, int r2, int c2);
void free_matrix(double** matrix, int rows);
double** transpose_matrix(const double* matrix[], int rows, int cols);
double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);

//config handling
void load_config(const char* config_file);
void export_config(const Config* config, const char* filename);
void reset_config(Config* config);
void print_config();
void save_config(const char* config_file);

//logging
void init_logger(const char* filename);
void set_log_level(int level); // 0: debug, 1: info, 2: warning, 3: error
void log_info(const char* message);
void log_debug(const char* message);
void log_warning(const char* message);
void log_error(const char* message);
void handle_error(const char* message);
void close_logger();
void configure_logger(const char* filename, int level);
void print_last_log();
void clear_logs();
void log_to_file(const char* message,const char* filename);
void log_complex_data(const char* message, const char* data);

#endif
