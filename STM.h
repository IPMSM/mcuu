/*
 * STM.h
 *
 *  Created on: 2022. 3. 11.
 *      Author: user
 */

#ifndef STM_H_
#define STM_H_

/* Memory name mapping */

/*Module*/
#define STM0    *(unsigned int*)(0xF0000000)
#define STM1    *(unsigned int*)(0xF0000100)
#define STM2    *(unsigned int*)(0xF0000200)

/* STM_0Register*/

#define STM0_TIM0    *(unsigned int*)(0xF0000000 + 0x10)
#define STM0_TIM1    *(unsigned int*)(0xF0000000 + 0x14)
#define STM0_TIM2    *(unsigned int*)(0xF0000000 + 0x18)
#define STM0_TIM3    *(unsigned int*)(0xF0000000 + 0x1C)
#define STM0_TIM4    *(unsigned int*)(0xF0000000 + 0x20)
#define STM0_TIM5    *(unsigned int*)(0xF0000000 + 0x24)
#define STM0_TIM6    *(unsigned int*)(0xF0000000 + 0x28)
#define STM0_CMP0    *(unsigned int*)(0xF0000000 + 0x30)
#define STM0_CMP1    *(unsigned int*)(0xF0000000 + 0x34)

/* Compare match Control Register*/
#define STM0_CMCON    *(unsigned int*)(0xF0000000 + 0x38)
/** Compare match control register bits*/
#define MSIZE0          0 /* This bit field determines the number of bits in register
                            CMP0 (starting from bit 0) that are used for the
                            compare operation with the System Timer.
                            00000B CMP0[0] used for compare operation
                            00001B CMP0[1:0] used for compare operation
                            ...
                            11110B CMP0[30:0] used for compare operation
                            11111B CMP0[31:0] used for compare operation*/
#define MSTART0         8 /*This bit field determines the lowest bit number of the
                            64-bit STM that is compared with the content of
                            register CMP0 bit 0. The number of bits to be
                            compared is defined by bit field MSIZE0.
                            00000B STM[0] is the lowest bit number
                            00001B STM[1] is the lowest bit number
                            ...
                            11110B STM[30] is the lowest bit number
                            11111B STM[31] is the lowest bit number*/
#define MSIZE1          16
#define MSTART1         24
/** Interrupt Registers**/
#define STM0_ICR    *(unsigned int*)(0xF0000000 + 0x3C)

#define CMP0EN      0 /* cpm interrupt 0 : disabled, 1 : enabled */
#define CMP0IR      1 /* Compare Register CMP0 Interrupt Request Flag
                        This bit indicates whether or not a compare match
                        interrupt request of compare register CMP0 is pending.
                        CMP0IR must be cleared by software.
                        0B A compare match interrupt has not been detected
                        since the bit has been cleared for the last time.
                        1B A compare match interrupt has been detected.
                        CMPIR0 must be cleared by software and can be set by
                        software, too (see CMPISCR register). After a STM
                        reset operation, CMP0IR is immediately set as a result
                        of a compare match event with the reset values of the
                        STM and the compare registers CMP0.*/

#define CMP0OS      1   /*Compare Register CMP0 Interrupt Output Selection
                        This bit determines the interrupt output that is activated
                        on a compare match event of compare register CMP0.
                        0B Interrupt output STMIR0 selected
                        1B Interrupt output STMIR1 selected*/

#define CMP1EN      4
#define CMP1IR      5
#define CMP1OS      6

#define STM0_ISCR    *(unsigned int*)(0xF0000000 + 0x40)

#define CMP0IRR     0/*Reset Compare Register CMP0 Interrupt Flag
                        0B Bit ICR.CMP0IR is not changed.
                        1B Bit ICR.CMP0IR is cleared.*/
#define CMP0IRS     1/*Set Compare Register CMP0 Interrupt Flag
                        0B Bit ICR.CMP0IR is not changed.
                        1B Bit ICR.CMP0IR is set. The state of bit CMP0IRR
                        is ¡°don¡¯t care¡± in this case.*/

#define SYSTEM_TIMER_31_0   *(unsigned int *)(0xF0000000+0x10)
#define SYSTEM_TIMER_PERIOD 10  // 100Mhz



#endif /* STM_H_ */
