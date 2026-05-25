#ifndef SIMULATOR_GENERATOR_H
#define SIMULATOR_GENERATOR_H

#include "args.h"

#define MAX_TICKER_LEN 8
#define MAX_TICKERS    10
#define BASE_PRICE     10000
#define PRICE_RANGE    5000
#define MAX_VOLUME     1000

typedef struct
{
     char       tickers[MAX_TICKERS][MAX_TICKER_LEN];
     long long  sim_time;
     SimConfig *config;
} SimState;

SimState *state_create(SimConfig *config);
void      state_destroy(SimState *state);
void      run_generator(SimState *state);

#endif