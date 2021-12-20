/**
 * @file    Utils.cpp
 * @brief   Utils module
 *
 * Copyright (c) 2021 AlgoIdeas
 *
 * @author    AlgoIdeas
 * @date      2021/8/16
 * @version   1.0
 */

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>


uint32_t system_tick(void)
{
    static uint32_t basic_ms = 0;
    uint32_t ms = 0;
    struct timespec monotonic_time;

    memset(&monotonic_time, 0, sizeof(struct timespec));
    if (basic_ms == 0)
    {
        clock_gettime(CLOCK_MONOTONIC, &monotonic_time);
        basic_ms = monotonic_time.tv_sec * 1000 + monotonic_time.tv_nsec/1000000;
    }

    clock_gettime(CLOCK_MONOTONIC, &monotonic_time);
    ms = monotonic_time.tv_sec * 1000 + monotonic_time.tv_nsec/1000000;

    return (ms - basic_ms);
}


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

