// This is the header provided by AllWinner SDK
// Put in the start of spl image
// Starting at 8K from the start of the SD card.
#include <defs.h>

const boot0_file_head_t header = {
    {
        /* jump_instruction*/
        JUMP_INSTRUCTION,
        BOOT0_MAGIC,
        STAMP_VALUE,
    #ifdef ALIGN_SIZE_8K
        0x2000,
    #else
        0x4000,
    #endif
        sizeof(boot_file_head_t),
        BOOT_PUB_HEAD_VERSION,
        CONFIG_BOOT0_RET_ADDR,
        CONFIG_BOOT0_RUN_ADDR,
        0,
        {
        /*brom modify: nand-4bytes sdmmc-2bytes*/
        5, 0, 0, 0, '4', '.', '0', 0
        },
    },

    {
        /*__u32 prvt_head_size;*/
        0,
        /*char prvt_head_vsn[4];*/
        8,
        0,/* power_mode */
        {0},/* reserver[2]  */
        /*unsigned int     dram_para[32] ;*/
        {
            0x00000318,
            0x00000003,
            0x007b7bfb,
            0x00000001,
            0x000010d2,
            0x00000000,
            0x00001c70,
            0x00000042,
            0x00000018,
            0x00000000,
            0x004a2195,
            0x02423190,
            0x0008b061,
            0xb4787896,
            0x00000000,
            0x48484848,
            0x00000048,
            0x1620121e,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00870000,
            0x00000024,
            0x34050100,
        },
        /*__s32	uart_port;*/
        0,
        /*normal_gpio_cfg   uart_ctrl[2];*/
        {
            {2, 8, 6, 1, 0xff, 0xff, {0} }, /*PB8: 6--RX*/
            {2, 9, 6, 1, 0xff, 0xff, {0} }, /*PB9: 6--TX*/
        },
        /*__s32 enable_jtag;*/
        0,
        /*normal_gpio_cfg	 jtag_gpio[5];*/
        {
            {6, 0, 4, 0xff, 0xff, 0xff, {0} },
            {6, 5, 4, 0xff, 0xff, 0xff, {0} },
            {6, 3, 4, 0xff, 0xff, 0xff, {0} },
            {6, 1, 4, 0xff, 0xff, 0xff, {0} },
        },
        /*normal_gpio_cfg   storage_gpio[32];*/
        {
            {6, 2, 2, 1, 2, 0xff, {0} },/*PF0-5: 2--SDC*/
            {6, 3, 2, 1, 2, 0xff, {0} },
            {6, 1, 2, 1, 2, 0xff, {0} },
            {6, 0, 2, 1, 2, 0xff, {0} },
            {6, 5, 2, 1, 2, 0xff, {0} },
            {6, 4, 2, 1, 2, 0xff, {0} },
        },
        /*char  storage_data[512 - sizeof(normal_gpio_cfg) * 32];*/
#ifdef CFG_SUNXI_SDMMC
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
            0x02, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
#endif
#ifdef CFG_SUNXI_SPINAND
        // for Nezha_D1-H 2Gb MX35LF2GE4AD SPI NAND Flash
        {
            0x01, 0x00, 0x01, 0x01, 0x01, 0x04, 0x00, 0x00,
            0x40, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,
            0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0xc2, 0x26, 0x03, 0xff,
            0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0xe8, 0xfd, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        }
#endif
    },
    {CI_INFO},
#ifdef CFG_SUNXI_SELECT_DRAM_PARA
    .fes_union_addr.extd_head.magic = DRAM_EXT_MAGIC,
#endif
};
