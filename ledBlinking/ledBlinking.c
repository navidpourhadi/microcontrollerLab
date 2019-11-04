#include <mega16.h>
#include <delay.h>
void main(void)
{
int delay = 500;
DDRA = 0x04;
PORTA = 0xff;
while (1)
      {
        if(PINA.0 == 0 ) {
            if(delay > 150)
                delay -= 100 ; 
            else{
                delay = 150 ;
            }
        }
        if(PINA.1 == 0 ) {
            if(delay < 900)
                delay += 100 ;
            else{
                delay = 900;
            }     
            
        }          
        PORTA.2 = !PORTA.2;
        delay_ms(delay);
      }
}
