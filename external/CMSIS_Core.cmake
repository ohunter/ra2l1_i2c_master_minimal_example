
project(CMSIS_Core)

add_library(CMSIS_Core
    INTERFACE
)

target_include_directories(CMSIS_Core
    INTERFACE
    cmsis_core/Include
)
