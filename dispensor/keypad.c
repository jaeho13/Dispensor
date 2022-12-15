#include "keypad.h"

int main()
{
	init_keypad();
	DDRB = 0xFF;
	PORTB = 0x00;

	for(;;)
	{
		get_passwd();
	}

	return 0;
}
