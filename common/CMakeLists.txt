project(common LANGUAGES CXX C ASM)

add_library(common
    STATIC
    syscalls.cpp
    print.cpp
)

target_compile_options(common
    PRIVATE
    -fno-builtin
    -fno-common
    -ffunction-sections
    -fdata-sections
    -ffreestanding
    -fmerge-constants
    -fno-threadsafe-statics
)

target_link_options(common
    INTERFACE
    LINKER:--wrap=printf
)

target_link_libraries(common PRIVATE
    -lgcc
    -lc
    SEGGER_RTT
)