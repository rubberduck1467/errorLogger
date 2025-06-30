#ifndef ERROR_LOGGER_H
#define ERROR_LOGGER_H

/*
 * Error logging program that can log to stderr or
 * a logfile.
 * Uses different colors for each type when printed to
 * stderr or the file is outputed to terminal using cat.
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define NO_ERRNO 0
#define USE_ERRNO 1

enum log_msg_type
{
        INFO,
        WARNING,
        ERROR
};

struct log_msg
{
        char* msg;
        enum log_msg_type type;
};

// Prints an error message to stderr or a file
void printLogMsg(struct log_msg msg, FILE *file, int useErrno);
#endif // ERROR_LOGGER_H
