#include "ConsoleUtility.h"

// ���� �����̳� Sequence Conatiner : vector, list, deque
// #include <�����̳�>

#include <vector>
#include <list>
#include <deque>

// ���� �����̳� associate Container : (multi, unordered) set, map | 6����

#include <set>
#include <map>
#include <algorithm> // �����̳ʿ� �����͸� ó���ϴ� ��ɵ��� ����Ǿ��ִ� ���̺귯��

// 3�ܰ�. ������, �߰� ������ ������ ���Ͽ� ������ ���� �����̳� ����ϱ�

#pragma region (1)�ܰ�. ���� �����̳� ������ �Է� �ð� ��
void DataPushByVector()
{
	std::vector<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void DataPushByList()
{
	std::list<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void DataPushByDeque()
{
	std::deque<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void Test1()
{
	cout << "������ �Է� �ð� ��" << endl;
	cout << "vector �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(DataPushByVector);
	cout << "list   �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(DataPushByList);
	cout << "deque  �ҿ� �ð� : "; 
	ConsoleUtil::TimeCheck(DataPushByDeque);

	cout << "��� : �ܼ� ������ �Է¿��� vector�� ���� ������." << endl << endl;
}
#pragma endregion

#pragma region (2)�ܰ�. ���� �����̳� �߰� ������ �Է� �ð� ��

void InsertDataByVector()
{
	std::vector<int> nums;
	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 10000; i++)
	{
	auto it = nums.begin()+5;
	nums.insert(it, i);
	}
}
void InsertDataByList()
{
	std::list<int> nums;
	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 10000; i++)
	{
		auto it = std::next(nums.begin(), 5);
		nums.insert(it, i);
	}
}
void InsertDataByDeque()
{
	std::deque<int> nums;
	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 10000; i++)
	{
		auto it = std::next(nums.begin(), 5);
		nums.insert(it, i);
	}
}

void Test2()
{
	cout << "�߰� ������ �Է� �ð� ��" << endl;
	cout << "vector �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByVector);
	cout << "list   �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByList);
	cout << "deque  �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByDeque);
	cout << "��� : ó�� �����͸� �Է����� ������ vector�� ������ (1000ȸ �ݺ�)" << endl;
	cout << "��� : �߰� ����(����)�ϴ� ������ ������ �������� list�� ������ �� �ִ�." << endl << endl;
}
#pragma endregion

#pragma region (2-2)�ܰ�. ���� �����̳� �����͸� �� �տ��� �߰��� �� �ɸ��� �ð� ��

void FrontPushByVector()
{
	std::vector<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		auto it = nums.begin();
		nums.insert(it, i);
	}
}
void FrontPushByList()
{
	std::list<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_front(i);
	}
}
void FrontPushByDeque()
{
	std::deque<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_front(i);
	}
}

void Test2_2()
{
	cout << "ù��° ������ �Է� �ð� ��" << endl;
	cout << "vector �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(FrontPushByVector);
	cout << "list   �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(FrontPushByList);
	cout << "deque  �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(FrontPushByDeque);
	cout << "��� : ù��° ���Ҹ� �ִ� ��쿡 vector�� ������ ������ �ذ��� �� �ִ�." << endl << endl;
}

#pragma endregion

#pragma region (2-3)�ܰ�. ���� �����̳ʿ��� ���� ���� ���ٿ� �ɸ��� �ð� ��
void RandomAccessByVector()
{
	std::vector<int> nums;
	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 50; i++)
	{
		nums[i] = 0;
	}
}
void RandomAccessByList()
{
	std::list<int> nums;
	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 50; i++)
	{
		auto it = std::next(nums.begin(), 1);
		*it = 0;
	}
}
void RandomAccessByDeque()
{
	std::deque<int> nums;
	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 50; i++)
	{
		nums[i] = 0;
	}
}

void Test2_3()
{
	cout << "���� ��ġ�� ������ ���� �ð� ��" << endl;
	cout << "vector �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessByVector);
	cout << "list   �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessByList);
	cout << "deque  �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessByDeque);
	cout << "��� : �迭 ������ �ڷᱸ��(vector, deque)������ �׻� �����Ϳ� �ٷ� ������ �����ϴ�." << endl;
	cout << "       list�� ��쿡�� ���۰� �Ÿ��� �ָ� �ּ��� �ð��̿��� �ɸ���" << endl << endl;
}

