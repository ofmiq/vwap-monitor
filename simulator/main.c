#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "args.h"
#include "generator.h"

int main(int argc, char *argv[])
{
     SimConfig config;
     SimState *state;

     if(parse_args(argc, argv, &config) == ARGS_ERROR)
     {
          return 1;
     }

     srand(time(NULL));

     state = state_create(&config);

     if(state == NULL)
     {
          return 1;
     }

     run_generator(state);
     state_destroy(state);

     return 0;
}