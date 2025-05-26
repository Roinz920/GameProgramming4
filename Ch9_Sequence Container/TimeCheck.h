#pragma once

#include <iostream>
#include <chrono> // 시간과 관련된 헤더 (clock 기능)
#include <vector>
#include <list>

/*
*	vector와 list의 비교
* 
*	1. 임의의 데이터에 접근하는 시간을 비교한다.
*		
* 	   결과 : vector는 바로 임의의 데이터에 접근할 수 있다. (빠르다)			(0(1))
*			  List는 n번째 데이터에 접근하는데 길이에 비례해서 시간이 걸린다.	(Linear Time O(n))
*	2. 첫번째와 끝의 데이터가 아닌 데이터를 삭제 or 수정하는데 걸리는 시간
*	- 데이터를 자주 삭제 또는 수정하는 경우, Vector의 시간이 비효율적이다.
*	  ※ 1 ~ n 의 데이터 -> 1 ~ n-1 의 위치로 데이터를 옮기는 작업
* 
*	데이터를 지우거나, 변경하는 작업이 많으면 많을수록 vector가 시간적으로 비효율적이다.
*/

/*
*	(번외) 어떠한 자료구조를 사용해야할지 잘 모르겠다면, vector를 사용해볼 것 (더 빠름)
*	vector로 무엇을 했을 때에 시간이 더 오래 걸릴까?
*/
void TimeCheckTest()
{
	std::cout << "vector 기능 수행 소요시간 측정" << std::endl;
	auto Start = std::chrono::high_resolution_clock::now();
	//
	std::vector<int> nums;
	for (int i = 0; i < 100000; i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 10000; i++)
	{
		auto it = nums.begin() + 5;
		nums.erase(it); // n번째 데이터를 지우는 코드
	}
	//
	auto End = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;
}
void TimeCheckTest2()
{
	std::cout << "STL list 기능 수행 소요시간 측정" << std::endl;
	auto Start = std::chrono::high_resolution_clock::now();
	//
	std::list<int> nums;
	for (int i = 0; i < 100000; i++)
	{
		nums.push_back(i);
	}
	for (int i = 0; i < 10000; i++)
	{
		auto it = std::next(nums.begin(), 5);
		nums.erase(it); // n번째 데이터를 지우는 코드
	}
	//
	auto End = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;
}