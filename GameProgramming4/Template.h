#pragma once

#include "Common.h"

// 더하기 함수

// 함수 오버로딩으로 실수도 계산 가능하게 추가
//	일반화 된 코드로 만들면 유지, 보수, 가독성에 좋지 않을까?

// T가 int, double, char

template<typename T>
T Add(T a, T b)
{
	return a + b;
}
