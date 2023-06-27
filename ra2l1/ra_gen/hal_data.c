/* generated HAL source file - do not edit */
#include "hal_data.h"
iic_master_instance_ctrl_t g_i2c_master0_ctrl;
const iic_master_extended_cfg_t g_i2c_master0_extend =
{
    .timeout_mode             = IIC_MASTER_TIMEOUT_MODE_SHORT,
    .timeout_scl_low          = IIC_MASTER_TIMEOUT_SCL_LOW_ENABLED,
    /* Actual calculated bitrate: 99272. Actual calculated duty cycle: 49%. */ .clock_settings.brl_value = 27, .clock_settings.brh_value = 26, .clock_settings.cks_value = 2,
};
const i2c_master_cfg_t g_i2c_master0_cfg =
{
    .channel             = 0,
    .rate                = I2C_MASTER_RATE_STANDARD,
    .slave               = 0x00,
    .addr_mode           = I2C_MASTER_ADDR_MODE_7BIT,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
                .p_transfer_tx       = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
                .p_transfer_rx       = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
    .p_callback          = NULL,
    .p_context           = NULL,
#if defined(VECTOR_NUMBER_IIC0_RXI)
    .rxi_irq             = VECTOR_NUMBER_IIC0_RXI,
#else
    .rxi_irq             = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC0_TXI)
    .txi_irq             = VECTOR_NUMBER_IIC0_TXI,
#else
    .txi_irq             = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC0_TEI)
    .tei_irq             = VECTOR_NUMBER_IIC0_TEI,
#else
    .tei_irq             = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC0_ERI)
    .eri_irq             = VECTOR_NUMBER_IIC0_ERI,
#else
    .eri_irq             = FSP_INVALID_VECTOR,
#endif
    .ipl                 = (2),
    .p_extend            = &g_i2c_master0_extend,
};
/* Instance structure to use this module. */
const i2c_master_instance_t g_i2c_master0 =
{
    .p_ctrl        = &g_i2c_master0_ctrl,
    .p_cfg         = &g_i2c_master0_cfg,
    .p_api         = &g_i2c_master_on_iic
};
void g_hal_init(void) {
g_common_init();
}
