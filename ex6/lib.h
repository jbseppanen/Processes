#ifndef lib_h
#define lib_h

int clock_get(struct timespec *tv)
{
    return timespec_get(tv, TIME_UTC);
}
#endif