#ifndef ERROR_LOGGER_H
#define ERROR_LOGGER_H

/*
 * Error logging program that can log to stderr or
 * a logfile.
 * Uses different colors for each type when printed to
 * stderr.
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define NO_ERRNO 0
#define USE_ERRNO 1

enum msgType
{
        INFO,
        WARNING,
        ERROR
};

struct msg
{
        char* msg;
        enum msgType type;
};

// Prints an error message to stderr or a file
void printMsg(struct msg value, FILE *file, int useErrno);
#endif // ERROR_LOGGER_H
