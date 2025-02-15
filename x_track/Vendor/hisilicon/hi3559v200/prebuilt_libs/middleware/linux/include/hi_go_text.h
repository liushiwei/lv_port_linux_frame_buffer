/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description:HIGO Text ADT & proptypes
 * Author: sdk
 * Create: 2019-10-12
 */
#ifndef __HI_GO_TEXT_H__
#define __HI_GO_TEXT_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

/***************************** Macro Definition ******************************/
/*************************** Structure Definition ****************************/
/** \addtogroup      HIGO_TEXT */
/** @{ */  /** <!—[HIGO_TEXT] */

#define LAYOUT_LEFT          HIGO_LAYOUT_LEFT     /**< Horizontally left *//**< CNcomment:水平居左 */
#define LAYOUT_RIGHT         HIGO_LAYOUT_RIGHT    /**< Horizontally right *//**< CNcomment:水平居右 */
#define LAYOUT_HCENTER       HIGO_LAYOUT_HCENTER  /**< Horizontally center *//**< CNcomment:水平居中 */
#define LAYOUT_TOP           HIGO_LAYOUT_TOP      /**< Vertically top *//**< CNcomment:垂直居顶 */
#define LAYOUT_BOTTOM        HIGO_LAYOUT_BOTTOM   /**< Vertically bottom *//**< CNcomment:垂直居底 */
#define LAYOUT_VCENTER       HIGO_LAYOUT_VCENTER  /**< Vertically center *//**< CNcomment:垂直居中 */
#define LAYOUT_WRAP          HIGO_LAYOUT_WRAP     /**< Wrap *//**< CNcomment:自动换行 */
#define LAYOUT_WORDELLIPSIS  HIGO_LAYOUT_WORDELLIPSIS /**< Ellipsis format *//**< CNcomment:使用省略号风格 */
#define LAYOUT_FORCE_LEFT    HIGO_LAYOUT_FORCE_LEFT     /**< Force Horizontally left *//**< CNcomment:强制水平居左 */
#define LAYOUT_FORCE_RIGHT   HIGO_LAYOUT_FORCE_RIGHT    /**< Force Horizontally right *//**< CNcomment:强制水平居右 */

/** */
typedef enum {
    HIGO_LAYOUT_LEFT             = 0x0001,
    HIGO_LAYOUT_RIGHT            = 0x0002,
    HIGO_LAYOUT_HCENTER          = 0x0004,
    HIGO_LAYOUT_WRAP             = 0x0008,
    HIGO_LAYOUT_WORDELLIPSIS     = 0x0010,
    HIGO_LAYOUT_TOP              = 0x0100,
    HIGO_LAYOUT_BOTTOM           = 0x0200,
    HIGO_LAYOUT_VCENTER          = 0x0400,
    HIGO_LAYOUT_FORCE_LEFT       = 0x8000,
    HIGO_LAYOUT_FORCE_RIGHT      = 0x10000,
    HIGO_LAYOUT_VERTICAL         = 0x20000,
    HIGO_LAYOUT_BUTT             = 0x40000,
} HIGO_LAYOUT_E;

/**< Definition of a character set */ /** CNcomment: 字符集定义 */
typedef enum {
    HIGO_CHARSET_UNKOWN,
    HIGO_CHARSET_ASCI,
    HIGO_CHARSET_GB2312,
    HIGO_CHARSET_UTF8,
    HIGO_CHARSET_UTF16,
    HIGO_CHARSET_UCS2 = HIGO_CHARSET_UTF16,
    HIGO_CHARSET_UTF32,
    HIGO_CHARSET_BUTT,
} HIGO_CHARSET_E;

/** Definition of a text base direction */ /** CNcomment: 文本输出基础方向定义 */
typedef enum {
    HIGO_TEXT_DIR_NEUTRAL = 0, /**< neutral deirction *//**< CNcomment:中性方向，按内容查找强字符方向 */
    HIGO_TEXT_DIR_LTR, /**< Left to right *//**< CNcomment:从左到右方向 */
    HIGO_TEXT_DIR_RTL, /**< Right to left *//**< CNcomment:从右到左方向 */
    HIGO_TEXT_DIR_BUTT
} HIGO_TEXT_DIR_E;


typedef struct {
    HIGO_CHARSET_E Charset; /**< Character set name *//**< CNcomment:字符集名称 */
    HI_U8 Height;           /**< Font height *//**< CNcomment:字体高度 */
    HI_U8 MaxWidth;         /**< Maximum font width *//**< CNcomment:字体最大宽度 */
}HIGO_FONTATTR_S;

/** Attributes of a text output object */ /** CNcomment: 文本输出对像属性 */
typedef struct {
    HI_COLOR        BgColor;     /**< Background color *//**< CNcomment:背景色 */
    HI_COLOR        FgColor;     /**< Foreground color *//**< CNcomment:前景色 */
    HIGO_FONTATTR_S SbFontAttr;  /**< Font attributes of the SBC *//**< CNcomment:单字节字符集字体属性 */
    HIGO_FONTATTR_S MbFontAttr;  /**< Font attributes of the MBC *//**< CNcomment:多字节字符集字体属性 */
} HIGO_TEXTOUTATTR_S;

