#ifndef PWM_H
#define PWM_H
#include <pic18fregs.h>

#define T2_POST_1_1    0b10000111  //Timer2 Postscaler 1:1
#define T2_POST_1_2    0b10001111  //Timer2 Postscaler 1:2
#define T2_POST_1_3    0b10010111  //Timer2 Postscaler 1:3
#define T2_POST_1_4    0b10011111  //Timer2 Postscaler 1:4
#define T2_POST_1_5    0b10100111  //Timer2 Postscaler 1:5
#define T2_POST_1_6    0b10101111  //Timer2 Postscaler 1:6
#define T2_POST_1_7    0b10110111  //Timer2 Postscaler 1:7
#define T2_POST_1_8    0b10111111  //Timer2 Postscaler 1:8
#define T2_POST_1_9    0b11000111  //Timer2 Postscaler 1:9
#define T2_POST_1_10   0b11001111  //Timer2 Postscaler 1:10
#define T2_POST_1_11   0b11010111  //Timer2 Postscaler 1:11
#define T2_POST_1_12   0b11011111  //Timer2 Postscaler 1:12
#define T2_POST_1_13   0b11100111  //Timer2 Postscaler 1:13
#define T2_POST_1_14   0b11101111  //Timer2 Postscaler 1:14
#define T2_POST_1_15   0b11110111  //Timer2 Postscaler 1:15
#define T2_POST_1_16   0b11111111  //Timer2 Postscaler 1:16
#define T2_PS_1_1      0b11111100  //Timer2 Prescale 1:1
#define T2_PS_1_4      0b11111101  //Timer2 Prescale 1:4
#define T2_PS_1_16     0b11111110  //Timer2 Prescale 1:16

#define TIMER_INT_OFF  0b01111111  //Disable TIMER Interrupt
#define TIMER_INT_ON   0b11111111  //Enable TIMER Interrupt


void setPWMPeriod( char period )
{
	T2CONbits.TMR2ON = 0;  // STOP TIMER2
	PR2 = period;          // Set period
	T2CONbits.TMR2ON = 1;  // Turn on TIMER2
}
void OpenPWM1( char period )
{
	CCP1CON |= 0b00001100;

	TRISCbits.TRISC2 = 0;
	setPWMPeriod(period);
}
void OpenPWM2( char period )
{
	CCP2CON |= 0b00001100;

	TRISCbits.TRISC2 = 0;
	setPWMPeriod(period);
}

void SetDCPWM1(unsigned int dutycycle)
{
	short dutyH, dutyL;
	dutyH = dutycycle>>2;
	dutyL = (dutycycle & 0x03);
	T2CONbits.TMR2ON = 0;  // STOP TIMER2
	CCPR1L = dutyH;
	CCP1CON = CCP1CON | (dutyL << 4);
	T2CONbits.TMR2ON = 1;  // Turn on TIMER2

}
void SetDCPWM2(unsigned int dutycycle)
{
	short dutyH, dutyL;
	dutyH = dutycycle>>2;
	dutyL = (dutycycle & 0x03);
	T2CONbits.TMR2ON = 0;  // STOP TIMER2
	CCPR2L = dutyH;
	CCP2CON = CCP2CON | (dutyL << 4);
	T2CONbits.TMR2ON = 1;  // Turn on TIMER2
}

void OpenTimer2(unsigned char config)
{
	T2CON = (0xfb & config);  // Set all configuration values, but
	                          // don't start timer yet 

	TMR2 = 0;                 // Clear Timer2
	PIR1bits.TMR2IF = 0;

	if(config & 0x80)         // Enable timer interrupts?
		PIE1bits.TMR2IE = 1;
	else
		PIE1bits.TMR2IE = 0;

	T2CON = config; // Turn on Timer2
}
#endif
