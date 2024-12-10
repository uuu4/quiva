#include "config.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Config global_config = {
    .log_level = 1,  // default to "Warning"
    .output_directory = "./results",
    .max_iterations = 1000,
    .precision = 1e-9,
    .enable_visualization = 1,
    .visualization_mode = "3D",
    .random_seed = -1,
    .num_qubits = 2,
    .initial_state = {1.0, 0.0}
};

void save_config(const char* config_file) {
    FILE* file = fopen(config_file, "w");
    if (!file) {
        perror("Failed to save configuration file");
        return;
    }

    fprintf(file, "log_level = %d\n", global_config.log_level);
    fprintf(file, "output_directory = %s\n", global_config.output_directory);
    fprintf(file, "max_iterations = %d\n", global_config.max_iterations);
    fprintf(file, "precision = %e\n", global_config.precision);
    fprintf(file, "enable_visualization = %d\n", global_config.enable_visualization);
    fprintf(file, "visualization_mode = %s\n", global_config.visualization_mode);
    fprintf(file, "random_seed = %d\n", global_config.random_seed);
    fprintf(file, "num_qubits = %d\n", global_config.num_qubits);
    fprintf(file, "initial_state_real = %f\n", global_config.initial_state[0]);
    fprintf(file, "initial_state_imag = %f\n", global_config.initial_state[1]);

    fclose(file);
}

void export_config(const Config* config, const char* filename) {
    if (!config || !filename) return;
    save_config(filename);
}
void load_config(const char* config_file) {
    FILE* file = fopen(config_file, "r");
    if (!file) {
        perror("Failed to open configuration file");
        return;
    }

    char key[256];
    char value[256];

    while (fscanf(file, "%255s = %255s", key, value) != EOF) {
        if (strcmp(key, "log_level") == 0) {
            global_config.log_level = atoi(value);
        } else if (strcmp(key, "output_directory") == 0) {
            strncpy(global_config.output_directory, value, sizeof(global_config.output_directory) - 1);
        } else if (strcmp(key, "max_iterations") == 0) {
            global_config.max_iterations = atoi(value);
        } else if (strcmp(key, "precision") == 0) {
            global_config.precision = atof(value);
        } else if (strcmp(key, "enable_visualization") == 0) {
            global_config.enable_visualization = atoi(value);
        } else if (strcmp(key, "visualization_mode") == 0) {
            strncpy(global_config.visualization_mode, value, sizeof(global_config.visualization_mode) - 1);
        } else if (strcmp(key, "random_seed") == 0) {
            global_config.random_seed = atoi(value);
        } else if (strcmp(key, "num_qubits") == 0) {
            global_config.num_qubits = atoi(value);
        } else if (strcmp(key, "initial_state_real") == 0) {
            global_config.initial_state[0] = atof(value);
        } else if (strcmp(key, "initial_state_imag") == 0) {
            global_config.initial_state[1] = atof(value);
        }
    }

    fclose(file);
}

void print_config(const Config* config) {
    if (!config) return;

    printf("=== Current Configuration ===\n");
    printf("Log Level: %d\n", config->log_level);
    printf("Output Directory: %s\n", config->output_directory);
    printf("Max Iterations: %d\n", config->max_iterations);
    printf("Precision: %e\n", config->precision);
    printf("Enable Visualization: %d\n", config->enable_visualization);
    printf("Visualization Mode: %s\n", config->visualization_mode);
    printf("Random Seed: %d\n", config->random_seed);
    printf("Number of Qubits: %d\n", config->num_qubits);
    printf("Initial State: [%f, %f]\n", config->initial_state[0], config->initial_state[1]);
}

void reset_config(Config* config) {
    if (!config) return;

    config->log_level = 1;  // default to "Warning"
    strcpy(config->output_directory, "./results");
    config->max_iterations = 1000;
    config->precision = 1e-9;
    config->enable_visualization = 1;
    strcpy(config->visualization_mode, "3D");
    config->random_seed = -1;
    config->num_qubits = 2;
    config->initial_state[0] = 1.0;
    config->initial_state[1] = 0.0;
}

