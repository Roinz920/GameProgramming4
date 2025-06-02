#include <iostream>
#include <map>
#include <unordered_map>
#include "ConsoleUtility.h"


#pragma region 해쉬 함수란 무엇인가?
/*
*	Hash Function : Hashing하다 의 의미?
*	- 전달하는 타입을 특정한 규칙으로 다른 타입으로 변환하는 작업.
* 
*	왜 Hasing을 하는가?
*	-> Hasing 결과로 데이터를 재정렬하여 사용할 수 있다.
*/
/*
*	Hash로 만든 자료구조의 장점?
*	map보다 데이터 접근이 빠르고, 데이터 탐색이 빠르다.
*/
int HashFucntion(int input)
{
	return input % 10; // 0 ~ 9 값만을 반환
}
void Test1()
{
	HashFucntion(252349429);	//	252349429 -> 9로 저장

	// unordered_map : [key - value] :: 9라는 해쉬값에는 252349429 라는 숫자가 들어있다.

	std::unordered_map <std::string, int> umap;

	umap.insert({ "바나나",5 });
	umap.insert({ "사과",5 });

	std::cout << "바나나의 갯수 : " << umap["바나나"] << std::endl;


}


#pragma endregion 

#pragma region map과 unordered_map의 비교

/*
*	탐색하는데 unordered_ma이 빠르다.
*	데이터 수가 많으면 많을수록 unodered_map이 좋다.
*	데이터 수가 적으면 
* 
*	왜 유리한가? - 데이터를 초기화 할 떄에 걸리는 시간
*	순차 컨테이너 > 연관 컨테이너 (map) > unordered_map (자체적으로 해시함수가 구현되어있고, 해시함수로 내부 데이터 저장)
*	
*	해시함수의 단점
*	-	해싱충돌이 발생할 때 성능저하가 발생할 수 있다.
*/

void MapTimeTest()
{
	std::map<std::string, int> map;

	map.insert({ "A", 1 });
	map.insert({ "B", 1 });
	map.insert({ "C", 1 });
	map.insert({ "D", 1 });
	map.insert({ "E", 1 });

	for (int i = 0; i < 1000; i++)
	{
		map.find ("A");
	}
}

void newMapTimeTest()
{
	std::map<std::string, int> umap;

	umap.insert({ "A", 1 });
	umap.insert({ "B", 1 });
	umap.insert({ "C", 1 });
	umap.insert({ "D", 1 });
	umap.insert({ "E", 1 });

	for (int i = 0; i < 1000; i++)
	{
		umap.find ("A");
	}
}

void Test2()
{
	std::cout << "첫번째 비교 - 데이터 입력 비교" << endl;

	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(newMapTimeTest);

	std::cout << "map의 장점 : 데이터 자동 정렬이 발생함" << endl;
	std::cout << "정렬이 된 데이터를 필요할 때에 map이 유용" << endl;
	std::cout << "그 이외에 컨테이너 안에 빠게 데이터를 찾고 변경하고 싶다." << endl;

	std::cout << "두번째 비교 - 데이터 검색 시간 비교" << std::endl;
	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(newMapTimeTest);
}

#pragma endregion 


int main()
{
	
	Test2();
}