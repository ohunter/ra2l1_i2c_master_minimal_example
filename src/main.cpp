#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvolatile"
#include <r_iic_master.h>
#pragma GCC diagnostic pop

extern const iic_master_extended_cfg_t g_i2c_master0_extend;

extern "C"
const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] = {
    ICU_EVENT_IIC0_RXI,
    ICU_EVENT_IIC0_TXI,
    ICU_EVENT_IIC0_TEI,
    ICU_EVENT_IIC0_ERI,
    static_cast<bsp_interrupt_event_t>(0)
};


int main() {
    constexpr uint8_t tx_data[] = {0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00};

    constexpr static auto default_callback = [](i2c_master_callback_args_t * const) constexpr noexcept {
        __asm("nop");
    };
    constexpr static auto tx_callback = [](i2c_master_callback_args_t * const args) constexpr noexcept {
        switch (args->event) {
            // case I2C_MASTER_EVENT_TX_COMPLETE: {
            //     __asm("nop");
            // }
            // break;
            default:
                __asm("nop");
        }
    };

    fsp_err_t err = FSP_SUCCESS;
    iic_master_instance_ctrl_t handle;
    i2c_master_cfg_t config = {
        .channel = 0,
        .rate = I2C_MASTER_RATE_STANDARD,
        .slave = 0,
        .addr_mode = I2C_MASTER_ADDR_MODE_7BIT,
        .ipl = 0,
        .rxi_irq = VECTOR_NUMBER_IIC0_RXI,
        .txi_irq = VECTOR_NUMBER_IIC0_TXI,
        .tei_irq = VECTOR_NUMBER_IIC0_TEI,
        .eri_irq = VECTOR_NUMBER_IIC0_ERI,
        .p_transfer_tx = nullptr,
        .p_transfer_rx = nullptr,
        .p_callback = default_callback,
        .p_context = &handle,
        .p_extend = &g_i2c_master0_extend,
    };
    i2c_master_callback_args_t xfer_mem{nullptr, i2c_master_event_t::I2C_MASTER_EVENT_ABORTED};
    
    err = R_IIC_MASTER_Open(&handle, &config);
    if (err != FSP_SUCCESS)
        return -1;

    err = R_IIC_MASTER_Abort(&handle);
    if (err != FSP_SUCCESS)
        return -2;

    err = R_IIC_MASTER_CallbackSet(&handle, tx_callback, nullptr, &xfer_mem);
    if (err != FSP_SUCCESS)
        return -3;

    err = R_IIC_MASTER_SlaveAddressSet(&handle, 0x10, I2C_MASTER_ADDR_MODE_7BIT);
    if (err != FSP_SUCCESS)
        return -4;

    err = R_IIC_MASTER_Write(&handle, const_cast<uint8_t*>(tx_data), sizeof(tx_data), true);
    if (err != FSP_SUCCESS)
        return -5;
    
    while (1) {
        __asm("nop");
    }

    return 0;
}