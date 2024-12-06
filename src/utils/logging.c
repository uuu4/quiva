#include <time.h>
#include "utils.h"
#include <stdio.h>


static clock_t start;
void start_timer() {
    start = clock();
}

double stop_timer() {
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    return time_spent;
}