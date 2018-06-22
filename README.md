
# Atmel 8bit MCUs (__AVR__) Libraries
Based on __ATmega48/88/168/328(P)__, may not perform properly on other chips.

## Usage
Every folder contains files named like: `main.c` `HAL_ADC.c` `DEV_ADXL345.c` `APP_Clock.h`, copy these .h & .c files except `main.c` to your project.

### USART
The USART serial _hardware abstract_ library, normally used to transfer data with Computers.  
You should define the __frequency of crystal__ `F_CPU` and `BAUD` at `Project> Properties> Toolchain> AVR/GNU C Complier> Symbols` (*Don't include whitespaces*) like this:
```Makefile
F_CPU=8000000
```

### ADC
The Analog-Digital-Converter _hardware abstract_ library.

### Clock
The Clock _application_ library, employs __TIMER1__ to count time 1 second per tick.  
You should define the __frequency of crystal__ at `Project> Properties> Toolchain> AVR/GNU C Complier> Symbols`.

### TIMER
The TIMER0&2 _hardware abstract_ library, uses macro to calculate `TCCRxB` and `TCNTx` for __TIMER0__ and __TIMER2__ with the period you set.  
This library contains only a .h file.  
You should define the __frequency of crystal__ `F_CPU`, `TIMER0_Period` and `TIMER2_Period` (unit: microsecond __μs__) at `Project> Properties> Toolchain> AVR/GNU C Complier> Symbols`.

### TWI
The TWI (IIC, __I<sup>2</sup>C__) _hardware abstract_ library.

### ADXL345
The ADXL345 __acceleration__ sensor _device_ library. Based on __TWI__ library.

# License
This library is licensed under MIT, a really permissive license. Feel free to clone, contribute, or use it to your project for either non-commercial or commercial purpose. 
