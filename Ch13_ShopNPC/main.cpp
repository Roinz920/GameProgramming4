
/*
*	��ǥ : (1) �ܼ� â���� �÷��̾ �����δ�. (2) Ư�� ��ġ���� ���� NPC�� ������ ���� ������ �׸��� �����ش�. (3) ������ �̿��Ѵ�.
* 
*	Game Object : Player, NPC, Shop
*	�ڷᱸ��, Item�� � �����̳ʿ� �����Ͽ� ����� ���ΰ�?�� ���� ���
*	File Input&Output�� ���� �޸��忡 �ִ� �����͸� NPC���� �����ϴ� ���
*/

//Ŭ���� ���� -> �׽�Ʈ -> ��� �ű��

#include <iostream>
#include <map>
#include <utility>
#include <conio.h>
#include "ConsoleUtility.h"

#include <fstream> // ifstream ofstream
#include <iomanip> // ����� ���� ���
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

	virtual void Use() = 0; // ���� �����Լ� : Item�� ����ϴ� Ŭ������ �� �Լ��� �ݵ�� ������ �ؾ��Ѵٰ� �����ϴ� ��

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
		std::cout << "���⸦ �����մϴ�" << std::endl;
	}
};

/// <summary>
/// ��� ������ ������ Ŭ���� �Դϴ�. �������� Use()���� ���� ������� ������ �������Դϴ�.
/// Player Ŭ������ RemoveItem�� ����ϼ���.
/// </summary>
class UsableItem : public Item
{
public:
	UsableItem(std::string name, int price, std::string type) :Item(name, price, type) {}

	void Use() override
	{
		std::cout << "�Ҹ�ǰ�� ����մϴ�" << std::endl;
		// Remove�Ǵ� �������� ȣ���ϼ���.
	}
};

#pragma region �÷��̾� �ڵ�

class Player
{
private:
	//Item items[100]; // ������ ������ ������� �ƴ����� ���� �Ǵ��� �ȵ� -> �ʿ��� ������ ������ �����ϴ� �� / �ڷᱸ���� �ʿ��� ����
	std::unordered_map<std::string, Item*> inventory; // Item�� �������� �̸����� ã�� �����̳�

public:
	//��ǥ
	int posX;
	int posY;
	//��
	int money;

#pragma region �κ��丮 �ڵ�
	//	(1) �÷��̾ ������ �κ��丮�� �ڷᱸ���� �Ѱ��� �����ؼ�, �� �ڷᱸ���� ������ �������� �����غ�����.
	//	(2) ������ �ڷᱸ���� ����ϴ� �Լ��� ��������.

	void AddItem(Item* item)
	{
		inventory.insert({ item->getName(), item });
	}

	void RemoveItem(std::string name)
	{
		// ������ �� ���ǻ���! ������ �� ���� ��쿡�� ���� ó�� �ʿ�.
		if (inventory.find(name) != inventory.end()) // inventory��� �����̳ʿ� �����Ͱ� ������ ������
		{ 
			inventory.erase(name);
		}
		else
		{
			std::cout << "�κ��丮�� �ش� �������� �����ϴ�." << std::endl;
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
			std::cout << "�κ��丮�� �ش� �������� �����ϴ�." << std::endl;
		}
	}

#pragma endregion

	/*
	*	������ ��� �������� �Ⱦƾ��Ѵ� (����� Ŭ���� �� class)
	*	�ش� �����۵��� ���� �Լ� Use()�� ������ ������, �ٸ� ������� ���ǰ� �ϰ� �ʹ�. (Ŭ������ ������)
	*	Item�� �ּҷ� �޾ƿ���, �������� ����� �� �ִ�.
	*/

	// Ư�� Ű�� ������ �� (���� �Է� Player Input)


	void Use(Item* item)
	{
		// �Һ� ������ -> ȸ��
		// ��� ������ -> ����
		item->Use();
	}

public:
	Player() = default;
	Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(60, 5);
		std::cout << "�÷��̾��� ����" << std::endl;
		ConsoleUtil::GotoXY(60, 6);
		std::cout << "������ : " << money << std::endl;
		ConsoleUtil::GotoXY(60, 7);
		for (const auto& itemname : inventory)
		{
			std::cout << "[ " << itemname.first << " ] ";
		}


		// ������ ������ ���
	}

	void BuyItem(Item* item)
	{
		money -= item->getPrice();
		AddItem(item);
		Use(item);

		// vector.push_back(item);;
		// map.insert(?, item); // ������ �̸����� �˻��� �� �ְ� map<string, item>
		// unordered_map<string, item>
	}
	// Shop �ڵ�� ���� �� money, Shop.Items[i].price�� �� �� money -= price;
	// �κ��丮 (� Ÿ���� �����̳�?) shop �� player.inventory
};
#pragma endregion

#pragma region ���� �ڵ�
const int total_width = 60;		// ��ü
const int field1_width = 30;	// �̸�
const int field2_width = 15;	// ����
const int field3_width = 15;	// Ÿ��

class Shop
{
private:
	// �ڷᱸ�� �� ���� vector, list, deque, set map
	std::map<int, Item*> items;	//�ڷᱸ�� Ŭ������ ����

