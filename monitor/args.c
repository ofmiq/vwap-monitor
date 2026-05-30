#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "args.h"

int parse_args(int argc, char *argv[], MonConfig *config)
{
     int opt;

     config->window     = DEFAULT_WINDOW;
     config->lag        = DEFAULT_LAG;
     config->precision  = DEFAULT_PRECISION;
     config->show_empty = DEFAULT_SHOW_EMPTY;

     while((opt = getopt(argc, argv, "a:l:p:z")) != -1)
     {
          switch(opt)
          {
               case 'a':
                    config->window = atoi(optarg);
                    if(config->window < 1)
                    {
                         fprintf(stderr, "error: window must be at least 1 second\n");
                         return ARGS_ERROR;
                    }
                    break;
               case 'l':
                    config->lag = atoi(optarg);
                    if(config->lag < 1)
                    {
                         fprintf(stderr, "error: lag must be at least 1 ms\n");
                         return ARGS_ERROR;
                    }
                    break;
               case 'p':
                    config->precision = atoi(optarg);
                    if(config->precision < 0 || config->precision > 10)
                    {
                         fprintf(stderr, "error: precision must be between 0 and 10\n");
                         return ARGS_ERROR;
                    }
                    break;
               case 'z':
                    config->show_empty = 1;
                    break;
               default:
                    return ARGS_ERROR;
          }
     }

     return ARGS_OK;
}