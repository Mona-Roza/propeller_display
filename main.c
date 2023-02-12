#include <avr/io.h>
#include <util/delay.h>

#include "alphanumerics.h"

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif

uint8_t leds[] = {PORTD5, PORTD6, PORTD7, PORTB0, PORTB1, PORTB2, PORTB3, PORTB4};
uint8_t hall_effect_sensor = PORTB5;

void print_alphanumeric(uint8_t alphanumeric[5][8])
{
    uint8_t i, j, k, l;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (j < 3)
            {
                if (alphanumeric[i][j] == 1)
                    PORTD |= (1 << leds[j]);
                else
                    PORTD &= ~(1 << leds[j]);
            }
            else
            {
                if (alphanumeric[i][j] == 1)
                    PORTB |= (1 << leds[j]);
                else
                    PORTB &= ~(1 << leds[j]);
            }
        }
        _delay_ms(1);
    }

    for (k = 0; k < 2; k++)
    {
        for (l = 0; l < 8; l++)
        {
            if (l < 3)
            {
                PORTD &= ~(1 << leds[l]);
            }
            else
            {
                PORTB &= ~(1 << leds[l]);
            }
        }
        _delay_ms(1);
    }
}

int main()
{
    DDRD = 0xE0;
    // D portunun 7, 6, 5 numaralı bitleri output olarak işaretlendi.

    DDRB = 0x1F;
    // B portunun 0, 1, 2, 3, 4 numaralı bitleri input 5 numaralı pini
    // output olarak işaretlendi.

    while (1)
    {
        print_alphanumeric(M);
        print_alphanumeric(O);
        print_alphanumeric(N);
        print_alphanumeric(A);
        print_alphanumeric(WORD_SPACE);
        print_alphanumeric(WORD_SPACE);
        print_alphanumeric(R);
        print_alphanumeric(O);
        print_alphanumeric(Z);
        print_alphanumeric(A);
        print_alphanumeric(WORD_SPACE);
        print_alphanumeric(WORD_SPACE);
    }
}
