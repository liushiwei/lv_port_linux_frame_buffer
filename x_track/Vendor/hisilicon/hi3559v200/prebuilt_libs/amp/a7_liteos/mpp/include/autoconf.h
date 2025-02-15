/*
 * Automatically generated C config: don't edit
 * Busybox version: 
 */
#define AUTOCONF_TIMESTAMP "2019-09-19 09:26:46 CST"


/*
 * General Setup
 */
#define CONFIG_HI3516CV500 1
#define CONFIG_HI_CHIP_TYPE 0x3516C500
#define CONFIG_HI_ARCH "hi3516cv500"
#define CONFIG_HI_SUBARCH "hi3559v200"
#define CONFIG_HI_SUBCHIP_TYPE 0x35590200
#define CONFIG_SUBCHIP_HI3559V200 1
#define CONFIG_HI_SUBARCH "hi3559v200"
#define CONFIG_HI_SUBCHIP_TYPE 0x35590200
#define CONFIG_AMP 1
#define CONFIG_ARM_ARCH_TYPE "amp"
#define CONFIG_A7 1
#define CONFIG_CPU_TYPE "a7"
#define CONFIG_VERSION_ASIC 1
#define CONFIG_HI_FPGA "n"
#define CONFIG_HUAWEI_LITEOS_OS 1
#define CONFIG_OS_TYPE "liteos"
#define CONFIG_KERNEL_VERSION "liteos"
#define CONFIG_KERNEL_ARM_HIMIX100_LINUX 1
#define CONFIG_HI_CROSS "arm-himix100-linux-"
#define CONFIG_LIBC_TYPE "uclibc"
#define CONFIG_KERNEL_BIT "KERNEL_BIT_32"
#define CONFIG_USER_ARM_HIMIX100_LINUX 1
#define CONFIG_HI_CROSS_LIB "arm-himix100-linux-"
#define CONFIG_USER_BIT "USER_BIT_32"
#define CONFIG_RELEASE_TYPE_RELEASE 1
#define CONFIG_HI_RLS_MODE "HI_RELEASE"
#define CONFIG_CUSTOMER_VERSION_COMMON 1
#define CONFIG_CUSTOMER_VERSION "COMMON"

/*
 * Media Modules Setup
 */

/*
 * media base config
 */

/*
 * media sys config
 */
#define CONFIG_HI_SYS_SUPPORT 1
#define CONFIG_HI_SYS_SCALE_COEF_SUPPORT 1

/*
 * media vi config
 */
#define CONFIG_HI_VI_SUPPORT 1
#define CONFIG_HI_VI_BT656 1
#define CONFIG_HI_VI_MIPI 1
#define CONFIG_HI_VI_LDCV1_SUPPORT 1
#define CONFIG_HI_VI_LDCV2_SUPPORT 1
#define CONFIG_HI_VI_SENDYUV_SUPPORT 1
#define CONFIG_HI_VI_3DNRX_SUPPORT 1
#define CONFIG_HI_SNAP_SUPPORT 1

/*
 * media isp config
 */
#define CONFIG_HI_ISP_SUPPORT 1
#define CONFIG_HI_ISP_AF_SUPPORT 1
#define CONFIG_HI_ISP_CR_SUPPORT 1
#define CONFIG_HI_ISP_SPECAWB_SUPPORT 1
#define CONFIG_HI_ISP_DPC_STATIC_TABLE_SUPPORT 1
#define CONFIG_HI_ISP_LITEOS_BOTTOM_HALF_SUPPORT 1

/*
 * media dis config
 */
#define CONFIG_HI_DIS_SUPPORT 1

/*
 * media vpss config
 */
#define CONFIG_HI_VPSS_SUPPORT 1
#define CONFIG_HI_VPSS_3DNR_SUPPORT 1
#define CONFIG_HI_VPSS_BUF_SHARE_SUPPORT 1
#define CONFIG_HI_VPSS_SPREAD_SUPPORT 1

/*
 * media avs config
 */

/*
 * media gdc config
 */
#define CONFIG_HI_GDC_SUPPORT 1
#define CONFIG_HI_GDC_LOWDELAY_SUPPORT 1
#define CONFIG_HI_GDC_NNIE_SHARE_RAM 1

/*
 * media vgs config
 */
#define CONFIG_HI_VGS_SUPPORT 1

/*
 * media chnl config
 */
#define CONFIG_HI_CHNL_SUPPORT 1

/*
 * media venc config
 */
