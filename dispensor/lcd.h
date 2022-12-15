#include <avr/io.h>
#include <avr/delay.h>

#define LCD_DATA  PORTA
#define LCD_INST  PORTA
#define LCD_PIN   PINA

#define LCD_CTRL  PORTD

#define LCD_RS    0
#define LCD_RW    1
#define LCD_EN    2

#define LCD_CLR             0      // DB0: clear display
#define LCD_HOME            1      // DB1: return to home position
#define LCD_ENTRY_MODE      2      // DB2: set entry mode
#define LCD_ENTRY_INC       1      // DB1: increment
#define LCD_ENTRY_SHIFT     0      // DB2: shift
#define LCD_ON_CTRL         3      // DB3: turn lcd/cursor on
#define LCD_ON_DISPLAY      2      // DB2: turn display on
#define LCD_ON_CURSOR       1      // DB1: turn cursor on
#define LCD_ON_BLINK        0      // DB0: blinking cursor
#define LCD_MOVE            4      // DB4: move cursor/display
#define LCD_MOVE_DISP       3      // DB3: move display (0-> move cursor)
#define LCD_MOVE_RIGHT      2      // DB2: move right (0-> left)
#define LCD_FUNCTION        5      // DB5: function set
#define LCD_FUNCTION_8BIT   4      // DB4: set 8BIT mode (0->4BIT mode)
#define LCD_FUNCTION_2LINES 3      // DB3: two lines (0->one line)
#define LCD_FUNCTION_10DOTS 2      // DB2: 5x10 font (0->5x7 font)
#define LCD_CGRAM           6      // DB6: set CG RAM address
#define LCD_DDRAM           7      // DB7: set DD RAM address
#define LCD_BUSY            7      // DB7: LCD is busy


void portOut(void)
{
	DDRA = 0xFF;	
	DDRD = 0xFF;	//제어선은 항상 출력용	
}

void portIn(void)
{
	DDRA = 0x00;	
	DDRD = 0xFF;	 //제어선은 항상 출력용 	
}

void writeCTRL(unsigned char ch)
{
	LCD_CTRL = (1<<LCD_EN) | (0<<LCD_RW) | (0<<LCD_RS);
	_delay_us(50); 

	LCD_INST = ch;
	_delay_us(50); 

	LCD_CTRL = (0<<LCD_EN) | (0<<LCD_RW) | (0<<LCD_RS); 
}

void writeChar(unsigned char ch)
{
	LCD_CTRL = (1<<LCD_EN) | (0<<LCD_RW) | (1<<LCD_RS);
	_delay_us(50); 

	LCD_DATA = ch;
	_delay_us(50); 

	LCD_CTRL = (0<<LCD_EN) | (0<<LCD_RW) | (0<<LCD_RS); 
}

void writeSTR(unsigned char *str)
{
	while(*str != 0)
	{
		writeChar(*str);
		str++;
	}
}

unsigned char readChar(void)
{
	unsigned char data;

	LCD_CTRL = (1<<LCD_EN) | (1<<LCD_RW) | (1<<LCD_RS);
	_delay_us(50); 

	data = LCD_PIN;
	_delay_us(50); 

	LCD_CTRL = (0<<LCD_EN) | (0<<LCD_RW) | (0<<LCD_RS); 

	return data;
}

unsigned char readBF_AC(void)
{
	unsigned char data;
	LCD_CTRL = (1<<LCD_EN) | (1<<LCD_RW) | (0<<LCD_RS);
	_delay_us(50); 
	data = LCD_PIN;
	_delay_us(50); 
	LCD_CTRL = (0<<LCD_EN) | (0<<LCD_RW) | (0<<LCD_RS); 
	return data;
}

void waitBusy(void)
{
	portIn();
	while ((readBF_AC() & (1<<LCD_BUSY)) != 0);
	portOut();
}

void setCGRAM_ADDR()
{
	writeCTRL(1<<LCD_CGRAM);
	_delay_ms(2);
}

