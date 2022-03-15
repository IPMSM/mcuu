/*
 * PWM.h
 *
 *  Created on: 2022. 3. 15.
 *      Author: user
 */

#ifndef PWM_H_
#define PWM_H_





#endif /* PWM_H_ */
#include "GPIO.h"
#include "External_ISR_Default.h"

// GTM Registers
// GTM - CMU
#define SCU_BASE        (0xF0036000)
#define SCU_WDT_CPU0CON0 (*(volatile unsigned int*)(SCU_BASE + 0x100))
#define GTM_BASE                    (0xF0100000)
#define GTM_CMU_CLK_EN              (*(volatile unsigned int*)(GTM_BASE + 0x00300))
#define GTM_CMU_FXCLK_CTRL          (*(volatile unsigned int*)(GTM_BASE + 0x00344))

#define EN_FXCLK                    22
#define FXCLK_SEL                   0

// GTM - TOM0
#define GTM_TOM0_TGC0_GLB_CTRL      (*(volatile unsigned int*)(GTM_BASE + 0x08030))
#define GTM_TOM0_TGC0_ENDIS_CTRL    (*(volatile unsigned int*)(GTM_BASE + 0x08070))
#define GTM_TOM0_TGC0_OUTEN_CTRL    (*(volatile unsigned int*)(GTM_BASE + 0x08078))
#define GTM_TOM0_TGC0_FUPD_CTRL     (*(volatile unsigned int*)(GTM_BASE + 0x08038))
#define GTM_TOM0_CH1_CTRL           (*(volatile unsigned int*)(GTM_BASE + 0x08040))
#define GTM_TOM0_CH1_SR0            (*(volatile unsigned int*)(GTM_BASE + 0x08044))
#define GTM_TOM0_CH1_SR1            (*(volatile unsigned int*)(GTM_BASE + 0x08048))


#define GTM_TOM0_CH2_CTRL           (*(volatile unsigned int*)(GTM_BASE + 0x08040+0x0040))
#define GTM_TOM0_CH2_SR0            (*(volatile unsigned int*)(GTM_BASE + 0x08044+0x0040))
#define GTM_TOM0_CH2_SR1            (*(volatile unsigned int*)(GTM_BASE + 0x08048+0x0040))


#define UPEN_CTRL1                  18
#define UPEN_CTRL2                  20
#define HOST_TRIG                   0
#define ENDIS_CTRL1                 2
#define ENDIS_CTRL2                 4
#define OUTEN_CTRL1                 2
#define OUTEN_CTRL2                 4
#define RSTCN0_CH1                  18
#define RSTCN0_CH2                  20
#define FUPD_CTRL1                  2
#define FUPD_CTRL2                  4
#define CLK_SRC_SR                  12
#define SL                          11

// GTM
#define GTM_CLC                     (*(volatile unsigned int*)(GTM_BASE + 0x9FD00))
#define GTM_TOUTSEL6                (*(volatile unsigned int*)(GTM_BASE + 0x9FD48))

#define DISS                        1
#define DISR                        0
#define SEL7                        14
#define SEL8                        15
