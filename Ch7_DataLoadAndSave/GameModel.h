#pragma once
#include <iostream>
#include <fstream>
#include <vector>

/*
*	��ǥ : ������ �ý����� ����
*	int exp, maxExp;  // ���� ����ġ > maxExp -> ������ 1 �ø���.
*/

/*
*	��ǥ2: ������ ���� ����ġ �䱸���� �ڷᱸ���� ǥ���ϱ�.
*	vector<"">
*/
/*
*	����ġ ���̺��� �����
*	Lv.1 - 100
* 	Lv.2 - 100
* 	Lv.3 - 200
* 	Lv.4 - 250
* 	Lv.5 - 350
* 	Lv.6 - 500
*/

/*
*	�����͸� ǥ���ϱ� ���� Ŭ���� ����. LevelExp
*	Ư�� Ŭ���� �ȿ� ǥ���ϱ� ���� Ŭ������ �ڷᱸ���� �����ϼ���. Player-> std::vector<LevelExp> leveltable;
*/
/*
*	�����ڿ� �����͸� ���� �ۼ�.
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
		// 1������ �����͸� �����ͼ� ����Ѵ�.
		maxExp = leveltable[0].maxExp;
	}
	int GetMaxExpforLevel(int level)
	{
		for (auto& data : leveltable)
		{
			//������ table������ ���϶�
			if (level == data.level)
			{
			    return data.maxExp;
			}
		}
		return -1; // -1 ��ȯ�ϸ� ������ �ν��϶�.
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
