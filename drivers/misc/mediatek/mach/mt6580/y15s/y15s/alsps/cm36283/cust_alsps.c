#include <linux/types.h>
#include <mach/mt_pm_ldo.h>
#include <cust_alsps.h>
#include <mach/upmu_common.h>

/* Mysteryagr
 Sync values with x510.dts */

static struct alsps_hw cust_alsps_hw = {
    .i2c_num    = 2,
   	//.i2c_addr				= <0x60 0 0 0>;
	.polling_mode_ps =0,
	.polling_mode_als =1,
    .power_id   = MT65XX_POWER_NONE,    /*LDO is not used*/
    .power_vol  = VOL_DEFAULT,          /*LDO is not used*/
    //.i2c_addr   = {0x0C, 0x48, 0x78, 0x00},
    /* MTK: modified to support AAL */
    .als_level = <0x00 0x7d 0x13f 0x20d 0x443 0x9b0 0xbf2 0x13fb 0x218d 0x2a11 0x3239 0x458f 0x564b 0xffff 0xffff>;
	.als_value = <0x00 0x85 0x12f 0x1f8 0x3ea 0x7d3 0xbbe 0x138b 0x1f42 0x2710 0x2ee0 0x3e80 0x4e20 0x4e20 0x4e20 0x4e20>;
    //.als_level  = {0, 1, 7, 15, 50, 100, 500, 1000, 2000, 3000, 6000, 10000, 14000, 18000, 20000},
    //TODO.als_value  = {0, 1, 40, 90, 160, 225, 320, 640, 1280, 2000, 3000, 4000, 6000, 8000, 10240, 20000},
    .ps_threshold_high = <0x1a>;
	.ps_threshold_low = <0x15>;
    //.ps_threshold_high = 20,
    //TODO.ps_threshold_low = 14,
    .is_batch_supported_ps = false,
    .is_batch_supported_als = false,
	
};
struct alsps_hw *get_cust_alsps_hw(void) {
    return &cust_alsps_hw;
}

