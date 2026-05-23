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

     return 0;
}