project(ra2l1 LANGUAGES CXX C)

add_library(ra2l1 OBJECT
    # This is first so that the `R_BSP_WarmStart` symbol is defined when needed and won't be confused with the weak symbol defined later in system.c
    src/hal_entry.cpp

    ra_gen/common_data.c
    ra_gen/hal_data.c
    ra_gen/pin_data.c
    ra_gen/vector_data.c
    ra/board/ra2l1_ek/board_init.c
    ra/board/ra2l1_ek/board_leds.c
    ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/startup.c
    ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/system.c
    ra/fsp/src/bsp/mcu/all/bsp_clocks.c
    ra/fsp/src/bsp/mcu/all/bsp_common.c
    ra/fsp/src/bsp/mcu/all/bsp_delay.c
    ra/fsp/src/bsp/mcu/all/bsp_group_irq.c
    ra/fsp/src/bsp/mcu/all/bsp_guard.c
    ra/fsp/src/bsp/mcu/all/bsp_io.c
    ra/fsp/src/bsp/mcu/all/bsp_irq.c
    ra/fsp/src/bsp/mcu/all/bsp_register_protection.c
    ra/fsp/src/bsp/mcu/all/bsp_rom_registers.c
    ra/fsp/src/bsp/mcu/all/bsp_sbrk.c
    ra/fsp/src/bsp/mcu/all/bsp_security.c
    ra/fsp/src/bsp/mcu/ra2l1/bsp_power.c
    ra/fsp/src/r_iic_master/r_iic_master.c
    ra/fsp/src/r_ioport/r_ioport.c
)

target_compile_definitions(ra2l1
    PUBLIC _RENESAS_RA_
    PUBLIC _RA_CORE=CM23
)

target_include_directories(ra2l1
    PUBLIC ra/fsp/inc
    PUBLIC ra/fsp/inc/api
    PUBLIC ra/fsp/inc/instances
    PUBLIC ra_cfg/fsp_cfg
    PUBLIC ra_cfg/fsp_cfg/bsp
    PUBLIC ra_gen
)

target_link_libraries(ra2l1
    PRIVATE common
    PUBLIC CMSIS_Core
)

target_link_options(ra2l1
    INTERFACE LINKER:--library-path=${CMAKE_CURRENT_SOURCE_DIR}
    INTERFACE LINKER:--script=${CMAKE_CURRENT_SOURCE_DIR}/script/fsp.ld
    INTERFACE LINKER:--print-memory-usage
    INTERFACE LINKER:--no-demangle
)

set_target_properties(ra2l1 PROPERTIES LINK_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/script/fsp.ld)
