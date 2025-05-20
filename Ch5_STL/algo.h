#pragma once
#include "ConsoleUtility.h"

// 찾으면 iterator를 반환, 못 찾으면 end() 값을 반환
// 데이터들 안에 찾는 데이터가 있는지 확인하는 함수

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

// 알고리즘을 사용한 심화 코드

/*
*	std::함수이름( vec.begin(), vec.end(), 정의된 함수, 람다식, 펑터)
*	
*	함수에는 사실..
*	1. function pointer
*	bool (*함수이름)(int x);
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
	monsters.emplace_back(1, "피카츄");
	monsters.emplace_back(2, "이상해씨");
	monsters.emplace_back(3, "파이리");
	monsters.emplace_back(4, "꼬부기");
	

	// monster
	// monster.id 의 차이 때문에 find를 사용할 수 없다 | find(monsters.begin(), monsters.end(), 3); 사용 불가
	// find_if : 3번째 인자에 어떠한 데이터를 찾을것인지 조건을 넣어준다	-	함수(function), 함자(functor), 람다식(lamda)
	auto it = std::find_if(monsters.begin(), monsters.end(),
		[](const Monster& find_monster) {return find_monster.id == 3; });

	cout << it->name << endl;

	// map은 2가지 타입을 가져와야함
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
		cout << "nums의 모든 데이터가 홀수 입니다." << endl;
	}
	else
	{
		cout << "nums에 짝수가 존재합니다." << endl;
	}
}