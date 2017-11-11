# Atmel 8bit MCUs (__AVR__) Libraries
Based on __ATmega48/88/168/328(P)__, may not perform properly on other chips.  

Each folder contains a entire project.  
Those library files you need are named like: `HAL_ADC.c` `DEV_ADXL345.c` `APP_Clock.h`, copy those .h & .c files to your projects.

### USART
The USART serial _hardware abstract_ library, normally used to transfer data with Computers.  
You should define the __frequency of crystal__ `F_CPU` and `baud` in a file called `F_CPU.h`.

### ADC
The Analog-Digital-Converter _hardware abstract_ library.

### Clock
The Clock _application_ library, employs __TIMER1__ to count time 1 second per tick.  
You should define the __frequency of crystal__ `F_CPU` in a file called `F_CPU.h`.

### TIMER
The TIMER0&2 _hardware abstract_ library, uses macro to calculate `TCCRxB` and `TCNTx` for __TIMER0__ and __TIMER2__ with the period you set.  
This library contains only a .h file.  
You should define the __frequency of crystal__ `F_CPU`, `TIMER0_Period` and `TIMER2_Period` (unit: microsecond __¦Ìs__) in a file called `F_CPU.h`.

### TWI
The TWI (IIC, __I<sup>2</sup>C__) _hardware abstract_ library.

### ADXL345
The ADXL345 __acceleration__ sensor _device_ library. Based on __TWI__ library.

These libraries are wrote on __Atmel Studio__ 7.0.