typedef enum {
    HIGO_TEXT_STYLE_NORMAL = 0x00, /**< Normal font *//**< CNcomment:正常字体 */
    HIGO_TEXT_STYLE_ITALIC = 0x01, /**< Italic font *//**< CNcomment:斜体字体 */
    HIGO_TEXT_STYLE_BOLD   = 0x02, /**< Bold font *//**< CNcomment:粗体字体 */
    HIGO_TEXT_STYLE_HALF_HEIGHT   = 0x04, /**< Half-height font *//**< CNcomment:半高字体 */
    HIGO_TEXT_STYLE_HALF_WIDTH    = 0x08, /**< Half-width font *//**< CNcomment:半宽字体 */
    HIGO_TEXT_STYLE_DOUBLE_HEIGHT = 0x10, /**< Double-height font *//**< CNcomment:双倍高度字体 */
    HIGO_TEXT_STYLE_DOUBLE_WIDTH  = 0x20, /**< Double-widht font *//**< CNcomment:双倍宽度字体 */
    HIGO_TEXT_STYLE_BUTT          = 0x40
} HIGO_TEXT_STYLE_E;

typedef struct {
    HI_HANDLE     hFont; /**< Handle of font file *//**< CNcomment:字体句柄 */
    HI_U32        Style; /**< Layout style *//**< CNcomment:布局类型 */
    HI_S32        s32Width; /**< Width of display arear *//**< CNcomment:显示区域宽度 */
    HI_S32        s32Height;  /**< Height of display arear *//**< CNcomment:显示区域高度 */
    HI_S32  	  horz_dist;  /**< Character horizontal spacing *//**< CNcomment:字符间距 */
    HI_S32  	  vert_dist;  /**< Raw vertical spacing *//**< CNcomment:行间距,一行文字下线和下行文字上线之间的距离 */
    HI_BOOL       single_para_flg; /**< Whether it is a single paragraph *//**< CNcomment:是否为单段落 */
    HI_BOOL    	  auto_dir; /**< Whether it is automatic direction *//**< CNcomment:是否为自动方向 */
    HIGO_TEXT_DIR_E base_dir; /**< Base direction *//**< CNcomment: 基本方向 */
    HI_U32        max_char;  /**< Max character *//**< CNcomment:最大字符数量 */
    HI_COLOR      select_bg; /**< Selected background color *//**< CNcomment:选中的背景色 */
    HI_COLOR      select_fg; /**< Selected frontground color *//**< CNcomment:选中的前景色 */
}HIGO_LAYOUT_INFO_S;

typedef struct {
    const HI_CHAR* pSbcFontFile; /**< Single-byte character font file. *//**< CNcomment:单字节字体文件 */
    const HI_CHAR* pMbcFontFile; /**< Multi-byte character font file. *//**< CNcomment:多字节字体文件 */
    HI_U32   u32Size; /**< This value is ignored for the dot-matrix font. *//**< CNcomment:点阵字体，则该值被忽略 */
} HIGO_TEXT_INFO_S;

typedef enum {
    HIGO_LAYOUT_MOVECURSOR_UP,    /**< move cursor to up position *//**< CNcomment:移动到上方位置 */
    HIGO_LAYOUT_MOVECURSOR_DOWN,  /**< move cursor to down position *//**< CNcomment:移动到下方位置 */
    HIGO_LAYOUT_MOVECURSOR_PREV,  /**< move cursor to previous postion *//**< CNcomment:移动到前一个位置 */
    HIGO_LAYOUT_MOVECURSOR_NEXT,  /**< move cursor to next position *//**< CNcomment:移动到后一个位置 */
    HIGO_LAYOUT_MOVECURSOR_LEFT,  /**< move cursor to left position *//**< CNcomment:移动到左方位置 */
    HIGO_LAYOUT_MOVECURSOR_RIGHT, /**< move cursor to right positon *//**< CNcomment:移动到右方位置 */
    HIGO_LAYOUT_MOVECURSOR_SOT,   /**< move cursor to start position of text *//**< CNcomment:移动到文本开始位置 */
    HIGO_LAYOUT_MOVECURSOR_EOT,   /**< move curosr to end position of text *//**< CNcomment:移动到文本结束位置 */
    HIGO_LAYOUT_MOVECURSOR_SOL,   /**< move cursor to start of current line *//**< CNcomment:移动到当前行开始位置 */
    HIGO_LAYOUT_MOVECURSOR_EOL,   /**< move cursor to end of current line *//**< CNcomment:移动到当前行结束位置 */
    HIGO_LAYOUT_MOVECURSOR_SOP,   /**< move cursor to start of current paragraph *//**< CNcomment:移动到段落开始 */
    HIGO_LAYOUT_MOVECURSOR_EOP,   /**< move cursor to end of current paragraph *//**< CNcomment:移动到当前段落的末尾 */
	HIGO_LAYOUT_MOVECURSOR_BUTT,
}HIGO_TEXT_CURSOR_DIR_E;