	/*
	*	Item �߻�Ŭ������ �����, item ��ü�� Ŭ������ ������ �� ����.(�ν��Ͻ�)
	*	�ּҷ� �޾ƿ;��ϴµ�, enum Ÿ�Կ� ���� Ŭ������ �ٸ��� ����ϰԲ� �ڵ带 �ۼ��� �ʿ䰡 �ִ�.
	*	"���丮 ����" - ���丮 Ŭ������ ���� 
	*/
public:
	Shop()	// �����͸� �ʱ�ȭ�Ѵ�.
	{
		items.insert({ 0, new Weapon("����������", 120, "����") });
		items.insert(std::make_pair(1, new UsableItem("��������", 10, "�Ҹ�ǰ")));
		std::pair<int, Item*> p1(2, new Weapon("�ʱ޿���", 50, "����"));
		items.insert(p1);
		items.insert({ 3, new Weapon("����������", 60, "��") });
		items.insert({ 4, new Weapon("���ٸ���", 30, "��") });
		items.insert({ 5, new Weapon("���ٹ���", 25, "��") });
		items.insert({ 5, new Weapon("���ٱ۷���", 10, "��") });
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

		if (!in_file) // ����ó�� ����
		{
			std::cerr << "������ ���µ� �����Ͽ����ϴ�." << endl;
			std::exit(1);
		}
		
		int index = 0; // ���� ������ �ε��� ��ȣ
		while (!in_file.eof()) // �� ������ ������ ���ϱ��� �������� �ʾҴٸ� ��� �ݺ��� (���� �б�) ������ �϶�
		{
			in_file >> name >> price >> type; // ���Ͽ��� ����� �����͸� �ҷ����� ����
			
			if (type == "�Ҹ�ǰ")
			{
				items.insert({ index, new UsableItem(name, price, type) }); // map �ڷᱸ���� ����
				index++; // ���� �ε��� ��ȣ�� �Ѿ��
			}
			else if (type == "����")
			{
				items.insert({ index, new Weapon(name, price, type) }); // map �ڷᱸ���� ����
				index++; // ���� �ε��� ��ȣ�� �Ѿ��
			}
			else if (type == "��")
			{
				items.insert({ index, new Weapon(name, price, type) }); // map �ڷᱸ���� ����
				index++; // ���� �ε��� ��ȣ�� �Ѿ��
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

		if (!out_file) // ����ó�� ����
		{
			std::cerr << "������ ���µ� �����Ͽ����ϴ�." << endl;
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

	// �����͸� ����Ͽ� ����� ����
	void showShop(int x, int y)
	{
		// �������� �Ӹ���
		//std::string headersize = "123456789012345678901234567890123456789012345678901234567890";
		//cout << headersize << endl;
		ConsoleUtil::GotoXY(x, y);
		cout << std::left << std::setw(field1_width) << "�̸�"
			<< std::setw(field2_width) << " ����"
			<< std::setw(field3_width) << " Ÿ��"
			<< endl;
		// ���� �ߴ� ���
		ConsoleUtil::GotoXY(x, y+1);
		cout << std::setw(total_width) << std::setfill('=') << "" << endl;
		cout << std::setfill(' '); // ��ĭ�� ä��� ������ = ���� �� �������� �ʱ�ȭ

		for (int i = 0; i < items.size(); i++) //�ε��� ����� ������ ������ �ڷᱸ�����߸� �Ѵ�. vector, map
		{
			ConsoleUtil::GotoXY(x, y + 2 + i);
			cout << std::left << std::setw(field1_width) << items[i]->getName()
				<< std::setw(field2_width) << items[i]->getPrice()
				<< std::setw(field3_width) << items[i]->getType()
				<< endl;
		}
	}

	// �������� �Ǹ��Ѵ�. (��, �÷��̾ ���� ���ٸ�...)
	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end()) // index�� �ش��ϴ� �������� ã�Ҵٸ�
		{
			
			Item* itemInstance = items[index];
			if (player.money >= itemInstance->getPrice())
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				std::cout << "�������� �����մϴ�." << endl;
			}			
		}
		else
		{
			std::cout << "�������� ���� ���Ͽ����ϴ�." << endl;
		}
	}

	void Interact(Player& player)
	{
		int select;
		std::cout << "��ȣ�� �Է��Ͽ� ������ ����." << endl;

		std::cin >> select;
		
		BuyItem(select, player);

	}
};

#pragma endregion

#pragma region NPC �ڵ�

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
		shop = Shop(filename); // NPC�� ���� ������ ������ �ʱ�ȭ��Ű�� �۾�
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
		if (npc.isActivate == false) { return; } // ������ ��Ȱ��ȭ�Ǹ� ��� �Ұ���

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
	Player player(10, 10, 1000); // �÷��̾��� ���� ����

	NPC npc1("shop1.txt",  3, 15);
	NPC npc2("shop2.txt",  8, 15);
	NPC npc3("shop3.txt", 13, 15);
	
	//shop.SaveShopData("shop3.txt");

	while (true)
	{

		// �Է��� �޾��� ���� ��ǥ�� ���ϴ� �ڵ�
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