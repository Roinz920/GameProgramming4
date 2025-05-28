#include "ConsoleUtility.h"

// 순차 컨테이너 Sequence Conatiner : vector, list, deque
// #include <컨테이너>

#include <vector>
#include <list>
#include <deque>

// 연관 컨테이너 associate Container : (multi, unordered) set, map | 6가지

#include <set>
#include <map>
#include <algorithm> // 컨테이너에 데이터를 처리하는 기능들이 저장되어있는 라이브러리

// 3단계. 갯수와, 중간 데이터 삭제를 비교하여 적합한 순차 컨테이너 사용하기

#pragma region (1)단계. 순차 컨테이너 데이터 입력 시간 비교
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
	cout << "데이터 입력 시간 비교" << endl;
	cout << "vector 소요 시간 : ";
	ConsoleUtil::TimeCheck(DataPushByVector);
	cout << "list   소요 시간 : ";
	ConsoleUtil::TimeCheck(DataPushByList);
	cout << "deque  소요 시간 : "; 
	ConsoleUtil::TimeCheck(DataPushByDeque);

	cout << "결과 : 단순 데이터 입력에는 vector가 가방 빠르다." << endl << endl;
}
#pragma endregion

#pragma region (2)단계. 순차 컨테이너 중간 데이터 입력 시간 비교

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
	cout << "중간 데이터 입력 시간 비교" << endl;
	cout << "vector 소요 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByVector);
	cout << "list   소요 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByList);
	cout << "deque  소요 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByDeque);
	cout << "결과 : 처음 데이터를 입력했을 때에는 vector가 빠르다 (1000회 반복)" << endl;
	cout << "결과 : 중간 삽입(삭제)하는 과정이 많으면 많을수록 list가 빨라질 수 있다." << endl << endl;
}
#pragma endregion

#pragma region (2-2)단계. 순차 컨테이너 데이터를 맨 앞에서 추가할 때 걸리는 시간 비교

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
	cout << "첫번째 데이터 입력 시간 비교" << endl;
	cout << "vector 소요 시간 : ";
	ConsoleUtil::TimeCheck(FrontPushByVector);
	cout << "list   소요 시간 : ";
	ConsoleUtil::TimeCheck(FrontPushByList);
	cout << "deque  소요 시간 : ";
	ConsoleUtil::TimeCheck(FrontPushByDeque);
	cout << "결과 : 첫번째 원소를 넣는 경우에 vector의 장점과 단점을 해결할 수 있다." << endl << endl;
}

#pragma endregion

#pragma region (2-3)단계. 순차 컨테이너에서 랜덤 원소 접근에 걸리는 시간 비교
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
	cout << "랜덤 위치에 데이터 접근 시간 비교" << endl;
	cout << "vector 소요 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessByVector);
	cout << "list   소요 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessByList);
	cout << "deque  소요 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessByDeque);
	cout << "결과 : 배열 형태의 자료구조(vector, deque)에서는 항상 데이터에 바로 접근이 가능하다." << endl;
	cout << "       list의 경우에는 시작과 거리가 멀면 멀수록 시간이오래 걸린다" << endl << endl;
}

#pragma endregion

#pragma region 순차 컨테이너 비교

/*
*		 |	Vector	|	List	|	Deque	|
* push	 |	1		|	3		|	2		|
* insert |	2		|	1		|	3		|
* front	 |	3		|	2t		|	1		|
* access |	1		|	3		|	2		|
*/

/*
*	Case1. 상황부여, 데이터의 입력이 (많이)발생하고, 중간 데이터 입력이 (적으며), 앞에 데이터(적으며), 랜덤 접근이 (많은) 경우
*/
#pragma endregion

#pragma region (3)단계. 순차 컨테이너와 연관 컨테이너

// 데이터를 저장하는 공간으로 컨테이너는 만들었다. -> 사용을 위해서는 찾아서 활용할 수 있어야한다.
// std::vector<monster> mon;  monster a = mon[?];
// 컨테이너 안에 해당하는 데이터가 없다면? 에러 발생 -> 예외조항 설정 필요. if(데이터가 존재하나요?) -> 실행; else() -> 데이터 없음;
bool Find(int value)
{
	int nums[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 10; i++)
	{
		if (nums[i] == value)
		{
			cout << nums[i] << " 값을 찾았습니다." << endl;
			return true;
		}
	}
	cout << "값을 찾지 못했습니다." << endl;
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
		std::find(nums.begin(), nums.end(), i); // 시작과 끝 사이에서 i라는 숫자를 찾아줘
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
	cout << "데이터 검색 시간 비교" << endl;
	cout << "vector 소요 시간 : ";
	ConsoleUtil::TimeCheck(FindByVector);
	cout << "list   소요 시간 : ";
	ConsoleUtil::TimeCheck(FindByList);
	cout << "deque  소요 시간 : ";
	ConsoleUtil::TimeCheck(FindByDeque);
	cout << "set    소요 시간 : ";
	ConsoleUtil::TimeCheck(FindBySet);
	cout << "결과 : 순차 컨테이너는 데이터를 입력하는데 빠르다." << endl;
	cout << "       연관 컨테이너는 자체적으로 데이터를 입력하는 로직이 존재하기 때문에 시간이 더 걸린다. (로딩 타임)" << endl;
	cout << "       데이터를 지속적으로 입력해야하는 경우가 아니면서, 자주 데이터를 검색할 때에 사용합니다." << endl << endl;
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
	//FindBySet(); // 연관 컨테이너의 경우, 자동으로 정렬을 하는 기능이 들어있음 (작업 속도 느려짐) | 그리고 Set(집합)은 동일한 데이터를 중복해서 저장하지 못한다.
	//cout << endl;
}