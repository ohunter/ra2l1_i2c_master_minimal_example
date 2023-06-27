project(ra2l1 LANGUAGES CXX C)

add_library(ra2l1_c STATIC
    ra/board/ra2l1_ek/board_init.c
    ra/board/ra2l1_ek/board_leds.c
    ra/fsp/src/r_ioport/r_ioport.c
    ra/fsp/src/r_iic_master/r_iic_master.c
    ra/fsp/src/bsp/mcu/ra2l1/bsp_power.c
    ra/fsp/src/bsp/mcu/all/bsp_delay.c
    ra/fsp/src/bsp/mcu/all/bsp_security.c
    ra/fsp/src/bsp/mcu/all/bsp_rom_registers.c
    ra/fsp/src/bsp/mcu/all/bsp_clocks.c
    ra/fsp/src/bsp/mcu/all/bsp_irq.c
    ra/fsp/src/bsp/mcu/all/bsp_register_protection.c
    ra/fsp/src/bsp/mcu/all/bsp_guard.c
    ra/fsp/src/bsp/mcu/all/bsp_group_irq.c
    ra/fsp/src/bsp/mcu/all/bsp_io.c
    ra/fsp/src/bsp/mcu/all/bsp_sbrk.c
    ra/fsp/src/bsp/mcu/all/bsp_common.c
    ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/startup.c
    ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/system.c
    ra_gen/vector_data.c
    ra_gen/pin_data.c
    ra_gen/hal_data.c
    ra_gen/common_data.c
)

target_include_directories(ra2l1_c
    PUBLIC ra/fsp/inc
    PUBLIC ra/fsp/inc/api
    PUBLIC ra/fsp/inc/instances
    PUBLIC ra_cfg/fsp_cfg
    PUBLIC ra_cfg/fsp_cfg/bsp
    PUBLIC ra_gen
)

target_compile_definitions(ra2l1_c
    PUBLIC _RENESAS_RA_
    PUBLIC _RA_CORE=CM23
)

target_link_libraries(ra2l1_c
    PRIVATE common
    PUBLIC CMSIS_Core
)

target_link_options(ra2l1_c
    INTERFACE LINKER:--library-path=${CMAKE_CURRENT_SOURCE_DIR}
    INTERFACE LINKER:--script=${CMAKE_CURRENT_SOURCE_DIR}/script/fsp.ld
    INTERFACE LINKER:--print-memory-usage
)

set_target_properties(ra2l1_c PROPERTIES LINK_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/script/fsp.ld)

# This is added as a separate library because GNU ld expects weak symbols to be overwritten in other libraries
# Thus the default implementations of `R_BSP_WarmStart` will be replaced by the one provided in hal_entry.cpp
add_library(ra2l1 STATIC
    src/hal_entry.cpp
)

target_include_directories(ra2l1 PRIVATE $<TARGET_PROPERTY:ra2l1_c,INCLUDE_DIRECTORIES>)
target_link_libraries(ra2l1 INTERFACE ra2l1_c)
