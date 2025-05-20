#include "ConsoleUtility.h"
#include "algo.h"

/*
*	int 타입의 데이터를 저장하는  vector 클래스를 만들어서 1,2,3,4,5를 저장해보시오
*/

/*
*	iterator (반복기)
*	포인터의 역할을 하는 클래스.
*	자료 구조::iterator 라고 하면 접근 가능
*/

/*
*	iterator를 사용해서 자료구조의 element를 출력할 수 있다.
*	begin()	, cbegin()	, rbegin()	, crbegin()
*	end()	, cend()	, rend()	, crend()
*/

// iterator 기본 사용방법
void test1()
{
	vector<int> nums = { 1,2,3,4,5 };
	std::list<int> intlist = { 1,2,3,4,5 };
	std::vector<int>::iterator it = nums.begin();

	cout << "iterator 반복문을 활용한 자료구조 전체 데이터 출력" << endl;
	while (it != nums.end()) // iterator를 통한 vector의 값이 end값이 아닐때 까지 반복하라
	{
		std::cout << *it << " "; // iterator에 저장된 주소의 값을 역참조해서 출력하라.
		it++;
	}
	cout << endl;
	cout << "for 반복문을 활용한 자료구조 전체 데이터 출력" << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}

	// vector가 아닌 자료구조에서의 데이터를 순회, 사용
	std::list<int>::iterator it2 = intlist.begin();
	cout << endl;
	cout << "list를 활용한 자료구조 전체 데이터 출력" << endl;
	while (it2 != intlist.end()) // iterator를 통한 vector의 값이 end값이 아닐때 까지 반복하라
	{
		std::cout << *it2 << " "; // iterator에 저장된 주소의 값을 역참조해서 출력하라.
		it2++;
	}
	cout << endl;
}

// 역순으로 출력하는 방법
void test2()
{
	cout << "====================================================" << endl;
	vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	std::list<int> list1 = { 2,4,6,7,8,9 };
	// vector<int>::reverse_iterator 가 클래스 이름을 뜻함. 자동추론 기능인 auto로 실행하여도 동일하게 작동함
	// vector<int>::reverse_iterator it = vec.rbegin();
	auto it = vec.rbegin();
	auto it2 = list1.rbegin();

	while (it != vec.rend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	cout << "list를 역순으로 출력" << endl;
	while (it2 != list1.rend())
	{
		cout << *it2 << " ";
		it2++;
	}
}

// auto 키워드
void test3()
{
	cout << "====================================================" << endl;

	// 예시 1
	auto x = 5;

	// 예시2. 언제 사용하면 좋은가? -> 타입의 이름이 매우 긴 예제들
	std::vector<int> nums = { 1,2,3,4,5 };
	auto it = nums.begin();

	// 주의할 사항 : 대입 연산자 오른쪽에 오는 value가 불특정한 데이터일 때에 사용하지 않을 것

	// 예시3.
	
	// 데이터 자료형이 매우 작을 때에 사용

	/*
	*	auto		: int, double primitive type 사용할 때에 편하게 사용 (복사해서 만들어진다)
	*	auto&		: 메모리에 접근해서 데이터를 변경할 수 있다.
	*	const auto&	: 메모리 데이터를 문법적으로 변경하지 못하게 한다.
	*/
	for (auto num : nums)
	{
		num = 0;
	}
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	// 출력값 : 1,2,3,4,5
	cout << endl;
	for (auto& num : nums)
	{
		num = 0;
	}	
	for (auto num : nums)
	{
		cout << num << " ";
	}
	// 출력값 : 0,0,0,0,0
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
	
	auto start = vec.begin() + 2;	// 3번째 element를 가리키고 있다.
	auto finish = vec.end() - 3;	// 뒤에서 4번째 elemnt를 가리키고 있다.

	while (start != finish)
	{
		cout<< *start << " ";
		start++;
	}
	// 출력값 3,4,5,6
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