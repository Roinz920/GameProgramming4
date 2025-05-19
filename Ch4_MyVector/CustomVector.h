#pragma once

/*
*	Vetor(가변배열)의 특징
*	- 프로그램이 실행되는 도중에 길이가 변할 수 있다. 동적 크기 변환이 가능하다.	
*	- 자동으로 크기가 변경된다.	
* 
*	int arr[20];
*/

/*
* int size 크기;
* int capacity 수용량;
* 
* int arr = new int[5];	size는 0, capacity는 5.
* size 6인 int[6]; 사용 불가
* arr = new int[10];를 통해 저장공간을 늘려야 함
* 
* 즉, resize(); 함수 필요
* └ int size, int capacity가 필요
*/


template<typename T>
class MyVector
{
private:
	int size;						
	int capacity;					
	T* vec;	// 배열의 첫번째 주소	
public:
	// 생성자
	MyVector() = default;
	MyVector(int startsize)
	{
		vec = new T[startsize];
		size = 0;
		capacity = startsize;
	}
	//소멸자
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
		// size : 현재 배열에 들어있는 원소의 숫자
		// newsize : 변경하려는 사이즈의 크기
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
		delete[] vec;	// 기존에 vec가 가리키고 있는 공간의 메모리를 해제한다.
		vec = arr;		// vec가 새로운 공간을 가르켜라 라는 뜻
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
		size = size > 0 ? size - 1 : 0; // size가 0보다 크면 1을 감소시키고, 그게 아니라면 0으로 설정하라
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