/*
*	�ڷ� ���� (Data Structure)
*	
*	Data		: ���ӿ� �����ϴ� ����. ��ǻ�Ͱ� �ؼ��� �� �ֵ��� �ۼ��� ��
*	Structure	: ����, ���� - ���꼺, ������
* 
*	�����͸� �����ؾ��ϴ� ����?
*	STL (Standard Tamplate Library) - ǥ�� ���ø� ���̺귯��
*	ǥ�� : �ſ��� �� �ִ� ����. ���������� ���� ���ȴ�.
*	���ø� : �Ϲ�ȭ ���α׷����� �����ϱ� ���� ����		// �Ϲ�ȭ ���α׷��� - Ÿ�Կ� ������� ����� �� �ִ� ������ (������ �ſ��� �� ����)
*	���̺귯�� : ������� �Լ�, Ŭ����
* 
*	�����̳� : Ư���� ������ ���� ��Ƴ��� ��ü(Class)
*	�˰��� : �����̳� �ȿ� �ִ� �����͸� ����ϴ� �Լ� ���̺귯��
*	�ݺ��� : �˰��� �ڵ带 �����ϰ� ����ϱ� ���� ���� (�˰��� ����� �ݺ����� ���� ���� ����Ҽ� �ְ� ���ִ� ������)
*/

/*
*	array, vectore, list, stack, queue, priority queue, hash-set, map
*	� ��쿡 ������ ����ؾ� �ϴ°�?
*/

#include "Common.h"
#include "Template.h"
#include "Sample.h"

int main()
{
	cout << "�ڷ� ���� ����" << endl;

	std::vector<int> nums = { 1,5,3, 10, 2, 4 };	//������ ������ 3���� �����ϰ��ִ� 'nums' vector
	
	// ������ ���1. 1,5,3
	cout << endl << "������ ���1 " << endl;
	for (auto& num : nums)
	{
		cout << num << " ";
	}

	std::sort(nums.begin(), nums.end()); //�����͸� �����Ѵ�.
	
	// ������ ���2. 1,3,5
	cout << endl << "������ ���2 " << endl;
	for (auto& num : nums)	// 'nums'�ȿ� �ִ� ������ Ÿ�� ������ҵ� ��θ� �����϶�
	{
		cout << num << " ";
	}

	
	cout << endl << endl << "���ø� ����" << endl;

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