/** @} */  /*! <!-- Structure Definition end */

/******************************* API declaration *****************************/
/** \addtogroup      HIGO_TEXT */
/** @{ */  /** <!—[HIGO_TEXT] */

/**
\brief Creates a text output object.CNcomment: 创建文本输出对象 CNend
\attention \n
The values of pSbFontFile and pMbFontFile cannot be empty at the same time. If the received file name is in vector
font, the font height is set based on the 22-dot array.
CNcomment: pSbFontFile和pMbFontFile不可同时为空,如果传入的是矢量字体文件名,则字体高度按
22点阵创建 CNend
\param[in] pSbFontFile Font file of the single-byte character set. If the value is empty, it indicates that the single
-byte character set library is not used.CNcomment: 单字节字符集字体文件，为空表示不使用单字节字符集字库 CNend
\param[in] pMbFontFile  Font file of the multi-byte character set. If the value is empty, it indicates that the multi-
byte character set library is not used. Ensure that the font files of the single-byte and multi-byte character sets
cannot be empty concurrently.CNcomment: 多字节字符集字体文件，为空表示不使用多字节字符集字库，但是不能与单字节字符文件同时为空。 CNend
\param[out]  pTextOut Handle of a text output object.CNcomment: 文本输出对象句柄 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_INVFILE
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_NOMEM

\see \n
::HI_GO_DestroyText
*/
HI_S32 HI_GO_CreateText(const HI_CHAR* pSbFontFile, const HI_CHAR* pMbFontFile, HI_HANDLE* pTextOut);

/**
\brief Destroys a text output object.CNcomment:销毁文本输出对象 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] TextOut Handle of a text output object.CNcomment:文本输出对象句柄 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
::HI_GO_CreateText
*/
HI_S32 HI_GO_DestroyText(HI_HANDLE TextOut);

/**
\brief set the input charset. CNcomment:设置输入字符集 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] TextOut Handle of a text output object.CNcomment:文本输出对象句柄 CNend
\param[out] CharSet  charset of input text.CNcomment:输入文本字符集合 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORT_CHARSET

\see \n
::HI_GO_CreateText
*/
HI_S32 HI_GO_SetInputCharSet(HI_HANDLE TextOut, HIGO_CHARSET_E CharSet);

/**
\brief Obtains the attributes of a text output object.CNcomment:获取文本输出对象属性 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] TextOut Handle of a text output object.CNcomment:文本输出对象句柄 CNend
\param[out] pTextOutAttr  Attributes of a text output object.CNcomment:文本输出对象属性 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_GetTextAttr(HI_HANDLE TextOut, HIGO_TEXTOUTATTR_S *pTextOutAttr);

/**
\brief Obtains the width and height of text contents.CNcomment:获取文本内容的宽高 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] TextOut Handle of a text output object.CNcomment:文本输出对象句柄 CNend
\param[in] pText Text contents.CNcomment:文本内容 CNend
\param[out] pWidth Width of text contents. It cannot be empty.CNcomment:文本内容宽度，不可为空 CNend
\param[out] pHeight Height of text contents. It cannot be empty.CNcomment:文本内容高度，不可为空 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORT_CHARSET

\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_GetTextExtent(HI_HANDLE TextOut, const HI_CHAR *pText, HI_S32 *pWidth, HI_S32 *pHeight);

/**
\brief Obtains the width and height of vertical text contents.CNcomment:获取竖排文本内容的宽高 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] TextOut Handle of a text output object.CNcomment:文本输出对象句柄 CNend
\param[in] pText Text contents.CNcomment:文本内容 CNend
\param[out] pTextWidth Actual width of text contents. It cannot be empty.CNcomment:文本内容实际宽度，不可为空 CNend
\param[out] pHeight Height of text contents. It cannot be empty.CNcomment:文本内容高度，不可为空 CNend
\param[out] pLayoutAreaWidth Minmal width of layout area. It cannot be empty.CNcomment:文本排版区域的最小宽度，不可为空 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORT_CHARSET

\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_GetVerticalTextExtent(HI_HANDLE hFont, const HI_CHAR *pText,
                                   HI_S32 *pTextWidth, HI_S32 *pHeight, HI_S32 *pLayoutAreaWidth);

/**
\brief Sets to display the background color of a text output object.CNcomment:设置文本输出对象的背景色是否显示 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] TextOut Handle of a text output object.CNcomment:文本输出对象句柄 CNend
\param[in] bTransparent  Whether to display the background color of a text output object. If the value is set to
HI_TRUE, the background color is not displayed. The default value is HI_TRUE.CNcomment:文本输出对象背景色是否显示，为HI_TRUE, 则不显示，默认为HI_TRUE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/ACNcomment:无 CNend
*/
HI_S32 HI_GO_SetTextBGTransparent(HI_HANDLE TextOut, HI_BOOL bTransparent);

