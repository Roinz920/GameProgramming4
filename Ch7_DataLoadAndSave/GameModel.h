#pragma once
#include <iostream>
#include <fstream>
#include <vector>

/*
*	목표 : 레벨업 시스템의 구현
*	int exp, maxExp;  // 현재 경험치 > maxExp -> 레벨을 1 올린다.
*/

/*
*	목표2: 레벨에 따른 경험치 요구량을 자료구조로 표현하기.
*	vector<"">
*/
/*
*	경험치 테이블을 만든다
*	Lv.1 - 100
* 	Lv.2 - 100
* 	Lv.3 - 200
* 	Lv.4 - 250
* 	Lv.5 - 350
* 	Lv.6 - 500
*/

/*
*	데이터를 표현하기 위한 클래스 생성. LevelExp
*	특정 클래스 안에 표현하기 위한 클래스의 자료구조로 선언하세요. Player-> std::vector<LevelExp> leveltable;
*/
/*
*	생성자에 데이터를 직접 작성.
*	vector.push_back()
*	vector.emplace_back()
*/
struct LevelExp
{
	int level;
	int maxExp;
	LevelExp(int level, int maxExp) :level(level), maxExp(maxExp) {}
};

class Player
{
private:
	int exp;
	int maxExp;
	int level;
	std::vector<LevelExp> leveltable;

public:
	Player() : exp(0), maxExp(100), level(1) {}
	Player(int exp, int maxExp) : exp(exp), maxExp(maxExp), level(1) 
	{
		leveltable.emplace_back(1, 100);
		leveltable.emplace_back(2, 100);
		leveltable.emplace_back(3, 200);
		leveltable.emplace_back(4, 250);
		leveltable.emplace_back(5, 350);
		leveltable.emplace_back(6, 500);
	}

	void LoadExpInExptable()
	{
		// 1레벨의 데이터를 가져와서 사용한다.
		maxExp = leveltable[0].maxExp;
	}
	int GetMaxExpforLevel(int level)
	{
		for (auto& data : leveltable)
		{
			//레벨과 table레벨을 비교하라
			if (level == data.level)
			{
			    return data.maxExp;
			}
		}
		return -1; // -1 반환하면 에러로 인식하라.
	}
	void GetExp(int amount)
	{
		exp += amount;
		maxExp = GetMaxExpforLevel(level);
		if (exp >= maxExp)
		{
			level++;
			exp -= maxExp;
		}
	}

	void Show() const
	{
		std::cout << "Lv  : " << level << std::endl;
		std::cout << "exp : " << exp << std::endl;
		std::cout << "maxExp : " << maxExp << std::endl;
	}

	void SaveData(const std::string& filename)
	{
		std::ofstream file(filename);
		if (file.is_open())
		{
			file << level << " " << exp << std::endl;
			file.close();
		}
	}
	void LoadData(const std::string& filename)
	{
		std::ifstream file(filename);
		int _exp, _level;
		file >> _level >> _exp;
		level = _level;
		exp = _exp;
	}
};
