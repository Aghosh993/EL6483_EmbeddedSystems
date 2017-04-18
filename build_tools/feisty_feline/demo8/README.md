# Demo 8: EXTI (External Interrupts)

This demo shows how to use the EXTI (External interrupt) module on the STM32 to detect a rising and/or falling edge on a GPIO pin, and trigger an interrupt. In this case, PA0 (which is wired to the blue USER button on the F3 Discovery board) is used to raise an interrupt on EXTI0 whenever either a rising or falling edge occurs. If a rising edge is detected, it can be inferred that the button was pressed, and some action can be taken (in this case, the program begins execution of the main loop where a set of LEDs blink at a constant rate).

(c) Abhimanyu Ghosh, 2017