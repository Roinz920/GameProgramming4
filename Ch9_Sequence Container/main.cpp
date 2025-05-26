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
*	(목표) Vector와 List의 차이점을 직접 비교
*	1. vector push_back 추가, List push_back 추가 한 시간을 비교.	: vector가 더 빠르다
*	2. 임의의 데이터에 접근하는데 걸리는 시간						: List가 더 빠르다
* 
*	데이터가 삭제는 적은데, 접근이 많은 경우 : vector가 유리
*	데이터 삭제가 빈번한 경우 : list가 유리
*
*	(★★★★★)데이터 삭제도 많고, 접근고 많은 경우 : unordered_map

	vector
	unordered_map
*/

/*
*	Vector, List 크게 차이점은 없다. 단,
*	Vector	[] 인덱스로 데이터 출력할 수 없다.
*	List	[] 인덱스로 접근할 수 없다.	
* 
*	차이점을 눈으로 확인하기 위해서 환경 설정을 진행.
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
	std::cout << "임의 데이터 접근 소요 시간" << std::endl;
	std::cout << nums[900] << std::endl;

	// erase함수를 n번 사용하는 예제
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
	std::cout << "임의 데이터 접근 소요 시간" << std::endl;
	auto it = std::next(nums.begin(), 900);
	std::cout << *it << std::endl;
	
	// erase함수를 n번 사용하는 예제
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
	
	// 자료구조 시간 테스트
	//TimeCheckTest();
	//TimeCheckTest2();

	// 함수 포인터 테스트
	//Test_FP();

	//
	ConsoleUtil::TimeCheck(VectorExample);
	ConsoleUtil::TimeCheck(ListExample);
}