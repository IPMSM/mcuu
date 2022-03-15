/*
 * GPIO.h
 *
 *  Created on: 2022. 3. 11.
 *      Author:Hyeonjun lee
 */
#ifndef GPIO_H_
#define GPIO_H_
#endif /* GPIO_H_ */

/*
 * GPIO.h
 *
 *  Created on: 2022. 3. 11.
 *      Author:Hyeonjun lee
 */
#ifndef GPIO_H_
#define GPIO_H_
#endif /* GPIO_H_ */

/***Module***/
/*=================Group Common bits==========*/
/*Pxx_IN bits*/
#define P0          0
#define P1          1
#define P2          2
#define P3          3
#define P4          4
#define P5          5
#define P6          6
#define P7          7
#define P8          8
#define P9          9
#define P10         10
#define P11         11
/*IOCR 0 bits*/
#define PC0         3
#define PC1         11
#define PC2         19
#define PC3         27
#define PC7         27
#define PC5         11
#define PCL7        23

/*Pxx OMR bits*/
#define CLEAR     0
#define SET       1
/*Px Out bits*/
#define PS1         1 /* 0 : No Operation, 1 : Sets */
#define PS2         2 /* 0 : No Operation, 1 : Sets */
#define PS3         3 /* 0 : No Operation, 1 : Sets */
#define PS4         4 /* 0 : No Operation, 1 : Sets */
#define PS5         5 /* 0 : No Operation, 1 : Sets */
#define PS6         6 /* 0 : No Operation, 1 : Sets */
#define PS7         7 /* 0 : No Operation, 1 : Sets */
#define PS8         8 /* 0 : No Operation, 1 : Sets */
#define PS9         9 /* 0 : No Operation, 1 : Sets */
#define PS10        10 /* 0 : No Operation, 1 : Sets */
#define PS11        11 /* 0 : No Operation, 1 : Sets */
#define PS12        12 /* 0 : No Operation, 1 : Sets */
#define PS13        13 /* 0 : No Operation, 1 : Sets */
#define PS14        14 /* 0 : No Operation, 1 : Sets */
#define PS15        15 /* 0 : No Operation, 1 : Sets */
/*Port Clear Bits*/
#define PCL0        16  /* 0 : No operation , 1: Clears*/
#define PCL1        17  /* 0 : No operation , 1: Clears*/
#define PCL2        18  /* 0 : No operation , 1: Clears*/
#define PCL3        19  /* 0 : No operation , 1: Clears*/
#define PCL4        20  /* 0 : No operation , 1: Clears*/
#define PCL5        21  /* 0 : No operation , 1: Clears*/
#define PCL6        22  /* 0 : No operation , 1: Clears*/
#define PCL7        23  /* 0 : No operation , 1: Clears*/
#define PCL8        24  /* 0 : No operation , 1: Clears*/
#define PCL9        25  /* 0 : No operation , 1: Clears*/
#define PCL10       26  /* 0 : No operation , 1: Clears*/
#define PCL11       27  /* 0 : No operation , 1: Clears*/
#define PCL12       28  /* 0 : No operation , 1: Clears*/
#define PCL13       29  /* 0 : No operation , 1: Clears*/
#define PCL14       30  /* 0 : No operation , 1: Clears*/
#define PCL15       31  /* 0 : No operation , 1: Clears*/
/* PCx coding*/
#define GPIO_OUT_PUSHPULL 0x10
#define GPIO_INPUT_PULLUP 0x02
#define AT1_PUSHPULL 0x11
#define AT2_PUSHPULL 0x12

/*===============P00 Group====================*/
#define P00         (0xF003A000)

/*===============P01 Group====================*/
#define P01         (0xF003A100)

/*===============P02 Group====================*/
#define P02         (0xF003A200)
#define P02_IOCR0   (*(volatile unsigned int*)(P02 + 0x0010))
#define P02_IOCR4   (*(volatile unsigned int*)(P02 + 0x0014))            /* Input Output Clear Register */
#define P02_IN      (*(volatile unsigned int*)(P02 + 0x00024))
#define P02_OMR     (*(volatile unsigned int*)(P02 + 0x00004))
/*===============P10 Group====================*/
#define P10         (0xF003B000)
#define P10_IOCR0   (*(volatile unsigned int*)(P10 + 0x0010))
#define P10_IOCR4   (*(volatile unsigned int*)(P10 + 0x0014))
#define P10_OMR     (*(volatile unsigned int*)(P10 + 0x0004))/**Output Modification Register **/



/* P10_OMR bits*/
/* Port Selection bits*/
/*
0 0 Bit Pn_OUT.Px is not changed.
0 1 Bit Pn_OUT.Px is set.
1 0 Bit Pn_OUT.Px is reset.
1 1 Bit Pn_OUT.Px is toggled.
*/