void setDDRAM_ADDR()
{
	writeCTRL(1<<LCD_DDRAM);
	_delay_ms(2);
}

void setPosition(unsigned char row, unsigned char col) 
{
	unsigned char addr;
	
	switch(row)
	{
		case 0:  addr = 0x00 + col; 
				 break;
		case 1:  addr = 0x40 + col; 
				 break;
		default: addr = 0x00 + col;
	}

	writeCTRL(1<<LCD_DDRAM | addr); 
	_delay_ms(2);
}

void blinkCursor(void)
{
	 writeCTRL((1<<LCD_ON_CTRL)   | (1<<LCD_ON_DISPLAY) |
			   (1<<LCD_ON_CURSOR) | (1<<LCD_ON_BLINK));
	 _delay_ms(2);
}

void displayShiftLeft(void)
{
	 writeCTRL((1<<LCD_MOVE) | (1<<LCD_MOVE_DISP) | (0<<LCD_MOVE_RIGHT));
	 _delay_ms(2);
}

void displayShiftRight(void)
{
	 writeCTRL((1<<LCD_MOVE) | (1<<LCD_MOVE_DISP) | (1<<LCD_MOVE_RIGHT));
	 _delay_ms(2);
}

void cursorShiftLeft(void)
{
	 writeCTRL((1<<LCD_MOVE) | (0<<LCD_MOVE_DISP) | (0<<LCD_MOVE_RIGHT));
	 _delay_ms(2);
}

void cursorShiftRight(void)
{
	 writeCTRL((1<<LCD_MOVE) | (0<<LCD_MOVE_DISP) | (1<<LCD_MOVE_RIGHT));
	 _delay_ms(2);
}

void entryForward(void)
{
	 writeCTRL((1<<LCD_ENTRY_MODE) | (1<<LCD_ENTRY_INC) | (0<<LCD_ENTRY_SHIFT));
	 _delay_ms(2);
}

void entryReward(void)
{
	 writeCTRL((1<<LCD_ENTRY_MODE) | (0<<LCD_ENTRY_INC) | (0<<LCD_ENTRY_SHIFT));
	 _delay_ms(2);
}

void entryForwardShift(void)
{
	 writeCTRL((1<<LCD_ENTRY_MODE) | (1<<LCD_ENTRY_INC) | (1<<LCD_ENTRY_SHIFT));
	 _delay_ms(2);
}

void entryRewardShift(void)
{
	 writeCTRL((1<<LCD_ENTRY_MODE) | (0<<LCD_ENTRY_INC) | (1<<LCD_ENTRY_SHIFT));
	 _delay_ms(2);
}

void clearLCD(void)	
{
       writeCTRL(1<<LCD_CLR);
       _delay_ms(2);
}

void returnHome(void)
{
	   writeCTRL(LCD_HOME);
       _delay_ms(2);
}


void set10Dots(void)
{
	 writeCTRL((1<<LCD_FUNCTION) | (1<<LCD_FUNCTION_8BIT) |
			  (0<<LCD_FUNCTION_2LINES) | (1<<LCD_FUNCTION_10DOTS));
	 _delay_ms(2);
}

void LCDInit()
{
	writeCTRL((1<<LCD_FUNCTION) | (1<<LCD_FUNCTION_8BIT) |
			  (1<<LCD_FUNCTION_2LINES) | (0<<LCD_FUNCTION_10DOTS));
	_delay_ms(2);

	writeCTRL((1<<LCD_ON_CTRL) | (1<<LCD_ON_DISPLAY) |
			  (1<<LCD_ON_CURSOR) | (0<<LCD_ON_BLINK));
	_delay_ms(2);

	writeCTRL((1<<LCD_CLR));
	_delay_ms(2);

	writeCTRL((1<<LCD_ENTRY_MODE) | (1<<LCD_ENTRY_INC) | (0<<LCD_ENTRY_SHIFT));
	_delay_ms(2);
}
