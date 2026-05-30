#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "args.h"

int parse_args(int argc, char *argv[], SimConfig *config)
{
     int opt;

     config->num_tickers = DEFAULT_TICKERS;
     config->rate        = DEFAULT_RATE;
     config->burst       = DEFAULT_BURST;
     config->chaos       = DEFAULT_CHAOS;
     config->duration    = DEFAULT_DURATION;

     while((opt = getopt(argc, argv, "t:r:b:c:d:")) != -1)
     {
          switch(opt)
          {
               case 't':
                    config->num_tickers = atoi(optarg);
                    if(config->num_tickers < 1 || config->num_tickers > MAX_TICKERS)
                    {
                         fprintf(stderr, "error: tickers must be between 1 and %d\n", MAX_TICKERS);
                         return ARGS_ERROR;
                    }
                    break;
               case 'r':
                    config->rate = atoi(optarg);
                    if(config->rate < 1)
                    {
                         fprintf(stderr, "error: rate must be at least 1\n");
                         return ARGS_ERROR;
                    }
                    break;
               case 'b':
                    config->burst = atof(optarg);
                    if(config->burst < 0.0 || config->burst > 1.0)
                    {
                         fprintf(stderr, "error: burst must be between 0.0 and 1.0\n");
                         return ARGS_ERROR;
                    }
                    break;
               case 'c':
                    config->chaos = atof(optarg);
                    if(config->chaos < 0.0 || config->chaos > 1.0)
                    {
                         fprintf(stderr, "error: chaos must be between 0.0 and 1.0\n");
                         return ARGS_ERROR;
                    }
                    break;
               case 'd':
                    config->duration = atoi(optarg);
                    if(config->duration < 0)
                    {
                         fprintf(stderr, "error: duration must be 0 or greater\n");
                         return ARGS_ERROR;
                    }
                    break;
               default:
                    return ARGS_ERROR;
          }
     }

     return ARGS_OK;
}