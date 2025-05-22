#pragma once
#include <fstream>
#include <iostream>

/*
*	데이터를 저장.
*	└ 플레이어의 레벨, 경험치
*
*	데이터를 자료구조 형태로 저장. (메모장에)
*	
*/

class Data
{
private:
	int exp;
	int level;

public:
	Data() : exp(100), level(1) {}

	void SaveData(const std::string& filename)
	{
		std::ofstream file(filename);
		// file을 열어라 (open)
		if (file.is_open())
		{
			// 메모장에 exp와 level을 저장하라.		
			file << level << " " << exp << std::endl;
			// file을 닫아라 (close)
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

	int GetExp()
	{
		return exp;
	}

	int GetLevel()
	{
		return level;
	}
};