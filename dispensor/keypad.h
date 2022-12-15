#include "LCD.h"
#include "motor.h"

#define IN_0	0x0E	//0b00001110
#define IN_1	0x0D	//0b00001101
#define IN_2	0x0B	//0b00001011
#define IN_3	0x07	//0x00000111

#define LINE_0	0x10	//0b00010000
#define LINE_1	0x20	//0x00100000
#define LINE_2	0x40	//0x01000000
#define LINE_3	0x80	//0x10000000

unsigned char cnt = 0;
unsigned char pass[2] = {0,0};
unsigned char loop = 1;



void init_coke()
{
	portOut();
	LCDInit();

	setPosition(0, 0);
	writeSTR("coke");

	setPosition(1, 0);
	writeChar('>');
}

void init_cider()
{
	portOut();
	LCDInit();

	setPosition(0, 0);
	writeSTR("cider");

	setPosition(1, 0);
	writeChar('>');
}

void init_coffee()
{
	portOut();
	LCDInit();

	setPosition(0, 0);
	writeSTR("coffee");

	setPosition(1, 0);
	writeChar('>');
}

void init_milk()
{
	portOut();
	LCDInit();

	setPosition(0, 0);
	writeSTR("milk");

	setPosition(1, 0);
	writeChar('>');
}

void init_keypad()
{
	DDRC = 0x0F;
	PORTC = 0x00;
	
	portOut();
	LCDInit();

	setPosition(0, 0);
	writeSTR("Choose drink");

	setPosition(1, 0);
	writeChar('>');
}

void back_pass()
{
	if(cnt != 0)
	{			
		setPosition(1, cnt);
		writeChar(' ');

		setPosition(1, cnt);
		cnt--;
	}
	
	while((PINC & 0xF0) != 0xF0);
}

void reset_check()
{
	unsigned char i;
	clearLCD();
	_delay_ms(10);

	setPosition(0,0);
	writeSTR("Reset!!");
	_delay_ms(1000);

	setPosition(0,0);
	writeSTR("Choose drink");

	setPosition(1,0);
	writeChar('>');

	cnt = 0;
	loop = 1;

	while((PINC & 0xF0) != 0xF0);
}

unsigned char data;

void passcheck(unsigned char data)
{
	if(cnt != 1)
	{	
		writeChar(data);
		pass[cnt++] = data;		
	}
	else if(cnt == 1)
	{
		writeChar(data);
		pass[cnt] = data;

	}
}

void get_passwd()
{
	PORTC =	IN_0;
	_delay_ms(1);
		
	if((PINC & LINE_0) == 0)
	{
		motor_a();
	}
	else if((PINC & LINE_1) == 0)
	{
		motor_a1();
	}
	else if((PINC & LINE_2) == 0)
	{
		motor_a2();
	}
	else if((PINC & LINE_3) == 0)
	{
		motor_a3();
	}
	_delay_ms(10);		
	

	PORTC =	IN_1;
	_delay_ms(1);
		
	if((PINC & LINE_0) == 0)
	{
		motor_b();
	}
	else if((PINC & LINE_1) == 0)
	{
		motor_b1();
	}
	else if((PINC & LINE_2) == 0)
	{
		motor_b2();
	}
	else if((PINC & LINE_3) == 0)
	{
		motor_b3();
	}
	_delay_ms(10);		
	

	PORTC =	IN_2;
	_delay_ms(1);
		
	if((PINC & LINE_0) == 0)
	{
		motor_c();
	}
	else if((PINC & LINE_1) == 0)
	{
		motor_c1();
	}
	else if((PINC & LINE_2) == 0)
	{
		motor_c2();
	}
	else if((PINC & LINE_3) == 0)
	{
		motor_c3();
	}
	_delay_ms(10);		
	

	PORTC =	IN_3;
	_delay_ms(1);
		
	if((PINC & LINE_0) == 0)
	{
		motor_d();
	}
	else if((PINC & LINE_1) == 0)
	{
		motor_d1();
	}
	else if((PINC & LINE_2) == 0)
	{
		motor_d2();
	}
	else if((PINC & LINE_3) == 0)
	{
		motor_d3();
	}
	_delay_ms(10);		
}
