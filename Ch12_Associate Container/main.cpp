
// ���� �����̳�

#include <set>
#include <map>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include <utility>

#pragma region ���� �����̳� ����ϱ�
// set�� ������� �� ���� ���� �߻��ϴ°�?

void Test1()
{
	std::set<int> nums;

	// �������� ���� ���? push
	// ���� �����̳�? insert | why? �����Ͱ� ����� ���� ����� ��ġ�� �����ϱ� ����
	
	std::cout << "Ư¡1. ���� �����̳ʿ� �����͸� �Է��ϸ� �ڵ����� ���� ��" << std::endl; // Ž���� �� �� ���ĵ� ����� ����ϸ� ȿ�����̱� ����
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);	// {1,5,2,7} �� �ƴ�, {1,5} �� {1,5,2} �� {1,2,5} �� {1,2,5,7}�� ������ ���ĵ�
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	std::cout << "Ư¡2. Set�� �����ʹ� �ߺ��� ������ �ʴ´�." << std::endl;
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
	std::cout << "<multiset> ���� �����̳� �տ� Ư�� Ű���带 ���̸� ������ ���Ѵ�." << std::endl;
	std::multiset<int> nums;
	std::cout << "Ư¡1. ���� �����̳ʿ� �����͸� �Է��ϸ� �ڵ����� ���� ��" << std::endl;
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);	// {1,5,2,7} �� �ƴ�, {1,5} �� {1,5,2} �� {1,2,5} �� {1,2,5,7}�� ������ ���ĵ�
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	std::cout << "Ư¡2. multiset�� �����ʹ� �ߺ��� ���ȴ�." << std::endl;
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

#pragma region Ŀ���� Ŭ������ set�� �ִ� ���

struct Item
{
	int id;
	std::string name;

	Item() = default;
	Item(int id, std::string name) : id(id), name(name) {}

	bool operator< (const Item& other) const // �񱳿����ڸ� ���� �ٸ� id�� ������ �� id�� ���� �۴ٸ� ��(true)�� ��ȯ. 
	{
		return id < other.id;
	}
};

void Test3()
{
	std::cout << "Ŀ���� ��ü�� Set���� ����ϱ�" << std::endl;
	std::set<Item> items;

	Item item1(1, "����");
	Item item2(2, "����");
	Item item3(3, "���");
	Item item4(10, "����");
	Item item5(7, "�ٳ���");

	items.insert(item1);
	items.insert(item2);
	items.insert(item3);
	items.insert(item4);
	items.insert(item5);

	std::cout << "�ߺ��� ������� ����" << std::endl;
	items.insert(Item(3, "����"));	// �� �ʰ� id 3���� ����� item�� �߰����� �ʴ� ���� �� �� �ִ�.
	for (const auto& item : items)
	{
		std::cout << item.id << " " << item.name << std::endl;
	}

	std::cout << "Set�� ����ϸ�, �������� ũ�⿡ ���� �ڵ����� ������ ����� ���� �� �ֽ��ϴ�." << std::endl;
	std::cout << "find �Լ��� ����Ͽ� ������ ������ �˻��� �����ϴ�." << std::endl;

	// item ��ü�� items �ȿ��� ã�ƾ��Ѵ�.
	// item�� id�� n���� �����͸� ã�� �;��! -> std::find_if �� �˻� ����
	// ������ �� ȿ������ ����� map�� ����ϸ� ���� ������ �ذ��� �� �ִ�.


}
#pragma endregion

#pragma region map ����ϱ�

void Test4()
{
	std::cout << "map �ڷᱸ�� ����ϱ�" << std::endl;

	std::map<int, Item> items;

	// map�� �����͸� �ִ� ���, pairŬ������ �����ϴ� ��� (1) �߰�ȣ�� ����Ͽ� ����  {Ÿ��,Ÿ��}
	
	items.insert({ 0, Item(100,"����") });


	// (2) make_pair �Լ� ����ϱ�
	items.insert(std::make_pair(10, Item(1000, "�ռҵ�")));
	// (3) pairŬ������ ���� �����ϱ�.
	std::pair<int, Item> p1(5, Item(101, "���� ����"));

	std::cout << "Ư¡1. map�� pair�� �̷���� �����͸� �����ϴ� �����̳��̴�." << std::endl;
	std::cout << "Ư¡2. map�� key ������ �ڵ� ������ �̷�����ϴ�." << std::endl;
	for (const auto& item : items)
	{
		// firts : Ű �� | second : data ��
		std::cout << item.first << " ID :  " << item.second.id << " �̸� : " << item.second.name << std::endl;
	}

	std::cout << "Ư¡3. ����(Dictionary)�� �ڷᱸ���Դϴ�." << std::endl;
	std::cout << items[0].id << " " << items[0].name << std::endl;
}
#pragma endregion

