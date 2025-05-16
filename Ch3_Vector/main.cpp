#include "ConsoleUtility.h"
/*
*	��ǥ : �迭�� ũ�⸦ �������� �����ϴ� �ڵ带 �����
*
*			"�ڵ�" vector
*/

/*
*	int 10�� �迭�� ����
*	�迭�� Ư¡ : ũ�Ⱑ ����. ���� �� ũ�⸦ ������� �Ѵ�. 40byte�� ������ Ȯ���ؾ� ��
*	���� 41byte ������ �������� �޸𸮸� �����Ѵٸ� -> ���� �߻�
*/

//	�迭�� ũ�⸦ N���� ���� �� �ְ� �ڵ带 �߰��غ���

/*
*	vector Ŭ������ ���
*	
*	push_back		: ������ ���� �����͸� �߰��Ѵ�. (�̹� �����ϴ� �����͸� �߰��ϴ� ��)
*	size()			: ������ ���̸� ��ȯ�Ѵ�.
*	emplace_back	: ������ ���� ���� ������ �����͸� �ٷ� �߰��Ѵ�.
*	pop_back		: ���� �ڿ� �ִ� ������ 1���� �����Ѵ�.
*	empty			: ������ ũ�Ⱑ 0�̸� true, �����Ͱ� �ϳ��� �ִٸ� false
*	insert()		: �־��� ��ġ�� �����͸� �Է��Ѵ�. vec.insert(vec.begin()+2, 10);	�� insert(�ּ�, ��)
*	erase()			: �־��� ��ġ�� �����͸� �����Ѵ�. vec.erase(vec.begin());			�� earse(�ּ�)
*/

void Example()
{
	// delete (aPtr+0)
	// delete (aPtr+1)
	// ...
	// delete (aPtr+9)
	//delete[] aPtr; // �迭 ��ü�� �����ִ� �ڵ� delete�ڿ� [] ǥ�ø� �Ѵ�.

	//cout << endl;
	//aPtr = new int[20];
	//MakeArray<int, 20>(aPtr, 0);
}

template<typename T, int N>
void MakeArray(T*& ptr, T value) // int*�� �����ϴ� ������� ������ �������� ���� �� ���. int*&
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
	for (int i = 0; i < vec.size(); i++) // size() : ������ ���̸� ��ȯ
	{
		cout << vec[i] << " ";
	}
		cout << endl;
}

int main()
{
	int* aPtr = new int[10];	// �ּҸ� �����ϴ� ����. int Ÿ���� ���� 10���� ����ڴٴ� ��. �ʱ�ȭ�� ���� ����
	double* bPtr = new double[10];
	string* cPtr = new string[10];
	Monster* dPtr = new Monster[10];

	Monster sample = Monster(0, "���");

	MakeArray<int, 10>(aPtr, 0);
	MakeArray<double, 10>(bPtr, 0.1);
	MakeArray<string, 10>(cPtr, "A");
	MakeArray<Monster, 10>(dPtr, sample);

	// vector�� ���� �迭�� �����ϰ� ����ϱ�

	std::vector<int> nums; // vector int�� �����ϴ� �����迭 Ŭ����.

	// push_back : ������ ���� �����͸� �߰��Ѵ�.
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	//size() : ������ ���� ��ȯ
	Show<int>(nums);
	nums.clear();
	
	
	std::vector<Monster> monsterDatabase;
	monsterDatabase.emplace_back(1, "���");
	monsterDatabase.emplace_back(2, "������");
	monsterDatabase.emplace_back(3, "�ں�Ʈ");
	monsterDatabase.emplace_back(4, "��");
	Show<Monster>(monsterDatabase);
	//monsterDatabase.pop_back();	// ������ �����͸� �����ִ� �ڵ�
	//Show<Monster>(monsterDatabase);
	//monsterDatabase.pop_back();
	//monsterDatabase.pop_back();
	//Show<Monster>(monsterDatabase);
	//monsterDatabase.pop_back();
	monsterDatabase.clear();		// �����͸� �����ִ� �ڵ�

	if (monsterDatabase.empty()) //empty() : �����Ͱ� 1����� ���� ��� false, �����Ͱ� ��� ������� true
	{
		cout << "���� ������ �����ϴ�" << endl;
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

	// int Ÿ���� �����ϴ� �迭�� vector �����̳ʿ� �����ϴ� �ڵ带 �ۼ��Ͻÿ�.
	std::vector<int> nnn;
	nnn.push_back(1);
	nnn.pop_back();
	nnn.size();

}