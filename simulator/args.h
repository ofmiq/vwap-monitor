#ifndef SIMULATOR_ARGS_H
#define SIMULATOR_ARGS_H

/**
 * @file args.h
 * @brief Argument parsing for the simulator module
 */

// Default values for simulator options
#define DEFAULT_TICKERS 5
#define DEFAULT_RATE 100
#define DEFAULT_BURST 0.5
#define DEFAULT_CHAOS 0.3
#define DEFAULT_DURATION 60

// Return codes
#define ARGS_OK 0
#define ARGS_ERROR 1

/**
 * @brief Holds all runtime parameters for the simulator
 */
typedef struct
{
     int    num_tickers; /**< Number of tickers to simulate */
     int    rate;        /**< Average trade messages per second */
     double burst;       /**< Burst coefficient */
     double chaos;       /**< Chaos coefficient  */
     int    duration;    /**< Simulation duration in seconds */
} SimConfig;

/**
 * @brief Parse command line arguments
 * @param argc Argument count
 * @param argv Argument vector
 * @param config Pointer to SimConfig struct
 * @return ARGS_OK on success, ARGS_ERROR on unknown flag
 */
int parse_args(int argc, char *argv[], SimConfig *config);

#endif