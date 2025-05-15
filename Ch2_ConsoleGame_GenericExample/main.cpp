#include "ConsoleUtility.h"
#include "Poketball.h"

void Example1()
{
	// 0.1�ʸ��� 1~100 ������ ���� �������� �� �� �� ����ϴ� �ڵ�
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
	cout << "���� ��ǥ�� ���" << endl;
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
			cout << "�� ";
		}
		else
		{
			cout << "�� ";
		}
	}
}

template<int N>
void Display2D(int index)
{
	int height	= index / N;	//����
	int width	= index % N;	//����


	for (int y = 0; y < N; y++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == width && y == height)
			{
				cout << "�� ";
			}
			else
			{
				cout << "�� ";
			}
		}
		cout << endl;
	}
}

/*
*	std::array (���� �迭) Fixed size array
*	- Ư¡ : ũ�Ⱑ �����Ǿ��ֱ� ������ ��Ģ�� ��Ȯ�� ǥ���� �� �ִ�. 
*/

int main()
{
	system("mode con: cols=64 lines=18");
	ConsoleUtil::SetCursorVisible(false);
	int selectedIndex = 0;
	char input;

	// ���ϸ����� �����͸� ����
	// PokeMon	(�� Ÿ��)			: ������ ����, ũ�Ⱑ ���� ���, �� ��ü�� ���¸� ǥ���� ���� ���
	// PokeMon*	(���� Ÿ��, �ּҰ�)	: ���縦 �� �ϰ� �����͸� �����´�.

	// ������ ������ ���� ũ�Ⱑ ũ��. PokeMon*
	// ���� ���� ������ ����, �� ���� ���� ���°� �����ϱ� ������ ������ ǥ�� 
	std::array<PokeMon*, 100> poketballs;
	//std::array<PokeBall, 5> poketball;

	PokeMon defaultMonster(0, "            ");
	poketballs.fill(&defaultMonster);

	poketballs[0] = new PokeMon(1, "�̻��ؾ�");
	poketballs[4] = new PokeMon(4, "���̸�");
	poketballs[7] = new PokeMon(7, "���α�");
	poketballs[12] = new PokeMon(12, "������");
	poketballs[16] = new PokeMon(16, "����");
	poketballs[25] = new PokeMon(25, "��ī��");

	//Ű������ �����¿� �Է��� �޾� �������� �����ϴ� �׸� ���
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
				//cout << "���� ȭ��Ű �Է�";
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
			system("cls"); // ȭ�� �����
		}
		
		ConsoleUtil::GotoXY(40, 0);
		cout << "���� UI";
		ConsoleUtil::GotoXY(40, 1);
		cout << "No_ " << poketballs[selectedIndex]->get_number() << " " << poketballs[selectedIndex]->get_name() << endl;
	}
}