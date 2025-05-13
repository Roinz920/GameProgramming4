#pragma once

// int array[100];
// 1. vector<int> vec;


// 2. template ������ �ڵ�� �����غ� ��

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
		// this->_number : �ڽ��� ���� ��ȣ
		// other.Get_Number() : �� ����� ���� ��ȣ

		return this->_number < other.Get_Number();

		// �ڽ��� ������ȣ�� �� ����� ������ȣ���� ������ true, �ƴϸ� false
	}
};

// 

void Example1()
{
	PocketMonster �̻��ؾ�(1, "�̻��ؾ�");
	PocketMonster ���̸�(4, "���̸�");
	PocketMonster ���α�(7, "���α�");
	PocketMonster ������(12, "������");
	PocketMonster ����(16, "����");
	PocketMonster ��ī��(25, "��ī��");
	//cout << "No." << ��ī��.Get_Number() << " " << ��ī��.Get_Name() << endl;

	cout << ���̸�.Get_Name() << " ��(��) " << ��ī��.Get_Name() << " ���� ������ȣ�� ū����? ";
	if (��ī�� < ���̸� == true) { cout << "��" << endl; }
	else { cout << "�ƴϿ�" << endl; };

	cout << endl;

	std::vector<PocketMonster> PocketDatabase;
	// �������� �Է�
	PocketDatabase.push_back(�̻��ؾ�);
	PocketDatabase.push_back(���̸�);
	PocketDatabase.push_back(����);
	PocketDatabase.push_back(������);
	PocketDatabase.push_back(���α�);
	PocketDatabase.push_back(��ī��);
	// �������� �˰��� (�־��� ������ �ذ�. �̹� �ð����� ����)
	sort(PocketDatabase.begin(), PocketDatabase.end());
	reverse(PocketDatabase.begin(), PocketDatabase.end());

	// �������� ���
	for (auto& pocketmon : PocketDatabase)
	{
		cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}

	// ������ ã��(�˻�)
	int searchIndex = 25;
	for (auto& pocketmon : PocketDatabase)
	{
		if (pocketmon.Get_Number() == searchIndex)
		{
			cout << endl << searchIndex << "�� ���͸� ã�Ҵ�!" << endl;
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
			break;
		}
		else
		{
			cout << searchIndex << "�� ���͸� ���� ������ ���ߴ�";
			break;
		}
	}
}