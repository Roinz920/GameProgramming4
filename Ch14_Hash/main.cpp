#include <iostream>
#include <map>
#include <unordered_map>
#include "ConsoleUtility.h"


#pragma region �ؽ� �Լ��� �����ΰ�?
/*
*	Hash Function : Hashing�ϴ� �� �ǹ�?
*	- �����ϴ� Ÿ���� Ư���� ��Ģ���� �ٸ� Ÿ������ ��ȯ�ϴ� �۾�.
* 
*	�� Hasing�� �ϴ°�?
*	-> Hasing ����� �����͸� �������Ͽ� ����� �� �ִ�.
*/
/*
*	Hash�� ���� �ڷᱸ���� ����?
*	map���� ������ ������ ������, ������ Ž���� ������.
*/
int HashFucntion(int input)
{
	return input % 10; // 0 ~ 9 ������ ��ȯ
}
void Test1()
{
	HashFucntion(252349429);	//	252349429 -> 9�� ����

	// unordered_map : [key - value] :: 9��� �ؽ������� 252349429 ��� ���ڰ� ����ִ�.

	std::unordered_map <std::string, int> umap;

	umap.insert({ "�ٳ���",5 });
	umap.insert({ "���",5 });

	std::cout << "�ٳ����� ���� : " << umap["�ٳ���"] << std::endl;


}


#pragma endregion 

#pragma region map�� unordered_map�� ��

/*
*	Ž���ϴµ� unordered_ma�� ������.
*	������ ���� ������ �������� unodered_map�� ����.
*	������ ���� ������ 
* 
*	�� �����Ѱ�? - �����͸� �ʱ�ȭ �� ���� �ɸ��� �ð�
*	���� �����̳� > ���� �����̳� (map) > unordered_map (��ü������ �ؽ��Լ��� �����Ǿ��ְ�, �ؽ��Լ��� ���� ������ ����)
*	
*	�ؽ��Լ��� ����
*	-	�ؽ��浹�� �߻��� �� �������ϰ� �߻��� �� �ִ�.
*/

void MapTimeTest()
{
	std::map<std::string, int> map;

	map.insert({ "A", 1 });
	map.insert({ "B", 1 });
	map.insert({ "C", 1 });
	map.insert({ "D", 1 });
	map.insert({ "E", 1 });

	for (int i = 0; i < 1000; i++)
	{
		map.find ("A");
	}
}

void newMapTimeTest()
{
	std::map<std::string, int> umap;

	umap.insert({ "A", 1 });
	umap.insert({ "B", 1 });
	umap.insert({ "C", 1 });
	umap.insert({ "D", 1 });
	umap.insert({ "E", 1 });

	for (int i = 0; i < 1000; i++)
	{
		umap.find ("A");
	}
}

void Test2()
{
	std::cout << "ù��° �� - ������ �Է� ��" << endl;

	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(newMapTimeTest);

	std::cout << "map�� ���� : ������ �ڵ� ������ �߻���" << endl;
	std::cout << "������ �� �����͸� �ʿ��� ���� map�� ����" << endl;
	std::cout << "�� �̿ܿ� �����̳� �ȿ� ���� �����͸� ã�� �����ϰ� �ʹ�." << endl;

	std::cout << "�ι�° �� - ������ �˻� �ð� ��" << std::endl;
	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(newMapTimeTest);
}

#pragma endregion 


int main()
{
	
	Test2();
}