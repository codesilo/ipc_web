/*
****************************************************************************
*
** \file      webservice.h
**
** \version   $Id: webservice.h 2593 2015-01-16 08:57:28Z houwentao $
**
** \brief
**
** \attention THIS SAMPLE CODE IS PROVIDED AS IS. GOFORTUNE SEMICONDUCTOR
**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**            OMMISSIONS.
**
** (C) Copyright 2012-2013 by GOKE MICROELECTRONICS CO.,LTD
**
****************************************************************************
*/
#ifndef __WEBSERVICE_H__
#define __WEBSERVICE_H__

#include "adi_osd.h"
#include "mw_struct.h"
//#include "adi_venc.h"
//#define SERVER_CONFIG_PATH		"/etc/ambaipcam/mediaserver"
#define WEBSERVICE_PORT			(20000)
//#define IMAGE_SERVER_PORT			(20002)
#define BUFFER_SIZE					(1024)
#define ENCODE_STREAM_NUM           (4)
#define STREAM_ID_OFFSET			(28)
#define HOST                        "127.0.0.1"

#define false                  (0)       /*  */
#define true                !(false)      /*  */

#define OSD_TEXT_LENGTH		(64)

//#define	FILE_CONTENT_SIZE		(10 * 1024)
//
typedef int bool;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef signed short s16;
typedef unsigned short u16;

#if 1 //legacy has 
/*=========================Start AMBA_VIDEO_INFO==============================*/
#if 0
#define AMBA_VIDEO_FPS(fps)				(fps)
#define AMBA_VIDEO_FRAC_FPS(fps)		(fps)
#define AMBA_VIDEO_FPS_AUTO			0			//0
#define AMBA_VIDEO_FPS_1				512000000	//(512000000 / 1)
#define AMBA_VIDEO_FPS_2				256000000	//(512000000 / 2)
#define AMBA_VIDEO_FPS_3				170666667	//(512000000 / 3)
#define AMBA_VIDEO_FPS_4				128000000	//(512000000 / 4)
#define AMBA_VIDEO_FPS_5				102400000	//(512000000 / 5)
#define AMBA_VIDEO_FPS_6				85333333	//(512000000 / 6)
#define AMBA_VIDEO_FPS_10				51200000	//(512000000 / 10)
#define AMBA_VIDEO_FPS_15				34133333	//(512000000 / 15)
#define AMBA_VIDEO_FPS_20				25600000	//(512000000 / 20)
#define AMBA_VIDEO_FPS_24				21333333	//(512000000 / 24)
#define AMBA_VIDEO_FPS_25				20480000	//(512000000 / 25)
#define AMBA_VIDEO_FPS_30				17066667	//(512000000 / 30)
#define AMBA_VIDEO_FPS_50				10240000	//(512000000 / 50)
#define AMBA_VIDEO_FPS_60				8533333		//(512000000 / 60)
#define AMBA_VIDEO_FPS_120			4266667		//(512000000 / 120)
#define AMBA_VIDEO_FPS_29_97			17083750	//(512000000 / 2997 * 100)
#define AMBA_VIDEO_FPS_59_94			8541875		//(512000000 / 5994 * 100)
#define AMBA_VIDEO_FPS_23_976			21354688	//(512000000 / 23976 * 1000)
#define AMBA_VIDEO_FPS_12_5			40960000	//(512000000 / 25 * 2)
#define AMBA_VIDEO_FPS_6_25			81920000	//(512000000 / 25 * 4)
#define AMBA_VIDEO_FPS_3_125			163840000	//(512000000 / 25 * 8)
#define AMBA_VIDEO_FPS_7_5			68266667	//(512000000 / 15 * 2)
#define AMBA_VIDEO_FPS_3_75			136533333	//(512000000 / 15 * 4)
#else
#define VIDEO_FPS(fps)			(fps)
#define VIDEO_FRAC_FPS(fps)		(0x10000 + fps)
#define VIDEO_FPS_AUTO			VIDEO_FPS(0)
#define VIDEO_FPS_1			VIDEO_FPS(1)
#define VIDEO_FPS_2			VIDEO_FPS(2)
#define VIDEO_FPS_3			VIDEO_FPS(3)
#define VIDEO_FPS_4			VIDEO_FPS(4)
#define VIDEO_FPS_5			VIDEO_FPS(5)
#define VIDEO_FPS_6			VIDEO_FPS(6)
#define VIDEO_FPS_10			VIDEO_FPS(10)
#define VIDEO_FPS_15			VIDEO_FPS(15)
#define VIDEO_FPS_20			VIDEO_FPS(20)
#define VIDEO_FPS_24			VIDEO_FPS(24)
#define VIDEO_FPS_25			VIDEO_FPS(25)
#define VIDEO_FPS_30			VIDEO_FPS(30)
#define VIDEO_FPS_50			VIDEO_FPS(50)
#define VIDEO_FPS_60			VIDEO_FPS(60)
#define VIDEO_FPS_120			VIDEO_FPS(120)
#define VIDEO_FPS_29_97			VIDEO_FRAC_FPS(0)
#define VIDEO_FPS_59_94			VIDEO_FRAC_FPS(1)
#define VIDEO_FPS_23_976			VIDEO_FRAC_FPS(2)
#define VIDEO_FPS_12_5			VIDEO_FRAC_FPS(3)
#define VIDEO_FPS_6_25			VIDEO_FRAC_FPS(4)
#define VIDEO_FPS_3_125			VIDEO_FRAC_FPS(5)
#define VIDEO_FPS_7_5			VIDEO_FRAC_FPS(6)
#define VIDEO_FPS_3_75			VIDEO_FRAC_FPS(7)
#define VOUT_SINK_TYPE_CVBS    (1)
#endif
#endif
#if 1
/* ======================= Standart format defines ========================== */
enum amba_video_mode_e {
	VIDEO_MODE_AUTO		= 0,

