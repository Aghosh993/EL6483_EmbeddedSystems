#ifndef PWM_HAL_H_
#define PWM_HAL_H_	1

#include "hal_common_includes.h"

#define TIMER_PERIOD_1KHZ	6545

typedef enum {
	led_pwm1,
	led_pwm2
} pwm_channel;

void init_pwm(void);
void set_pwm(pwm_channel ch, float duty);

#endif