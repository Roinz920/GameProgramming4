#pragma once
#include <iostream>
#include <vector>
#include "ConsoleUtility.h"

/*
*	1. DropItem 생성자를 만들어보세요
*	2. Monster가 데이터를 받어올 수 있게 private 필드를 선언한다.
*	3. public 레이블에 생성자, vector 형태의 DropItem을 추가해보세요.
*/



struct DropItem
{
	int index;
	int exp;
	int money;
	
	DropItem() = default;
	DropItem(int index, int exp, int money) : index(index), exp(exp), money(money) {}
};

class Monster
{
private:
	int exp;
	int money;

	std::vector<DropItem> drop;
	DropItem currentDrop;

public:

	Monster(int exp, int money) : exp(exp), money(money)
	{
		drop.emplace_back(1, 5, 20);
		drop.emplace_back(2, 10, 40);
		drop.emplace_back(3, 20, 80);
		drop.emplace_back(4, 35, 150);
		drop.emplace_back(5, 50, 300);

		// 내가 어떤 경험치 테이블을 선택했는가? 에 대한 테이블의 작성
		SetDropItem();
	}

	void SetDropItem()
	{
		int index = ConsoleUtil::GetRandomInt(drop.size() - 1);
		currentDrop = drop[index];
	}
	void GetDrop()
	{
		std::cout << "획득한 경험치 : " << currentDrop.exp << std::endl;
		std::cout << "획득한 돈 : " << currentDrop.money << std::endl;
	}
};