	VIDEO_MODE_320_240		= 1,		//320x240
	VIDEO_MODE_320_288		= 2,		//320x288
	VIDEO_MODE_360_240		= 3,		//360x240
	VIDEO_MODE_360_288		= 4,		//360x288
	VIDEO_MODE_480_240		= 5,		//480x240
	VIDEO_MODE_720_240		= 6,		//720x240
	VIDEO_MODE_960_240		= 7,		//960x240
	VIDEO_MODE_VGA		= 8,		//640x480
	VIDEO_MODE_SVGA		= 9,		//800x600
	VIDEO_MODE_XGA		= 10,		//1024x768
	VIDEO_MODE_SXGA		= 11,		//1280x1024
	VIDEO_MODE_UXGA		= 12,		//1600x1200
	VIDEO_MODE_QXGA		= 13,		//2048x1536
	VIDEO_MODE_WVGA		= 14,		//800x480
	VIDEO_MODE_WSVGA		= 15,		//1024x600
	VIDEO_MODE_1280_960	= 16,		//1280x960
	VIDEO_MODE_WXGA		= 17,		//1280x800
	VIDEO_MODE_WSXGA		= 18,		//1440x900
	VIDEO_MODE_WSXGAP		= 19,		//1680x1050
	VIDEO_MODE_WUXGA		= 20,		//1920x1200

	/* Add new format below and update AMBA_VIDEO_MODE_NUM*/
	VIDEO_MODE_480_640		= 21,		//480x640
	VIDEO_MODE_SXGAP		= 22,		//1400x1050
	VIDEO_MODE_QSXGA		= 23,		//2592x1944

	//Still Standard
	VIDEO_MODE_3M_4_3		= 0xFFE0,
	VIDEO_MODE_3M_16_9		= 0xFFE1,
	VIDEO_MODE_4M_4_3		= 0xFFE2,
	VIDEO_MODE_4M_16_9		= 0xFFE3,
	VIDEO_MODE_5M_4_3		= 0xFFE4,
	VIDEO_MODE_5M_16_9		= 0xFFE5,

