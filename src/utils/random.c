#include <stdlib.h>
#include <time.h>
double generate_random_number() {
    return (double)rand() / (double)RAND_MAX;
}
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}
double random_double(double min, double max) {
    return min + (max - min) * generate_random_number();
}
void init_random_seed() {
    srand(time(NULL));
}
double** random_matrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = random_double(-1, 1);
        }
    }
    return matrix;
}