#ifndef MONITOR_ARGS_H
#define MONITOR_ARGS_H

#define DEFAULT_WINDOW     10
#define DEFAULT_LAG        500
#define DEFAULT_PRECISION  4
#define DEFAULT_SHOW_EMPTY 0

#define ARGS_OK    0
#define ARGS_ERROR 1

typedef struct
{
     int window;
     int lag;
     int precision;
     int show_empty;
} MonConfig;

int parse_args(int argc, char *argv[], MonConfig *config);

#endif