#pragma once
#include <fstream>
#include <iostream>

/*
*	�����͸� ����.
*	�� �÷��̾��� ����, ����ġ
*
*	�����͸� �ڷᱸ�� ���·� ����. (�޸��忡)
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
		// file�� ����� (open)
		if (file.is_open())
		{
			// �޸��忡 exp�� level�� �����϶�.		
			file << level << " " << exp << std::endl;
			// file�� �ݾƶ� (close)
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