#pragma endregion

#pragma region ���� �����̳� ��

/*
*		 |	Vector	|	List	|	Deque	|
* push	 |	1		|	3		|	2		|
* insert |	2		|	1		|	3		|
* front	 |	3		|	2t		|	1		|
* access |	1		|	3		|	2		|
*/

/*
*	Case1. ��Ȳ�ο�, �������� �Է��� (����)�߻��ϰ�, �߰� ������ �Է��� (������), �տ� ������(������), ���� ������ (����) ���
*/
#pragma endregion

#pragma region (3)�ܰ�. ���� �����̳ʿ� ���� �����̳�

// �����͸� �����ϴ� �������� �����̳ʴ� �������. -> ����� ���ؼ��� ã�Ƽ� Ȱ���� �� �־���Ѵ�.
// std::vector<monster> mon;  monster a = mon[?];
// �����̳� �ȿ� �ش��ϴ� �����Ͱ� ���ٸ�? ���� �߻� -> �������� ���� �ʿ�. if(�����Ͱ� �����ϳ���?) -> ����; else() -> ������ ����;
bool Find(int value)
{
	int nums[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 10; i++)
	{
		if (nums[i] == value)
		{
			cout << nums[i] << " ���� ã�ҽ��ϴ�." << endl;
			return true;
		}
	}
	cout << "���� ã�� ���߽��ϴ�." << endl;
	return false;
}

void FindByVector()
{
	std::vector<int> nums;
	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}
	/*
	for (auto num : nums)
	{
		cout << num << " ";
	}
	*/
	for (int i = 0; i <10; i++)
	{
		std::find(nums.begin(), nums.end(), i); // ���۰� �� ���̿��� i��� ���ڸ� ã����
	}
}
void FindByList()
{
	std::list<int> nums;
	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}
	/*
	for (auto num : nums)
	{
		cout << num << " ";
	}
	*/
	for (int i = 0; i < 10; i++)
	{
		std::find(nums.begin(), nums.end(), i);
	}
}
void FindByDeque()
{
	std::deque<int> nums;
	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}
	/*
	for (auto num : nums)
	{
		cout << num << " ";
	}
	*/
	for (int i = 0; i < 10; i++)
	{
		std::find(nums.begin(), nums.end(), i);
	}
}
void FindBySet()
{
	std::set<int> nums;

	for (int i = 10; i > 0; i--)
	{
		nums.insert(i);
	}
	/*
	for (auto num : nums)
	{
		cout << num << " ";
	}
	*/
	for (int i = 0; i < 10; i++)
	{
		nums.find(i);
	}
}
void Test3()
{
	cout << "������ �˻� �ð� ��" << endl;
	cout << "vector �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(FindByVector);
	cout << "list   �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(FindByList);
	cout << "deque  �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(FindByDeque);
	cout << "set    �ҿ� �ð� : ";
	ConsoleUtil::TimeCheck(FindBySet);
	cout << "��� : ���� �����̳ʴ� �����͸� �Է��ϴµ� ������." << endl;
	cout << "       ���� �����̳ʴ� ��ü������ �����͸� �Է��ϴ� ������ �����ϱ� ������ �ð��� �� �ɸ���. (�ε� Ÿ��)" << endl;
	cout << "       �����͸� ���������� �Է��ؾ��ϴ� ��찡 �ƴϸ鼭, ���� �����͸� �˻��� ���� ����մϴ�." << endl << endl;
}
#pragma endregion

int main()
{
	Test1();
	Test2();
	Test2_2();
	Test2_3();

	cout << endl << std::boolalpha << Find(8) << endl << endl;

	Test3();

	//FindByVector();
	//cout << endl;
	//FindByList();
	//cout << endl;
	//FindByDeque();
	//cout << endl;
	//FindBySet(); // ���� �����̳��� ���, �ڵ����� ������ �ϴ� ����� ������� (�۾� �ӵ� ������) | �׸��� Set(����)�� ������ �����͸� �ߺ��ؼ� �������� ���Ѵ�.
	//cout << endl;
}