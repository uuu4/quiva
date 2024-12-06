#include "timers.h"

void start_new_timer(Timer* timer) {
    timer->start_time = clock();
}

double stop_new_timer(Timer* timer) {
    timer->end_time = clock();
    return (double)(timer->end_time - timer->start_time) / CLOCKS_PER_SEC;
}

void log_timer_duration(Timer* timer, const char* label) {
    double duration = (double)(timer->end_time - timer->start_time) / CLOCKS_PER_SEC;
    printf("%s: %f seconds\n", label, duration);
}