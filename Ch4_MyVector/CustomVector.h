#pragma once

/*
*	Vetor(�����迭)�� Ư¡
*	- ���α׷��� ����Ǵ� ���߿� ���̰� ���� �� �ִ�. ���� ũ�� ��ȯ�� �����ϴ�.	
*	- �ڵ����� ũ�Ⱑ ����ȴ�.	
* 
*	int arr[20];
*/

/*
* int size ũ��;
* int capacity ���뷮;
* 
* int arr = new int[5];	size�� 0, capacity�� 5.
* size 6�� int[6]; ��� �Ұ�
* arr = new int[10];�� ���� ��������� �÷��� ��
* 
* ��, resize(); �Լ� �ʿ�
* �� int size, int capacity�� �ʿ�
*/


template<typename T>
class MyVector
{
private:
	int size;						
	int capacity;					
	T* vec;	// �迭�� ù��° �ּ�	
public:
	// ������
	MyVector() = default;
	MyVector(int startsize)
	{
		vec = new T[startsize];
		size = 0;
		capacity = startsize;
	}
	//�Ҹ���
	~MyVector()
	{
		delete[] vec;
	}



	T& operator[](int idx)
	{
		return vec[idx];
	}
	void resize(int newsize)
	{
		// size : ���� �迭�� ����ִ� ������ ����
		// newsize : �����Ϸ��� �������� ũ��
		if (size < newsize)
		{
			size = size;
		}
		else
		{
			size = newsize;
		}
		capacity = newsize;
		T* arr = new T[newsize];
		for (int i = 0; i < size; i++)
		{
			arr[i] = vec[i];
		}
		delete[] vec;	// ������ vec�� ����Ű�� �ִ� ������ �޸𸮸� �����Ѵ�.
		vec = arr;		// vec�� ���ο� ������ �����Ѷ� ��� ��
	}
	void push_back(const T& element)
	{
		if (capacity <= size)
		{
			capacity = capacity * 2;
			resize(capacity);
		}
		vec[size] = element;
		size++;
	}
	void pop_back()
	{
		size = size > 0 ? size - 1 : 0; // size�� 0���� ũ�� 1�� ���ҽ�Ű��, �װ� �ƴ϶�� 0���� �����϶�
	}

	size_t Size() const
	{
		return size;
	}

};

void test1()
{
	while (true)
	{
		MyVector<int>* myVec = new MyVector<int>(10);
		delete myVec;
	}
}

void test2()
{
	MyVector<int> vec(5);
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i + 1);
		std::cout << vec[i] << " ";
	}
	vec.push_back(6);
	cout << endl;

	for (int i = 0; i < vec.Size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	MyVector<double> vec2(5);
	for (int i = 0; i < 5; i++)
	{
		vec2.push_back(i + 0.1);
		std::cout << vec2[i] << " ";
	}

}