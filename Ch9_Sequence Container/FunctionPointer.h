#pragma once

#include <iostream>
#include <chrono>

/*
*	1�ܰ�. �Լ����� ( (��ȯ��)(*ȣ���� �Լ� �̸�)()		)
*	2�ܰ�. ȣ���� �Լ��� ���ڰ� �ִ� ���
*		�Լ����� ( (��ȯ��)(*ȣ���� �Լ� �̸�)(Ÿ�� �̸�, Ÿ�� �̸�), Ÿ�� �̸�, Ÿ�� �̸�	)
*/

void Add(int a, int b)
{
	std::cout << "���ϱ� ����" << std::endl;
	std::cout << a + b << std::endl;
}
void Minus(int a, int b)
{
	std::cout << "���� ����" << std::endl;
	std::cout << a - b << std::endl;
}
void Multiply(int a, int b)
{
	std::cout << "���ϱ� ����" << std::endl;
	std::cout << a * b << std::endl;
}
void Divide(int a, int b)
{
	if (b == 0)
	{
		return;
	}
	std::cout << "������ ����" << std::endl;
	std::cout << a / b << std::endl;
}

void Calculate(void (*Func)(int a, int b), int a, int b)
{
	Func(a, b);
}

void Test_FP()
{
	Calculate(Add, 50, 550);
	
	Calculate(Minus, 100,5);

	Calculate(Multiply, 4, 600);

	Calculate(Divide, 100, 4);
}