/*
 * Timer_ISR_Default.h
 *
 *  Created on: 2022. 3. 14.
 *      Author: user
 */
#include "External_ISR_Default.h"

#ifndef TIMER_ISR_DEFAULT_H_
#define TIMER_ISR_DEFAULT_H_


#endif /* TIMER_ISR_DEFAULT_H_ */

#define SCU           (0xF0036000)
#define SRPN        0
#define SRE         10
#define SRC           (0xF0038000)
#define SCU_WDT_CPU0CON0    (*(volatile unsigned int*)(SCU + 0x100 ))   /*page : */
#define SRC_CCU60_SR0       (*(volatile unsigned int*)(SRC + 0x420 ))

/*===============CCU60 Kernal Register Groups====================*/
#define CCU60 0xF0002A00

/* CCU 60 Registers*/
#define CCU60_CLC           (*(volatile unsigned int*)(CCU60 + 0x000 )) /* Clock Control Register
/* CLC bits*/
#define DISR            0       /*Module Disable Request Bit
                                Used for enable/disable control of the module.
                                0B Module disable is not requested.
                                1B Module disable is requested.*/
#define DISS            1       /*Module Disable Status Bit
                                Bit indicates the current status of the module.
                                0B Module is enabled.
                                1B Module is disabled.*/
#define CCU60_T12           (*(volatile unsigned int*)(CCU60 + 0x020 )) /*Timer T12 Counter Register*/
#define CCU60_T12PR         (*(volatile unsigned int*)(CCU60 + 0x024 )) /*Timer T12 Period Register*/
#define CCU60_TCTR0         (*(volatile unsigned int*)(CCU60 + 0x070 )) /*Timer T12,13 Control Register*/
/* TCRT0 bits*/

#define T12CLK          0       /*Timer T12 Input Clock Select
Selects the input clock for timer T12 that is derived from
the peripheral clock according to the equation
fT12 = fCC6 / 2<T12CLK>.
000B fT12 = fCC6
001B fT12 = fCC6 / 2
010B fT12 = fCC6 / 4
011B fT12 = fCC6 / 8
100B fT12 = fCC6 / 16
101B fT12 = fCC6 / 32
110B fT12 = fCC6 / 64
111B fT12 = fCC6 / 128*/

#define T12PRE          3       /*Timer T12 Prescaler Bit
                                In order to support higher clock frequencies, an
                                additional prescaler factor of 1/256 can be enabled for
                                the prescaler for T12.
                                0B The additional prescaler for T12 is disabled.
                                1B The additional prescaler for T12 is enabled.*/

#define T12R           4       /*Timer T12 Run Bit1)
                                T12R starts and stops timer T12. It is set/cleared by SW
                                by setting bits T12RR or T12RS or it is cleared by HW
                                according to the function defined by bit field T12SSC.
                                0B Timer T12 is stopped.
                                1B Timer T12 is running.*/

#define STE12           5       /*Timer T12 Shadow Transfer Enable
                                Bit STE12 enables or disables the shadow transfer of
                                the T12 period value, the compare values and passive
                                state select bits and levels from their shadow registers to
                                the actual registers if a T12 shadow transfer event is
                                detected. Bit STE12 is cleared by hardware after the
                                shadow transfer.
                                A T12 shadow transfer event is a period-match while
                                counting up or a one-match while counting down.
                                0B The shadow register transfer is disabled.
                                1B The shadow register transfer is enabled.*/

#define CDIR            6       /*Count Direction of Timer T12
                                This bit is set/cleared according to the counting rules of
                                T12.
                                0B T12 counts up.
                                1B T12 counts down.*/

#define CTM             7       /*T12 Operating Mode
                                    0B Edge-aligned Mode:
                                    T12 always counts up and continues counting
                                    from zero after reaching the period value.
                                    1B Center-aligned Mode:
                                    T12 counts down after detecting a period-match
                                    and counts up after detecting a one-match.*/
#define CCU60_TCTR4         (*(volatile unsigned int*)(CCU60 + 0x078 )) /*TCTR4 provides software-control (independent set and clear conditions) for the
                                                                            run bits T12R and T13R. Furthermore, the timers can be reset (while running) and bits
                                                                             STE12 and STE13 can be controlled by software. Reading these bits always returns 0.*/

/* TCTR4 bits*/
#define T12STR          6       /*Timer T12 Shadow Transfer Request
0B No action
1B STE12 is set, enabling the shadow transfer.*/

#define T12RS           1       /*Timer T12 Run Set
Setting this bit sets the T12R bit.
0B T12R is not influenced.
1B T12R is set, T12 starts counting.*/

#define CCU60_INP         (*(volatile unsigned int*)(CCU60 + 0x0AC)) /*Interrupt Node Pointer Register*/
/* INP bits*/
#define INPT12          10      /*Interrupt Node Pointer for Timer12 Interrupts
This bit field defines the service request output activated
due to a set condition for bit T12OM (if enabled by bit
ENT12OM) or for bit T12PM (if enabled by bit
ENT12PM).
Coding see INPCC6x.*/
#define CCU60_IEN         (*(volatile unsigned int*)(CCU60 + 0x0B0))  /*Interrupt Enable Register
                        Register IEN contains the interrupt enable bits and a control bit to enable the automatic
                        idle function in the case of a wrong hall pattern.*/

#define ENT12PM        7   /*Enable Interrupt for T12 Period-Match
                            0B No interrupt will be generated if the set condition
                            for bit T12PM in register IS occurs.
                            1B An interrupt will be generated if the set condition
                            for bit T12PM in register IS occurs. The service
                            request output that will be activated is selected by
                            bit field INPT12.*/


