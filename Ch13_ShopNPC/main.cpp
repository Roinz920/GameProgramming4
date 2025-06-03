
/*
*	목표 : (1) 콘솔 창에서 플레이어를 움직인다. (2) 특정 위치에서 상점 NPC와 조우할 때에 상점의 항목을 보여준다. (3) 상점을 이용한다.
* 
*	Game Object : Player, NPC, Shop
*	자료구조, Item을 어떤 컨테이너에 보관하여 사용할 것인가?에 대한 고민
*	File Input&Output을 통해 메모장에 있는 데이터를 NPC에게 전달하는 기능
*/

//클래스 구현 -> 테스트 -> 헤더 옮기기

#include <iostream>
#include <map>
#include <utility>
#include <conio.h>
#include "ConsoleUtility.h"

#include <fstream> // ifstream ofstream
#include <iomanip> // 입출력 조작 헤더
#include <Windows.h>
#include <unordered_map>

class Item
{
private:
	std::string name;
	int price;
	std::string type;
public:
	Item() = default;
	Item(std::string name, int price, std::string type) : name(name), price(price), type(type) {}

	virtual void Use() = 0; // 순수 가상함수 : Item을 상속하는 클래스가 이 함수를 반드시 구현을 해야한다고 선언하는 것

	std::string getName()
	{
		return name;
	}
	int getPrice()
	{
		return price;
	}
	std::string getType()
	{
		return type;
	}
};

class Weapon : public Item
{
public:
	Weapon(std::string name, int price, std::string type) :Item(name, price, type) {}

	void Use() override
	{
		std::cout << "무기를 장착합니다" << std::endl;
	}
};

/// <summary>
/// 사용 가능한 아이템 클래스 입니다. 아이템을 Use()했을 때에 사라지는 종류의 아이템입니다.
/// Player 클래스의 RemoveItem을 사용하세요.
/// </summary>
class UsableItem : public Item
{
public:
	UsableItem(std::string name, int price, std::string type) :Item(name, price, type) {}

	void Use() override
	{
		std::cout << "소모품을 사용합니다" << std::endl;
		// Remove되는 아이템을 호출하세요.
	}
};

#pragma region 플레이어 코드

class Player
{
private:
	//Item items[100]; // 아이템 공간이 충분한지 아닌지에 대한 판단이 안됨 -> 필요할 때에만 공간을 배정하는 것 / 자료구조가 필요한 이유
	std::unordered_map<std::string, Item*> inventory; // Item을 아이템의 이름으로 찾는 컨테이너

public:
	//좌표
	int posX;
	int posY;
	//돈
	int money;

#pragma region 인벤토리 코드
	//	(1) 플레이어가 소유한 인벤토리를 자료구조를 한가지 선택해서, 그 자료구조에 구매한 아이템을 저장해보세요.
	//	(2) 저장한 자료구조를 사용하는 함수를 만들어보세요.

	void AddItem(Item* item)
	{
		inventory.insert({ item->getName(), item });
	}

	void RemoveItem(std::string name)
	{
		// 제거할 때 주의사항! 제거할 수 없는 경우에는 예외 처리 필요.
		if (inventory.find(name) != inventory.end()) // inventory라는 컨테이너에 데이터가 존재할 때에만
		{ 
			inventory.erase(name);
		}
		else
		{
			std::cout << "인벤토리에 해당 아이템이 없습니다." << std::endl;
		}
	}
	void RemoveItem(Item* item)
	{
		if (inventory.find(item->getName()) != inventory.end())
		{
			inventory.erase(item->getName());
		}
		else
		{
			std::cout << "인벤토리에 해당 아이템이 없습니다." << std::endl;
		}
	}

#pragma endregion

	/*
	*	상점은 모든 아이템을 팔아야한다 (공통된 클래스 → class)
	*	해당 아이템들은 같은 함수 Use()를 가지고 있지만, 다른 기능으로 사용되게 하고 싶다. (클래스의 다형성)
	*	Item을 주소로 받아오면, 다형성을 사용할 수 있다.
	*/

	// 특정 키를 눌렀을 때 (게임 입력 Player Input)


