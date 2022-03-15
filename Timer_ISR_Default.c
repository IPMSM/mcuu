/*
 * Timer_ISR_Default.c
 *
 *  Created on: 2022. 3. 14.
 *      Author: user
 */

#include "Timer_ISR_Default.h"

void init_CCU60(float time){

    /* CCU60 T12 Setting */
        /* Password Access to unlock WDTSCON0 */
        SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
        while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

        /* Modify Access to clear ENDINIT bit */
        SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) & ~ (1 << ENDINIT);
        while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

        CCU60_CLC &= ~(1 << DISR);                     // Enable CCU60 Module


        /* Password Access to unlock WDTSCON0 */
        SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
        while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

        /* Modify Access to clear ENDINIT bit */
        SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) & ~ (1 << ENDINIT);
        while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

        while((CCU60_CLC & (1 << DISS)) != 0);       // Wait until module is enabled

        /* Core*/

        CCU60_TCTR0 &= ~((0x7) << T12CLK);           // f_T12 = f_CCU6 / prescaler
        CCU60_TCTR0 |= ((0x2) << T12CLK);            // F_CCU6 = 50 MHz, 4╨паж >> 12.5MHz
        CCU60_TCTR0 |= (1 << T12PRE);                // f_T12 = 48828 Hz >> 48.828k

        CCU60_TCTR0 &= ~(1 << CTM);                  // T12 always counts up and continues counting
                                                     // from zero after reaching the period value

        int value = time*48828 - 1;
        CCU60_T12PR = value;                  // Interrupt freq. = f_T12 / (period value  + 1)
        CCU60_TCTR4 |= (1 << T12STR);                // Interrupt freq. = 2 Hz

        CCU60_T12 = 0;                               // Clear T12 counting value

        /* CCU60 T12 Interrupt Setting */
        CCU60_INP &= ~((0x3) << INPT12);             // Service Request output SR0 is selected

        CCU60_IEN |= (1 << ENT12PM);                 // Enable Interrupt for T12 Period-Match

        /* SRC Interrupt Setting For CCU60 */
        SRC_CCU60_SR0 &= ~((0xFF) << SRPN);           // Set Priority : 0x0A
        SRC_CCU60_SR0 |= ((0x0C) << SRPN);

        SRC_CCU60_SR0 &= ~((0x3) << TOS);             // CPU0 services

        SRC_CCU60_SR0 |= (1 << SRE);                  // Service Request is enabled

        /* CCU60 T12 Start */
        CCU60_TCTR4 = (1 << T12RS);                  // T12 starts counting

}


