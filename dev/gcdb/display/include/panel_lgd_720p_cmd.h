/* Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of The Linux Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*---------------------------------------------------------------------------
 * This file is autogenerated file using gcdb parser. Please do not edit it.
 * Update input XML file to add a new entry or update variable in this file
 * VERSION = "1.0"
 *---------------------------------------------------------------------------*/

#ifndef _PANEL_LGD_720P_CMD_H_

#define _PANEL_LGD_720P_CMD_H_
/*---------------------------------------------------------------------------*/
/* HEADER files                                                              */
/*---------------------------------------------------------------------------*/
#include "panel.h"

/*---------------------------------------------------------------------------*/
/* Panel configuration                                                       */
/*---------------------------------------------------------------------------*/

static struct panel_config lgd_720p_cmd_panel_data = {
  "qcom,mipi_dsi_lgd_720p_cmd", "dsi:0:", "qcom,mipi-dsi-panel",
  10, 1, "DISPLAY_1", 0, 384000000, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1
};

/*---------------------------------------------------------------------------*/
/* Panel resolution                                                          */
/*---------------------------------------------------------------------------*/
static struct panel_resolution lgd_720p_cmd_panel_res = {
  720, 1280, 23, 16, 8, 0, 7, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel Color Information                                                   */
/*---------------------------------------------------------------------------*/
static struct color_info lgd_720p_cmd_color = {
  24, 2, 0xff, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel Command information                                                 */
/*---------------------------------------------------------------------------*/
static char lgd_mca[8] = {
	0x02, 0x00, 0x29, 0xC0,
	0xb0, 0x04, 0xff, 0xff
};
static char lgd_seqctrl[8] = {
	0x02, 0x00, 0x29, 0xC0,
	0xd6, 0x01, 0xff, 0xff
};
static char lgd_fmis1[12] = {
	0x07, 0x00, 0x29, 0xC0,
	0xb3, 0x00, 0xc0, 0x00,
	0x00, 0x00, 0x00, 0xff
};
static char lgd_fmis2[8] = {
	0x03, 0x00, 0x29, 0xC0,
	0xb4, 0x0c, 0x00, 0xff
};
static char lgd_fmis3[8] = {
	0x03, 0x00, 0x29, 0xC0,
	0xb6, 0x39, 0xa3, 0xff
};
static char lgd_gip[8] = {
	0x02, 0x00, 0x29, 0xC0,
	0xcc, 0x16, 0xff, 0xff
};

static char lgd_dispset1common[44] = {
	0x27, 0x00, 0x29, 0xC0,
	0xc1, 0x8c, 0x62, 0x40,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x62,
	0x30, 0x40, 0xa5, 0x0f,
	0x04, 0x07, 0x20, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x00, 0xff
};

static char lgd_dispset2[12] = {
	0x08, 0x00, 0x29, 0xC0,
	0xc2, 0x30, 0xf5, 0x00,
	0x0b, 0x0b, 0x00, 0x00
};

static char lgd_srctimming[20] = {
	0x0e, 0x00, 0x29, 0xC0,
	0xc4, 0x70, 0x7f, 0x7f,
	0x00, 0x80, 0xff, 0x01,
	0x0f, 0x0f, 0x0f, 0x03,
	0x01, 0x01, 0xff, 0xff
};

static char lgd_giptimming[12] = {
	0x07, 0x00, 0x29, 0xC0,
	0xc6, 0xb6, 0x7f, 0xff,
	0xb6, 0x7f, 0xff, 0xff
};

static char lgd_pwmfreq[12] = {
	0x08, 0x00, 0x29, 0xC0,
	0xce, 0x00, 0x01, 0x88,
	0x01, 0x18, 0x00, 0x01
};

static char lgd_pwrsetchargepump[24] = {
	0x11, 0x00, 0x29, 0xC0,
	0xd0, 0x00, 0x11, 0x18,
	0x18, 0x98, 0x98, 0x18,
	0x01, 0x89, 0x01, 0xff,
	0x4c, 0xc9, 0x0e, 0x21,
	0x20, 0xff, 0xff, 0xff
};

static char lgd_pwrsetinternal[32] = {
	0x19, 0x00, 0x29, 0xC0,
	0xd3, 0x1b, 0xb3, 0xbb,
	0xbb, 0x33, 0x33, 0x33,
	0x33, 0x55, 0x01, 0x00,
	0xf0, 0xf8, 0xa0, 0x00,
	0xc6, 0xb7, 0x33, 0xa2,
	0x72, 0xca, 0x00, 0x00,
	0x00, 0xff, 0xff, 0xff
};

static char lgd_sleepout[4] = {
	0x11, 0x00, 0x05, 0x80,
};

static char lgd_sleepout1[4] = {
	0xFF, 0xEE, 0x15, 0x80,
};

static char lgd_sleepout2[4] = {
	0xFB, 0x01, 0x15, 0x80,
};

static char lgd_sleepout21[4] = {
	0x12, 0x50, 0x15, 0x80,
};

static char lgd_sleepout22[4] = {
	0x13, 0x02, 0x15, 0x80,
};

static char lgd_sleepout23[4] = {
	0x6A, 0x60, 0x15, 0x80,
};

static char lgd_sleepout231[4] = {
	0x04, 0xAD, 0x15, 0x80,
};

static char lgd_sleepout232[4] = {
	0xFF, 0x05, 0x15, 0x80,
};

static char lgd_sleepout233[4] = {
	0xFB, 0x01, 0x15, 0x80,
};

static char lgd_sleepout234[4] = {
	0x19, 0x6F, 0x15, 0x80,
};

static char lgd_sleepout235[4] = {
	0xFF, 0x00, 0x15, 0x80,
};

static char lgd_sleepout24[4] = {
	0xFF, 0x01, 0x15, 0x80,
};

static char lgd_sleepout25[4] = {
	0xFB, 0x01, 0x15, 0x80,
};

static char lgd_sleepout26[4] = {
	0x39, 0x01, 0x15, 0x80,
};

static char lgd_sleepout27[4] = {
	0xFF, 0x00, 0x15, 0x80,
};

static char lgd_sleepout28[4] = {
	0xFB, 0x01, 0x15, 0x80,
};

static char lgd_sleepout3[4] = {
	0xBA, 0x03, 0x15, 0x80,
};

static char lgd_sleepout4[4] = {
	0xC2, 0x08, 0x15, 0x80,
};

static char lgd_sleepout41[4] = {
	0xFF, 0x05, 0x15, 0x80,
};

static char lgd_sleepout42[4] = {
	0x19, 0x7F, 0x15, 0x80,
};

static char lgd_sleepout43[4] = {
	0xFF, 0x00, 0x15, 0x80,
};

static char lgd_coladdr[12] = {
	0x05, 0x00, 0x39, 0xC0,
	0x2a, 0x00, 0x00, 0x02,
	0xcf, 0xff, 0xff, 0xff
};

static char lgd_pageaddr[12] = {
	0x05, 0x00, 0x39, 0xC0,
	0x2b, 0x00, 0x00, 0x04,
	0xff, 0xff, 0xff, 0xff
};

static char lgd_teon[8] = {
	0x02, 0x00, 0x39, 0xC0,
	0x35, 0x00, 0xff, 0xff
};

static char lgd_setaddr[8] = {
	0x02, 0x00, 0x39, 0xC0,
	0x36, 0x00, 0xff, 0xff
};

static char lgd_setpixfmt[8] = {
	0x02, 0x00, 0x39, 0xC0,
	0x3a, 0x07, 0xff, 0xff
};

static char lgd_dispon[4] = {
	0x29, 0x00, 0x05, 0x80,
};

static char auo_wdispbrightness[8] = {
	0x02, 0x00, 0x29, 0xC0,
	0x51, 0xef, 0xff, 0xff
};

static char auo_wctrldisp[8] = {
	0x02, 0x00, 0x29, 0xC0,
	0x53, 0x2c, 0xff, 0xff
};

static char auo_wcabcctrl[8] = {
	0x02, 0x00, 0x29, 0xC0,
	0x55, 0x01, 0xff, 0xff
};

static char lgd_wdispbrightness[8] = {
	0x03, 0x00, 0x39, 0xC0,
	0x51, 0x1f, 0xff, 0xff
};

static char lgd_wctrldisp[8] = {
	0x02, 0x00, 0x39, 0xC0,
	0x53, 0x2c, 0xff, 0xff
};

static char lgd_wcabcctrl[8] = {
	0x02, 0x00, 0x39, 0xC0,
	0x55, 0x02, 0xff, 0xff
};

static struct mipi_dsi_cmd lgd_720p_cmd_on_command[] = {
	{sizeof(lgd_mca), lgd_mca},
	{sizeof(lgd_seqctrl), lgd_seqctrl},
	{sizeof(lgd_fmis1), lgd_fmis1},
	{sizeof(lgd_fmis2), lgd_fmis2},
	{sizeof(lgd_fmis3), lgd_fmis3},
	{sizeof(lgd_gip), lgd_gip},
	{sizeof(lgd_dispset1common), lgd_dispset1common},
	{sizeof(lgd_dispset2), lgd_dispset2},
	{sizeof(lgd_srctimming), lgd_srctimming},
	{sizeof(lgd_giptimming), lgd_giptimming},
	{sizeof(lgd_pwmfreq), lgd_pwmfreq},
	{sizeof(lgd_pwrsetchargepump), lgd_pwrsetchargepump},
	{sizeof(lgd_pwrsetinternal), lgd_pwrsetinternal},
	{sizeof(lgd_sleepout), lgd_sleepout},
	{sizeof(lgd_coladdr), lgd_coladdr},
	{sizeof(lgd_pageaddr), lgd_pageaddr},
	{sizeof(lgd_teon), lgd_teon},
	{sizeof(lgd_setaddr), lgd_setaddr},
	{sizeof(lgd_setpixfmt), lgd_setpixfmt},
	{sizeof(lgd_dispon), lgd_dispon},
	{sizeof(lgd_wdispbrightness), lgd_wdispbrightness},
	{sizeof(lgd_wctrldisp), lgd_wctrldisp},
	{sizeof(lgd_wcabcctrl), lgd_wcabcctrl},
};
#define LGD_720P_CMD_ON_COMMAND 23

static struct mipi_dsi_cmd auo_720p_cmd_on_command[] = {
	{sizeof(lgd_sleepout1), lgd_sleepout1},
	{sizeof(lgd_sleepout2), lgd_sleepout2},
	{sizeof(lgd_sleepout21), lgd_sleepout21},
	{sizeof(lgd_sleepout22), lgd_sleepout22},
	{sizeof(lgd_sleepout23), lgd_sleepout23},
	{sizeof(lgd_sleepout231), lgd_sleepout231},
	{sizeof(lgd_sleepout232), lgd_sleepout232},
	{sizeof(lgd_sleepout233), lgd_sleepout233},
	{sizeof(lgd_sleepout234), lgd_sleepout234},
	{sizeof(lgd_sleepout235), lgd_sleepout235},
	{sizeof(lgd_sleepout24), lgd_sleepout24},
	{sizeof(lgd_sleepout25), lgd_sleepout25},
	{sizeof(lgd_sleepout26), lgd_sleepout26},
	{sizeof(lgd_sleepout27), lgd_sleepout27},
	{sizeof(lgd_sleepout28), lgd_sleepout28},
	{sizeof(lgd_sleepout3), lgd_sleepout3},
	{sizeof(lgd_sleepout4), lgd_sleepout4},
	{sizeof(lgd_sleepout), lgd_sleepout},
	{sizeof(lgd_sleepout41), lgd_sleepout41},
	{sizeof(lgd_sleepout42), lgd_sleepout42},
	{sizeof(lgd_sleepout43), lgd_sleepout43},
	{sizeof(auo_wdispbrightness), auo_wdispbrightness},
	{sizeof(auo_wctrldisp), auo_wctrldisp},
	{sizeof(auo_wcabcctrl), auo_wcabcctrl},
	{sizeof(lgd_coladdr), lgd_coladdr},
	{sizeof(lgd_pageaddr), lgd_pageaddr},
	{sizeof(lgd_teon), lgd_teon},
	{sizeof(lgd_dispon), lgd_dispon},
};
#define AUO_720P_CMD_ON_COMMAND 28

static struct mipi_dsi_cmd jdi_720p_cmd_on_command[] = {
	{sizeof(lgd_sleepout), lgd_sleepout},
	{sizeof(lgd_coladdr), lgd_coladdr},
	{sizeof(lgd_pageaddr), lgd_pageaddr},
	{sizeof(lgd_teon), lgd_teon},
	{sizeof(lgd_setaddr), lgd_setaddr},
	{sizeof(lgd_setpixfmt), lgd_setpixfmt},
	{sizeof(lgd_dispon), lgd_dispon},
	{sizeof(lgd_wdispbrightness), lgd_wdispbrightness},
	{sizeof(lgd_wctrldisp), lgd_wctrldisp},
	{sizeof(lgd_wcabcctrl), lgd_wcabcctrl},
};
#define JDI_720P_CMD_ON_COMMAND 10

static char lgd_720p_cmdoff_cmd0[] = {
0x28, 0x00, 0x05, 0x80 };


static char lgd_720p_cmdoff_cmd1[] = {
0x10, 0x00, 0x05, 0x80 };

static struct mipi_dsi_cmd lgd_720p_cmd_off_command[] = {
{ 0x4 , lgd_720p_cmdoff_cmd0, 0},
{ 0x4 , lgd_720p_cmdoff_cmd1, 0}
};
#define LGD_720P_CMD_OFF_COMMAND 2


static struct command_state lgd_720p_cmd_state = {
  0, 1
};

/*---------------------------------------------------------------------------*/
/* Command mode panel information                                            */
/*---------------------------------------------------------------------------*/
static struct commandpanel_info lgd_720p_cmd_command_panel = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Video mode panel information                                              */
/*---------------------------------------------------------------------------*/

static struct videopanel_info lgd_720p_cmd_video_panel = {
  0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Lane Configuration                                                        */
/*---------------------------------------------------------------------------*/

static struct lane_configuration lgd_720p_cmd_lane_config = {
  4, 0, 1, 1, 1, 1
};


/*---------------------------------------------------------------------------*/
/* Panel Timing                                                              */
/*---------------------------------------------------------------------------*/
const uint32_t lgd_720p_cmd_timings[] = {
  0xb3, 0x8c, 0x1d, 0x00, 0x20, 0x94, 0x20, 0x8e, 0x20, 0x03, 0x04
};



static struct mipi_dsi_cmd lgd_720p_cmd_rotation[] = {

};
#define TOSHIBA_720P_VIDEO_ROTATION 0


static struct panel_timing lgd_720p_cmd_timing_info = {
  0x04, 0x04, 34, 59
};

// TODO
static struct panel_reset_sequence lgd_720p_cmd_panel_reset_seq = {
{ 1, 0, 1, }, { 20, 200, 20, }, 2
};

/*---------------------------------------------------------------------------*/
/* Backlight Settings                                                        */
/*---------------------------------------------------------------------------*/

// TODO
static struct backlight lgd_720p_cmd_backlight = {
  1, 1, 4095, 100, 1, "PMIC_8921"
};
#define LGD_720P_CMD_SIGNATURE 0xFFF4


#endif /*_PANEL_LGD_720P_CMD_H_*/
