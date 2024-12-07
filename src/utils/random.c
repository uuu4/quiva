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
