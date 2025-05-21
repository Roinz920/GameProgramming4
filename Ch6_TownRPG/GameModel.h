#pragma once

#include <iostream>

/*
*	virtual이라는 키워드를 사용하라면, 해당 클래스를 상속하는 자식 클래스가 반드시 필요하다.
*	Combat - Player, Monster
*	override 기능을 사용하여 Combat 타입임에도 Player의 Combat과 Monster의 Combat
*	
*	virtual 함수() = 0; // 순수 가상 함수
*/

class Combat
{
public:
	virtual ~Combat() = default;

	virtual void attack(Combat& target) = 0;
	virtual void takeDamage(int damage) = 0;
	virtual int getHealth() = 0;

};

class Player : public Combat
{
private:
	int health;
	int ATK;
public:
	Player(int health, int ATK) : health(health), ATK(ATK) {}

	void attack(Combat& target) override
	{
		target.takeDamage(ATK);
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		std::cout << "Player가 " << damage << "의 피해를 입었습니다." << std::endl;
	}
	int getHealth() override
	{
		return health;
	}
};

class Monster : public Combat
{
private:
	int health;
	int ATK;

public:
	Monster(int health, int ATK) : health(health), ATK(ATK) {}

	void attack(Combat& target) override
	{
		target.takeDamage(ATK);
	}
	
	void takeDamage(int damage) override
	{
		health -= damage;
		std::cout << "Monster가 " << damage << "의 피해를 입었습니다." << std::endl;
	}
	int getHealth() override
	{
		return health;
	}
};