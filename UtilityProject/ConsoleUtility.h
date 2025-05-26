#pragma once

#include <random>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <array>
#include <map>
#include <list>
#include <chrono>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class ConsoleUtil
{
public:
	static void GotoXY(int x, int y)
	{
		COORD pos = { static_cast<short>(x), static_cast<short>(y) };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static int GetRandomInt(int max)
	{
		static std::random_device rd; // �õ� ������
		static std::mt19937 gen(rd()); // Mersenne Twister ����
		std::uniform_int_distribution<> dist(1, max); // 1���� max������ ������ ���� ����
		return dist(gen); // ��
	}

	static void SetCursorVisible(bool enable)
	{
		CONSOLE_CURSOR_INFO cursorInfo;
		cursorInfo.bVisible = enable;
		cursorInfo.dwSize = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	}

	static void TimeCheck(void (*Func)())
	{
		
		auto start = std::chrono::high_resolution_clock::now();
		// �Լ� ������
		Func();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> duration = end - start;
		std::cout << duration.count() << "ms �ҿ�" << std::endl;
	}
};
