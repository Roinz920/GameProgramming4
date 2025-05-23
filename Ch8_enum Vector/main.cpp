/*
*	class �ȿ� enum�� Ȱ���غ���
*/

/*
*	enum : ������.
*	enum���� ����� ������ �� �ִ�.
*/

#include <vector>
#include <iostream>

enum Trait
{
	Strength,
	Dexterity,
	Intelligence,
	None
};

enum Stat
{
	Damage,
	Health,
	Mana,
	Speed
};

/*
*	Trait�� Stat ������ ���踦 �����ؾ��Ѵ�.
*	����)
*	STR 1 ��� :  Dagame (���� ��ġ) + ( ); // �տ���
*/
/*
*	Vector Ÿ���� �Ѱ���
*	
*	Dex�� �ø��� Speed�� �����ϴ� �ý����� ������� ���� ��
*	-> 
*	
*	�� �迭 ���·� ����Ǿ� �ִ� �ڷᱸ���̱� ������, �ڷ��� ���� �� �߰��� �� ���� ������ �߻��� �� �ִ�.
*	(Ư���� ������� �����Ǿ����� ���� �������� ������ �߻����� ���� ������ �����)
*/

class TraitBonus
{
private:
	void IncreaseStat(Stat stat, int amount)
	{
		Stats[static_cast<int>(stat)] += amount;
	}
public: 
	Trait trait;
	Stat stat;
	int additiveBonusPoint;
	std::vector<int> Stats;

	TraitBonus() : Stats(4, 0) {}
	TraitBonus(Trait trait, Stat stat, int additiveBonusPoint)
		: trait(trait), stat(stat), additiveBonusPoint(additiveBonusPoint), Stats(4,0) {}

	void GetTrait(Trait trait)
	{
		switch (trait)
		{
		case Trait::Strength: IncreaseStat(Damage, 5); IncreaseStat(Health, 10); break;
		case Trait::Dexterity: IncreaseStat(Speed, 1); break;
		case Trait::Intelligence: IncreaseStat(Mana, 5); break;
		}
	}
	void ShowStats()
	{
		std::cout << "Damage : " << Stats[Damage] << std::endl;
		std::cout << "Health : " << Stats[Health] << std::endl;
		std::cout << "Mana   : " << Stats[Mana] << std::endl;
		std::cout << "Speed   : " << Stats[Speed] << std::endl;
	}
};

class Player
{
	/*
	Trait trait;	// Ư���� 1���� �����Ѵ�.
	Stat stat;		// ������ 1���� �����Ѵ�.
	std::vector<Trait> traits;
	std::vector<Stat> stats;
	�̷��� �������� ȿ�������� ����
	*/

	TraitBonus traitbonus;
	/*std::vector<int> stats;*/
public:
	Player() : traitbonus() {}
	TraitBonus GetTraits() const { return traitbonus; }

	void GetTrait(Trait trait)
	{
		traitbonus.GetTrait(Trait::Strength);
	}
	void ShowStats()
	{
		traitbonus.ShowStats();
	}
	/*
	Player() : stats(4, 0)
	{
		stats[static_cast<int>(Stat::Damage)] = 5;
		stats[static_cast<int>(Stat::Health)] = 100;
		stats[static_cast<int>(Stat::Mana)] = 50;
		stats[static_cast<int>(Stat::Speed)] = 50;
	}
	void IncreaseStat(Stat stat, int amount)
	{
		stats[static_cast<int>(stat)] += amount;
	}
	void ShowPlayerStat()
	{
		std::cout << "Damage : " << stats[Damage] << std::endl;
		std::cout << "Health : " << stats[Health] << std::endl;
		std::cout << "Mana   : " << stats[Mana] << std::endl;
	}
	*/

};

/*
*	C���� Casting�� ������
*	- �������� ����ȯ�� ���ÿ� �� �� �ִ�. -> static, const, reinterpret cast�� ���ÿ� ó���Ѵ� 
	-> ��, �ǵ�ġ ���� ����ȯ�� �߻��� �� �ִ�.
*	CPP ������ Casting
*	- static_case, const_cast, reinterpret_cast // dynamic_cast
* 
*	Tib) int, double, std::string ���� primitive type�� ��ȯ�ϰ� �ʹٸ�, static_cast ��� ����
*	const_cast : ����� �����ִ� ����ȯ
*	reinterpret_cast : �޸𸮿� �����Ͽ� int* -> double*�� ���ؼ��Ͽ� ��ȯ�ϴ� ����ȯ
*/
void EnumTest1()
{
	// enum�� ������, ������ enum���� ��ȯ�ϴ� �����Դϴ�.
	int num = Stat::Damage;

	Stat someType1 = (Stat)num;					// C������ ����ȯ
	Stat someType2 = static_cast<Stat>(num);	// C++�� ����ȯ

	if (someType1 == Stat::Damage)
	{
		std::cout << "����::����� ���" << std::endl;
	}
}
void EnumTest2()
{
	//Player player;
	//player.ShowPlayerStat();
	//player.IncreaseStat(Stat::Damage, 5); // �÷��̾��� ���ݷ� ������ 5��ŭ �������Ѷ�.
	//std::cout << std::endl << "�÷��̾� ���� ���" << std::endl << std::endl;
	//player.ShowPlayerStat();
}
void EnumTest3()
{
	TraitBonus traits;
	traits.GetTrait(Trait::Strength);
	traits.ShowStats();

	
	// �÷��̾��� Ư���� ���������� ��, Ư�� ������ �����ϰ� �Ϸ��� � ����� �ڵ带 �ۼ��ؾ��ϴ°�?

}
void EnumTest4()
{
	Player player;
	// player�ȿ� �ִ� Traitbouns Ŭ������ �����Ͽ� �Լ��� ���
	//player.GetTraits().GetTrait(Trait::Strength);
	//player.GetTraits().ShowStats();

	// �÷��̾� Ŭ������ Traitbouns �Լ��� Wrapping �ߴ�.
	player.GetTrait(Trait::Strength);
	player.ShowStats();
}

int main()
{
	//EnumTest1();
	//EnumTest2();
	//EnumTest3();
	//EnumTest4();

	// �Է��� ����Ͽ� ������ �������Ѻ���
	Player player;

	std::cout << "========= Level Up! ========" << std::endl;

	int input;
	std::cout << "���ڸ� ���� Ư���� �ø��ϴ�." << std::endl;
	std::cin >> input;
	
	if (input > Trait::None)
	{
		std::cout << "�߸��� �Է�" << std::endl;
	}
	else
	{
		player.GetTrait(static_cast<Trait>(input));
	}
	player.ShowStats();
}