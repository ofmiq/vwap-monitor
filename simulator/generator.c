#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "generator.h"

static const char *TICKER_NAMES[] = {"AAPL", "GOOG", "MSFT", "AMZN", "TSLA",
                                     "META", "NVDA", "NFLX", "AMD",  "INTC"};

static void sleep_us(long long us)
{
     struct timespec ts;

     if(us <= 0)
     {
          return;
     }

     ts.tv_sec  = us / 1000000;
     ts.tv_nsec = (us % 1000000) * 1000;

     nanosleep(&ts, NULL);
}

static long long compute_pause(SimState *state)
{
     long long base_pause;
     double    roll;

     base_pause = 1000000 / state->config->rate;

     roll = (double)rand() / RAND_MAX;

     if(roll < state->config->burst)
     {
          return base_pause / 100;
     }

     return base_pause * (1 + (rand() % 3));
}

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
     fflush(stdout);
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

void state_destroy(SimState *state) 
{
     free(state); 
}

void run_generator(SimState *state) 
{
     long long pause_us;
     long long max_time;

     max_time = (long long)state->config->duration * 1000000;

     while(state->config->duration == 0 || state->sim_time < max_time)
     {
          generate_one(state);

          pause_us         = compute_pause(state);
          state->sim_time += pause_us;

          sleep_us(pause_us);
     }
}