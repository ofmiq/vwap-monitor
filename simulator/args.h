#ifndef SIMULATOR_ARGS_H
#define SIMULATOR_ARGS_H

#define DEFAULT_TICKERS 5
#define DEFAULT_RATE 100
#define DEFAULT_BURST 0.5
#define DEFAULT_CHAOS 0.3
#define DEFAULT_DURATION 60

#define ARGS_OK 0
#define ARGS_ERROR 1

typedef struct
{
     int    num_tickers;
     int    rate;
     double burst;
     double chaos;
     int    duration;
} SimConfig;

int parse_args(int argc, char *argv[], SimConfig *config);

#endif