/**
\brief Sets the background color of a text output object.CNcomment:设置文本输出对象的背景色 CNend
\attention \n
If the target surface is a palette, the color is the palette index.CNcomment:如果目标surface是调色板，则Color是调色板索引 CNend
\param[in] TextOut Handle of a text output object.CNcomment:文本输出对象句柄 CNend
\param[in] Color  Background color of a text output object.CNcomment:文本输出对象背景色，CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetTextBGColor(HI_HANDLE TextOut, HI_COLOR Color);

/**
\brief Sets the font color of a text output object.CNcomment: 设置文本输出对象的字体颜色 CNend
\attention \n
If the target surface is a palette, the color is the palette index.CNcomment: 如果目标surface是调色板，则Color是调色板索引 CNend
\param[in] TextOut Handle of a text output object.CNcomment: 文本输出对象句柄 CNend
\param[in] Color  Font color of a text output object.CNcomment: 文本输出对象字体颜色 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment: 无 CNend
*/
HI_S32 HI_GO_SetTextColor(HI_HANDLE TextOut, HI_COLOR Color);

/**
\brief Outputs text contents to a specified surface.CNcomment:输出文本内容到指定surface CNend
\attention
N/A.CNcomment:无 CNend
\param[in] TextOut Handle of a text output object.CNcomment:文本输出对象句柄 CNend
\param[in] Surface Surface handle.CNcomment:Surface句柄 CNend
\param[in] pText  Text contents.CNcomment:文本内容 CNend
\param[in] pRect Text output region. If the value is empty, it indicates that text contents are output from the
surface origin.CNcomment:文本输出区域，为空表示从surface原点输出 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_TextOut(HI_HANDLE TextOut, HI_HANDLE Surface, const HI_CHAR *pText, const HI_RECT *pRect);

/**
\brief Outputs texts. This API is an extended API. You can call this API to output contents based on customized
styles and formatting.CNcomment:文本输出扩展接口,输出内容可以按照用户指定的排版进行输出。CNend
\param[in] hTextOut Text output handle.CNcomment:文本输出句柄 CNend
\param[in] hSurface Surface handle.CNcomment:Surface句柄 CNend
\param[in] pText    Text contents ending with /0.CNcomment:以/0结尾的文本内容 CNend
\param[in] pRect    Text output region.CNcomment:文本输出区域 CNend
\param[in] Style    Styles and formatting including LAYOUT_LEFT, LAYOUT_RIGHT, and LAYOUT_HCENTER.CNcomment:排版格式，如LAYOUT_LEFT、LAYOUT_RIGHT、LAYOUT_HCENTER等 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR

\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_TextOutEx(HI_HANDLE hTextOut, HI_HANDLE hSurface, const HI_CHAR *pText,
                       const HI_RECT *pRect, HIGO_LAYOUT_E Style);

/**
\brief Calculates the number of characters in a specified text output region.CNcomment: 计算指定文本输出区域字符个数 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hTextOut Text output handle.CNcomment: 文本输出句柄 CNend
\param[in] pText    Text contents ending with /0.CNcomment: 以/0结尾的文本内容 CNend
\param[in] pRect    Text output region. The value cannot be empty.CNcomment: 文本输出区域,不可为空 CNend
\param[in] pLen      Pointer to the string length.CNcomment: 字符串长度指针 CNend

\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HI_SUCCESS

\see \n
N/A.CNcomment: 无 CNend
*/
HI_S32 HI_GO_GetTextExtentEx(HI_HANDLE TextOut, const HI_CHAR *pText,
                             const HI_RECT *pRect, HI_U32 *pLen);

/**
\brief Creates a font.CNcomment:创建字体 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] phText Text output handle.CNcomment:文本输出句柄 CNend
\param[in] pInfo  Text information.CNcomment:文件信息 CNend

\retval ::HI_SUCCESS A font is created successfully.CNcomment:字体创建成功 CNend
\retval ::HI_FAILURE A font fails to be created.CNcomment:字体创建失败 CNend
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_CreateTextEx(const HIGO_TEXT_INFO_S *pInfo, HI_HANDLE *phText);

/**
\brief Sets the style of a font, such as bold, italic, or normal.CNcomment:设置字体的风格，比如:粗体，斜体，正常体 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hTextOut Text output handle.CNcomment:文本输出句柄 CNend
\param[in] eStyle   Font style.CNcomment:字体风格 CNend

\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetTextStyle(HI_HANDLE hTextOut, HIGO_TEXT_STYLE_E eStyle);



/**
\brief Sets the the text base direction
lines.CNcomment:设置文本输出对象的基本方向 CNend
\attention \n
N/A.CNcomment:无 CNend

\param[in] hTextOut Text output handle. CNcomment:文本输出句柄 CNend
\param[in] BaseDir the base direction of the text. CNcomment: 文本输出对象基本方向 CNend

\retval ::HI_SUCCESS Success.CNcomment: 成功 CNend
\retval ::HIGO_ERR_INVHANDLE Failure.CNcomment:失败 CNend

\see \n
N/A.CNcomment:无 CNend
*/

