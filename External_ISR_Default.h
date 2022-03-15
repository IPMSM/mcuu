/*
 * ISR_Default.h
 *
 *  Created on: 2022. 3. 11.
 *      Author: user
 */

#ifndef EXTERNAL_ISR_DEFAULT_H_
#define EXTERNAL_ISR_DEFAULT_H_

#endif /* EXTERNAL_ISR_DEFAULT_H_ */

/*===============SCU Kernal Register Groups====================*/
#define SCU           (0xF0036000)
#define SCU_SYSCON    (*(volatile unsigned int*)(  + 0x007C ))           /* Input Output Clear Register */

#define SCU_WDTSCON0  (*(volatile unsigned int*)(SCU + 0x00F0 ))
#define ENDINIT     0 /* End-of-Initialization Control Bit
                        0B Access to Endinit-protected registers is
                        permitted.
                        1B Access to Endinit-protected registers is not
                        permitted. */
#define LCK         1   /*Lock Bit to Control Access to WDTxCON0
                        0B Register WDTxCON0 is unlocked
                        1B Register WDTxCON0 is locked
                        (default after ApplicationReset)*/




#define SCU_WDTSCON1  (*(volatile unsigned int*)(SCU + 0x00F4 ))
#define SCU_EICR0     (*(volatile unsigned int*)(SCU + 0x0210 ))
#define EXIS0       4 /*External Input Selection 0
                        This bit field determines which input line is selected
                        for Input Channel (2i).
                        000B Input (2i) 0 is selected
                        001B Input (2i) 1 is selected
                        010B Input (2i) 2 is selected
                        011B Input (2i) 3 is selected
                        100B Reserved
                        101B Reserved
                        110B Reserved
                        111B Reserved*/


#define FEN0        8   /*Falling Edge Enable 0
                        This bit determines if the falling edge of Input Channel
                        (2i) is used to set bit INTF(2i).
                        0B The falling edge is not used
                        1B The detection of a falling edge of Input Channel
                        0 generates a trigger event. INTF(2i) becomes
                        set.*/
#define REN0        9   /*Rising Edge Enable 0
                        This bit determines if the rising edge of Input Channel
                        (2*i) is used to set bit INTF(2i).
                        0B The rising edge is not used
                        1B The detection of a rising edge of Input Channel
                        (2*i) generates a trigger event. INTF(2*i)
                        becomes set*/
#define LDEN0       10  /*Level Detection Enable 0
                        This bit determines if bit INTF(2i) is cleared
                        automatically if an edge of the input Input Channel (2i)
                        is detected, which has not been selected (rising edge
                        with REN0 = 0 or falling edge with FEN0 = 0).
                        0B Bit INTF(2i) will not be cleared
                        1B Bit INTF(2i) will be cleared*/

#define EIEN0       11  /* External Inteerupt Enable*/
                        // 0 : disalbed
                        // 1 : enabled

#define INP0        12  /*Input Node Pointer
                        This bit field determines the destination (output
                        channel) for trigger event (2i) (if enabled by EIEN(2i)).
                        000B An event from input ETL 2i triggers output
                        OGU0 (signal TR(2i) 0)
                        001B An event from input ETL 2i triggers output
                        OGU1 (signal TR(2i) 1)
                        010B An event from input ETL 2i triggers output
                        OGU2 (signal TR(2i) 2)
                        011B An event from input ETL 2i triggers output
                        OGU3 (signal TR(2i) 3)
                        100B An event from input ETL 2i triggers output
                        OGU4 (signal TR(2i) 0)
                        101B An event from input ETL 2i triggers output
                        OGU5 (signal TR(2i) 0)
                        110B An event from input ETL 2i triggers output
                        OGU6 (signal TR(2i) 0)
                        111B An event from input ETL*/

#define EXIS1       20/*External Input Selection 1

                        This bit field determines which input line is selected
                        for Input Channel (2i).
                        000B Input (2i) 0 is selected
                        001B Input (2i) 1 is selected
                        010B Input (2i) 2 is selected
                        011B Input (2i) 3 is selected
                        100B Reserved
                        101B Reserved
                        110B Reserved
                        111B Reserved*/

#define FEN1        24
#define REN1        25
#define LDEN1       26
#define EIEN1       27
#define INP1        28


#define SCU_EICR1     (*(volatile unsigned int*)(SCU + 0x0214 ))
#define SCU_EICR2     (*(volatile unsigned int*)(SCU + 0x0218 ))
#define SCU_IGCR0     (*(volatile unsigned int*)(SCU + 0x022C ))
#define IGP0        14  /*Interrupt Gating Pattern 0
                        In each register IGCRj, bit field IGP0 determines how
                        the pattern detection influences the output lines
                        GOUT(2j) and IOUT(2j).
                        00B IOUT(2j) is inactive.The pattern is not
                        considered.
                        01B IOUT(2j) is activated in response to a trigger
                        event. The pattern is not considered.
                        10B The detected pattern is considered. IOUT(2j) is
                        activated if a trigger event occurs while the
                        pattern is present.
                        11B The detected pattern is considered. IOUT(2j) is
                        activated if a trigger event
                        */
#define IGP1        30

#define SCU_IGCR1     (*(volatile unsigned int*)(SCU + 0x0230 ))
#define SCU_IGCR2     (*(volatile unsigned int*)(SCU + 0x0234 ))
#define SCU_IGCR3     (*(volatile unsigned int*)(SCU + 0x0238 ))

/* SCU_WDTSCON1 bits*/

#define LCK         1

/*===============SRC Kernal Register Groups====================*/
#define SRC           (0xF0038000)
/*Service Request Control Register*/
#define SRC_SCUERU0     (*(volatile unsigned int*)(SRC + 0x0CD4 ))
#define SRPN    0   /*Service Request Priority Number
                    00H Service request is on lowest priority
                    01H Service request is one before lowest priority
                    ¡¦ ¡¦
                    FFH Service request is on highest priority
                    Note: For a CPU 01H is the lowest priority as 00H is
                    never serviced. For the DMA 00H triggers
                    channel 0
                    Note: For DMA, SRPN must be =< the highest
                    implemented DMA channel number*/
#define SRE     10  /*Service Request Enable
                    0B Service request is disabled
                    1B Service request is enabled*/

#define TOS     11  /*Type of Service Control
                    0H CPU0 service is initiated
                    1H CPU1 service is initiated
                    2H CPU2 service is initiated
                    3H DMA service is initiated
                    Other bit combinations are reserved.
                    */

#define SRC_SCUERU1     (*(volatile unsigned int*)(SRC + 0x0CD8 ))
#define SRC_SCUERU2     (*(volatile unsigned int*)(SRC + 0x0CDC ))
