
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

#pragma region ���� �ڵ�
const int total_width = 60;		// ��ü
const int field1_width = 30;	// �̸�
const int field2_width = 15;	// ����
const int field3_width = 15;	// Ÿ��
class Item
{
private:
	std::string name;
	int price;
	std::string type;
public:
	Item() = default;
	Item(std::string name, int price, std::string type) : name(name), price(price), type(type) {}
	
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

class Shop
{
private:
	// �ڷᱸ�� �� ���� vector, list, deque, set map
	std::map<int, Item> items;	//�ڷᱸ�� Ŭ������ ����
public:
	Shop()	// �����͸� �ʱ�ȭ�Ѵ�.
	{
		items.insert({ 0, Item("����������", 120, "����") });
		items.insert(std::make_pair(1, Item("��������", 10, "�Ҹ�ǰ")));
		std::pair<int, Item> p1(2, Item("�ʱ޿���", 50, "����"));
		items.insert(p1);
		items.insert({ 3, Item("����������", 60, "��") });
		items.insert({ 4, Item("���ٸ���", 30, "��") });
		items.insert({ 5, Item("���ٹ���", 25, "��") });
		items.insert({ 5, Item("���ٱ۷���", 10, "��") });
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
			items.insert({index, Item(name, price, type) }); // map �ڷᱸ���� ����
			index++; // ���� �ε��� ��ȣ�� �Ѿ��
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
			out_file << std::left << std::setw(field1_width) << items[i].getName()
				<< std::setw(field2_width) << items[i].getPrice()
				<< std::setw(field3_width) << items[i].getType()
				<< endl;
		}

		out_file.close();
	}

	// �����͸� ����Ͽ� ����� ����
	void showShop()
	{
		// �������� �Ӹ���
		//std::string headersize = "123456789012345678901234567890123456789012345678901234567890";
		//cout << headersize << endl;
		ConsoleUtil::GotoXY(0, 0);
		cout << std::left << std::setw(field1_width) << "�̸�"
			<< std::setw(field2_width) << " ����"
			<< std::setw(field3_width) << " Ÿ��"
			<< endl;
		// ���� �ߴ� ���
		cout << std::setw(total_width) << std::setfill('=') << "" << endl;
		cout << std::setfill(' '); // ��ĭ�� ä��� ������ = ���� �� �������� �ʱ�ȭ

		for (int i = 0; i < items.size(); i++) //�ε��� ����� ������ ������ �ڷᱸ�����߸� �Ѵ�. vector, map
		{
			cout << std::left << std::setw(field1_width) << items[i].getName()
				<< std::setw(field2_width) << items[i].getPrice()
				<< std::setw(field3_width) << items[i].getType()
				<< endl;
		}
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
	NPC() = default;
	NPC(std::string filename, int posX, int posY) : posX(posX), posY(posY)
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
	void ShowItems()
	{
		shop.showShop();
	}
	void ShowNPC()
	{
		ConsoleUtil::GotoXY(posX, posY);
		std::cout << "$";
	}
};
void Interact(int x1, int y1, NPC& npc) // Player, NPC
{
	if (x1 == npc.getPosX() && y1 == npc.getPosY())
	{
		npc.ShowItems();
	}
}

void ShowPhase(Shop& shop)
{
	shop.showShop();
}
#pragma endregion

#pragma region �÷��̾� �ڵ�

class Player
{
	int posX;
	int posY;
	int money;
};
#pragma endregion

int main()
{
	system("mode con:cols=80 lines=20");
	ConsoleUtil::SetCursorVisible(false);
	int playerX = 10;
	int playerY = 10;

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
				playerY--;
				if (playerY <= 0) { playerY = 0; }
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				playerY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				playerX--;
				if (playerX <= 0) { playerX = 0; }
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				playerX++;
			}
		}
	
		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();
		Interact(playerX, playerY, npc1);
		Interact(playerX, playerY, npc2);
		Interact(playerX, playerY, npc3);
		ConsoleUtil::GotoXY(playerX, playerY);
		std::cout << "a";	
		Sleep(100);
	}
}