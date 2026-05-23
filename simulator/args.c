#include "args.h"

int parse_args(int argc, char *argv[], SimConfig *config)
{
     int opt;

     config->num_tickers = DEFAULT_TICKERS;
     config->rate        = DEFAULT_RATE;
     config->burst       = DEFAULT_BURST;
     config->chaos       = DEFAULT_CHAOS;
     config->duration    = DEFAULT_DURATION;

     /* implement flag handling */
}