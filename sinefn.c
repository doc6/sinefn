/*
 * sinefn.c
 *
 * A program to generate a sine wave using the DCA module
 *
 */

#include <avr/io.h>

#include <math.h>


/*
 * init_portD()
 *
 * Initialise Port D to be all outputs.  Port D is digital pins
 * 0 to 7 of the Arduino Uno.
 *
 * modified by D O Corlett 2/08/16
 */
void init_ports(void)
{
	/* Make all 8 bits of Port D outputs */
	DDRD = 0xff;
	/* Set outputs to low voltage. */
	PORTD = 0;
}


/*
 * write_dac()
 *
 * Write 8-bit number out to DAC via port D.
 */
void write_dac(unsigned char value)
{
	PORTD = value;
}

/**  Main Function  ********************************************************/

int main(void)
{
	unsigned char value;
	float angle, step;

	init_ports();

	angle = 0.0;
	step = 0.1;
	while (1) {
		value = (unsigned char)((sin(angle) + 1)*127);		// fixed the sine calculation to range from 0 to 254.
		write_dac(value);
		angle += step;
	}

	return 0;
}

