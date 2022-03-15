/*
 * GPIO.c
 *
 *  Created on: 2022. 3. 11.
 *      Author: user
 */


#include "GPIO.h"

void init_LED(void){

    /* P10 Group Reset (BLUE / RED LED*/
    /* Rest PC1 & PC2 in ICR0*/
    P10_IOCR0 &= ~((0x1F) <<PC1); /* 0b0000 reset*/
    P10_IOCR0 &= ~((0x1F) <<PC2);


    /* Set PC1 and PC2 with push pull*/
    P10_IOCR0 |= ((GPIO_OUT_PUSHPULL) <<PC1);
    P10_IOCR0 |= ((GPIO_OUT_PUSHPULL) <<PC2);


}


void init_SW(void){
    /* P02 Group Reset (SW1 / SW2) */
    P02_IOCR0 &= ~((0x1F) << PC1); /* SW1*/
    P02_IOCR0 &= ~((0x1F) << PC0); /* SW2*/

    /* Set SW1 and SW2 with internal pull-up INPUT ports*/
    P02_IOCR0 |= ((GPIO_INPUT_PULLUP) <<PC1); /* SW1*/
    P02_IOCR0 |= ((GPIO_INPUT_PULLUP) <<PC0); /* SW2*/
}

void init_RGBLED(void){
    P02_IOCR4 &= ~((0x1F)<< PC7);
    P10_IOCR4 &= ~((0x1F)<< PC5);
    P10_IOCR0 &= ~((0x1F)<< PC3);

    /* Set PC bits in IOCR0 with push-pull*/

    P02_IOCR4 |= ((GPIO_OUT_PUSHPULL) <<PC7);
    P10_IOCR4 |= ((GPIO_OUT_PUSHPULL) <<PC5);
    P10_IOCR0 |= ((GPIO_OUT_PUSHPULL) <<PC3);

}