HI_S32 HI_GO_SetBaseDir(HI_HANDLE TextOut, HIGO_TEXT_DIR_E eBaseDir);
/**
\brief Sets the horizontal spacing between displayed characters, that is, the horizontal spacing between character
lines.CNcomment:设置字符显示水平间距，两个字符行水平间距 CNend
\attention \n
N/A.CNcomment:无 CNend

\param[in] hTextOut Text output handle.CNcomment:文本输出句柄 CNend
\param[in] u32Distance Horizontal spacing.CNcomment:水平间距 CNend

\retval ::HI_SUCCESS Success.CNcomment: 成功 CNend
\retval ::HIGO_ERR_INVHANDLE Failure.CNcomment:失败 CNend

\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetCharExtra(HI_HANDLE hTextOut, HI_U32 u32Distance);

/**
\brief Sets the vertical and horizontal spacing.CNcomment:设置垂直水平间距 CNend
\attention \n
This API is available only when the font style is changed.CNcomment:只有换行风格才有效 CNend

\param[in] hTextOut Text output handle.CNcomment:文本输出句柄 CNend
\param[in] u32Distance Vertical spacing.CNcomment:垂直间距 CNend

\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_INVHANDLE Failure.CNcomment:失败 CNend

\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetLineExtra(HI_HANDLE hText, HI_U32 u32Distance);

/**
\brief Initializes the character module.CNcomment: 初始化字符模块 CNend
\attention \n
N/A.CNcomment: 无 CNend
\param N/A.CNcomment: 无 CNend
\retval ::HI_SUCCESS Success.CNcomment: 成功 CNend
\retval ::HI_FAILURE Failure.CNcomment: 失败 CNend
\retval ::HIGO_ERR_DEPEND_TDE

\see \n
N/A.CNcomment: 无 CNend
*/
HI_S32 HI_GO_InitText();

