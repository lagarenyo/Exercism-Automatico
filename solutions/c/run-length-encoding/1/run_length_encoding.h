#ifndef RUN_LENGTH_ENCODING_H
#define RUN_LENGTH_ENCODING_H

#include <stdlib.h>

#define LONGIT 100

char *encode(const char *text);
char *decode(const char *data);

#endif
