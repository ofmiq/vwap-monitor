#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "generator.h"

static const char *TICKER_NAMES[] = {"AAPL", "GOOG", "MSFT", "AMZN", "TSLA",
                                     "META", "NVDA", "NFLX", "AMD",  "INTC"};

static void generate_one(SimState *state)
{
     char      *ticker;
     int        price;
     int        volume;
     long long  max_offset;
     long long  offset;
     long long  sent_time;

     ticker     = state->tickers[rand() % state->config->num_tickers];
     price      = BASE_PRICE + (rand() % PRICE_RANGE);
     volume     = 1 + (rand() % MAX_VOLUME);
     max_offset = (long long)(1000000 / state->config->rate * state->config->chaos * 10);
     offset     = (rand() % (2 * max_offset + 1)) - max_offset;
     sent_time  = state->sim_time + offset;

     printf("%s %d %d %lld\n", ticker, price, volume, sent_time);
}

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

void run_generator(SimState *state) {
     long long max_time;
     max_time = (long long)state->config->duration * 1000000;

     while(state->config->duration == 0 || state->sim_time < max_time)
     {
          generate_one(state);
     }
}