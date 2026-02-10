//ex4
#include <stdio.h> // inclui as configurações para entradas e saídas (I/O) padrões
#include <stdlib.h> // inclui as bibliotecas padrões
#include <xc.h> // inclui a biblioteca principal

#define _XTAL_FREQ 4000000 // ajuste da freq. de Clock (conforme o hardware/placa)
#define botao1 PORTAbits.RA2 // define botão como o terminal PORTA2
#define botao2 PORTAbits.RA3
#define led PORTBbits.RB3 // led como o terminal PORTB0

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF        // FLASH Program Memory Write Enable (Unprotected program memory may not be written to by EECON control)

void main(void) //função principal
{
    TRISAbits.TRISA2=1; //portA2 como entrada
    TRISB=0; //todo o portB como saída
    PORTB=0xFF; //desliga todos os leds

    ADCON1bits.PCFG3=0; //configura todo o portA como digital
    ADCON1bits.PCFG2=1;
    ADCON1bits.PCFG1=1;
    ADCON1bits.PCFG0=1;
    ADCON0bits.ADON=0; //desliga conversores A/D

    INTCONbits.GIE=0; //desliga interrupções

    while(1) //loop infinito{
    {
        if(botao2==0)
        {
            led=1;//apaga led
            __delay_ms(300);// aguarde 300 ms
        }

        if(botao1==0)
        {
            led=0;//acende led
            __delay_ms(300);//aguarda 300 ms
        }


    }
    return; //retorna da função principal, não obrigatório para funções void

} 

/* Exemplo
 #include <stdio.h> // inclui as configurações para entradas e saídas (I/O) padrões
#include <stdlib.h> // inclui as bibliotecas padrões
#include <xc.h> // inclui a biblioteca principal

#define _XTAL_FREQ 4000000 // ajuste da freq. de Clock (conforme o hardware/placa)
#define botao PORTAbits.RA2 // define botão como o terminal PORTA2
#define led PORTBbits.RB0 // led como o terminal PORTB0

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF        // FLASH Program Memory Write Enable (Unprotected program memory may not be written to by EECON control)

void main(void) //função principal
{
    TRISAbits.TRISA2=1; //portA2 como entrada
    TRISB=0; //todo o portB como saída
    PORTB=0xFF; //desliga todos os leds

    ADCON1bits.PCFG3=0; //configura todo o portA como digital
    ADCON1bits.PCFG2=1;
    ADCON1bits.PCFG1=1;
    ADCON1bits.PCFG0=1;
    ADCON0bits.ADON=0; //desliga conversores A/D

    INTCONbits.GIE=0; //desliga interrupções

    while(1) //loop infinito{
    {
        if(botao==1)
            //se botão liberado
        {
            led=1;//apaga led
            __delay_ms(300);// aguarde 300 ms
        }else//senão
        {
            led=0;//acende led
            __delay_ms(300);//aguarda 300 ms
        }


    }
    return; //retorna da função principal, não obrigatório para funções void

}
 */

/* //Exercício 1

#include <stdio.h> // inclui as configurações para entradas e saídas (I/O) padrões
#include <stdlib.h> // inclui as bibliotecas padrões
#include <xc.h> // inclui a biblioteca principal

#define _XTAL_FREQ 4000000 // ajuste da freq. de Clock (conforme o hardware/placa)
#define botao PORTAbits.RA4 // define botão como o terminal PORTA2
#define led PORTBbits.RB3 // led como o terminal PORTB0

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF        // FLASH Program Memory Write Enable (Unprotected program memory may not be written to by EECON control)

void main(void) //função principal
{
    TRISAbits.TRISA2=1; //portA2 como entrada
    TRISB=0; //todo o portB como saída
    PORTB=0xFF; //desliga todos os leds

    ADCON1bits.PCFG3=0; //configura todo o portA como digital
    ADCON1bits.PCFG2=1;
    ADCON1bits.PCFG1=1;
    ADCON1bits.PCFG0=1;
    ADCON0bits.ADON=0; //desliga conversores A/D

    INTCONbits.GIE=0; //desliga interrupções

    while(1) //loop infinito{
    {
        if(botao==1)
            //se botão liberado
        {
            led=1;//apaga led
            __delay_ms(300);// aguarde 300 ms
        }else//senão
        {
            led=0;//acende led
            __delay_ms(300);//aguarda 300 ms
        }


    }
    return; //retorna da função principal, não obrigatório para funções void

}
 */

/* //Exercício 2
  #include <stdio.h> // inclui as configurações para entradas e saídas (I/O) padrões
#include <stdlib.h> // inclui as bibliotecas padrões
#include <xc.h> // inclui a biblioteca principal

#define _XTAL_FREQ 4000000 // ajuste da freq. de Clock (conforme o hardware/placa)
#define botao4 PORTAbits.RA4
#define botao5 PORTAbits.RA5
#define led3 PORTBbits.RB0
#define led4 PORTBbits.RB1
#define led5 PORTBbits.RB2
#define led6 PORTBbits.RB3
#define led7 PORTBbits.RB4
#define led8 PORTBbits.RB5
#define led9 PORTBbits.RB6
#define led10 PORTBbits.RB7

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF        // FLASH Program Memory Write Enable (Unprotected program memory may not be written to by EECON control)

void main(void) //função principal
{
    TRISAbits.TRISA2=1; //portA2 como entrada
    TRISB=0; //todo o portB como saída
    PORTB=0xFF; //desliga todos os leds

    ADCON1bits.PCFG3=0; //configura todo o portA como digital
    ADCON1bits.PCFG2=1;
    ADCON1bits.PCFG1=1;
    ADCON1bits.PCFG0=1;
    ADCON0bits.ADON=0; //desliga conversores A/D

    INTCONbits.GIE=0; //desliga interrupções

    while(1) //loop infinito{
    {
        if(botao4==1)
            //se botão liberado
        {
            led3=1;//apaga led
            led4=1;
            led5=1;
            led6=1;
            __delay_ms(300);// aguarde 300 ms
        } else//senão
        {
            led3=0;//acende led
            led4=0;
            led5=0;
            led6=0;

            __delay_ms(300);//aguarda 300 ms
        }

        if(botao5==1)
            //se botão liberado
        {
            led7=1;//apaga led
            led8=1;
            led9=1;
            led10=1;

            __delay_ms(300);// aguarde 300 ms
        } else//senão
        {
            led7=0;//apaga led
            led8=0;
            led9=0;
            led10=0;

            __delay_ms(300);//aguarda 300 ms
        }


    }
    return; //retorna da função principal, não obrigatório para funções void

}
 */

