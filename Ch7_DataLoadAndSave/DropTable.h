#pragma once
#include <iostream>
#include <vector>
#include "ConsoleUtility.h"

/*
*	1. DropItem �����ڸ� ��������
*	2. Monster�� �����͸� �޾�� �� �ְ� private �ʵ带 �����Ѵ�.
*	3. public ���̺� ������, vector ������ DropItem�� �߰��غ�����.
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

		// ���� � ����ġ ���̺��� �����ߴ°�? �� ���� ���̺��� �ۼ�
		SetDropItem();
	}

	void SetDropItem()
	{
		int index = ConsoleUtil::GetRandomInt(drop.size() - 1);
		currentDrop = drop[index];
	}
	void GetDrop()
	{
		std::cout << "ȹ���� ����ġ : " << currentDrop.exp << std::endl;
		std::cout << "ȹ���� �� : " << currentDrop.money << std::endl;
	}
};
