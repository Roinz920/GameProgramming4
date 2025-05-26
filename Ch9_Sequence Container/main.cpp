#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "TimeCheck.h"
#include "FunctionPointer.h"
#include "ConsoleUtility.h"

/*
*	Sequence Container
*	Vector
*	Deque
*	List
*/
/*	
*	(��ǥ) Vector�� List�� �������� ���� ��
*	1. vector push_back �߰�, List push_back �߰� �� �ð��� ��.	: vector�� �� ������
*	2. ������ �����Ϳ� �����ϴµ� �ɸ��� �ð�						: List�� �� ������
* 
*	�����Ͱ� ������ ������, ������ ���� ��� : vector�� ����
*	������ ������ ����� ��� : list�� ����
*
*	(�ڡڡڡڡ�)������ ������ ����, ���ٰ� ���� ��� : unordered_map

	vector
	unordered_map
*/

/*
*	Vector, List ũ�� �������� ����. ��,
*	Vector	[] �ε����� ������ ����� �� ����.
*	List	[] �ε����� ������ �� ����.	
* 
*	�������� ������ Ȯ���ϱ� ���ؼ� ȯ�� ������ ����.
*/
struct Node
{
	int value;
	Node* nextPtr;
	Node* prevPtr;
};

void Test1_Vector()
{
	std::vector<int> nums;
	
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
	std::cout << nums[500] << std::endl;
}
void Test2_List()
{
	std::list<int> nums;
	nums.push_back(3);
	nums.push_front(2);
	nums.push_back(1);

	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
}

void VectorExample()
{
	std::vector<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
	std::cout << "���� ������ ���� �ҿ� �ð�" << std::endl;
	std::cout << nums[900] << std::endl;

	// erase�Լ��� n�� ����ϴ� ����
	for (int i = 0; i < 700; i++)
	{
		auto it = nums.begin();
		nums.erase(it); 
	}
}
void ListExample()
{
	std::list<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
	std::cout << "���� ������ ���� �ҿ� �ð�" << std::endl;
	auto it = std::next(nums.begin(), 900);
	std::cout << *it << std::endl;
	
	// erase�Լ��� n�� ����ϴ� ����
	for (int i = 0; i < 700; i++)
	{
		auto it = std::next(nums.begin(), 0);
		nums.erase(it); 
	}
}

int main()
{
	//Test1_Vector();
	//Test2_List();
	
	// �ڷᱸ�� �ð� �׽�Ʈ
	//TimeCheckTest();
	//TimeCheckTest2();

	// �Լ� ������ �׽�Ʈ
	//Test_FP();

	//
	ConsoleUtil::TimeCheck(VectorExample);
	ConsoleUtil::TimeCheck(ListExample);
}