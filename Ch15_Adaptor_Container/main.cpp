/*
*	adapt : �����ϴ�, �����ϴ�
*	adapt �����̳�
*	(Vector, List, Deque) ������� Ư���� �����̳�
* 
*	stack, queue, priority_queue
*	����, ť, �켱���� ť
*/
#include <iostream>

#pragma region ����
/*
*	�޸� ������ LIFO�̴�. (Last In First Out)
*	�����͸� ����ϴ� ��Ģ�� �����ϴ� ������ ȿ���� ��� �ڷᱸ�� (����� ����)
*	�� Iterator�� �������� �ʴ´�.(���������� iterator Ŭ������ ���ٴ� ��)
*	Ctrl + z (histroy - Ư�� ��ġ�� ���ư� �� �ִ�.)
*/
#include <stack>

void Test1()
{
	std::cout << "���� ��� ����" << std::endl;
	std::stack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}
	//	iterator�� �������� �ʱ� ������, ���� ��� for loop�� ����� �� ����
	//	for (const auto& num : nums)
	//	{	std:: cout << num << " "; 	}
	
	while (!nums.empty())
	{
		std::cout << nums.top() << " ";	// ���� ���� �ִ� ��(ù��° ��)�� ���
		nums.pop();						// ���� ���� �ִ� ���� Ƣ������� ��(����)
	}
	std::cout << std::endl << std::endl;
}
#pragma endregion

#pragma region ť
/*
*	�޸� ������ FIFO�̴�. (First In First Out)
*/

#include <queue>
void Test2()
{
	std::cout << "ť ��� ����" << std::endl;
	std::queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	while (!nums.empty())
	{
		std::cout << nums.front() << " ";	// ���� �տ� �ִ� ���� ���
		nums.pop();							// ���� �տ� �ִ� ���� Ƣ������� ��(����)
	}
	std::cout << std::endl << std::endl;
}
#pragma endregion

#pragma region �켱����ť
// ť : ���� ������� ������(FIFO). | ���� �������� ����� ���� ������.
// ��� - �Ϲ� �ʴ��, Ư�� �ʴ��
// �ð�, ��
// �� �Ȱ��� �ð��� ���� ��, ���� ���� ����� �켱���� �����ٸ� ť�� ó���ϸ� ����������, VIP ��� ���� ���� �ʿ��ϸ� �켱���� ť ���

// #include<queue>�� ���� ��
// heap �˰������� �����Ǿ��ִ�. / ���� ����(or ū) �� Ʈ�� ������ �� ���� ������ ���� (heapify)
void Test3()
{
	std::cout << "�켱���� ť ��� ����" << std::endl;
	std::priority_queue<int> nums;

	nums.push(0);
	nums.push(5);
	nums.push(7);
	nums.push(3);
	nums.push(9);
	
	while (!nums.empty())
	{
		std::cout << nums.top() << " ";		// ���� ���� �ִ� ���� ���
		nums.pop();							// ���� ���� �ִ� ���� Ƣ������� ��(����)
	}
	std::cout << std::endl << std::endl;
}

#pragma endregion

#pragma region ���� ���� ť
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
	std::cout << "���� ���� ť ��� ����" << std::endl;
	MyQueue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	while (!nums.empty())
	{
		std::cout << nums.front() << " ";	// ���� �տ� �ִ� ���� ���
		nums.pop();							// ���� �տ� �ִ� ���� Ƣ������� ��(����)
	}
	std::cout << std::endl << std::endl;
}

#pragma endregion
#pragma region ���� ���� ����
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
	std::cout << "���� ���� ���� ��� ����" << std::endl;
	MyStack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	while (!nums.empty())
	{
		std::cout << nums.top() << " ";		// ���� ���� �ִ� ���� ���
		nums.pop();							// ���� ���� �ִ� ���� Ƣ������� ��(����)
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