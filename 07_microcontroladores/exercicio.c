//Exercicio 3,
// CONFIG
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config CP = OFF
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 4000000
#define botao1 PORTAbits.RA4 //botao 2 a 5 -> direçao
#define led0 PORTBbits.RB0 // led 0 a 6 -> direçao
#define led1 PORTBbits.RB1
#define led2 PORTBbits.RB2
#define led3 PORTBbits.RB3
#define led4 PORTBbits.RB4
#define led5 PORTBbits.RB5
#define led6 PORTBbits.RB6
#define led7 PORTBbits.RB7

//Dar nomes de cada variavel led e botao!

void main(void) {
    TRISAbits.TRISA3 = 1;
    TRISB = 0;
    PORTB = 0xFF;

    ADCON1bits.PCFG3 = 0; //0 quer dizer ligado, 1 quer dizer desligado.
    ADCON1bits.PCFG2 = 1;
    ADCON1bits.PCFG1 = 1;
    ADCON1bits.PCFG0 = 1;
    ADCON0bits.ADON = 0;

    INTCONbits.GIE = 0;

    int contador = 1;
    while (1) {
        while (1) {
            switch (contador) {
                case 1:
                    led0 = 0;
                    led1 = 1;
                    led2 = 1;
                    led3 = 1;
                    led4 = 1;
                    led5 = 1;
                    led6 = 1;
                    led7 = 1;

                    contador++;
                    break;
                case 2:
                    led0 = 1;
                    led1 = 0;
                    led2 = 1;
                    led3 = 1;
                    led4 = 1;
                    led5 = 1;
                    led6 = 1;
                    led7 = 1;

                    contador++;
                    break;
                case 3:
                    led0 = 1;
                    led1 = 1;
                    led2 = 0;
                    led3 = 1;
                    led4 = 1;
                    led5 = 1;
                    led6 = 1;
                    led7 = 1;

                    contador++;
                    break;
                case 4:
                    led0 = 1;
                    led1 = 1;
                    led2 = 1;
                    led3 = 0;
                    led4 = 1;
                    led5 = 1;
                    led6 = 1;
                    led7 = 1;

                    contador++;
                    break;
                case 5:
                    led0 = 1;
                    led1 = 1;
                    led2 = 1;
                    led3 = 1;
                    led4 = 0;
                    led5 = 1;
                    led6 = 1;
                    led7 = 1;

                    contador++;
                    break;
                case 6:
                    led0 = 1;
                    led1 = 1;
                    led2 = 1;
                    led3 = 1;
                    led4 = 1;
                    led5 = 0;
                    led6 = 1;
                    led7 = 1;

                    contador++;
                    break;
                case 7:
                    led0 = 1;
                    led1 = 1;
                    led2 = 1;
                    led3 = 1;
                    led4 = 1;
                    led5 = 1;
                    led6 = 0;
                    led7 = 1;

                    contador++;
                    break;
                case 8:
                    led0 = 1;
                    led1 = 1;
                    led2 = 1;
                    led3 = 1;
                    led4 = 1;
                    led5 = 1;
                    led6 = 1;
                    led7 = 0;

                    contador++;
                    break;
            }


            __delay_ms(300);
            if (contador >= 9) {
                contador=8;
                break;
            }
        }


    

        while (1) {

            switch (contador) {
                case 1:
                    led0 = 0;
                    led1 = 1;
                    led2 = 1;
                    led3 = 1;
                    led4 = 1;
                    led5 = 1;
                    led6 = 1;
                    led7 = 1;

                    contador--;
                    break;
                case 2:
                    led0 = 1;
                    led1 = 0;
                    led2 = 1;
                    led3 = 1;
                    led4 = 1;
                    led5 = 1;
                    led6 = 1;
                    led7 = 1;

                    contador--;
                    break;
                case 3:
                    led0 = 1;
                    led1 = 1;
                    led2 = 0;
                    led3 = 1;
                    led4 = 1;
                    led5 = 1;
                    led6 = 1;
                    led7 = 1;

                    contador--;
                    break;
                case 4:
                    led0 = 1;
                    led1 = 1;
                    led2 = 1;
                    led3 = 0;
                    led4 = 1;
                    led5 = 1;
                    led6 = 1;
                    led7 = 1;

                    contador--;
                    break;
                case 5:
                    led0 = 1;
                    led1 = 1;
                    led2 = 1;
                    led3 = 1;
                    led4 = 0;
                    led5 = 1;
                    led6 = 1;
                    led7 = 1;

                    contador--;
                    break;
                case 6:
                    led0 = 1;
                    led1 = 1;
                    led2 = 1;
                    led3 = 1;
                    led4 = 1;
                    led5 = 0;
                    led6 = 1;
                    led7 = 1;

                    contador--;
                    break;
                case 7:
                    led0 = 1;
                    led1 = 1;
                    led2 = 1;
                    led3 = 1;
                    led4 = 1;
                    led5 = 1;
                    led6 = 0;
                    led7 = 1;

                    contador--;
                    break;
                case 8:
                    led0 = 1;
                    led1 = 1;
                    led2 = 1;
                    led3 = 1;
                    led4 = 1;
                    led5 = 1;
                    led6 = 1;
                    led7 = 0;

                    contador--;
                    break;
            }


            __delay_ms(300);
            if (contador <= 0) {
                contador=1;
                break;
            }
        }
    }


}