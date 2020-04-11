/*
 * File:   DIO.c
 * Author: nagay
 *
 * Created on April 10, 2020, 11:02 PM
 */

/*Driver input output functions*/
#include <xc.h>
#include "DIO.h"

//set specific pin direction as output or input
void PINAas(int pinNum,int dir){ 
    switch(dir){
        case IN: DDRA &= ~(1 << pinNum);break;
        case OUT: DDRA |= (1 << pinNum);break;      
    }
}
void PINBas(int pinNum,int dir){
    switch(dir){
        case IN: DDRB &= ~(1 << pinNum);break;
        case OUT: DDRB |= (1 << pinNum);break;      
    }
}
void PINCas(int pinNum,int dir){
    switch(dir){
        case IN: DDRC &= ~(1 << pinNum);break;
        case OUT: DDRC |= (1 << pinNum);break;      
    }
}
void PINDas(int pinNum,int dir){
    switch(dir){
        case IN: DDRD &= ~(1 << pinNum);break;
        case OUT: DDRD |= (1 << pinNum);break;      
    }
}


//direction OUT ,IN
void PORTAas(int dir){//set Data Direction Register(input or output)
    switch(dir){
        case IN: DDRA=0x00;break;
        case OUT: DDRA=0xFF;break;      
    }
}
void PORTBas(int dir){
    switch(dir){
        case IN: DDRB=0x00;break;
        case OUT: DDRB=0xFF;break;     
    }
    
}
void PORTCas(int dir){
    switch(dir){
        case IN: DDRC=0x00;break;
        case OUT: DDRC=0xFF;break;     
    }
}
void PORTDas(int dir){
    switch(dir){
        case IN: DDRD=0x00;break;
        case OUT: DDRD=0xFF;break;     
    }
}
void setPORT(char port) {//set o/p port pins to HIGH 
    switch (port) {

        case 1:
            PORTA = 0xFF;
            break;
        case 2:
            PORTB = 0xFF;
            break;
        case 3:
            PORTC = 0xFF;
            break;
        case 4:
            PORTD = 0xFF;
            break;
    }
}

void resetPORT(char port) {//reset o/p port pins to LOW 
    switch (port) {

        case 1:
            PORTA = 0x00;
            break;
        case 2:
            PORTB = 0x00;
            break;
        case 3:
            PORTC = 0x00;
            break;
        case 4:
            PORTD = 0x00;
            break;
    }
}

int isPressedA(int pinNum) { //returns status of i/p pin for//Functions are PORT specified
    if (PINA & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}
int isPressedB(int pinNum) {
    if (PINB & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}
int isPressedC(int pinNum) {
    if (PINC & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}
int isPressedD(int pinNum) {
    if (PIND & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}
//setPIN(LED, portA);

void setPIN(int pinNum, char port) {//set o/p pin as HIGH 

    switch (port) {

        case 1:
            PORTA |= (1 << pinNum);
            break;
        case 2:
            PORTB |= (1 << pinNum);
            break;
        case 3:
            PORTC |= (1 << pinNum);
            break;
        case 4:
            PORTD |= (1 << pinNum);
            break;
    }

}

void resetPIN(int pinNum, char port) {//reset o/p pin to LOW

    switch (port) {

        case 1:
            PORTA &= ~(1 << pinNum);
            break;
        case 2:
            PORTB &= ~(1 << pinNum);
            break;
        case 3:
            PORTC &= ~(1 << pinNum);
            break;
        case 4:
            PORTD &= ~(1 << pinNum);
            break;
    }

}


/*
void setPINA(int pinNum) {
    PORTA |= (1 << pinNum);
}

void setPINB(int pinNum) {
    PORTB |= (1 << pinNum);
}

void setPINC(int pinNum) {
    PORTC |= (1 << pinNum);
}

void setPIND(int pinNum) {
    PORTD |= (1 << pinNum);
}

void _setPIN(int pinNum) { //set o/p pin as HIGH in port A
    PORTA |= (1 << pinNum);
}

void _resetPIN(int pinNum) {//reset o/p pin to LOW in port A
    PORTA &= ~(1 << pinNum);
}*/