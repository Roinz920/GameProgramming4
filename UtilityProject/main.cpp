

#include "ConsoleUtility.h"

int main()
{
	while (true)
	{
		int random = ConsoleUtil::GetRandomInt(100);
		cout << random << endl;
		Sleep(100);
		break;
	}
	ConsoleUtil::GotoXY(0, 10);
	cout << "숫자" << endl;
	ConsoleUtil::GotoXY(10, 10);
	cout << "숫자" << endl;
}