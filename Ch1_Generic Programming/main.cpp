/*
*	자료 구조
*	- 일반화 프로그래밍 (Generic Programming)
*	- '일반적이다'라는 의미 : 어떤 타입이든 모두 사용할 수 있는 범용적인 코드
* 
*	변수들을 T,N,Q 선언할 것인데, 컴퓨터가 어떠한 형태인지 알 수 있도록 키워드를 사용해야 한다.
* 
*	과거에는 어떻게 일반화 프로그래밍을 했을까?
*	- Macro로 일반화 프로그래밍 작성하는 것은 지양합니다. (컴파일 체크를 지원하지 않기 때문에 비추천)
*/

/*
*	legacy 코드를 읽고, 옛날 코드임을 인지할 수 있는게 중요.
*	※ 단점 ※
*	1. 의도하지 않은 결과가 발생할 수 있다.
*	2. 컴파일 체크를 지원하지 않는다.
*/

/*
*	컴파일 타임	(compile time)	: 컴파일 하는 시점. 컴퓨터가 언어를 번역해서 전달하는 시점. 어류를 검증하는 단계를 거친다.
*	런 타임		(run time)		: 프로그램이 시작하는 시점.
*/

/*
*	template 키워드
*	<Type지정 변수 이름>
*	타입 자체를 받아오는 키워드 : typename, class
*	※타입에서 사용하는 class랑 객체를 생성할때 쓰는 class는 코드만 같은 다른 기능임
*/


/*
*	타입 추런 : 컴파일러 앞 뒤 코드를 보고, 명시되지 않은 타입을 유추하는 것

	auto 이름 = 10; → 자동으로 타입을 추론하여 정수형의 10과 동일한 int 이름 = 10;으로 인식
*/
#include <iostream>
#define Max(a,b) ((a>b) ? a : b) // (a>b)의 값이 true이면 a반환, 아니라면 b반환
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

// person 객체를 위해 배열을 흉내 낸 클래스
template<int N>
class people
{
private:
	int size = N;			// N의 크기를 일반화 하기 위함
	person HumanInCity[10];

public:
	//연산자 오버로딩을 통해 배열기능을 흉내
	person& operator[](int index)
	{
		return HumanInCity[index];
	}

	void at(int index)
	{
		// person 배열의 n번째에 접근하는 기능
		std::cout << "나이: " << HumanInCity[index].age << " | 이름 : " << HumanInCity[index].name << std::endl;
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
*	자료 구조에서 자습해야할 것
*	데이터 선언
*	데이터를 저장
*	컨테이너 마다 장단점이 존재
* 
*	배열의 장/단점
*	특징 : 크기가 고정되어있다.
*	장점 : 정해진 규칙을 문법적으로 제한할 수 있어서 안전하고, 빠르다.
*	단점 : 크기가 고정되어있어 생기는 한계가 있다. 
	ex.) 파티 시스템 - 일반던전 - 파티원 4명 → 업데이트로 레이드 추가 - 파티원 8명 (파티 시스템을 갈아엎어야겠지?) 
		| 불가능한 것은 아니다! 하지만 배열의 크기를 변경하는게 드는 비용이 크다 (배열이 8개 처럼 적은 것이라면 모르겠지만 1000개 단위일 경우에는...)
*/

void Ex1()
{
	int result1 = Max(5, 1);	// ((5>1)?5:1)
	double result2 = Max(1.1, 2.2); // ( (1.1 > 2.2) ? 1.1:2.2 )
	int result3 = 100 / Square(5); // 실제 계산 방향 : 100/5*5
	std::cout << result1 << std::endl;
	std::cout << result2 << std::endl;
	std::cout << result3 << std::endl;

	std::cout << MaxFunc<int>(1.2, 2.4) << std::endl;
	std::cout << MaxFunc(0.1, 0.2) << std::endl;

	// 타입 추론
	std::cout << MaxFunc(1.2, 2.4) << std::endl;

	Func<int, std::string>(25, "피카츄");

	Func2<5>();

	Func3<5, int>();

	std::cout << std::endl << "Min 예제" << std::endl;
	std::cout << Min(2, 4) << std::endl;
	std::cout << Min('a', 'b') << std::endl;

	std::cout << std::endl << "Multiply 예제" << std::endl;
	std::cout << Multiply(2, 4) << std::endl;
	std::cout << Multiply(1.1, 2.2) << std::endl;
}

int main()
{
	// 함수 템플릿 예제
	//Ex1();	
	//보충 예제
	person p1{ 10,"A" };
	person p2{ 20,"B" };
	person p3 = Min<person>(p1, p2);
	std::cout << p3.name << "의 나이가 " << p3.age << "살 이므로 더 어리다" << std::endl;

	people<5> Busan;
	Busan[0] = { 15, "장영실" };
	Busan.at(0);
	Busan[1] = { 53, "이순신" };
	Busan.at(1);

	std::cout << std::endl << "직접 만든 배열 클래스 예제" << std::endl;
	Array<5, person> Seoul;
	Seoul[0] = { 52, "세종대왕" };
	Seoul.at(1) = { 72, "김구" };

	std::cout << Seoul[0].name << std::endl;
	std::cout << Seoul[1].name << std::endl;

	std::cout << Seoul.at(0).name << std::endl;
	std::cout << Seoul.at(1).name << std::endl;


	Array<10, PocketMon> MyPocketmons;
	MyPocketmons[0] = { 1, "이상해씨" };
	MyPocketmons.at(1) = {25, "피카츄"};

	std::cout << MyPocketmons[0].name << std::endl;
	std::cout << MyPocketmons.at(1).name << std::endl;
	
	MyPocketmons.at(11) = { 4, "파이리" };
	std::cout << MyPocketmons[11].name << std::endl;

}
