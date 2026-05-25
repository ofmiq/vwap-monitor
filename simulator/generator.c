#include <stdlib.h>

#include "generator.h"

static const char *TICKER_NAMES[] = {"AAPL", "GOOG", "MSFT", "AMZN", "TSLA",
                                     "META", "NVDA", "NFLX", "AMD",  "INTC"};

SimState *state_create(SimConfig *config)
{
     SimState *state;
     int       i;

     state = (SimState *)malloc(sizeof(SimState));
     if(state == NULL)
     {
          return NULL;
     }

     state->config   = config;
     state->sim_time = 0;

     for(i = 0; i < config->num_tickers; i++)
     {
          strncpy(state->tickers[i], TICKER_NAMES[i], MAX_TICKER_LEN - 1);
          state->tickers[i][MAX_TICKER_LEN - 1] = '\0';
     }

     return state;
}

void state_destroy(SimState *state) { free(state); }