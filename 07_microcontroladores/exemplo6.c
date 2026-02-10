//config
#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF
#pragma config BOREN = OFF
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 4000000

#define botao PORTAbits.RA2

//Variáveis

char const display[] = {
    0b11000000, //0
    0b11111001, //1
    0b10100100, //2
    0b10110000, //3
    0b10011001, //4
    0b10010010, //5
    0b10000010, //6
    0b11111000, //7
    0b10000000, //8
    0b10010000, //9
    0b11111111, //10 - DESLIGA TUDO
};

bit sentido;

void main()
{
    TRISAbits.TRISA2 = 1;//PortA2 como entrada
    TRISB=0x00;//ajustando as saidas da porta b
    TRISC=0x00;//ajustando as saidas da porta c
    PORTB=0xFF;//Desliga todos os leds
    PORTC=0xFF;//desligar todos displays
    ADCON1bits.PCFG3=0;//Configura portA digital
    ADCON1bits.PCFG2=1;
    ADCON1bits.PCFG1=1;
    ADCON1bits.PCFG0=1; // OS ADCON SÃO OS BOTAOZINHOS PRETOS EMBAIXO DOS LEDS(4UN)
    ADCON0bits.ADON=0;//Desliga Conversores Analogico e Digital
    INTCONbits.GIE=0;//Desliga interrupções

    int cont=0;
    sentido=1;

    while(1)
    {
        if(botao==0)//testa botao pressionado
        {
            if(sentido==1)//teste de sentido
            {
                if(cont>=9)//se maior ou igual a 9
                {
                    cont--;//decrementa
                    sentido=0; //inverte o sentido
                }
                else
                {
                    cont++;//incrementa
                }
            }
            else // se o sentido for inverso (igual a 0)
            {
                if(cont<=0) //verifica se a contagem esta menor/igual 0
                {
                    cont++;//incrementa
                    sentido=1;// inverte sentido
                }
                else
                {
                    cont--;//decrementa
                }
            }
        }
        PORTB=display[cont]; //atualiza PORTB com o valor
        PORTCbits.RC4=0;//habilita display1
        PORTCbits.RC3=1;//desabilita as demais
        PORTCbits.RC2=1;
        __delay_ms(300);
    }
}