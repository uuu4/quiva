#ifndef CONFIG_H
#define CONFIG_H

typedef struct Config {
    // General settings
    int log_level;            // Logging verbosity (e.g., 0=Error, 1=Warning, 2=Info)
    char output_directory[256]; // Directory to save outputs

    // Simulation settings
    int max_iterations;       // Maximum iterations for a simulation
    double precision;         // Precision threshold for calculations

    // Visualization settings
    int enable_visualization; // 1 to enable, 0 to disable visualization
    char visualization_mode[64]; // Visualization type (e.g., "2D", "3D")

    // Random generator settings
    int random_seed;          // Seed for random number generator (-1 for auto)

    // Quantum-specific settings
    int num_qubits;           // Number of qubits in the system
    double initial_state[2];  // Initial quantum state (real and imaginary parts)

} Config;

// Global instance of Config (if needed for global access)
extern Config global_config;

