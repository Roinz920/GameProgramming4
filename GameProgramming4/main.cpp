/*
*	자료 구조 (Data Structure)
*	
*	Data		: 게임에 등장하는 정보. 컴퓨터가 해석할 수 있도록 작성한 것
*	Structure	: 구조, 설계 - 생산성, 안정성
* 
*	데이터를 설계해야하는 이유?
*	STL (Standard Tamplate Library) - 표준 템플릿 라이브러리
*	표준 : 신용할 수 있는 기준. 대중적으로 많이 사용된다.
*	템플릿 : 일반화 프로그래밍을 구현하기 위한 문법		// 일반화 프로그래밍 - 타입에 상관없이 사용할 수 있는 문법들 (이지만 신용할 수 있음)
*	라이브러리 : 만들어진 함수, 클래스
* 
*	컨테이너 : 특정한 목적에 따라 모아놓은 객체(Class)
*	알고리즘 : 컨테이너 안에 있는 데이터를 사용하는 함수 라이브러리
*	반복자 : 알고리즘 코드를 용이하게 사용하기 위한 문법 (알고리즘에 적용된 반복문을 아주 쉽게 사용할수 있게 해주는 문법임)
*/

/*
*	array, vectore, list, stack, queue, priority queue, hash-set, map
*	어떤 경우에 무엇을 사용해야 하는가?
*/

#include "Common.h"
#include "Template.h"
#include "Sample.h"

int main()
{
	cout << "자료 구조 에제" << endl;

	std::vector<int> nums = { 1,5,3, 10, 2, 4 };	//정수형 데이터 3개를 저장하고있는 'nums' vector
	
	// 데이터 출력1. 1,5,3
	cout << endl << "데이터 출력1 " << endl;
	for (auto& num : nums)
	{
		cout << num << " ";
	}

	std::sort(nums.begin(), nums.end()); //데이터를 정렬한다.
	
	// 데이터 출력2. 1,3,5
	cout << endl << "데이터 출력2 " << endl;
	for (auto& num : nums)	// 'nums'안에 있는 데이터 타입 개별요소들 모두를 실행하라
	{
		cout << num << " ";
	}

	
	cout << endl << endl << "템플릿 에제" << endl;

	int num = Add<int>(2, 5);
	cout << num << endl;
	int num1 = Add(1, 4);
	cout << num1 << endl;
	double num2 = Add(2.3, 3.4);
	cout << num2 << endl;
	char num3 = Add( 'b', 'a');
	cout << num3 << endl;

	Example1();
}