	//Video Standard
	VIDEO_MODE_480I		= 0xFFF0,
	VIDEO_MODE_576I		= 0xFFF1,
	VIDEO_MODE_D1_NTSC		= 0xFFF2,	//480p
	VIDEO_MODE_D1_PAL		= 0xFFF3,	//576p
	VIDEO_MODE_720P		= 0xFFF4,
	VIDEO_MODE_720P_PAL	= 0xFFF5,	//720p50
	VIDEO_MODE_1080I		= 0xFFF6,
	VIDEO_MODE_1080I_PAL	= 0xFFF7,	//1080i50
	VIDEO_MODE_1080P		= 0xFFF8,
	VIDEO_MODE_1080P_PAL	= 0xFFF9,	//1080i50
	VIDEO_MODE_1080I48		= 0xFFFA,	//1080i48
	VIDEO_MODE_1080P24		= 0xFFFB,	//1080p24

	VIDEO_MODE_TEST		= 0xFFFE,
	VIDEO_MODE_MAX	= 0xFFFF,
};
#endif
typedef enum {
	HIGH_FRAMERATE = 0,
	LOW_DELAY,
	HIGH_MP,
	TOTAL_ENCODE_MODE,
} ENCODE_MODE;


typedef enum {
	REQ_SET_FORCEIDR = 17,
	REQ_GET_VIDEO_PORT,

	REQ_STREAM_START,
	REQ_STREAM_STOP,

	REQ_CHANGE_BR,
	REQ_CHANGE_FR,
	REQ_CHANGE_BRC,

	REQ_GET_PARAM = 100,
	REQ_SET_PARAM,
	REQ_AAA_CONTROL,
} REQUSET_ID;


typedef enum {
	AAA_START = 0,
	AAA_STOP,
} AAA_CONTROL_ID;


typedef struct {
	u32		id;
	u32		info;
	u32		dataSize;
} Request;/*REQ*/


typedef struct {
	u32		result;
	u32		info;
} Ack;/*ACK*/


typedef enum {
	DATA_MAGIC = 0x20110725,
	DATA_VERSION = 0x00000012,
} VERSION_MAGIC;


typedef struct {
	u32		magic;
	u32		version;
} VERSION;
#if 0
typedef enum {
	MAP_TO_U32 = 0,
	MAP_TO_U16,
	MAP_TO_U8,
	MAP_TO_S32,
	MAP_TO_S16,
	MAP_TO_S8,
	MAP_TO_DOUBLE,
	MAP_TO_STRING,
} mapping_data_type;


typedef enum {
	NO_LIMIT = 0,
	MIN_MAX_LIMIT,
	MIN_LIMIT,
	MAX_LIMIT,
} mapping_data_constraint;
#endif

typedef struct {
	char * 					TokenName;		// name
	void * 					Address;		// address
	mapping_data_type		Type;			// type: 0 - u32, 1 - u16, 2 - u8, 3 - int(s32), 4 - double, 5 - char[]>
	double					Default;			// default value>
	mapping_data_constraint	ParamLimits;	// 0 - no limits, 1 - min and max limits, 2 - only min limit, 3 - only max limit
	double					MinLimit;		// Minimun value
	double					MaxLimit;		// Maximun value
	int						StringLengthLimit;	// Dimension of type char[]
    bool                    Update;
} mapping_t;

typedef int (*get_func)(char * section_name, u32 info);
typedef int (*set_func)(char * section_name);

typedef struct {
	char *		name;
	mapping_t *	map;
	get_func		get;
	set_func		set;
} Section;


typedef struct {
	u32				enable;
	u32				mode;
	u32				frame_rate;
//	mw_mirror_mode	mirror_mode;
} gk_vin_mode;


typedef struct {
	u32				mode;
	u32				type;
} gk_vout_mode;


typedef struct
{
    u32            streamId;
    u8             encode_type;
    u8             sourceBuf;
    u8             flip_rotate;
    u16            encode_width;
    u16            encode_height;
    u16            xOffset;
    u16            yOffset;
    u32            encode_fps;
}gk_venc_StreamFormat;

typedef struct
{
    u32            streamId;
    u8             gopM;
    u8             gopN;
    u8             idrInterval;
    u8             gopModel;
    u8             profile;
    u8             brcMode;
    u32            cbrAvgBps;
    u32            vbrMinbps;
    u32            vbrMaxbps;
}gk_venc_H264Config;

