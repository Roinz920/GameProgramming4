#include "ConsoleUtility.h"
#include "Poketball.h"

void Example1()
{
	// 0.1초마다 1~100 사이의 값을 랜덤으로 한 줄 씩 출력하는 코드
	while (true)
	{
		int random = ConsoleUtil::GetRandomInt(100);
		cout << random << endl;
		Sleep(100);
		break;
	}

	int x = ConsoleUtil::GetRandomInt(10);
	int y = ConsoleUtil::GetRandomInt(10);
	ConsoleUtil::GotoXY(x, y);
	cout << "랜덤 좌표에 출력" << endl;
}

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13

template<int N>
void Display(int index)
{
	for (int i = 0; i < N; i++)
	{
		if (i == index)
		{
			cout << "■ ";
		}
		else
		{
			cout << "□ ";
		}
	}
}

template<int N>
void Display2D(int index)
{
	int height	= index / N;	//세로
	int width	= index % N;	//가로


	for (int y = 0; y < N; y++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == width && y == height)
			{
				cout << "■ ";
			}
			else
			{
				cout << "□ ";
			}
		}
		cout << endl;
	}
}

/*
*	std::array (고정 배열) Fixed size array
*	- 특징 : 크기가 고정되어있기 때문에 규칙을 명확히 표현할 수 있다. 
*/

int main()
{
	system("mode con: cols=64 lines=18");
	ConsoleUtil::SetCursorVisible(false);
	int selectedIndex = 0;
	char input;

	// 포켓몬스터의 데이터를 세팅
	// PokeMon	(값 타임)			: 데이터 복사, 크기가 작은 경우, 값 자체가 상태를 표현할 때에 사용
	// PokeMon*	(참조 타입, 주소값)	: 복사를 안 하고 데이터를 가져온다.

	// 몬스터의 종류가 많고 크기가 크다. PokeMon*
	// 몬스터 볼의 갯수가 적고, 각 볼에 따른 상태가 존재하기 때문에 값으로 표현 
	std::array<PokeMon*, 100> poketballs;
	//std::array<PokeBall, 5> poketball;

	PokeMon defaultMonster(0, "            ");
	poketballs.fill(&defaultMonster);

	poketballs[0] = new PokeMon(1, "이상해씨");
	poketballs[4] = new PokeMon(4, "파이리");
	poketballs[7] = new PokeMon(7, "꼬부기");
	poketballs[12] = new PokeMon(12, "버터플");
	poketballs[16] = new PokeMon(16, "구구");
	poketballs[25] = new PokeMon(25, "피카츄");

	//키보드의 상하좌우 입력을 받아 아이템을 선택하는 그림 출력
	while (true)
	{
		
		const int size = 10;
		int sizePow = size * size;
		ConsoleUtil::GotoXY(0, 0);
		Display2D<size>(selectedIndex);

		
		if (_kbhit)
		{
			input = _getch();

			if (input == LEFT)
			{
				//cout << "왼쪽 화살키 입력";
				selectedIndex = (selectedIndex - 1 + sizePow) % sizePow;	// 0 ~ 5 -4
			}
			else if (input == RIGHT)
			{
				selectedIndex = (selectedIndex + 1) % sizePow;		// 0~5-44
			}
			else if (input == UP)
			{
				selectedIndex = (selectedIndex - size + sizePow) % sizePow;
			}
			else if (input == DOWN)
			{
				selectedIndex = (selectedIndex + size) % sizePow;
			}
			else if (input == ENTER)
			{
				break;
			}
			system("cls"); // 화면 지우기
		}
		
		ConsoleUtil::GotoXY(40, 0);
		cout << "몬스터 UI";
		ConsoleUtil::GotoXY(40, 1);
		cout << "No_ " << poketballs[selectedIndex]->get_number() << " " << poketballs[selectedIndex]->get_name() << endl;
	}
}