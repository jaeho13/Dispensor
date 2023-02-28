DISPENSOR

PROCESS

C언어로 코드를 구현하고 연결하여 동작을 실행한다.

코드

첫 번째로 메인 함수를 선언하고 입력을 받으면 실행한다.

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
