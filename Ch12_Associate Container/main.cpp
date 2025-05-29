
// 연관 컨테이너

#include <set>
#include <map>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include <utility>

#pragma region 연관 컨테이너 사용하기
// set을 사용했을 때 무슨 일이 발생하는가?

void Test1()
{
	std::set<int> nums;

	// 데이터의 저장 방법? push
	// 연관 컨테이너? insert | why? 데이터가 저장될 때에 저장될 위치를 정의하기 때문
	
	std::cout << "특징1. 연관 컨테이너에 데이터를 입력하면 자동으로 정렬 됨" << std::endl; // 탐색을 할 때 정렬된 결과로 사용하면 효과적이기 때문
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);	// {1,5,2,7} 이 아닌, {1,5} → {1,5,2} → {1,2,5} → {1,2,5,7}의 순서로 정렬됨
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	std::cout << "특징2. Set의 데이터는 중복이 허용되지 않는다." << std::endl;
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}	
	std::cout << std::endl << std::endl;
}
void Test2()
{
	std::cout << "<multiset> 연관 컨테이너 앞에 특정 키워드를 붙이면 성질이 변한다." << std::endl;
	std::multiset<int> nums;
	std::cout << "특징1. 연관 컨테이너에 데이터를 입력하면 자동으로 정렬 됨" << std::endl;
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);	// {1,5,2,7} 이 아닌, {1,5} → {1,5,2} → {1,2,5} → {1,2,5,7}의 순서로 정렬됨
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	std::cout << "특징2. multiset의 데이터는 중복이 허용된다." << std::endl;
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}

	std::cout << std::endl << std::endl;
}
#pragma endregion

#pragma region 커스텀 클래스를 set에 넣는 방법

struct Item
{
	int id;
	std::string name;

	Item() = default;
	Item(int id, std::string name) : id(id), name(name) {}

	bool operator< (const Item& other) const // 비교연산자를 통해 다른 id의 값보다 내 id의 값이 작다면 참(true)를 반환. 
	{
		return id < other.id;
	}
};

void Test3()
{
	std::cout << "커스텀 객체를 Set으로 출력하기" << std::endl;
	std::set<Item> items;

	Item item1(1, "유리");
	Item item2(2, "가죽");
	Item item3(3, "사과");
	Item item4(10, "딸기");
	Item item5(7, "바나나");

	items.insert(item1);
	items.insert(item2);
	items.insert(item3);
	items.insert(item4);
	items.insert(item5);

	std::cout << "중복을 허용하지 않음" << std::endl;
	items.insert(Item(3, "투구"));	// 뒤 늦게 id 3으로 선언된 item은 추가되지 않는 것을 알 수 있다.
	for (const auto& item : items)
	{
		std::cout << item.id << " " << item.name << std::endl;
	}

	std::cout << "Set을 사용하면, 데이터의 크기에 따라 자동으로 정렬한 결과를 얻을 수 있습니다." << std::endl;
	std::cout << "find 함수를 사용하여 빠르게 데이터 검색이 가능하다." << std::endl;

	// item 전체를 items 안에서 찾아야한다.
	// item의 id가 n번인 데이터를 찾고 싶어요! -> std::find_if 로 검색 가능
	// 하지만 더 효율적인 방법은 map을 사용하면 위의 문제를 해결할 수 있다.


}
#pragma endregion

#pragma region map 사용하기

void Test4()
{
	std::cout << "map 자료구조 사용하기" << std::endl;

	std::map<int, Item> items;

	// map에 데이터를 넣는 방법, pair클래스를 선언하는 방법 (1) 중괄호를 사용하여 선언  {타입,타입}
	
	items.insert({ 0, Item(100,"포션") });


	// (2) make_pair 함수 사용하기
	items.insert(std::make_pair(10, Item(1000, "롱소드")));
	// (3) pair클래스를 직접 선언하기.
	std::pair<int, Item> p1(5, Item(101, "빨간 포션"));

	std::cout << "특징1. map은 pair로 이루어진 데이터를 저장하는 컨테이너이다." << std::endl;
	std::cout << "특징2. map은 key 값으로 자동 정렬이 이루어집니다." << std::endl;
	for (const auto& item : items)
	{
		// firts : 키 값 | second : data 값
		std::cout << item.first << " ID :  " << item.second.id << " 이름 : " << item.second.name << std::endl;
	}

	std::cout << "특징3. 사전(Dictionary)형 자료구조입니다." << std::endl;
	std::cout << items[0].id << " " << items[0].name << std::endl;
}
#pragma endregion

