#ifndef CONFIG_H
#define CONFIG_H
typedef struct Config {
    // General settings
    int log_level;             //(0=Error, 1=Warning, 2=Info)
    char output_directory[256];

    // Simulation settings
    int max_iterations;
    double precision;

    // Visualization settings
    int enable_visualization; // 1 to enable, 0 to disable visualization
    char visualization_mode[64]; // 2d or 3d

    // Random generator settings
    int random_seed;          // (-1 for auto)

    // Quantum-specific settings
    int num_qubits;
    double initial_state[2];

} Config;

// Global instance of Config (if needed for global access)
extern Config global_config;

//config handling
void load_config(const char* config_file); // [-]
void export_config(const Config* config, const char* filename); // [-]
void reset_config(Config* config); // [-]
void print_config(); // [-]
void save_config(const char* config_file); // [-]
#endif //CONFIG_H
