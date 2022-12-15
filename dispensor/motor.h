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
