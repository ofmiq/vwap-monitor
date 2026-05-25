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
                    break;
               case 'r':
                    config->rate = atoi(optarg);
                    break;
               case 'b':
                    config->burst = atof(optarg);
                    break;
               case 'c':
                    config->chaos = atof(optarg);
                    break;
               case 'd':
                    config->duration = atoi(optarg);
                    break;
               default:
                    return ARGS_ERROR;
          }
     }

     return ARGS_OK;
}