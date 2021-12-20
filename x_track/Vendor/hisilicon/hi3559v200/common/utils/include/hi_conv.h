/**
 * Copyright (C), 2019-2029, Unionman Tech. Co., Ltd.
 * All rights reserved.
 *
 * @file    hi_conv.h
 * @brief   hi conv functions declaration
 * @author  minjie.yu
 * @date    2019.03.25
 */
#ifndef __HI_CONV_H__
#define __HI_CONV_H__


#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

int HI_CONV_UTF8toUNICODE_CHAR(unsigned char *ch, int *unicode);

int HI_CONV_UTF8toUNICODE(unsigned char * utf8_str,
        unsigned short * unicode_str,
        int unicode_str_size);

int HI_CONV_GB2312toUTF8( char*  ptDestText,
        int  nDestLength,
        char*  ptSrcText,
        int  nSrcLength);

int HI_CONV_UTF8toGB2312(unsigned char *gb2312_str,
        int len_gb2312,
        unsigned char *utf8_str,
        int len_utf8);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif
