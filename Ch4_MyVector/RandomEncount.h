#pragma once
#include "ConsoleUtility.h"

class Monster
{
public:
	string name;
	int hp;
	int atk;
public:
	Monster() = default;
	~Monster() = default;
	Monster(string name, int hp, int atk)
		: name(name), hp(hp), atk(atk) {
	}

	void ShowInfo() const
	{
		cout << "몬스터 이름 : " << name << endl;
	}

	void takeDamage(int dmg)
	{
		hp -= dmg;
		if (hp <= 0)
		{
			cout << name << "이 패배했습니다." << endl;
		}
		else
		{
			cout << name << "의 남의 체력 : " << hp << endl;
		}
	}
};

class Player 
{
private:
	std::vector<Monster> huntedMonster;

public:

	// huntedMonster.push_back();
	void huntMonster(const Monster& monster)
	{
		huntedMonster.push_back(monster); // 사냥한 몬스터를 저장하는 코드
	}

	void display()
	{
		cout << "사냥한 몬스터 목록" << endl;
		int i = 0;
		for (const auto& monster : huntedMonster)
		{
			cout << i << "번째 사냥한 몬스터 : " << monster.name << endl;
		}
	}
};

void Battle(Player& player)
{
	std::vector<Monster> monsters =
	{
		Monster("Goblin", 30, 5),
		Monster("Orc", 50, 10),
		Monster("Dragon", 600, 50),
		Monster("Goblin", 30, 5),
		Monster("Zomebie", 20, 3)
	};

	int randIndex = ConsoleUtil::GetRandomInt(monsters.size() - 1);

	int playerAttackDMG = 10;

	Monster& selectedMonster = monsters[randIndex];
	while (selectedMonster.hp > 0)
	{
		//cout << "몬스터에게" << playerAttackDMG << "만큼 공격을 했습니다.";
		selectedMonster.takeDamage(playerAttackDMG);
	}
	player.huntMonster(selectedMonster);
}