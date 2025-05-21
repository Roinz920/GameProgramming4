#pragma once
#include "GameModel.h"

class BattleManager
{
private:
	Player& player;
	Monster& monster;

	// ü���� 0���� ũ�� �ݺ��ض�.
public: 
	void Battle()
	{
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
};