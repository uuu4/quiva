#include "logging.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static FILE* log_file = NULL;
static int log_level = 1; // default: info level
static char last_log[1024];

void init_logger(const char* filename) {
    log_file = fopen(filename, "a");
    if (!log_file) {
        fprintf(stderr, "Failed to open log file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fprintf(log_file, "Logger initialized.\n");
}

void set_log_level(int level) {
    log_level = level;
}

static void log_message(int level, const char* level_str, const char* message, ...) {
    if (level < log_level) return;

    va_list args;
    va_start(args, message);

    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), message, args);
    va_end(args);

    snprintf(last_log, sizeof(last_log), "[%s] %s", level_str, buffer);

    printf("%s\n", last_log);
    if (log_file) {
        fprintf(log_file, "%s\n", last_log);
        fflush(log_file);
    }
}

void log_info(const char* message) {
    log_message(1, "INFO", message);
}

void log_debug(const char* message) {
    log_message(0, "DEBUG", message);
}

void log_warning(const char* message) {
    log_message(2, "WARNING", message);
}

void log_error(const char* message) {
    log_message(3, "ERROR", message);
}

void handle_error(const char* message) {
    log_error(message);
    if (log_file) {
        fprintf(log_file, "Application terminated due to error.\n");
    }
    close_logger();
    exit(EXIT_FAILURE);
}

void close_logger() {
    if (log_file) {
        fprintf(log_file, "Logger closed.\n");
        fclose(log_file);
        log_file = NULL;
    }
}

void configure_logger(const char* filename, int level) {
    set_log_level(level);
    init_logger(filename);
}

void print_last_log() {
    if (strlen(last_log) > 0) {
        printf("Last log: %s\n", last_log);
    } else {
        printf("No logs recorded yet.\n");
    }
}

void clear_logs() {
    if (log_file) {
        freopen(NULL, "w", log_file);
        fprintf(log_file, "Logs cleared.\n");
    }
    memset(last_log, 0, sizeof(last_log));
}

void log_to_file(const char* message, const char* filename) {
    FILE* temp_file = fopen(filename, "a");
    if (!temp_file) {
        fprintf(stderr, "Failed to open file for logging: %s\n", filename);
        return;
    }
    fprintf(temp_file, "%s\n", message);
    fclose(temp_file);
}

void log_complex_data(const char* message, const char* data) {
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s: %s", message, data);
    log_info(buffer);
}
