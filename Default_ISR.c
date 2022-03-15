/*
 * Default_ISR.c
 *
 *  Created on: 2022. 3. 11.
 *      Author: user
 */
#include "External_ISR_Default.h"
#include "GPIO.h"
#include "STM.h"
#include "Timer_ISR_Default.h"

void tick_check(void);
void init_RGBLED(void);
void tick_check(void);
void init_LED(void);
void init_SW(void);
void init_ERU(void);
void ERU0_ISR(void);
void init_CCU60(float);
void init_VADC(void);
void VADC_startConversion(void);
unsigned int VADC_readResult(void);


__interrupt (0x0A) __vector_table(0)
void ERU0_ISR(void){

    SCU_EICR1  &= ~((0x1 << EIEN0)     |                       // The trigger event is disabled
                   (0x1 << EIEN1))     ;
    P10_OMR |= ((SET<<PCL1) | (SET<<PS1));
    tick_check();
    SCU_EICR1 |= ((0x01) <<EIEN0);  // // The trigger event is enabled
    SCU_EICR1 |= ((0x01) <<EIEN1);  // INTF cleared
}


__interrupt(0x0B) __vector_table(0)
void ERU1_ISR(void)
{
    SCU_EICR1  &= ~((0x1 << EIEN0)     |                       // The trigger event is enabled
                   (0x1 << EIEN1))     ;
    P10_OMR |= ((1<<PCL2) | (1<<PS2));           // Toggle LED BLUE
    tick_check();

    SCU_EICR1 |= ((0x01) <<EIEN0);  // INTF cleared
    SCU_EICR1 |= ((0x01) <<EIEN1);  // INTF cleared
}

int cnt_timer = 0;
int cnt_timer2 = 0;
unsigned int adcResult;
unsigned int adcResult_old;
unsigned int adcResult_flt;
float tau = 1;

__interrupt(0x0C) __vector_table(0)
void CCU60_T12_ISR(void)
{

    VADC_startConversion();
    adcResult = GetVADC4(7);

    adcResult_flt = (tau*adcResult_old + 0.1*adcResult)/(tau + 0.1);
    adcResult_old = adcResult_flt;
    //printf("%d\n",adcResult_flt);
    cnt_timer ++;

    if(adcResult_flt >= 3096)
    {
        P02_OMR |= (1<<PS7);            // Set LED RED
        P10_OMR |= (1<<PCL5);           // Clear LED GREEN
        P10_OMR |= (1<<PCL3);           // Clear LED BLUE
    }
    else if(adcResult_flt >= 2048)
    {
        P02_OMR |= (1<<PCL7);            // Clear LED RED
        P10_OMR |= (1<<PS5);             // Set LED GREEN
        P10_OMR |= (1<<PCL3);            // Clear LED BLUE
    }
    else if(adcResult_flt >= 1024)
    {
        P02_OMR |= (1<<PCL7);            // Clear LED RED
        P10_OMR |= (1<<PCL5);            // Clear LED GREEN
        P10_OMR |= (1<<PS3);             // Set LED BLUE
    }
    else
    {
        P02_OMR |= (1<<PCL7);            // Clear LED RED
        P10_OMR |= (1<<PCL5);            // Clear LED GREEN
        P10_OMR |= (1<<PCL3);            // Clear LED BLUE
    }

    if( cnt_timer%50== 0){          /* every 0.5msec*/
        P10_OMR |= ((SET<<PCL2) | (SET<<PS2));
        cnt_timer2++;

        if( cnt_timer2 % 2 == 0){   /* every 0.1msec*/
            P10_OMR |= ((SET<<PCL1) | (SET<<PS1));
        }
    }


}