#pragma region 연관 컨테이너 실습

struct WeaponItem
{
	std::string name;
	int ATK;
	int price;

	WeaponItem() = default;
	WeaponItem(std::string name, int ATK, int price) : name(name), ATK(ATK), price(price) {}
};
void Test5()
{
	std::map<std::string, int> map1;
	map1.insert({ "김", 0 });
	map1.insert({ "밥", 1 });
	map1.insert(std::make_pair("다", 2));
	map1.insert(std::pair<std::string, int>("라", 3));

	//std::make_pair
	//std::pair<T1, T2>
	for (const auto& e : map1)
	{
		std::cout << "[" << e.first << " " << e.second << "]";
	}
	std::cout << std:: endl << "밥 키워드에는 어떤 숫자가 들어있습니까? " << map1["밥"] << std::endl;

	std::map<int, int> map2;
	// 플레이어의 id번호 (고유번호), 해당 플레이어의 레벨
	map2.insert({ 0,10 });
	map2.insert({ 5,100 });
	map2.insert({ 100,999 });
	map2.insert({  50, 50 });
	map2.insert({  25,100 });
	std::cout << "map2컨테이너 안에 선택한 키워드에는 어떤 숫자가 들어있습니까?" << map2[100] << std::endl;

	std::map<std::string, WeaponItem> map3;
	map3.insert({ "롱소드", WeaponItem("롱소드", 50, 100) });
	map3.insert({ "스피어", WeaponItem("스피어", 30, 75) });

	std::cout << "map3 안에 들어있는 이름이 롱소드인 데이터를 불러와줘" << std::endl;
	WeaponItem itemInstance = map3["롱소드"];
	std::cout << "아이템 이름 : " << itemInstance.name << " | 공격력 : " << itemInstance.ATK << " | 가격 : " << itemInstance.price << std::endl;
	// void BuyItem(WeaponItem item) item 가격, player의 돈을 비교해서 구입한다.
}
#pragma endregion

#pragma region 상점 UI 및 기능 구현하기

// iomanip 문자열의 규격을 맞추는 기능 있음 setw left

class Player
{
private: 
	int money;
public:
	Player(int money) : money(money) {}
};

class Shop
{
public:
	// 타입 < > items
	std::map<int, WeaponItem> shopItems;
	Shop()
	{
		shopItems.insert({ 0, WeaponItem("부러진 직검", 5, 10) });
		shopItems.insert({ 1, WeaponItem("롱소드", 40,100) });
		shopItems.insert({ 2, WeaponItem("숏소드", 20, 50) });
		shopItems.insert({ 3, WeaponItem("단검", 10, 30) });
		shopItems.insert({ 4, WeaponItem("글라디우스", 70, 350) });
	}
	void ShowItem()
	{
		std::cout << std::left;
		std::cout << std::setw(8) << "인덱스"
			<< std::setw(18) << "이름"
			<< std::setw(14) << "공격력"
			<< std::setw(10) << "가격" << std::endl;

		for (const auto& item : shopItems)
		{
			std::cout << std::left; // 왼쪽 정렬
			std::cout << std::setw(8)/*10칸 확보*/ << item.first 
				<< std::setw(18) << item.second.name 
				<< std::setw(14) << item.second.ATK
				<< std::setw(10) << item.second.price << std::endl;
		}

	}
	void sellItem(Player& player)
	{

	}

};
void ShopTest()
{
	// 1. Item 데이터를 만든다
	// 2. 정의한 데이터를 사용하 ㄹ클래스.
	// 3. Shop 클래스 안에 map 자료구조를 추가해보세요 (Item이 저장되어야 함)
	// 4. items 데이터를 초기화 해줘야 함.
	
	Shop shop;

	shop.ShowItem();
	
}

#pragma endregion

// set으로 데이터를 정렬했을 때의 불편한 점, 그것을 개선한 map
// pair를 정의해야 한다.

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	ShopTest();
}
