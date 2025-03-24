#ifndef OPTIONS_HEADER
#define OPTIONS_HEADER

#include <getopt.h>

static struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
};

#endif