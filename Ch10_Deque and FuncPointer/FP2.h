#pragma once

#include "ConsoleUtility.h"
#include <iostream>

// ����. ��� ���. �Լ� �����ͷ� ǥ���ϱ�

#pragma region ��ȭ(1) �Լ� ������ �Ϲ�ȭ ���α׷��� Generic Programming ����


template <typename T>
void Plus (T a, T b)
{
	std::cout << "���ϱ� ��� : ";
	std::cout << a + b << std::endl;
}

template <typename T>
void Minus(T a, T b)
{
	std::cout << "���� ��� : ";
	std::cout << a - b << std::endl;
}

template <typename T>
void Multiply(T a, T b)
{
	std::cout << "���ϱ� ��� : ";
	std::cout << a * b << std::endl;
}
template <typename T>
void Divide(T a, T b)
{
	std::cout << "������ ��� : ";
	std::cout << a / b << std::endl;
}
template <typename T>
void Calculate(void (*Func)(T a, T b), T outA, T outB)
{
	Func(outA, outB);
}
#pragma endregion 

#pragma region ��ȭ(2) �������� Ŭ������ �Լ������� Ȱ��


// �������� �̸��� �׻� �빮�ڷ� �ۼ��ؼ�, �ٸ� �̸����� Ÿ������ �˾ƺ� �� �ְ� �����ϴ°� �Ϲ����̴�
// �Լ��� ù���ڰ� �빮�ڷ� ǥ���ϰ� �����Ͽ���.
enum ActorAction
{
	MOVE, TALK
};

class Actor
{
private:

	static void Move()
	{
		std::cout << "�����Դϴ�." << std::endl;
	}
	static void Talk()
	{
		std::cout << "��ȭ�մϴ�." << std::endl;
	}


public:
	Actor() = default;
	void (*Action)();

	void Think()
	{
		// ������ ���ڸ� �޾Ƽ�, 0�� ������ ��������.. 1�� ������ Talk, 2�� ������ ...
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

#pragma region ���������� ���� �����

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
		std::cout << "����" << std::endl;
	}
	static void Rock()
	{
		std::cout << "����" << std::endl;
	}
	static void Paper()
	{
		std::cout << "��" << std::endl;
	}
	RSP_TYPE computertype;
	RSP_TYPE playertype;

	int playerScore;
	int computerScore;

	void Result()
	{
		// ������ ��ǻ���� �¸� ����
		// ����, ��ǻ�� ���� : ���
		// ����> ��ǻ�� : �̱�
		// �� �ܿ� ����

		if (playertype == computertype)
		{
			std::cout << "�����." << std::endl;
		}
		else if (playertype == SCISSORS && computertype == PAPER
			|| playertype == PAPER && computertype == ROCK
			|| playertype == ROCK && computertype == SCISSORS)
		{
			std::cout << "�̰���!" << std::endl;
			playerScore++;
		}
		else
		{
			std::cout << "�����..." << std::endl;
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
			std::cout << "������������ ����! \n 0 : ����, 1 : ����, 2: ��" << std::endl;
			std::cout << "����� ������?" << std::endl;;
			std::cin >> input;
			playertype = static_cast<RSP_TYPE>(input);

			// ��ǻ�Ͱ� ������ ��ȣ�� �������� ����
			int select = ConsoleUtil::GetRandomInt(3); // 1,2,3
			computertype = static_cast<RSP_TYPE>(select - 1);
			//switch���� ��� -> �Լ� ������ ����
			switch (computertype)
			{
			case SCISSORS: Action = Scissors; break;
			case ROCK: Action = Rock; break;
			case PAPER: Action = Paper; break;
			}
			// �Լ� �������� �Լ� ����
			std::cout << "��ǻ���� ���� : ";
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
			std::cout << "�¸�!" << std::endl;
		}
		if (computerScore >= 3)
		{
			std::cout << "����..." << std::endl;
		}
	}

	
};

#pragma endregion

void FPTest()
{
	Calculate(Plus, 5, 6);
	//Calculate(Plus<int>, 5.5, 6.5); // template�� ����� namespace�� double�ε� int�� �����ϸ� ���� �߻�
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