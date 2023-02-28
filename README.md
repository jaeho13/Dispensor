# DISPENSOR

## PROCESS

C언어로 코드를 구현하고 연결하여 동작을 실행한다.

<hr></hr>

## CODE

### 1. 메인 함수를 선언하고 입력을 받으면 실행하는 코드를 작성한다.

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
		
### 2. 키패드 헤더 파일에 4X4 키패드 버튼에 각각 음료의 종류와 음료의 양을 선언해준다.

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
### 3. 모터를 양에 따른 회전수를 정하고 시간을 정한다.
		int i;

		void motor_a()
		{
			for(i=0; i<3; i++)
			{
				PORTB = 0x01;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}


		void motor_b()
		{
			for(i=0; i<6; i++)
			{
				PORTB = 0x01;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}


		void motor_c()
		{
			for(i=0; i<9; i++)
			{
				PORTB = 0x01;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}

		void motor_d()
		{
			for(i=0; i<12; i++)
			{
				PORTB = 0x01;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}


		void motor_a1()
		{
			for(i=0; i<3; i++)
			{
				PORTB = 0x02;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}


		void motor_b1()
		{
			for(i=0; i<6; i++)
			{
				PORTB = 0x02;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}


		void motor_c1()
		{
			for(i=0; i<9; i++)
			{
				PORTB = 0x02;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}


		void motor_d1()
		{
			for(i=0; i<12; i++)
			{
				PORTB = 0x02;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}


		void motor_a2()
		{
			for(i=0; i<3; i++)
			{
				PORTB = 0x04;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}

		void motor_b2()
		{
			for(i=0; i<6; i++)
			{
				PORTB = 0x04;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}

		void motor_c2()
		{
			for(i=0; i<9; i++)
			{
				PORTB = 0x04;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}

		void motor_d2()
		{
			for(i=0; i<12; i++)
			{
				PORTB = 0x04;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}


		void motor_a3()
		{
			for(i=0; i<3; i++)
			{
				PORTB = 0x08;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}

		void motor_b3()
		{
			for(i=0; i<6; i++)
			{
				PORTB = 0x08;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}


		void motor_c3()
		{
			for(i=0; i<9; i++)
			{
				PORTB = 0x08;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}


		void motor_d3()
		{
			for(i=0; i<12; i++)
			{
				PORTB = 0x08;
				_delay_ms(1000);
			}
			PORTB = 0x00;
		}
<hr></hr>

## RESULT
