#include "GameModel.h"
#include "DropTable.h"
#include <conio.h>
#include "DataHandler.h"

int main()
{
	Player player(0,100);	// exp 0, maxExp 100, level 0
	Monster monster(0,0);

	
	Data data;
	//data.SaveData("data.txt");
	data.LoadData("data.txt");
	
	std::cout << "플레이어 레벨 : " << data.GetLevel() << std::endl << "플레이어 경험치 : " << data.GetExp() << std::endl;
	_getch();

	int count = 0;

	while (true)
	{
		system("cls");
		player.GetExp(50);
		player.Show();
		count++;
		_getch();
		
		if (count >= 4)
		{
			break;
		}
	}
	player.SaveData("player.txt");


}