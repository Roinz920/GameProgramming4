#pragma once

// int array[100];
// 1. vector<int> vec;


// 2. template 간단한 코드로 구현해볼 것

#include "Common.h"

class PocketMonster
{
private:
	int _number;
	string _name;

public:
	PocketMonster(int number, string name) : _number(number), _name(name) {}

	int Get_Number() const
	{
		return _number;
	}

	string Get_Name() const
	{
		return _name;
	}

	bool operator<(const PocketMonster& other)
	{
		// this->_number : 자신의 도감 번호
		// other.Get_Number() : 비교 대상의 도감 번호

		return this->_number < other.Get_Number();

		// 자신의 도감번호가 비교 대상의 도감번호보다 작으면 true, 아니면 false
	}
};

// 

void Example1()
{
	PocketMonster 이상해씨(1, "이상해씨");
	PocketMonster 파이리(4, "파이리");
	PocketMonster 꼬부기(7, "꼬부기");
	PocketMonster 버터플(12, "버터플");
	PocketMonster 구구(16, "구구");
	PocketMonster 피카츄(25, "피카츄");
	//cout << "No." << 피카츄.Get_Number() << " " << 피카츄.Get_Name() << endl;

	cout << 파이리.Get_Name() << " 이(가) " << 피카츄.Get_Name() << " 보다 도감번호가 큰가요? ";
	if (피카츄 < 파이리 == true) { cout << "네" << endl; }
	else { cout << "아니오" << endl; };

	cout << endl;

	std::vector<PocketMonster> PocketDatabase;
	// 데이터의 입력
	PocketDatabase.push_back(이상해씨);
	PocketDatabase.push_back(파이리);
	PocketDatabase.push_back(구구);
	PocketDatabase.push_back(버터플);
	PocketDatabase.push_back(꼬부기);
	PocketDatabase.push_back(피카츄);
	// 데이터의 알고리즘 (주어진 문제의 해결. 이번 시간에는 정렬)
	sort(PocketDatabase.begin(), PocketDatabase.end());
	reverse(PocketDatabase.begin(), PocketDatabase.end());

	// 데이터의 출력
	for (auto& pocketmon : PocketDatabase)
	{
		cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}

	// 데이터 찾기(검색)
	int searchIndex = 25;
	for (auto& pocketmon : PocketDatabase)
	{
		if (pocketmon.Get_Number() == searchIndex)
		{
			cout << endl << searchIndex << "번 몬스터를 찾았다!" << endl;
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
			break;
		}
		else
		{
			cout << searchIndex << "번 몬스터를 아직 만나지 못했다";
			break;
		}
	}
}