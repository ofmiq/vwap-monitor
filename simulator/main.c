#include <stdio.h>
#include <stdlib.h>

#include "args.h"

int main(int argc, char *argv[])
{
     SimConfig config;

     if(parse_args(argc, argv, &config) == ARGS_ERROR)
     {
          return 1;
     }

     // debug: print parsed config
     printf("tickers:  %d\n", config.num_tickers);
     printf("rate:     %d\n", config.rate);
     printf("burst:    %.2f\n", config.burst);
     printf("chaos:    %.2f\n", config.chaos);
     printf("duration: %d\n", config.duration);

     return 0;
}