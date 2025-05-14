/*
*	�ڷ� ����
*	- �Ϲ�ȭ ���α׷��� (Generic Programming)
*	- '�Ϲ����̴�'��� �ǹ� : � Ÿ���̵� ��� ����� �� �ִ� �������� �ڵ�
* 
*	�������� T,N,Q ������ ���ε�, ��ǻ�Ͱ� ��� �������� �� �� �ֵ��� Ű���带 ����ؾ� �Ѵ�.
* 
*	���ſ��� ��� �Ϲ�ȭ ���α׷����� ������?
*	- Macro�� �Ϲ�ȭ ���α׷��� �ۼ��ϴ� ���� �����մϴ�. (������ üũ�� �������� �ʱ� ������ ����õ)
*/

/*
*	legacy �ڵ带 �а�, ���� �ڵ����� ������ �� �ִ°� �߿�.
*	�� ���� ��
*	1. �ǵ����� ���� ����� �߻��� �� �ִ�.
*	2. ������ üũ�� �������� �ʴ´�.
*/

/*
*	������ Ÿ��	(compile time)	: ������ �ϴ� ����. ��ǻ�Ͱ� �� �����ؼ� �����ϴ� ����. ����� �����ϴ� �ܰ踦 ��ģ��.
*	�� Ÿ��		(run time)		: ���α׷��� �����ϴ� ����.
*/

/*
*	template Ű����
*	<Type���� ���� �̸�>
*	Ÿ�� ��ü�� �޾ƿ��� Ű���� : typename, class
*	��Ÿ�Կ��� ����ϴ� class�� ��ü�� �����Ҷ� ���� class�� �ڵ常 ���� �ٸ� �����
*/


/*
*	Ÿ�� �߷� : �����Ϸ� �� �� �ڵ带 ����, ��õ��� ���� Ÿ���� �����ϴ� ��

	auto �̸� = 10; �� �ڵ����� Ÿ���� �߷��Ͽ� �������� 10�� ������ int �̸� = 10;���� �ν�
*/
#include <iostream>
#define Max(a,b) ((a>b) ? a : b) // (a>b)�� ���� true�̸� a��ȯ, �ƴ϶�� b��ȯ
#define Square(a) a*a;

template<typename T1>
T1 MaxFunc(T1 a, T1 b)
{
	return (a > b) ? a : b;
}

template<typename T1, typename T2>
void Func(T1 a, T2 name)
{
	std::cout << "No." << a << " " << name << std::endl;
}

template<int N>
void Func2()
{
	std::cout << N << std::endl;
}

template<int N, typename T>
void Func3()
{
	for (int i = 0; i < N; i++)
	{
		std::cout << typeid(T).name() << std::endl;
	}
}

template<typename T>
T Min(T a, T b)
{
	return (a < b) ? a : b;
}

template<class T>
T Multiply(T a, T b)
{
	return a * b;
}

struct PocketMon
{
	int age;
	std::string name;

	bool operator<(const PocketMon& other)
	{
		return this->age < other.age;
	}
};

struct person
{
	int age;
	std::string name;

	bool operator<(const person& other)
	{
		return this->age < other.age;
	}
};

// person ��ü�� ���� �迭�� �䳻 �� Ŭ����
template<int N>
class people
{
private:
	int size = N;			// N�� ũ�⸦ �Ϲ�ȭ �ϱ� ����
	person HumanInCity[10];

public:
	//������ �����ε��� ���� �迭����� �䳻
	person& operator[](int index)
	{
		return HumanInCity[index];
	}

	void at(int index)
	{
		// person �迭�� n��°�� �����ϴ� ���
		std::cout << "����: " << HumanInCity[index].age << " | �̸� : " << HumanInCity[index].name << std::endl;
	}
};



template <int N, typename T>
class Array
{
private:
	int size = N;
	T value[N];
public:
	T& operator[](int index)
	{
		return value[index];
	}

	T& at(int index)
	{
		return value[index];
	}

};

/*
*	�ڷ� �������� �ڽ��ؾ��� ��
*	������ ����
*	�����͸� ����
*	�����̳� ���� ������� ����
* 
*	�迭�� ��/����
*	Ư¡ : ũ�Ⱑ �����Ǿ��ִ�.
*	���� : ������ ��Ģ�� ���������� ������ �� �־ �����ϰ�, ������.
*	���� : ũ�Ⱑ �����Ǿ��־� ����� �Ѱ谡 �ִ�. 
	ex.) ��Ƽ �ý��� - �Ϲݴ��� - ��Ƽ�� 4�� �� ������Ʈ�� ���̵� �߰� - ��Ƽ�� 8�� (��Ƽ �ý����� ���ƾ���߰���?) 
		| �Ұ����� ���� �ƴϴ�! ������ �迭�� ũ�⸦ �����ϴ°� ��� ����� ũ�� (�迭�� 8�� ó�� ���� ���̶�� �𸣰����� 1000�� ������ ��쿡��...)
*/

void Ex1()
{
	int result1 = Max(5, 1);	// ((5>1)?5:1)
	double result2 = Max(1.1, 2.2); // ( (1.1 > 2.2) ? 1.1:2.2 )
	int result3 = 100 / Square(5); // ���� ��� ���� : 100/5*5
	std::cout << result1 << std::endl;
	std::cout << result2 << std::endl;
	std::cout << result3 << std::endl;

	std::cout << MaxFunc<int>(1.2, 2.4) << std::endl;
	std::cout << MaxFunc(0.1, 0.2) << std::endl;

	// Ÿ�� �߷�
	std::cout << MaxFunc(1.2, 2.4) << std::endl;

	Func<int, std::string>(25, "��ī��");

	Func2<5>();

	Func3<5, int>();

	std::cout << std::endl << "Min ����" << std::endl;
	std::cout << Min(2, 4) << std::endl;
	std::cout << Min('a', 'b') << std::endl;

	std::cout << std::endl << "Multiply ����" << std::endl;
	std::cout << Multiply(2, 4) << std::endl;
	std::cout << Multiply(1.1, 2.2) << std::endl;
}

int main()
{
	// �Լ� ���ø� ����
	//Ex1();	
	//���� ����
	person p1{ 10,"A" };
	person p2{ 20,"B" };
	person p3 = Min<person>(p1, p2);
	std::cout << p3.name << "�� ���̰� " << p3.age << "�� �̹Ƿ� �� ���" << std::endl;

	people<5> Busan;
	Busan[0] = { 15, "�念��" };
	Busan.at(0);
	Busan[1] = { 53, "�̼���" };
	Busan.at(1);

	std::cout << std::endl << "���� ���� �迭 Ŭ���� ����" << std::endl;
	Array<5, person> Seoul;
	Seoul[0] = { 52, "�������" };
	Seoul.at(1) = { 72, "�豸" };

	std::cout << Seoul[0].name << std::endl;
	std::cout << Seoul[1].name << std::endl;

	std::cout << Seoul.at(0).name << std::endl;
	std::cout << Seoul.at(1).name << std::endl;


	Array<10, PocketMon> MyPocketmons;
	MyPocketmons[0] = { 1, "�̻��ؾ�" };
	MyPocketmons.at(1) = {25, "��ī��"};

	std::cout << MyPocketmons[0].name << std::endl;
	std::cout << MyPocketmons.at(1).name << std::endl;
	
	MyPocketmons.at(11) = { 4, "���̸�" };
	std::cout << MyPocketmons[11].name << std::endl;

}
