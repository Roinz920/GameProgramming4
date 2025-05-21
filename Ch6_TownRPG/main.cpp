#include "GameModel.h"
#include "BattleManager.h"

/*
*	GameModel���� ���� ����� �׽�Ʈ�մϴ�.
*	BattleManager - Player, Monster
*/

int main()
{
	Player player(100, 10);
	Monster monster(80, 5);

	// ü���� 0���� ũ�� �ݺ��ض�.
	while (player.getHealth() > 0 && monster.getHealth() > 0)
	{
		player.attack(monster);
		if (monster.getHealth() > 0)
		{
			monster.attack(player);
		}
	}

	std::cout << "������ ����Ǿ����ϴ�." << std::endl;
}