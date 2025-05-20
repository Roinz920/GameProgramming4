#include "ConsoleUtility.h"
#include "algo.h"

/*
*	int Ÿ���� �����͸� �����ϴ�  vector Ŭ������ ���� 1,2,3,4,5�� �����غ��ÿ�
*/

/*
*	iterator (�ݺ���)
*	�������� ������ �ϴ� Ŭ����.
*	�ڷ� ����::iterator ��� �ϸ� ���� ����
*/

/*
*	iterator�� ����ؼ� �ڷᱸ���� element�� ����� �� �ִ�.
*	begin()	, cbegin()	, rbegin()	, crbegin()
*	end()	, cend()	, rend()	, crend()
*/

// iterator �⺻ �����
void test1()
{
	vector<int> nums = { 1,2,3,4,5 };
	std::list<int> intlist = { 1,2,3,4,5 };
	std::vector<int>::iterator it = nums.begin();

	cout << "iterator �ݺ����� Ȱ���� �ڷᱸ�� ��ü ������ ���" << endl;
	while (it != nums.end()) // iterator�� ���� vector�� ���� end���� �ƴҶ� ���� �ݺ��϶�
	{
		std::cout << *it << " "; // iterator�� ����� �ּ��� ���� �������ؼ� ����϶�.
		it++;
	}
	cout << endl;
	cout << "for �ݺ����� Ȱ���� �ڷᱸ�� ��ü ������ ���" << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}

	// vector�� �ƴ� �ڷᱸ�������� �����͸� ��ȸ, ���
	std::list<int>::iterator it2 = intlist.begin();
	cout << endl;
	cout << "list�� Ȱ���� �ڷᱸ�� ��ü ������ ���" << endl;
	while (it2 != intlist.end()) // iterator�� ���� vector�� ���� end���� �ƴҶ� ���� �ݺ��϶�
	{
		std::cout << *it2 << " "; // iterator�� ����� �ּ��� ���� �������ؼ� ����϶�.
		it2++;
	}
	cout << endl;
}

// �������� ����ϴ� ���
void test2()
{
	cout << "====================================================" << endl;
	vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	std::list<int> list1 = { 2,4,6,7,8,9 };
	// vector<int>::reverse_iterator �� Ŭ���� �̸��� ����. �ڵ��߷� ����� auto�� �����Ͽ��� �����ϰ� �۵���
	// vector<int>::reverse_iterator it = vec.rbegin();
	auto it = vec.rbegin();
	auto it2 = list1.rbegin();

	while (it != vec.rend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	cout << "list�� �������� ���" << endl;
	while (it2 != list1.rend())
	{
		cout << *it2 << " ";
		it2++;
	}
}

// auto Ű����
void test3()
{
	cout << "====================================================" << endl;

	// ���� 1
	auto x = 5;

	// ����2. ���� ����ϸ� ������? -> Ÿ���� �̸��� �ſ� �� ������
	std::vector<int> nums = { 1,2,3,4,5 };
	auto it = nums.begin();

	// ������ ���� : ���� ������ �����ʿ� ���� value�� ��Ư���� �������� ���� ������� ���� ��

	// ����3.
	
	// ������ �ڷ����� �ſ� ���� ���� ���

	/*
	*	auto		: int, double primitive type ����� ���� ���ϰ� ��� (�����ؼ� ���������)
	*	auto&		: �޸𸮿� �����ؼ� �����͸� ������ �� �ִ�.
	*	const auto&	: �޸� �����͸� ���������� �������� ���ϰ� �Ѵ�.
	*/
	for (auto num : nums)
	{
		num = 0;
	}
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	// ��°� : 1,2,3,4,5
	cout << endl;
	for (auto& num : nums)
	{
		num = 0;
	}	
	for (auto num : nums)
	{
		cout << num << " ";
	}
	// ��°� : 0,0,0,0,0
}

void test4()
{
	cout << "====================================================" << endl;
	vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	
	auto it = vec.cbegin(); //std::vector<int>::const_iterator it = vec.cbegin();
	
	while (it != vec.cend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	auto it2 = vec.crbegin();
	while (it2 != vec.crend())
	{
		cout << *it2 << " ";
		it2++;
	}
}

void test5()
{
	cout << "====================================================" << endl;
	vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	
	auto start = vec.begin() + 2;	// 3��° element�� ����Ű�� �ִ�.
	auto finish = vec.end() - 3;	// �ڿ��� 4��° elemnt�� ����Ű�� �ִ�.

	while (start != finish)
	{
		cout<< *start << " ";
		start++;
	}
	// ��°� 3,4,5,6
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//find_test();
	find_test2();

	for_each_test();
	all_of_test();
}