#include <stdio.h>
#include <stdlib.h>

#include "args.h"

int main(int argc, char *argv[])
{
     MonConfig config;

     if(parse_args(argc, argv, &config) == ARGS_ERROR)
     {
          return EXIT_FAILURE;
     }

     printf("window:     %d seconds\n", config.window);
     printf("lag:        %d ms\n",      config.lag);
     printf("precision:  %d\n",         config.precision);
     printf("show_empty: %d\n",         config.show_empty);

     return EXIT_SUCCESS;
}