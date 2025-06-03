/*
*	adapt : 적용하다, 응용하다
*	adapt 컨테이너
*	(Vector, List, Deque) 만들어진 특별한 컨테이너
* 
*	stack, queue, priority_queue
*	스택, 큐, 우선수위 큐
*/
#include <iostream>

#pragma region 스택
/*
*	메모리 구조가 LIFO이다. (Last In First Out)
*	데이터를 사용하는 규칙을 제한하는 것으로 효율을 얻는 자료구조 (공통된 사항)
*	→ Iterator를 지원하지 않는다.(내부적으로 iterator 클래스가 없다는 뜻)
*	Ctrl + z (histroy - 특정 위치로 돌아갈 수 있다.)
*/
#include <stack>

void Test1()
{
	std::cout << "스택 사용 예시" << std::endl;
	std::stack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}
	//	iterator를 지원하지 않기 때문에, 범위 기반 for loop를 사용할 수 없음
	//	for (const auto& num : nums)
	//	{	std:: cout << num << " "; 	}
	
	while (!nums.empty())
	{
		std::cout << nums.top() << " ";	// 제일 위에 있는 것(첫번째 것)을 출력
		nums.pop();						// 제일 위에 있는 것을 튀어오르게 함(삭제)
	}
	std::cout << std::endl << std::endl;
}
#pragma endregion

#pragma region 큐
/*
*	메모리 구조가 FIFO이다. (First In First Out)
*/

#include <queue>
void Test2()
{
	std::cout << "큐 사용 예시" << std::endl;
	std::queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	while (!nums.empty())
	{
		std::cout << nums.front() << " ";	// 제일 앞에 있는 것을 출력
		nums.pop();							// 제일 앞에 있는 것을 튀어오르게 함(삭제)
	}
	std::cout << std::endl << std::endl;
}
#pragma endregion

#pragma region 우선순위큐
// 큐 : 들어온 순서대로 나간다(FIFO). | 먼저 나가야할 사람이 먼저 나간다.
// 사람 - 일반 초대권, 특별 초대권
// 시간, 돈
// 다 똑같은 시간에 왔을 때, 먼저 들어온 사람이 우선권을 가진다면 큐로 처리하면 가능하지만, VIP 기능 같은 것이 필요하면 우선순위 큐 사용

// #include<queue>에 포함 됨
// heap 알고리즘으로 구현되어있다. / 가장 작은(or 큰) 값 트리 구조의 맨 위로 보내는 형태 (heapify)
void Test3()
{
	std::cout << "우선순위 큐 사용 예시" << std::endl;
	std::priority_queue<int> nums;

	nums.push(0);
	nums.push(5);
	nums.push(7);
	nums.push(3);
	nums.push(9);
	
	while (!nums.empty())
	{
		std::cout << nums.top() << " ";		// 제일 위에 있는 것을 출력
		nums.pop();							// 제일 위에 있는 것을 튀어오르게 함(삭제)
	}
	std::cout << std::endl << std::endl;
}

#pragma endregion

#pragma region 직접 만든 큐
template<typename T>
class MyQueue
{
private:
	int _size;
	std::deque<T> data;
public:
	MyQueue() : _size(0) {}
	void push(T& e)
	{
		_size++;
		data.push_back(e);
	}
	T front()
	{
		return data[0];
	}
	void pop()
	{
		_size--;
		data.pop_front();
	}
	int size()
	{
		return _size;
	}
	bool empty()
	{
		return _size == 0;
	}
};

void Test4()
{
	std::cout << "직접 만든 큐 사용 예시" << std::endl;
	MyQueue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	while (!nums.empty())
	{
		std::cout << nums.front() << " ";	// 제일 앞에 있는 것을 출력
		nums.pop();							// 제일 앞에 있는 것을 튀어오르게 함(삭제)
	}
	std::cout << std::endl << std::endl;
}

#pragma endregion
#pragma region 직접 만든 스택
template<typename T>
class MyStack
{
private:
	int _size;
	std::vector<T> data;
public:
	MyStack() : _size(0) {}
	void push(T& e)
	{
		_size++;
		data.push_back(e);
	}
	T top()
	{
		return data[_size - 1];
	}
	void pop()
	{
		_size--;
		data.pop_back();
	}
	int size()
	{
		return _size;
	}
	bool empty()
	{
		return _size == 0;
	}
};

void Test5()
{
	std::cout << "직접 만든 스택 사용 예시" << std::endl;
	MyStack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	while (!nums.empty())
	{
		std::cout << nums.top() << " ";		// 제일 위에 있는 것을 출력
		nums.pop();							// 제일 위에 있는 것을 튀어오르게 함(삭제)
	}
	std::cout << std::endl << std::endl;
}
#pragma endregion

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
}