typedef struct
{
    u32            streamId;
    u8             chromaFormat;
    u8             quality;
}gk_venc_MjpegConfig;

typedef struct
{
    gk_venc_StreamFormat streamFormat;
    gk_venc_H264Config   h264Conf;
    gk_venc_MjpegConfig  mjpegConf;
    u8                 dptz;
}gk_encode_stream;

typedef enum {
	COLOR_BLACK = 0,
	COLOR_RED,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_YELLOW,
	COLOR_MAGENTA,
	COLOR_CYAN,
	COLOR_WHITE,
	COLOR_TYPE_NUM,
} color_type;

typedef struct osd_text_s {
	u32			stream;
	u32			time_enable;
	// font content
	char			str[OSD_TEXT_LENGTH];	// text content
	u32			length;					// text string length
	// font attribute parameters
	u8			type;					// font type: 0/1 English, 2 Chinese, 3 Korean
	u8			size;					// font size
	u8			outline;					// font outline width
	u8			color;					// font color type
	int			bold;					// font bold
	int			italic;					// font italic
	// text area box parameters
	u16			start_x;					// text area offset x, 0~100, 100 means 100% of encode width
	u16			start_y;					// text area offset y, 0~100, 100 means 100% of encode height
	u16			box_w;					// text area box width, 0~100, 100 means 100% of encode width
	u16			box_h;					// text area box height, 0~100, 100 means 100% of encode height
} osd_text_t;

typedef struct osd_param_s {
	u8			bmp_enable;
	u8			time_enable;
	u8			text_enable;
	u8			no_rotate;
	osd_text_t	text;
} osd_param_t;

typedef struct privacy_mask_s{
	int				unit; //0- percent ,1-pixel
	int				x;
	int				y;
	int				width;
	int				height;
	u32				color;		// 0:Black, 1:Red, 2:Blue, 3:Green, 4:Yellow, 5:Magenta, 6:Cyan, 7:White
	u32				action;
} privacy_mask_t;

typedef struct live_view_param_s {
	u32		encode_type;
	u32		encode_fps;
	u16		encode_width;
	u16		encode_height;
	u32		brc_mode;
	u32		cbr_avg_bps;
	u32		vbr_min_bps;
	u32		vbr_max_bps;
} live_view_param_t;

typedef struct {
	mw_ae_param		ae;
	int					ae_preference;
	u32					day_night_mode;
	u32					metering_mode;
	u32					back_light_comp_enable;
	u32					local_exposure_mode;
	u32					mctf_strength;
	u32					dc_iris_enable;
	u32					dc_iris_duty_balance;
	u32					ae_target_ratio;
} basic_iq_params;
/*!
*******************************************************************************
** \brief one stream format struct.
*******************************************************************************
*/
typedef struct
{
    /*stream index.*/
    GADI_U32            streamId;
    /*0: none, 1: H.264, 2: MJPEG*/
    GADI_U8             encodeType;
    /*0: main source buffer (IAV_ENCODE_SOURCE_MAIN_BUFFER)    1: secondary source buffer*/
    GADI_U8             sourceBuf;
    /*rotate*/
    GADI_U8             flipRotate;
    /*encode width.*/
    GADI_U16            width;
    /*encode height.*/
    GADI_U16            height;
    /*encode x offset.*/
    GADI_U16            xOffset;
    /*encode y offset.*/
    GADI_U16            yOffset;
    /*encode frame rate.*/
    GADI_U32            fps;
}GADI_VENC_StreamFormatT;

typedef struct
{
    /*stream index for setting the bitrate.*/
    GADI_U32            streamId;
    /*VBR mode: the min bitrate, CBR mode: the average bitrate.*/
    GADI_U32            minBps;
    /*VBR mode: the max bitrate.*/
    GADI_U32            maxBps;
}GADI_VENC_BitRateRangeT;

static inline int get_func_null(char *section_name, u32 info)
{
	return 0;
}

static inline int set_func_null(char *section_name)
{
	return 0;
}



void * webserver_process(void * argv);


#endif
