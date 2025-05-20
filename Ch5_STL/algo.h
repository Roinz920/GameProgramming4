#pragma once
#include "ConsoleUtility.h"

// ã���� iterator�� ��ȯ, �� ã���� end() ���� ��ȯ
// �����͵� �ȿ� ã�� �����Ͱ� �ִ��� Ȯ���ϴ� �Լ�

void find_test()
{
	cout << "====================================================" << endl;
	vector<int> nums = { 1,2,3,4,5 };

	
	auto it = std::find(nums.begin(), nums.end(), 6);
	
	if (it != nums.end())
	{
		cout << *it << endl;
	}
	else
	{
		cout << "Data not found" << endl;
	}
}

struct Monster
{
	int id;
	string name;

	Monster(int id, string name) : id(id), name(name) {}
};

// �˰����� ����� ��ȭ �ڵ�

/*
*	std::�Լ��̸�( vec.begin(), vec.end(), ���ǵ� �Լ�, ���ٽ�, ����)
*	
*	�Լ����� ���..
*	1. function pointer
*	bool (*�Լ��̸�)(int x);
*/

bool isEven(int x)
{
	return x % 2 != 0;
}
bool isOdd(int x)
{
	return x % 2 == 0;
}

void find_test2()
{
	std::vector<Monster> monsters;
	monsters.emplace_back(1, "��ī��");
	monsters.emplace_back(2, "�̻��ؾ�");
	monsters.emplace_back(3, "���̸�");
	monsters.emplace_back(4, "���α�");
	

	// monster
	// monster.id �� ���� ������ find�� ����� �� ���� | find(monsters.begin(), monsters.end(), 3); ��� �Ұ�
	// find_if : 3��° ���ڿ� ��� �����͸� ã�������� ������ �־��ش�	-	�Լ�(function), ����(functor), ���ٽ�(lamda)
	auto it = std::find_if(monsters.begin(), monsters.end(),
		[](const Monster& find_monster) {return find_monster.id == 3; });

	cout << it->name << endl;

	// map�� 2���� Ÿ���� �����;���
	//std::map<int, std::string> datas;
}


struct Square_Functor
{
	void operator()(int x)
	{
		cout << x * x << " ";
	}
};

void for_each_test()
{
	std::vector<int> nums = { 1,3,5 };
	Square_Functor square;
	std::for_each(nums.begin(), nums.end(), square);
}
void all_of_test()
{
	std::vector<int> nums = { 1,2,3,4,5 };
	
	if (std::all_of(nums.begin(), nums.end(), isEven))
	{
		cout << "nums�� ��� �����Ͱ� Ȧ�� �Դϴ�." << endl;
	}
	else
	{
		cout << "nums�� ¦���� �����մϴ�." << endl;
	}
}