#pragma once

#include <iostream>
#include <chrono> // �ð��� ���õ� ��� (clock ���)
#include <vector>
#include <list>

/*
*	vector�� list�� ��
* 
*	1. ������ �����Ϳ� �����ϴ� �ð��� ���Ѵ�.
*		
* 	   ��� : vector�� �ٷ� ������ �����Ϳ� ������ �� �ִ�. (������)			(0(1))
*			  List�� n��° �����Ϳ� �����ϴµ� ���̿� ����ؼ� �ð��� �ɸ���.	(Linear Time O(n))
*	2. ù��°�� ���� �����Ͱ� �ƴ� �����͸� ���� or �����ϴµ� �ɸ��� �ð�
*	- �����͸� ���� ���� �Ǵ� �����ϴ� ���, Vector�� �ð��� ��ȿ�����̴�.
*	  �� 1 ~ n �� ������ -> 1 ~ n-1 �� ��ġ�� �����͸� �ű�� �۾�
* 
*	�����͸� ����ų�, �����ϴ� �۾��� ������ �������� vector�� �ð������� ��ȿ�����̴�.
*/

/*
*	(����) ��� �ڷᱸ���� ����ؾ����� �� �𸣰ڴٸ�, vector�� ����غ� �� (�� ����)
*	vector�� ������ ���� ���� �ð��� �� ���� �ɸ���?
*/
void TimeCheckTest()
{
	std::cout << "vector ��� ���� �ҿ�ð� ����" << std::endl;
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
		nums.erase(it); // n��° �����͸� ����� �ڵ�
	}
	//
	auto End = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;
}
void TimeCheckTest2()
{
	std::cout << "STL list ��� ���� �ҿ�ð� ����" << std::endl;
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
		nums.erase(it); // n��° �����͸� ����� �ڵ�
	}
	//
	auto End = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;
}