#define CONFIG_HI_VENC_SUPPORT 1
#define CONFIG_HI_H265E_SUPPORT 1
#define CONFIG_HI_H265E_USERDATA_SUPPORT 1
#define CONFIG_HI_H265E_INTRA_REFRESH_SUPPORT 1
#define CONFIG_HI_H264E_SUPPORT 1
#define CONFIG_HI_H264E_SVC_SUPPORT 1
#define CONFIG_HI_H264E_USERDATA_SUPPORT 1
#define CONFIG_HI_H264E_INTRA_REFRESH_SUPPORT 1
#define CONFIG_HI_JPEGE_SUPPORT 1
#define CONFIG_HI_MJPEGE_SUPPORT 1
#define CONFIG_HI_JPEGE_DCF_SUPPORT 1
#define CONFIG_HI_JPEGE_USERDATA_SUPPORT 1
#define CONFIG_HI_VENC_LOWDELAY_SUPPORT 1
#define CONFIG_HI_VENC_MPF_VGS_SUPPORT 1
#define CONFIG_HI_VENC_VGS_SUPPORT 1
#define CONFIG_HI_VENC_RCNREF_SHARE_SUPPORT 1
#define CONFIG_HI_VENC_SCENE1_SUPPORT 1
#define CONFIG_HI_VENC_SCENE2_SUPPORT 1
#define CONFIG_HI_RC_QVBR_SUPPORT 1

/*
 * media vdec config
 */
#define CONFIG_HI_VDEC_SUPPORT 1
#define CONFIG_HI_H265D_SUPPORT 1
#define CONFIG_HI_H264D_SUPPORT 1
#define CONFIG_VDEC_IP "VDEC_IP_VEDU"
#define CONFIG_HI_JPEGD_SUPPORT 1
#define CONFIG_HI_JPEGD_PROGRESSIVE 1
#define CONFIG_VDEC_USERDATA_SUPPORT 1

/*
 * media vo config
 */
#define CONFIG_HI_VO_SUPPORT 1
#define CONFIG_HI_VO_FB_SEPARATE 1
#define CONFIG_HI_VO_VGS 1
#define CONFIG_HI_VO_GRAPH 1

/*
 * media region config
 */
#define CONFIG_HI_REGION_SUPPORT 1
#define CONFIG_HI_RGN_VGS_QUICKCOPY_SUPPORT 1

/*
 * media audio config
 */
#define CONFIG_HI_AUDIO_SUPPORT 1
#define CONFIG_HI_ACODEC_SUPPORT 1
#define CONFIG_HI_ACODEC_VERSION "V660"
#define CONFIG_HI_ACODEC_MAX_GAIN 56
#define CONFIG_HI_ACODEC_MIN_GAIN 0
#define CONFIG_HI_ACODEC_GAIN_STEP 3
#define CONFIG_HI_ACODEC_FAST_POWER_SUPPORT 1
#define CONFIG_HI_DOWNVQE_SUPPORT 1
#define CONFIG_HI_TALKVQE_SUPPORT 1
#define CONFIG_HI_RECORDVQE_SUPPORT 1

/*
 * media hdr config
 */

/*
 * media mcf config
 */

/*
 * Device Driver Setup
 */

/*
 * drv config
 */
#define CONFIG_DRV 1
#define CONFIG_EXTDRV 1
#define CONFIG_INTERDRV 1
#define CONFIG_HIUSER 1
#define CONFIG_MIPI_TX 1
#define CONFIG_MIPI_RX 1
#define CONFIG_HI_RTC 1

/*
 * Component Setup
 */

/*
 * Component hdmi Config
 */
#define CONFIG_HI_HDMI_SUPPORT 1

/*
 * Component hifb Config
 */

/*
 * Component svp Config
 */
#define CONFIG_HI_SVP_SUPPORT 1
#define CONFIG_HI_SVP_CNN 1
#define CONFIG_HI_SVP_NNIE_FD 1
#define CONFIG_HI_SVP_NNE 1
#define CONFIG_HI_SVP_IVE 1
#define CONFIG_HI_SVP_IVE_CSC 1
#define CONFIG_HI_SVP_IVE_FILTER_AND_CSC 1
#define CONFIG_HI_SVP_IVE_NCC 1
#define CONFIG_HI_SVP_IVE_LBP 1
#define CONFIG_HI_SVP_IVE_NORM_GRAD 1
#define CONFIG_HI_SVP_IVE_ST_CANDI_CORNER 1
#define CONFIG_HI_SVP_IVE_RESIZE 1
#define CONFIG_HI_SVP_IE 1
#define CONFIG_HI_SVP_MD 1

/*
 * Component photo Config
 */

/*
 * Component tde Config
 */

/*
 * Component pciv Config
 */

/*
 * Component avs lut Config
 */

/*
 * Component pos_query Config
 */

/*
 * Component tzasc Config
 */

/*
 * Component motionfusion config
 */
#define CONFIG_HI_MOTIONFUSION_SUPPORT 1

/*
 * Component pm Config
 */
#define CONFIG_HI_PM_SUPPORT 1

/*
 * HISYSLINK Setup
 */

/*
 * hisyslink config
 */
#define CONFIG_HISYSLINK 1

/*
 * Debug Config
 */
#define CONFIG_HI_GDB_NO 1
#define CONFIG_HI_GDB "n"
#define CONFIG_HI_LOG_TRACE_SUPPORT 1
#define CONFIG_HI_LOG_TRACE_ALL 1
#define CONFIG_HI_LOG_TRACE_LEVEL 7

/*
 * Test Config
 */
