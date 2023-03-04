# DISPENSOR

## EXPLAIN

시대가 발전함에 따라 사람들도 더 편한 생활을 하고 싶어 합니다.

방에서 공부를 하거나 휴식을 취할 때 시원한 물 혹은 음료가 생각날 때가 있습니다.

그럴 때를 위해 음료 디스펜서를 만든다면 냉장고까지 가지도 않고 원하는 음료를 직접 뽑아서 마실 수 있도록 일상생활에 편리함을 줄 수 있습니다.

더 나아가 원하는 음료를 비율로 추출하기에, 음료수가 아니더라도 술을 좋아하시는 분들에게는 칵테일 등을 만들어서 마실 수도 있는 재미를 줄 수 있습니다.
<br>
<hr></hr>

## PROCESS

C언어를 기반으로 Main 함수와 그에 필요한 Header 함수를 만들었다.

Moter와 KeyPad 를 Header 함수로 구현하고, Main 함수에서 선언하여 함수를 묶어준다.
<br>
<hr></hr>

## components

#### ATmega128

![image01](https://user-images.githubusercontent.com/111284065/222880825-59307385-463e-4028-9b07-bc1ebccc473f.png)

ATmega128은 ATMEL 사가 개발한 8비트 AVR 마이크로 컨트롤러의 megaAVR 패밀리 계열 중 하나의 프로세서입니다.

이 프로세서는 64핀으로 구성되었으며, TQFP형 패키지의 저 전력 8비트 CMOS 마이크로컨트롤러이다. 내부 구조는 RISC 아키텍처(RISC like Architecture) 구조로 이루어져 있으며 대부분 1클록에서 수행되는 어셈블리어 명령어를 가지고 있어서 입력 클록 1MHz에서 1MIPS의 처리능력을 가집니다.

또한, ATmega128은 최적화된 전력 소모 구조를 가지고 있어서 다른 마이크로컨트롤러에 비해 상대적으로 작은 전력을 전력을 소모하며, 처리 능력도 뛰어납니다.

<br>

#### 펌프 모터

![231 3](https://user-images.githubusercontent.com/111284065/222880846-d8125e06-a780-4210-b01c-4725ebfaccc4.jpg)


음료수를 추출하기 위한 펌프 모터입니다.

펌프를 연결하여 속도 및 방향을 제어하여 추출되는 음료의 양을 조절합니다.

<br>

#### 4X4 키 패드

![25180223view](https://user-images.githubusercontent.com/111284065/222880858-01e279eb-1dbd-47f3-9755-46a3cdf536a2.jpg)


음료수를 고르는 키 패드입니다.

첫 번째 줄은 음료의 종류를 입력하고, 두 번째 줄은 음료의 비율을 정하여 음료를 추출한다.

1  2  3  4 <br>
5  6  7  8 <br>
9 10 11 12 <br>

13 14 15 16 

키 패드의 예시를 이렇게 설정하고

1에는 콜라를, 5에는 30ml를 저장한 후에 1,5를 누르면 콜라 30ml가 추출될 수 있도록 키 패드에 값을 저장해 놓습니다.

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
음료의 종류를 선언해주고, 화면에 표시될 수 있도록 입력한 종류의 음료를 보여준다.

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

![img](https://user-images.githubusercontent.com/111284065/221828112-cfe592a6-b96b-4802-a7f5-9b25c8c6cdba.jpg)
![img 1](https://user-images.githubusercontent.com/111284065/221828305-21b18af1-c0e7-4983-ad72-8602b1f1eebb.jpg)

