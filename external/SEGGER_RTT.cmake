
project(SEGGER_RTT)

add_library(SEGGER_RTT
    STATIC
    rtt/RTT/SEGGER_RTT.c
    rtt/RTT/SEGGER_RTT_printf.c
    rtt/Syscalls/SEGGER_RTT_Syscalls_GCC.c
)

target_include_directories(SEGGER_RTT
    PRIVATE
    rtt/Config
    PUBLIC
    rtt/RTT/
)

target_compile_options(SEGGER_RTT
    PRIVATE
    -fno-builtin
)

target_compile_definitions(SEGGER_RTT
    INTERFACE
    PRINTF_SINK=PRINTF_SINK_RTT # Used to wrap printf to SEGGER_RTT_printf
)
