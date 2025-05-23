/*
*	class 안에 enum을 활용해보기
*/

/*
*	enum : 열거형.
*	enum으로 상수를 저장할 수 있다.
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
*	Trait과 Stat 사이의 관계를 정의해야한다.
*	예시)
*	STR 1 상승 :  Dagame (기존 수치) + ( ); // 합연산
*/
/*
*	Vector 타입의 한계점
*	
*	Dex를 올리면 Speed가 증가하는 시스템을 만들어라고 했을 때
*	-> 
*	
*	※ 배열 형태로 저장되어 있는 자료구조이기 때문에, 자료의 삭제 및 추가를 할 때에 문제가 발생할 수 있다.
*	(특히나 순서대로 정리되어있지 않은 데이터의 변경이 발생했을 때에 문제가 예상됨)
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
	Trait trait;	// 특성을 1개만 소유한다.
	Stat stat;		// 스탯을 1개만 소유한다.
	std::vector<Trait> traits;
	std::vector<Stat> stats;
	이렇게 쓰지말고 효과적으로 쓰자
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
*	C형태 Casting의 문제점
*	- 여러가지 형변환을 동시에 할 수 있다. -> static, const, reinterpret cast를 동시에 처리한다 
	-> 즉, 의도치 않은 형변환이 발생할 수 있다.
*	CPP 형태의 Casting
*	- static_case, const_cast, reinterpret_cast // dynamic_cast
* 
*	Tib) int, double, std::string 등의 primitive type을 변환하고 싶다면, static_cast 사용 권장
*	const_cast : 상수를 없애주는 형변환
*	reinterpret_cast : 메모리에 접근하여 int* -> double*로 재해석하여 변환하는 형변환
*/
void EnumTest1()
{
	// enum을 정수로, 정수를 enum으로 변환하는 예제입니다.
	int num = Stat::Damage;

	Stat someType1 = (Stat)num;					// C형태의 형변환
	Stat someType2 = static_cast<Stat>(num);	// C++의 형변환

	if (someType1 == Stat::Damage)
	{
		std::cout << "스탯::대미지 출력" << std::endl;
	}
}
void EnumTest2()
{
	//Player player;
	//player.ShowPlayerStat();
	//player.IncreaseStat(Stat::Damage, 5); // 플레이어의 공격력 스탯을 5만큼 증가시켜라.
	//std::cout << std::endl << "플레이어 스탯 상승" << std::endl << std::endl;
	//player.ShowPlayerStat();
}
void EnumTest3()
{
	TraitBonus traits;
	traits.GetTrait(Trait::Strength);
	traits.ShowStats();

	
	// 플레이어의 특성을 증가시켰을 때, 특정 스탯을 증가하게 하려면 어떤 방식의 코드를 작성해야하는가?

}
void EnumTest4()
{
	Player player;
	// player안에 있는 Traitbouns 클래스에 접근하여 함수를 사용
	//player.GetTraits().GetTrait(Trait::Strength);
	//player.GetTraits().ShowStats();

	// 플레이어 클래스에 Traitbouns 함수를 Wrapping 했다.
	player.GetTrait(Trait::Strength);
	player.ShowStats();
}

int main()
{
	//EnumTest1();
	//EnumTest2();
	//EnumTest3();
	//EnumTest4();

	// 입력을 사용하여 스탯을 증가시켜보기
	Player player;

	std::cout << "========= Level Up! ========" << std::endl;

	int input;
	std::cout << "숫자를 눌러 특성을 올립니다." << std::endl;
	std::cin >> input;
	
	if (input > Trait::None)
	{
		std::cout << "잘못된 입력" << std::endl;
	}
	else
	{
		player.GetTrait(static_cast<Trait>(input));
	}
	player.ShowStats();
}