	void Use(Item* item)
	{
		// 소비 아이템 -> 회복
		// 장비 아이템 -> 착용
		item->Use();
	}

public:
	Player() = default;
	Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(60, 5);
		std::cout << "플레이어의 정보" << std::endl;
		ConsoleUtil::GotoXY(60, 6);
		std::cout << "소지금 : " << money << std::endl;
		ConsoleUtil::GotoXY(60, 7);
		for (const auto& itemname : inventory)
		{
			std::cout << "[ " << itemname.first << " ] ";
		}


		// 보유한 아이템 목록
	}

	void BuyItem(Item* item)
	{
		money -= item->getPrice();
		AddItem(item);
		Use(item);

		// vector.push_back(item);;
		// map.insert(?, item); // 아이템 이름으로 검색할 수 있게 map<string, item>
		// unordered_map<string, item>
	}
	// Shop 코드와 연동 → money, Shop.Items[i].price를 비교 → money -= price;
	// 인벤토리 (어떤 타입의 컨테이너?) shop → player.inventory
};
#pragma endregion

#pragma region 상점 코드
const int total_width = 60;		// 전체
const int field1_width = 30;	// 이름
const int field2_width = 15;	// 가격
const int field3_width = 15;	// 타입

class Shop
{
private:
	// 자료구조 중 선택 vector, list, deque, set map
	std::map<int, Item*> items;	//자료구조 클래스를 보관

	/*
	*	Item 추상클래스를 만들면, item 자체를 클래스로 생성할 수 없다.(인스턴스)
	*	주소로 받아와야하는데, enum 타입에 따라 클래스를 다르게 사용하게끔 코드를 작성할 필요가 있다.
	*	"팩토리 패턴" - 팩토리 클래스를 만들어서 
	*/
public:
	Shop()	// 데이터를 초기화한다.
	{
		items.insert({ 0, new Weapon("마법지팡이", 120, "무기") });
		items.insert(std::make_pair(1, new UsableItem("마나포션", 10, "소모품")));
		std::pair<int, Item*> p1(2, new Weapon("초급오브", 50, "무기"));
		items.insert(p1);
		items.insert({ 3, new Weapon("리넨케이프", 60, "방어구") });
		items.insert({ 4, new Weapon("리넨모자", 30, "방어구") });
		items.insert({ 5, new Weapon("리넨바지", 25, "방어구") });
		items.insert({ 5, new Weapon("리넨글러브", 10, "방어구") });
	}
	
	Shop(std::string filename)
	{
		LoadShopData(filename);
	}

	void LoadShopData(std::string filename)
	{
		std::ifstream in_file;		
		in_file.open(filename);

		std::string name;
		int price;
		std::string type;

		if (!in_file) // 예외처리 조항
		{
			std::cerr << "파일을 여는데 실패하였습니다." << endl;
			std::exit(1);
		}
		
		int index = 0; // 파일 저장할 인덱스 번호
		while (!in_file.eof()) // 이 파일의 마지막 파일까지 도달하지 않았다면 계속 반복문 (파일 읽기) 진행을 하라
		{
			in_file >> name >> price >> type; // 파일에서 저장된 데이터를 불러오는 순서
			
			if (type == "소모품")
			{
				items.insert({ index, new UsableItem(name, price, type) }); // map 자료구조에 저장
				index++; // 다음 인덱스 번호로 넘어가기
			}
			else if (type == "무기")
			{
				items.insert({ index, new Weapon(name, price, type) }); // map 자료구조에 저장
				index++; // 다음 인덱스 번호로 넘어가기
			}
			else if (type == "방어구")
			{
				items.insert({ index, new Weapon(name, price, type) }); // map 자료구조에 저장
				index++; // 다음 인덱스 번호로 넘어가기
			}			
		}
		in_file.close();
	}
	
	void SaveShopData(std::string filename)
	{
		std::ofstream out_file;
		out_file.open(filename);

		std::string name;
		int price;
		std::string type;

		if (!out_file) // 예외처리 조항
		{
			std::cerr << "파일을 여는데 실패하였습니다." << endl;
			std::exit(1);
		}
		for (int i = 0; i < items.size(); i++)
		{
			out_file << std::left << std::setw(field1_width) << items[i]->getName()
				<< std::setw(field2_width) << items[i]->getPrice()
				<< std::setw(field3_width) << items[i]->getType()
				<< endl;
		}

		out_file.close();
	}

