#include "ConsoleUtility.h"
/*
*	목표 : 배열의 크기를 수동으로 변경하는 코드를 만든다
*
*			"자동" vector
*/

/*
*	int 10개 배열로 저장
*	배열의 특징 : 크기가 고정. 만들 때 크기를 정해줘야 한다. 40byte의 공간을 확보해야 함
*	만약 41byte 떨어진 공간에서 메모리를 접근한다면 -> 문제 발생
*/

//	배열의 크기를 N으로 받을 수 있게 코드를 추가해보기

/*
*	vector 클래스의 기능
*	
*	push_back		: 벡터의 끝에 데이터를 추가한다. (이미 존재하는 데이터를 추가하는 것)
*	size()			: 벡터의 길이를 반환한다.
*	emplace_back	: 벡터의 끝에 직접 생성한 데이터를 바로 추가한다.
*	pop_back		: 가장 뒤에 있는 데이터 1개를 제거한다.
*	empty			: 벡터의 크기가 0이면 true, 데이터가 하나라도 있다면 false
*	insert()		: 주어진 위치에 데이터를 입력한다. vec.insert(vec.begin()+2, 10);	※ insert(주소, 값)
*	erase()			: 주어진 위치에 데이터를 제거한다. vec.erase(vec.begin());			※ earse(주소)
*/

void Example()
{
	// delete (aPtr+0)
	// delete (aPtr+1)
	// ...
	// delete (aPtr+9)
	//delete[] aPtr; // 배열 전체를 지워주는 코드 delete뒤에 [] 표시를 한다.

	//cout << endl;
	//aPtr = new int[20];
	//MakeArray<int, 20>(aPtr, 0);
}

template<typename T, int N>
void MakeArray(T*& ptr, T value) // int*를 참조하는 방식으로 변수를 가져오고 싶을 때 사용. int*&
{
	delete[] ptr;
	ptr = new T[N];

	for (int i = 0; i < N; i++)
	{
		*(ptr + i) = value;
		cout << *(ptr + i) << " ";
	}
	cout << endl;
}

//class MonsterHandler
//{
//private:
//	std::vector<Monster> mons;
//};
class Monster
{
private:
	int _num;
	string _name;
public:
	Monster() = default;
	~Monster() = default;
	Monster(int num, string name) : _num(num), _name(name) {}

	int get_num() const { return _num; }
	string get_name() const { return _name; }

	friend std::ostream& operator<<(std::ostream& os, const Monster& obj)
	{
		os << obj._num << "_" << obj._name << " ";
		return os;
	}
};

template<typename T>
void Show(std::vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++) // size() : 벡터의 길이를 반환
	{
		cout << vec[i] << " ";
	}
		cout << endl;
}

int main()
{
	int* aPtr = new int[10];	// 주소를 저장하는 공간. int 타입의 공간 10개를 만들겠다는 뜻. 초기화는 되지 않음
	double* bPtr = new double[10];
	string* cPtr = new string[10];
	Monster* dPtr = new Monster[10];

	Monster sample = Monster(0, "고블린");

	MakeArray<int, 10>(aPtr, 0);
	MakeArray<double, 10>(bPtr, 0.1);
	MakeArray<string, 10>(cPtr, "A");
	MakeArray<Monster, 10>(dPtr, sample);

	// vector로 쉽게 배열을 생성하고 출력하기

	std::vector<int> nums; // vector int를 저장하는 가변배열 클래스.

	// push_back : 벡터의 끝에 데이터를 추가한다.
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	//size() : 벡터의 길이 반환
	Show<int>(nums);
	nums.clear();
	
	
	std::vector<Monster> monsterDatabase;
	monsterDatabase.emplace_back(1, "고블린");
	monsterDatabase.emplace_back(2, "슬라임");
	monsterDatabase.emplace_back(3, "코볼트");
	monsterDatabase.emplace_back(4, "골렘");
	Show<Monster>(monsterDatabase);
	//monsterDatabase.pop_back();	// 마지막 데이터를 지워주는 코드
	//Show<Monster>(monsterDatabase);
	//monsterDatabase.pop_back();
	//monsterDatabase.pop_back();
	//Show<Monster>(monsterDatabase);
	//monsterDatabase.pop_back();
	monsterDatabase.clear();		// 데이터를 지워주는 코드

	if (monsterDatabase.empty()) //empty() : 데이터가 1개라고 있을 경우 false, 데이터가 모두 비워지면 true
	{
		cout << "몬스터 정보가 없습니다" << endl;
	}

	std::vector <double> doubleContainer;
	std::vector <string> stringContainer;

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(0);
		doubleContainer.push_back(0.1);
		stringContainer.push_back("A");
		monsterDatabase.push_back(sample);
	}
	Show<int>(nums);
	Show<double>(doubleContainer);
	Show<string>(stringContainer);
	Show<Monster>(monsterDatabase);

	// int 타입을 저장하는 배열을 vector 컨테이너에 저장하는 코드를 작성하시오.
	std::vector<int> nnn;
	nnn.push_back(1);
	nnn.pop_back();
	nnn.size();

}