/**
\brief Deinitializes the character module.CNcomment:去初始化字符模块 CNend
\attention \n
N/A.CNcomment:无 CNend
\param N/A.CNcomment:无 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend

\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_DeinitText();


/**
\brief Create layout context CNcomment:创建排版上下文 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] pLayoutInfo layout parameters CNcommnet 排版参数 CNend
\param[out] hlayout handle of layout context CNcommnet 排版上下文句柄 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_CreateLayout(HIGO_LAYOUT_INFO_S *pLayoutInfo, HI_HANDLE *hlayout);

/**
\brief Destroy layout context CNcomment:销毁排版上下文 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_DestroyLayout(HI_HANDLE hlayout);

/**
\brief Move coursor to a point CNcomment:将光标移动到指定点 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcommnet 排版上下文句柄 CNend
\param[in] ppoint  target point CNcommnet 目标点 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_MoveCursor2Point(HI_HANDLE hlayout, HI_POINT *pPoint);

/**
\brief Move cursor CNcomment:按照参数要求移动光标 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcommnet 排版上下文句柄 CNend
\param[in] dir  direction to move CNcommnet 目标方向 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_CursorMove(HI_HANDLE hlayout, HIGO_TEXT_CURSOR_DIR_E Dir);

/**
\brief Get position of cursor on screen CNcomment:获取光标的屏幕位置 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcommnet 排版上下文句柄 CNend
\param[out] prect cursor position CNcommnet 光标位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_CursorGetScreenPos(HI_HANDLE  hlayout, HI_RECT *pRect);

/**
\brief get text from context CNcomment:从上下文中获取字符串 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\prarm[out] length length of string CNcomment 字符串长度 CNend
\param[out] str address of UTF-8 string CNcomment UTF8编码的字符串地址 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutGetText(HI_HANDLE hlayout, HI_S32 *length, HI_CHAR **str);

/**
\brief clear text in context CNcomment:从上下文中清除字符串 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutClearText(HI_HANDLE hlayout);


/**
\brief insert text to context at current cursor pos CNcomment:在上下文的当前光标位置插入字符串 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] pText UTF-8 string to insert CNcomment 待插入的UTF-8字符串 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutInsertText(HI_HANDLE hlayout, const HI_CHAR *pText);

/**
\brief delete some character from context at current cursor pos CNcomment:在上下文的当前光标位置删除字符字符串 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] sCount CNcomment 待删除的字符数量 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutDeleteText(HI_HANDLE hlayout, HI_S32 sCount);

/**
\brief Get layout rectangle's width & height CNcomment:获得排版矩形的高度和宽度CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[out] layout rectangle, the x,y fields set to 0 CNcomment 排版矩形的高度和宽度 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutGetRect(HI_HANDLE hlayout, HI_RECT *pRect);

/**
\brief Set view port position CNcomment:设置视口的位置 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] position of view port  CNcomment 视口的位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetViewPort(HI_HANDLE hlayout, HI_POINT *pPos);

/**
\brief Set view port size CNcomment:设置视口的大小 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] w	width of viewport CNcomment w 视口宽度 CNend
\param[in] h	height of viewport CNcomment h 视口高度 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetViewPortSize(HI_HANDLE hlayout, HI_S32 w, HI_S32 h);

/**
\brief get view port position CNcomment:获取视口的位置 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] position of view port  CNcomment 视口的位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_GetViewPort(HI_HANDLE hlayout, HI_POINT *pPos);

/**
\brief Set view port position CNcomment:设置视口的大小和位置 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] size & position of view port  CNcomment 视口的位置和大小 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetViewPortEx(HI_HANDLE hlayout, HI_RECT *pPos);

/**
\brief Output text CNcomment:输出字符 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] hSurface surface to draw on CNcomment 待绘制的表面 CNend
\param[in] pRect display rectangle CNcomment 显示的矩形的位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutTextOut(HI_HANDLE hlayout, HI_HANDLE hSurface,  const HI_RECT *pRect);


/**
\brief begin select CNcomment:开始选择 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] pos position of select beginning  CNcomment 选择开始位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetSelecting(HI_HANDLE hlayout, HI_POINT *pos);

/**
\brief select area confirmed CNcomment:确定选择区域 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] pos end position of select area CNcomment 选择区域结束位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetSelected (HI_HANDLE hlayout, HI_POINT *pos);

/**
\brief select finished CNcomment:取消选择 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SelectFinish(HI_HANDLE hlayout);

/**
\brief get select string from ctx CNcomment:从上下文中获取选中的字符串 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] str  UTF8 string to output CNcomment 输出的UTF-8字符串 CNend
\param[in] len  lenth of output string 输出的字符串 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_GetSelectString(HI_HANDLE hlayout, HI_CHAR ** str, HI_U32 *len);
/**
\brief set selected area text color CNcomment:设置选中区域的颜色 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] fg foreground color CNcomment 前景色 CNend
\param[in] bg backgroud color CNcomment 背景色 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetSelectColor(HI_HANDLE hlayout, HI_COLOR fg, HI_COLOR bg);

/**
\brief delete select string CNcomment:删除选中区域 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] fg foreground color CNcomment 前景色 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_DeleteSelectString(HI_HANDLE hlayout);

/**
\brief Get line count of layout context CNcomment:获取排版的行数 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\retval ::line count of layout context or zero if failed.CNcomment:成功返回行数，失败返回0 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutGetLineNum(HI_HANDLE hlayout);

/**
\brief Get line height of context  CNcomment:获得指定行的高度 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] line_no index of line CNcomment 行号 CNend
\retval ::height of line or 0 if failed. CNcomment 成功返回行高度，失败返回0 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutGetLineHeight(HI_HANDLE hlayout, HI_S32 line_no);

/**
\brief Outputs texts. You can call this API to output contents based on customized
styles and formatting.CNcomment:文本输出扩展接口,输出内容可以按照用户指定的排版进行输出。CNend
\param[in] hLayout  Text layout handle.CNcomment:文本排版句柄 CNend
\param[in] hFont    Text output handle.CNcomment:文本输出句柄 CNend
\param[in] hSurface Surface handle.CNcomment:Surface句柄 CNend
\param[in] pText    Text contents ending with /0.CNcomment:以/0结尾的文本内容 CNend
\param[in] pRect    Text output region.CNcomment:文本输出区域 CNend
\param[in] eLayout  Styles and formatting including LAYOUT_LEFT, LAYOUT_RIGHT,
                    and LAYOUT_HCENTER.CNcomment:排版格式，如LAYOUT_LEFT、LAYOUT_RIGHT、LAYOUT_HCENTER等 CNend
\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_TextLayoutTextOut(HI_HANDLE hTextLayout, HI_HANDLE hFont, HI_HANDLE hSurface,
                               const HI_CHAR *pText,  const HI_RECT *pRect,  HIGO_LAYOUT_E eLayout);

/**
\brief Add text to layout context.CNcomment:向排版上下文中添加文本。CNend
\param[in] hlayout  Text layout handle.CNcomment:文本排版上下文句柄 CNend
\param[in] pText    Text contents ending with /0.CNcomment:以/0结尾的文本内容 CNend
\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutAddText(HI_HANDLE hlayout, const HI_CHAR* pText);

/**
\brief Check the layout context need to draw text cursor or not. CNcomment:判断排版上下文是否需要绘制光标。CNend
\param[in] hlayout  Text layout handle.CNcomment:文本排版上下文句柄 CNend
\retval ::HI_TRUE
\retval ::HI_FALSE
\see \n
N/A.CNcomment:无 CNend
*/
HI_BOOL HI_GO_NeedDrawCursor(HI_HANDLE hlayout);

 /**
\brief Check the cursor of context in SOT(Start of Text) position CNcomment:检查排版上下文中光标是否在SOT(文本开始位置)CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hLayout Handle of a text layout object.CNcomment:文本排版上下文句柄 CNend
\retval ::HI_TRUE
\retval ::HI_FALSE
\see \n
N/A.CNcomment:无 CNend
*/
HI_BOOL HI_GO_CursorInSot(HI_HANDLE hLayout);

 /**
\brief Check the cursor of context in EOT(End of Text) position CNcomment:检查排版上下文中光标是否在EOT(文本结束位置)CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hLayout Handle of a text layout object.CNcomment:文本排版上下文句柄 CNend
\retval ::HI_TRUE
\retval ::HI_FALSE
\see \n
N/A.CNcomment:无 CNend
*/
HI_BOOL HI_GO_CursorInEot(HI_HANDLE hLayout);

 /**
\brief Get cursor linear pos of cursor in text CNcomment:获取光标在文本中的线性位置CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hLayout Handle of a text layout object.CNcomment:文本排版上下文句柄 CNend
\retval position of cursor if succeed or -1 if failed.
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32  HI_GO_GetCursorLinearPos(HI_HANDLE hLayout);

/**
\brief Obtains rectangle of text contents.CNcomment:获取竖排文本内容的矩形 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hFont Handle of a text output object.CNcomment:文本输出对象句柄 CNend
\param[in] pText Text contents.CNcomment:文本内容 CNend
\param[in] pRect Text output region.CNcomment:文本输出区域 CNend
\param[in] eLayout    Styles and formatting including LAYOUT_LEFT, LAYOUT_RIGHT,
            and LAYOUT_HCENTER.CNcomment:排版格式，如LAYOUT_LEFT、LAYOUT_RIGHT、LAYOUT_HCENTER等 CNend
\param[out] pRcText Actual rectangle of text contents. It cannot be empty.CNcomment:文本内容实际矩形，不可为空 CNend
\param[out] pLen    Pointer to the string length.CNcomment: 字符串长度指针 CNend
\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_GetTextExtentEx2(HI_HANDLE hFont, const HI_CHAR *pText, const HI_RECT *pRect,
                              HIGO_LAYOUT_E eLayout, HI_RECT *pRcText, HI_U32 *pLen);
/**
\brief Move coursor to a point CNcomment:将光标移动到指定点 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcommnet 排版上下文句柄 CNend
\param[in] ppoint  target point CNcommnet 目标点 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_MoveCursor2Point(HI_HANDLE hlayout, HI_POINT *pPoint);

/**
\brief Move cursor CNcomment:按照参数要求移动光标 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcommnet 排版上下文句柄 CNend
\param[in] dir  direction to move CNcommnet 目标方向 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_CursorMove(HI_HANDLE hlayout, HIGO_TEXT_CURSOR_DIR_E Dir);

/**
\brief Get position of cursor on screen CNcomment:获取光标的屏幕位置 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcommnet 排版上下文句柄 CNend
\param[out] prect cursor position CNcommnet 光标位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_CursorGetScreenPos(HI_HANDLE hlayout, HI_RECT *pRect);

/**
\brief Create layout context CNcomment:创建排版上下文 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] pLayoutInfo layout parameters CNcommnet 排版参数 CNend
\param[out] hlayout handle of layout context CNcommnet 排版上下文句柄 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_CreateLayout(HIGO_LAYOUT_INFO_S *pLayoutInfo, HI_HANDLE *hlayout);

/**
\brief get text from context CNcomment:从上下文中获取字符串 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\prarm[out] length length of string CNcomment 字符串长度 CNend
\param[out] str address of UTF-8 string CNcomment UTF8编码的字符串地址 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutGetText(HI_HANDLE hlayout, HI_S32 *length, HI_CHAR **str);

/**
\brief clear text in context CNcomment:从上下文中清除字符串 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutClearText(HI_HANDLE hlayout);

/**
\brief insert text to context at current cursor pos CNcomment:在上下文的当前光标位置插入字符串 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] pText UTF-8 string to insert CNcomment 待插入的UTF-8字符串 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutInsertText(HI_HANDLE hlayout, const HI_CHAR *pText);

/**
\brief delete some character from context at current cursor pos CNcomment:在上下文的当前光标位置删除字符字符串 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] sCount CNcomment 待删除的字符数量 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutDeleteText(HI_HANDLE hlayout, HI_S32 sCount);

/**
\brief Get layout rectangle's width & height CNcomment:获得排版矩形的高度和宽度CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[out] layout rectangle, the x,y fields set to 0 CNcomment 排版矩形的高度和宽度 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutGetRect(HI_HANDLE hlayout, HI_RECT *pRect);

/**
\brief Set view port position CNcomment:设置视口的位置 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] position of view port  CNcomment 视口的位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetViewPort(HI_HANDLE hlayout, HI_POINT *pPos);

/**
\brief Set view port size CNcomment:设置视口的大小 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] w	width of viewport CNcomment w 视口宽度 CNend
\param[in] h	height of viewport CNcomment h 视口高度 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetViewPortSize(HI_HANDLE hlayout, HI_S32 w, HI_S32 h);

/**
\brief get view port position CNcomment:获取视口的位置 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] position of view port  CNcomment 视口的位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_GetViewPort(HI_HANDLE hlayout, HI_POINT *pPos);

/**
\brief Set view port position CNcomment:设置视口的大小和位置 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] size & position of view port  CNcomment 视口的位置和大小 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetViewPortEx(HI_HANDLE hlayout, HI_RECT *pPos);

/**
\brief Output text CNcomment:输出字符 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] hSurface surface to draw on CNcomment 待绘制的表面 CNend
\param[in] pRect display rectangle CNcomment 显示的矩形的位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutTextOut(HI_HANDLE hlayout, HI_HANDLE hSurface, const HI_RECT *pRect);

/**
\brief Destroy layout context CNcomment:销毁排版上下文 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_DestroyLayout(HI_HANDLE hlayout);

/**
\brief begin select CNcomment:开始选择 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] pos position of select beginning  CNcomment 选择开始位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetSelecting(HI_HANDLE hlayout, HI_POINT *pos);

/**
\brief select area confirmed CNcomment:确定选择区域 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] pos end position of select area CNcomment 选择区域结束位置 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetSelected(HI_HANDLE hlayout, HI_POINT *pos);

/**
\brief select finished CNcomment:取消选择 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SelectFinish(HI_HANDLE hlayout);

/**
\brief get select string from ctx CNcomment:从上下文中获取选中的字符串 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] str  UTF8 string to output CNcomment 输出的UTF-8字符串 CNend
\param[in] len  lenth of output string 输出的字符串 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:失败 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_GetSelectString(HI_HANDLE hlayout, HI_CHAR **str, HI_U32 *len);

/**
\brief set selected area text color CNcomment:设置选中区域的颜色 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] fg foreground color CNcomment 前景色 CNend
\param[in] bg backgroud color CNcomment 背景色 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_SetSelectColor(HI_HANDLE hlayout, HI_COLOR fg, HI_COLOR bg);

/**
\brief delete select string CNcomment:删除选中区域 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] fg foreground color CNcomment 前景色 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_DeleteSelectString(HI_HANDLE hlayout);

/**
\brief Get line count of layout context CNcomment:获取排版的行数 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\retval ::line count of layout context or zero if failed.CNcomment:成功返回行数，失败返回0 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutGetLineNum(HI_HANDLE hlayout);

/**
\brief Set font of layout context CNcomment:设置排版上下文的字体 CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hlayout handle of layout context CNcomment 排版上下文句柄 CNend
\param[in] hFont handle of font to set CNcomment 字体的句柄 CNend
\retval ::HI_SUCCESS Success.CNcomment:成功 CNend
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutSetFont(HI_HANDLE hlayout, HI_HANDLE hFont);

/**
\brief Add text to layout context.CNcomment:向排版上下文中添加文本。CNend
\param[in] hlayout  Text layout handle.CNcomment:文本排版上下文句柄 CNend
\param[in] pText    Text contents ending with /0.CNcomment:以/0结尾的文本内容 CNend
\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR
\see \n
N/A.CNcomment:无 CNend
*/
HI_S32 HI_GO_LayoutAddText(HI_HANDLE hlayout, const HI_CHAR *pText);

 /**
\brief Check the cursor of context in SOT(Start of Text) position CNcomment:检查排版上下文中光标是否在SOT(文本开始位置)CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hLayout Handle of a text layout object.CNcomment:文本排版上下文句柄 CNend
\retval ::HI_TRUE
\retval ::HI_FALSE
\see \n
N/A.CNcomment:无 CNend
*/
HI_BOOL HI_GO_CursorInSot(HI_HANDLE hLayout);

/**
\brief Check the cursor of context in EOT(End of Text) position CNcomment:检查排版上下文中光标是否在EOT(文本结束位置)CNend
\attention \n
N/A.CNcomment:无 CNend
\param[in] hLayout Handle of a text layout object.CNcomment:文本排版上下文句柄 CNend
\retval ::HI_TRUE
\retval ::HI_FALSE
\see \n
N/A.CNcomment:无 CNend
*/
HI_BOOL HI_GO_CursorInEot(HI_HANDLE hLayout);
/** @} */  /*! <!-- API declaration end */
#ifdef __cplusplus
#if __cplusplus
}
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#endif /* __HI_GO_TEXT_H__ */
