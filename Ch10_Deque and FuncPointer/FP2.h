#pragma once

#include "ConsoleUtility.h"
#include <iostream>

// 복습. 계산 기능. 함수 포인터로 표현하기

#pragma region 심화(1) 함수 포인터 일번화 프로그래밍 Generic Programming 적용


template <typename T>
void Plus (T a, T b)
{
	std::cout << "더하기 결과 : ";
	std::cout << a + b << std::endl;
}

template <typename T>
void Minus(T a, T b)
{
	std::cout << "빼기 결과 : ";
	std::cout << a - b << std::endl;
}

template <typename T>
void Multiply(T a, T b)
{
	std::cout << "곱하기 결과 : ";
	std::cout << a * b << std::endl;
}
template <typename T>
void Divide(T a, T b)
{
	std::cout << "나누기 결과 : ";
	std::cout << a / b << std::endl;
}
template <typename T>
void Calculate(void (*Func)(T a, T b), T outA, T outB)
{
	Func(outA, outB);
}
#pragma endregion 

#pragma region 심화(2) 열거형과 클래스로 함수포인터 활용


// 열거형의 이름은 항상 대문자로 작성해서, 다른 이름으로 타입으로 알아볼 수 있게 설정하는게 일반적이다
// 함수는 첫글자가 대문자료 표현하게 설정하였다.
enum ActorAction
{
	MOVE, TALK
};

class Actor
{
private:

	static void Move()
	{
		std::cout << "움직입니다." << std::endl;
	}
	static void Talk()
	{
		std::cout << "대화합니다." << std::endl;
	}


public:
	Actor() = default;
	void (*Action)();

	void Think()
	{
		// 랜덤한 숫자를 받아서, 0이 나오면 움직여라.. 1이 나오면 Talk, 2가 나오면 ...
		int select = ConsoleUtil::GetRandomInt(2); // 1 or 2

		ActorAction aAction = static_cast<ActorAction> (select - 1);
		switch (aAction)
		{
		case 0: Action = Move; break;
		case 1: Action = Talk; break;
		default: return;
		}
	}
};
#pragma endregion

#pragma region 가위바위보 예제 만들기

enum RSP_TYPE
{
	SCISSORS, ROCK,  PAPER
};

class RSPGame
{
private:
	
	void (*Action)();

	static void Scissors()
	{
		std::cout << "가위" << std::endl;
	}
	static void Rock()
	{
		std::cout << "바위" << std::endl;
	}
	static void Paper()
	{
		std::cout << "보" << std::endl;
	}
	RSP_TYPE computertype;
	RSP_TYPE playertype;

	int playerScore;
	int computerScore;

	void Result()
	{
		// 유저와 컴퓨터의 승리 판정
		// 유저, 컴퓨터 같음 : 비김
		// 유저> 컴퓨터 : 이김
		// 그 외에 졌다

		if (playertype == computertype)
		{
			std::cout << "비겼어요." << std::endl;
		}
		else if (playertype == SCISSORS && computertype == PAPER
			|| playertype == PAPER && computertype == ROCK
			|| playertype == ROCK && computertype == SCISSORS)
		{
			std::cout << "이겼어요!" << std::endl;
			playerScore++;
		}
		else
		{
			std::cout << "졌어요..." << std::endl;
			computerScore++;
		}
	}

public:
	RSPGame() : playerScore(0), computerScore(0) {}
	void StarGame()
	{
		while (true)
		{
			int input = -1;
			std::cout << "가위바위보를 선택! \n 0 : 가위, 1 : 바위, 2: 보" << std::endl;
			std::cout << "당신의 선택은?" << std::endl;;
			std::cin >> input;
			playertype = static_cast<RSP_TYPE>(input);

			// 컴퓨터가 선택할 번호를 랜덤으로 받음
			int select = ConsoleUtil::GetRandomInt(3); // 1,2,3
			computertype = static_cast<RSP_TYPE>(select - 1);
			//switch문의 사용 -> 함수 포인터 결정
			switch (computertype)
			{
			case SCISSORS: Action = Scissors; break;
			case ROCK: Action = Rock; break;
			case PAPER: Action = Paper; break;
			}
			// 함수 포인터의 함수 실행
			std::cout << "컴퓨터의 선택 : ";
			Action();			
			Result();

			Sleep(1000);
			system("cls");
			if (playerScore >= 3 || computerScore >= 3)
			{
				break;
			}
		}

		if (playerScore >= 3)
		{
			std::cout << "승리!" << std::endl;
		}
		if (computerScore >= 3)
		{
			std::cout << "퍠배..." << std::endl;
		}
	}

	
};

#pragma endregion

void FPTest()
{
	Calculate(Plus, 5, 6);
	//Calculate(Plus<int>, 5.5, 6.5); // template로 적용된 namespace가 double인데 int로 선언하면 에러 발생
	Calculate(Minus, 5, 6);
}
void FPTest2()
{
	Actor actor;
	actor.Think();
	actor.Action();
}

void FPTest3()
{
	RSPGame game;
	game.StarGame();
}