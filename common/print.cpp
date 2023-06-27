#include <stdio.h>
#include <cstdarg>

#define PRINTF_SINK_RTT 1

#ifndef PRINTF_SINK
#define PRINTF_SINK 0
#endif

#if PRINTF_SINK == PRINTF_SINK_RTT
    #include <SEGGER_RTT.h>
    #define VPRINTF_FN SEGGER_RTT_vprintf
#else
    #define VPRINTF_FN(idx, format, args) []() constexpr noexcept { return 0; }()
#endif

extern "C"
int __wrap_printf(const char *format, ...) {
    std::va_list args;
    va_start(args, format);

    int ret = VPRINTF_FN(0, format, &args);

    va_end(args);

    return ret;
}