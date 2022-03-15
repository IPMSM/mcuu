/*
 * ADC.h
 *
 *  Created on: 2022. 3. 14.
 *      Author: user
 */

#ifndef ADC_H_
#define ADC_H_





#endif /* ADC_H_ */

#include "GPIO.h"
#include "External_ISR_Default.h"
#include "Timer_ISR_Default.h"

#define SCU_WDT_CPU0    (*(volatile unsigned int*)(SCU + 0x100 ))

/*VADC Registers*/
#define VADC            (0xF0020000)
#define VADC_CLC        (*(volatile unsigned int*)(VADC + 0x000 ))
#define VADC_GLOBCFG    (*(volatile unsigned int*)(VADC + 0x080 ))
#define VADC_G4ARBCFG    (*(volatile unsigned int*)(VADC + 0x1480 ))
#define VADC_G4ARBPR    (*(volatile unsigned int*)(VADC + 0x1484 ))
#define VADC_G4ICLASS0    (*(volatile unsigned int*)(VADC + 0x14A0 ))
#define VADC_G4QMR0    (*(volatile unsigned int*)(VADC + 0x1504 ))
#define VADC_G4QINR0    (*(volatile unsigned int*)(VADC + 0x1510 ))
#define VADC_G4CHCTR6   (*(volatile unsigned int*)(VADC + 0x1618))
#define VADC_G4CHCTR7    (*(volatile unsigned int*)(VADC + 0x161C ))
#define VADC_G4RES1    (*(volatile unsigned int*)(VADC + 0x1704 ))

#define DISS            1
#define DISR            0
#define ANONC           0
#define ASEN0           24
#define CSM0            3
#define PRIO0           0
#define CMS             8
#define STCS            0
#define FLUSH           10
#define TREV            9
#define ENGT            0
#define RF              5
#define REQCHNR         0
#define RESPOS          21
#define RESREG          16
#define ICLSEL          0
#define VF              31
#define RESULT          0
