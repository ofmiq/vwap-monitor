#ifndef SIMULATOR_GENERATOR_H
#define SIMULATOR_GENERATOR_H

#include "args.h"

#define MAX_TICKER_LEN 8
#define MAX_TICKERS    10

typedef struct
{
     char       tickers[MAX_TICKERS][MAX_TICKER_LEN];
     long long  sim_time;
     SimConfig  *config;
} SimState;

SimState *state_create(SimConfig *config);
void state_destroy(SimState *state);

#endif