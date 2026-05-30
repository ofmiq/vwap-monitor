#ifndef SIMULATOR_GENERATOR_H
#define SIMULATOR_GENERATOR_H

/**
 * @file generator.h
 * @brief Trade generation for the simulator module
 */

#include "args.h"

// Generation constraints
#define MAX_TICKER_LEN 8
#define MAX_TICKERS    10
#define BASE_PRICE     10000
#define PRICE_RANGE    5000
#define MAX_VOLUME     1000

/**
 * @brief Holds the internal state of the trade generator
 */
typedef struct
{
     char       tickers[MAX_TICKERS][MAX_TICKER_LEN]; /**< Array of ticker symbols */
     long long  sim_time;                             /**< Current simulation time in microseconds */
     SimConfig *config;                               /**< Pointer to runtime configuration */
} SimState;

/**
 * @brief Allocates and initialises a SimState struct
 * @param config Pointer to a SimConfig struct
 * @return Pointer to a newly allocated SimState, or NULL on failure
 */
SimState *state_create(SimConfig *config);

/**
 * @brief Frees all memory associated with a SimState
 * @param state Pointer to the SimState to destroy
 */
void      state_destroy(SimState *state);

/**
 * @brief Runs the main generation loop
 * @param state Pointer to an initialised SimState
 */
void      run_generator(SimState *state);

#endif