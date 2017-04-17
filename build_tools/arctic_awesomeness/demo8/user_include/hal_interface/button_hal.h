#ifndef BUTTON_HAL_H_
#define BUTTON_HAL_H_	1

#include "hal_common_includes.h"

typedef enum {
	button_user
} button;

void button_init(void);
int button_pressed(button b);

#endif