#include "External_ISR_Default.h"


void init_ERU(void){
    /* Protected register access*/
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) & ~(1<<LCK)) | (1<<ENDINIT);
    while((SCU_WDTSCON0 & (1<<LCK)) != 0);

    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) | (1<<LCK) &~ (1<<ENDINIT));
    while((SCU_WDTSCON0 & (1<<LCK)) == 0);

    /*EICR Register initiazlie */
    SCU_EICR1 &= ~(((0x7) << EXIS0) | ((0x7) << EXIS1)); // Initialize P02.
    SCU_EICR1 &= ~(((0x7) << INP0) | ((0x7) << INP1));      // Input Node Pointer Clear > destination 지정 (OGU)
    SCU_IGCR0 &= ~(((0x3) << IGP0) | ((0x3) << IGP1));      // Interrupt Gating Patten 2, 3 Clear


    /* Switch External Interrupt Setting*/
    SCU_EICR1 |= ((0x01)<<EXIS0);    // SW 1 selected
    SCU_EICR1 |= ((0x02)<<EXIS1);    // SW 2 selected

    SCU_EICR1 |= ((1<<REN0));       // SW1 falling edge interrupt enabled
    SCU_EICR1 |= ((1<<FEN1));       // SW2 rising edge


    SCU_EICR1 |= ((0x01) <<EIEN0);  // INTF cleared
    SCU_EICR1 |= ((0x01) <<EIEN1);  // INTF cleared

    SCU_EICR1 |= (0x0 << INP0)      |                       // Trigger Input Channel 2 -> Output Channel 0
                 (0x1 << INP1)      ;                       // Trigger Input Channel 3 -> Output Channel 1

    SCU_IGCR0 |= ((0x1)<< IGP0);
    SCU_IGCR0 |= ((0x1)<< IGP1);

    /* 잠구는거..*/
    //SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) | (1<<LCK)) | (1<<ENDINIT);
    //while((SCU_WDTSCON0 & (1<<LCK)) ==0);
    /* SRC0 initiazlie*/
    SRC_SCUERU0 &= ~((0xFF)<<SRPN);
    SRC_SCUERU0 |= ((0x0A) <<SRPN);

    /* SRC1 initiazlie*/
    SRC_SCUERU1 &= ~((0xFF) << SRPN);           // Set Priority : 0x0B
    SRC_SCUERU1 |= ((0x0B) << SRPN);

    /* SRC0 Setting*/
    SRC_SCUERU0 &= ~((0x03)<<TOS);
    SRC_SCUERU0 |= (1<<SRE);
    /* SRC1 Setting*/
    SRC_SCUERU1 &= ~((0x3) << TOS);             // CPU0 services
    SRC_SCUERU1 |= (1 << SRE);                  // Service Request is enabled

}
