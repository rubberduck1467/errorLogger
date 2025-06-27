#include "logger.h"

void printMsg(struct msg value, FILE *file, int useErrno)
{
        switch(value.type) {
        case INFO:
                //print with blue background
                fprintf(file, "\033[44mINFO: ");
                break;
        case WARNING:
                fprintf(file, "\033[43mWARNING: ");
                break;
        case ERROR:
                fprintf(file, "\033[41mERROR: ");
                break;
        }

        fprintf(file, "%s", value.msg);
        if (useErrno)
                fprintf(file, "\nFROM ERRNO: %s\033[m\n", strerror(errno));
        else
                fprintf(file, "\033[m\n");
}
