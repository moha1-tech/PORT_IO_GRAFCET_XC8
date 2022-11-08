#include <stdio.h>
#include <stdlib.h>
#include <config.h>         // Copy config.h to C:\Program Files (x86)\Microchip\xc8\v2.00\pic\include
#include <xc.h>

#define _XTAL_FREQ  8000000

            
// *** SORTIES:
#define 		MG  LATCbits.LATC6
#define 		MD  LATCbits.LATC7
// *** ENTREES:
#define 		t  	PORTCbits.RC0
#define 		k  	PORTCbits.RC1
#define 		m 	PORTCbits.RC2
#define 		p  	PORTCbits.RC3

void Init_Ports() {
     LATC = 0;
     PORTC = 0;
     ANSELC = 0;
     TRISC = 0b00001111;
     
}
void main() {
     Init_Ports();
Etape0:
       MG = 1;    MD = 0;
       if(t) goto Etape4;
       if(p && k && !t) goto Etape1;
       goto Etape0;
Etape1:
       MG = 1;    MD = 1;
       if(m || !p) goto Etape2;
       if (!k) goto Etape3;
       goto Etape1;
Etape2:
      MG = 1;    MD = 0;
      if(t) goto Etape3;
      goto Etape2;
Etape3:
      MG = 0;    MD = 1;
      if(!k && !t) goto Etape0;
      goto Etape3;
Etape4:
      MG = 0;    MD = 1;
      __delay_ms(1000);
      goto Etape0;
}


