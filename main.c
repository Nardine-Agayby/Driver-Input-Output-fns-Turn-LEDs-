/*
 * File:   main.c
 * Author: nagay
 *
 * Created on April 10, 2020, 10:57 PM
 */


#include <avr/io.h>

#include "DIO.h"
#define  BUTTON0         0 //port B
#define  BUTTON1         4 //port B
#define  BUTTON2         2 //port D

#define  LED0            2 //port C
#define  LED1            7 //port C
#define  LED2            3 //port D

#define portA           1
#define portB           2
#define portC           3
#define portD           4

int main(void) {
    // Data Direction Register
    DDRC = 0xFF; //PORTC set as O/P
    DDRD |= (1 << LED2); //set as O/P PIN
    DDRB &= ~(1 << BUTTON0); // INPUT PIN.
    DDRB &= ~(1 << BUTTON1); // INPUT PIN.
    DDRD &= ~(1 << BUTTON2); // INPUT PIN.

   // PORTA = 0x00;
    //PORTC = 0x00;

    while (1) {
      //  setPORT(portC);
        // Loop until power OFF
        if (isPressedB(BUTTON0)) { //PINB & (1<<PIN_number)
            //True Condition
            //            PORTA |= (1<<LED); // Turn LED ON
            setPIN(LED0, portC);
        } else {
            // False Condition
            //  9          PORTA &= ~(1<<LED);// Turn LED OFF
            resetPIN(LED0, portC);
        }
        
      
        if (isPressedB(BUTTON1)) { 
            setPIN(LED1, portC);
        } else {
            resetPIN(LED1, portC);
        }
        
        
        if (isPressedD(BUTTON2)) { //PINB & (1<<PIN_number)
            //True Condition
            //            PORTA |= (1<<LED); // Turn LED ON
            setPIN(LED2, portD);
        } else {
            // False Condition
            //  9          PORTA &= ~(1<<LED);// Turn LED OFF
            resetPIN(LED2, portD);
        }
    }
}