	// 데이터를 사용하여 기능을 구현
	void showShop(int x, int y)
	{
		// 아이템의 머릿말
		//std::string headersize = "123456789012345678901234567890123456789012345678901234567890";
		//cout << headersize << endl;
		ConsoleUtil::GotoXY(x, y);
		cout << std::left << std::setw(field1_width) << "이름"
			<< std::setw(field2_width) << " 가격"
			<< std::setw(field3_width) << " 타입"
			<< endl;
		// 라인 긋는 방법
		ConsoleUtil::GotoXY(x, y+1);
		cout << std::setw(total_width) << std::setfill('=') << "" << endl;
		cout << std::setfill(' '); // 빈칸을 채우는 기준을 = 에서 빈 공간으로 초기화

		for (int i = 0; i < items.size(); i++) //인덱스 기반의 접근이 가능한 자료구조여야만 한다. vector, map
		{
			ConsoleUtil::GotoXY(x, y + 2 + i);
			cout << std::left << std::setw(field1_width) << items[i]->getName()
				<< std::setw(field2_width) << items[i]->getPrice()
				<< std::setw(field3_width) << items[i]->getType()
				<< endl;
		}
	}

	// 아이템을 판매한다. (단, 플레이어가 돈이 없다면...)
	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end()) // index에 해당하는 아이템을 찾았다면
		{
			
			Item* itemInstance = items[index];
			if (player.money >= itemInstance->getPrice())
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				std::cout << "소지금이 부족합니다." << endl;
			}			
		}
		else
		{
			std::cout << "아이템을 차지 못하였습니다." << endl;
		}
	}

	void Interact(Player& player)
	{
		int select;
		std::cout << "번호를 입력하여 아이템 구매." << endl;

		std::cin >> select;
		
		BuyItem(select, player);

	}
};

#pragma endregion

#pragma region NPC 코드

class NPC
{
private:
	Shop shop;
	int posX;
	int posY;
public:
	bool isActivate;

public:
	NPC() = default;
	NPC(std::string filename, int posX, int posY) : posX(posX), posY(posY), isActivate(true)
	{
		shop = Shop(filename); // NPC가 가진 상점의 정보를 초기화시키는 작업
	}
	int getPosX()
	{
		return posX;
	}
	int getPosY()
	{
		return posY;
	}
	void ShowItems(int x, int y)
	{
		shop.showShop(x, y);
	}

	void Interact(Player& player)
	{
		shop.Interact(player);
		isActivate = false;
	}

	void ShowNPC()
	{
		if (isActivate == false) { return; }
		ConsoleUtil::GotoXY(posX, posY);
		std::cout << "$";
	}
};
void Interact(Player& player, NPC& npc, int UI_x, int UI_y) // Player, NPC
{
	if (player.posX == npc.getPosX() && player.posY == npc.getPosY())
	{
		if (npc.isActivate == false) { return; } // 상점이 비활성화되면 사용 불가능

		npc.ShowItems(UI_x,UI_y);
		npc.Interact(player);
	}
}

void ShowPhase(Shop& shop, int UI_x, int UI_y)
{
	shop.showShop(UI_x, UI_y);
}
#pragma endregion

int main()
{
	system("mode con:cols=120 lines=40");
	ConsoleUtil::SetCursorVisible(false);
	Player player(10, 10, 1000); // 플레이어의 시작 설정

	NPC npc1("shop1.txt",  3, 15);
	NPC npc2("shop2.txt",  8, 15);
	NPC npc3("shop3.txt", 13, 15);
	
	//shop.SaveShopData("shop3.txt");

	while (true)
	{

		// 입력을 받았을 때에 좌표가 변하는 코드
		if (_kbhit())
		{
			system("cls");
			if (GetAsyncKeyState(VK_UP))
			{
				player.posY--;
				if (player.posY <= 0) { player.posY = 0; }
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				player.posY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				player.posX--;
				if (player.posX <= 0) { player.posX = 0; }
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				player.posX++;
			}
		}
		player.ShowPlayerUI();
		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();
		Interact(player, npc1, 0, 20);
		Interact(player, npc2, 0, 20);
		Interact(player, npc3, 0, 20);
		ConsoleUtil::GotoXY(player.posX, player.posY);
		std::cout << "a";	
		Sleep(100);
	}
}