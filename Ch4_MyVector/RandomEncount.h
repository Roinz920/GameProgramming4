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
		cout << "���� �̸� : " << name << endl;
	}

	void takeDamage(int dmg)
	{
		hp -= dmg;
		if (hp <= 0)
		{
			cout << name << "�� �й��߽��ϴ�." << endl;
		}
		else
		{
			cout << name << "�� ���� ü�� : " << hp << endl;
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
		huntedMonster.push_back(monster); // ����� ���͸� �����ϴ� �ڵ�
	}

	void display()
	{
		cout << "����� ���� ���" << endl;
		int i = 0;
		for (const auto& monster : huntedMonster)
		{
			cout << i << "��° ����� ���� : " << monster.name << endl;
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
		//cout << "���Ϳ���" << playerAttackDMG << "��ŭ ������ �߽��ϴ�.";
		selectedMonster.takeDamage(playerAttackDMG);
	}
	player.huntMonster(selectedMonster);
}