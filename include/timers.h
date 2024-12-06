//
// Created by Ali Emre Aydin on 7.12.2024.
//

#ifndef TIMERS_H
#define TIMERS_H
#include <time.h>
#include <stdio.h>
typedef struct Timer {
    clock_t start_time;
    clock_t end_time;
} Timer;


void start_timer();
double stop_timer();
void log_timer_duration(Timer* timer, const char* label);
#endif //TIMERS_H