/* ex 3
 #include <stdio.h> // inclui as configurações para entradas e saídas (I/O) padrões
#include <stdlib.h> // inclui as bibliotecas padrões
#include <xc.h> // inclui a biblioteca principal

#define _XTAL_FREQ 4000000 // ajuste da freq. de Clock (conforme o hardware/placa)
#define botao PORTAbits.RA2
#define led3 PORTBbits.RB0
#define led4 PORTBbits.RB1
#define led5 PORTBbits.RB2
#define led6 PORTBbits.RB3
#define led7 PORTBbits.RB4
#define led8 PORTBbits.RB5
#define led9 PORTBbits.RB6
#define led10 PORTBbits.RB7

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF        // FLASH Program Memory Write Enable (Unprotected program memory may not be written to by EECON control)

void main(void) //função principal
{
    int contador = 1;
    TRISAbits.TRISA2 = 1; //portA2 como entrada
    TRISB = 0; //todo o portB como saída
    PORTB = 0xFF; //desliga todos os leds

    ADCON1bits.PCFG3 = 0; //configura todo o portA como digital
    ADCON1bits.PCFG2 = 1;
    ADCON1bits.PCFG1 = 1;
    ADCON1bits.PCFG0 = 1;
    ADCON0bits.ADON = 0; //desliga conversores A/D

    INTCONbits.GIE = 0; //desliga interrupções

    while (1) //loop infinito
    {
        if (botao == 0) {
            switch (contador) {
                case 1:
                    led3 = 0; //acende
                    led4 = 1; //apaga
                    led5 = 1; //apaga
                    led6 = 1; //apaga
                    led7 = 1; //apaga
                    led8 = 1; //apaga
                    led9 = 1; //apaga
                    led10 = 1; //apaga
                    contador++;
                    __delay_ms(300);
                    break;
                case 2:
                    led3 = 1; //acende
                    led4 = 0; //apaga
                    led5 = 1; //apaga
                    led6 = 1; //apaga
                    led7 = 1; //apaga
                    led8 = 1; //apaga
                    led9 = 1; //apaga
                    led10 = 1; //apaga
                    contador++;
                    __delay_ms(300);
                    break;
                case 3:
                    led3 = 1; //acende
                    led4 = 1; //apaga
                    led5 = 0; //apaga
                    led6 = 1; //apaga
                    led7 = 1; //apaga
                    led8 = 1; //apaga
                    led9 = 1; //apaga
                    led10 = 1; //apaga
                    contador++;
                    __delay_ms(300);
                    break;
                case 4:
                    led3 = 1; //acende
                    led4 = 1; //apaga
                    led5 = 1; //apaga
                    led6 = 0; //apaga
                    led7 = 1; //apaga
                    led8 = 1; //apaga
                    led9 = 1; //apaga
                    led10 = 1; //apaga
                    contador++;
                    __delay_ms(300);
                    break;
                case 5:
                    led3 = 1; //acende
                    led4 = 1; //apaga
                    led5 = 1; //apaga
                    led6 = 1; //apaga
                    led7 = 0; //apaga
                    led8 = 1; //apaga
                    led9 = 1; //apaga
                    led10 = 1; //apaga
                    contador++;
                    __delay_ms(300);
                    break;
                case 6:
                    led3 = 1; //acende
                    led4 = 1; //apaga
                    led5 = 1; //apaga
                    led6 = 1; //apaga
                    led7 = 1; //apaga
                    led8 = 0; //apaga
                    led9 = 1; //apaga
                    led10 = 1; //apaga
                    contador++;
                    __delay_ms(300);
                    break;
                case 7:
                    led3 = 1; //acende
                    led4 = 1; //apaga
                    led5 = 1; //apaga
                    led6 = 1; //apaga
                    led7 = 1; //apaga
                    led8 = 1; //apaga
                    led9 = 0; //apaga
                    led10 = 1; //apaga
                    contador++;
                    __delay_ms(300);
                    break;
                case 8:
                    led3 = 1; //acende
                    led4 = 1; //apaga
                    led5 = 1; //apaga
                    led6 = 1; //apaga
                    led7 = 1; //apaga
                    led8 = 1; //apaga
                    led9 = 1; //apaga
                    led10 = 0; //apaga
                    contador++;
                    __delay_ms(300);
                    break;
            }

            if (contador >= 9) {
                contador = 1;
            }
        }
    }
    return; //retorna da função principal, não obrigatório para funções void

}
 */





