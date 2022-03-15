#include <stdio.h>
#include "STM.h"

unsigned int systemtick[2];
unsigned int tick_cnt;
unsigned int delay_time_ns;


void tick_check(){
    // Delay Check
    systemtick[0] = STM0_TIM0;
    for( volatile unsigned int i=0; i<100000; i++){
    }
    systemtick[1] = STM0_TIM0;

    // Calculate tick cnt
    tick_cnt =systemtick[1] - systemtick[0];

    // Calculate delay time, cnt * 10ns
    delay_time_ns = tick_cnt * SYSTEM_TIMER_PERIOD;

}
