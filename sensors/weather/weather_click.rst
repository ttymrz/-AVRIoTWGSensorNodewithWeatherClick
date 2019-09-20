======================
WEATHER Click Board
======================

Weather click carries BME280 integrated environmental unit from Bosch. Its a sensor that detects humidity, pressure, and 
temperature, specifically designed for low current consumption and long-term stability. The click is designed to work on a 
3.3V power supply. It communicates with the target microcontroller over SPI or I2C interface.



=================
Key features
=================
* Bosch BME280 
* Three sensors in one: pressure, humidity, temperature.
* 3.3V power supply only.
* Interfaces:I2C or SPI
* Humidity and pressure sensors can operate independently. Fast response time
* Multiple operating modes: sleep, force, normal.


.. raw:: html
	
	<a href="https://shop.mikroe.com/weather-click" target="_blank">
    <img src="data:image/jpeg;base64,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"/></a>


	
======================
Related Documents
======================


* Weather Click board product page:	`https://shop.mikroe.com/weather-click <https://shop.mikroe.com/weather-click>`_ 


========================
SUPPORTED EVALUATION KIT 
========================

==================  ========================  =====================  =====================
    mikroBUS         Xplained Pro              ATtiny817 Xpro+        ATmega324PB Xpro +  
(Weather Click)                                mikroBUS Xpro (EXT1)   mikroBUS Xpro (EXT1)
==================  ========================  =====================  =====================
ID                      1 ID                                                              
GND                     2 GND                                                             
AN                      3 ADC(+)                                                          
---                     4 ADC(-)                                                          
RST                     5 GPIO1                                                           
---                     6 GPIO2                                                           
PWM                     7 PWM(+)                                                          
---                     8 PWM(-)                                                          
INT                     9 IRQ/GPIO                                                        
---                     10 SPI_SS_B/GPIO                                                  
SDA                     11 I2C_SDA                PA1                     PE5             
SCL                     12 I2C_SCL                PA2                     PE6             
TX                      13 USART_RX*              PB3                     PD2             
RX                      14 USART_TX*              PB2                     PD3             
CS                      15 SPI_SS_A                                                       
MOSI                    16 SPI_MOSI                                                       
MISO                    17 SPI_MISO                                                       
SCK                     18 SPI_SCK                                                        
GND                     19 GND                                                            
VCC                     20 VCC                                                            
==================  ========================  =====================  =====================

[*]Optional Configuration of USART for printf debug support


==================
INTERFACE SETTINGS
==================
The MCU connects to the I2C of the Weather click board.

Interrupts: Only if drivers configured to use IRQs.


==================
Clickboard Example
==================

Example measures the value of temperature(DegC), Humidity(RH), Pressure(kPa) and prints it. 

===================
RUNNING THE EXAMPLE
===================
1. Add Weather click component to application
2. Configure dependencies, check default driver assignment 

   * I2C: Select I2C and ensure that the default state of I2C is in Master mode
   * USART: Add to run example, assign relevant pins. Ensure printf support is selected.
   * NOTE: Incase the Click supports only 5v Supply, make sure that it is provided Externally.
   
3. Configure system drivers: 
   
   * Enable global interrupts if we are using IRQ's. 
   
4. Export Project: Name and download to relevant IDE. 
5. In Atmel Studio 7: File->Import->Atmel Start Project.
6. In main.c: 
   
   * In main, while(1) loop call: Weather_example()(./examples/src/click_example.c)
   * Add related headerfile:#include<click_example.h>(./examples/include/click_example.h)
   
7. Build and flash into supported evaluation board.
8. Responses from the module are transmitted out via UART. Add "-Wl,-u,vfprintf -lprintf_flt" to  miscellaneous linker flags present under toolchain settings to observe the floating point value.