#pragma region ���� �����̳� �ǽ�

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
	map1.insert({ "��", 0 });
	map1.insert({ "��", 1 });
	map1.insert(std::make_pair("��", 2));
	map1.insert(std::pair<std::string, int>("��", 3));

	//std::make_pair
	//std::pair<T1, T2>
	for (const auto& e : map1)
	{
		std::cout << "[" << e.first << " " << e.second << "]";
	}
	std::cout << std:: endl << "�� Ű���忡�� � ���ڰ� ����ֽ��ϱ�? " << map1["��"] << std::endl;

	std::map<int, int> map2;
	// �÷��̾��� id��ȣ (������ȣ), �ش� �÷��̾��� ����
	map2.insert({ 0,10 });
	map2.insert({ 5,100 });
	map2.insert({ 100,999 });
	map2.insert({  50, 50 });
	map2.insert({  25,100 });
	std::cout << "map2�����̳� �ȿ� ������ Ű���忡�� � ���ڰ� ����ֽ��ϱ�?" << map2[100] << std::endl;

	std::map<std::string, WeaponItem> map3;
	map3.insert({ "�ռҵ�", WeaponItem("�ռҵ�", 50, 100) });
	map3.insert({ "���Ǿ�", WeaponItem("���Ǿ�", 30, 75) });

	std::cout << "map3 �ȿ� ����ִ� �̸��� �ռҵ��� �����͸� �ҷ�����" << std::endl;
	WeaponItem itemInstance = map3["�ռҵ�"];
	std::cout << "������ �̸� : " << itemInstance.name << " | ���ݷ� : " << itemInstance.ATK << " | ���� : " << itemInstance.price << std::endl;
	// void BuyItem(WeaponItem item) item ����, player�� ���� ���ؼ� �����Ѵ�.
}
#pragma endregion

#pragma region ���� UI �� ��� �����ϱ�

// iomanip ���ڿ��� �԰��� ���ߴ� ��� ���� setw left

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
	// Ÿ�� < > items
	std::map<int, WeaponItem> shopItems;
	Shop()
	{
		shopItems.insert({ 0, WeaponItem("�η��� ����", 5, 10) });
		shopItems.insert({ 1, WeaponItem("�ռҵ�", 40,100) });
		shopItems.insert({ 2, WeaponItem("���ҵ�", 20, 50) });
		shopItems.insert({ 3, WeaponItem("�ܰ�", 10, 30) });
		shopItems.insert({ 4, WeaponItem("�۶��콺", 70, 350) });
	}
	void ShowItem()
	{
		std::cout << std::left;
		std::cout << std::setw(8) << "�ε���"
			<< std::setw(18) << "�̸�"
			<< std::setw(14) << "���ݷ�"
			<< std::setw(10) << "����" << std::endl;

		for (const auto& item : shopItems)
		{
			std::cout << std::left; // ���� ����
			std::cout << std::setw(8)/*10ĭ Ȯ��*/ << item.first 
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
	// 1. Item �����͸� �����
	// 2. ������ �����͸� ����� ��Ŭ����.
	// 3. Shop Ŭ���� �ȿ� map �ڷᱸ���� �߰��غ����� (Item�� ����Ǿ�� ��)
	// 4. items �����͸� �ʱ�ȭ ����� ��.
	
	Shop shop;

	shop.ShowItem();
	
}

#pragma endregion

// set���� �����͸� �������� ���� ������ ��, �װ��� ������ map
// pair�� �����ؾ� �Ѵ�.

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	ShopTest();
}
