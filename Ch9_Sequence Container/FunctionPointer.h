#pragma once

#include <iostream>
#include <chrono>

/*
*	1단계. 함수선언 ( (반환값)(*호출할 함수 이름)()		)
*	2단계. 호출한 함수의 인자가 있는 경우
*		함수선언 ( (반환값)(*호출할 함수 이름)(타입 이름, 타입 이름), 타입 이름, 타입 이름	)
*/

void Add(int a, int b)
{
	std::cout << "더하기 실행" << std::endl;
	std::cout << a + b << std::endl;
}
void Minus(int a, int b)
{
	std::cout << "빼기 실행" << std::endl;
	std::cout << a - b << std::endl;
}
void Multiply(int a, int b)
{
	std::cout << "곱하기 실행" << std::endl;
	std::cout << a * b << std::endl;
}
void Divide(int a, int b)
{
	if (b == 0)
	{
		return;
	}
	std::cout << "나누기 실행" << std::endl;
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