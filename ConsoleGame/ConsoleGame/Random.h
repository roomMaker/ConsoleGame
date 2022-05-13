#pragma once

#include "Type.h"

// 랜덤 초기화
bool Random_Init();

// [) -> [ == 포함 ( == 비포함
/// <summary>
/// 무작위 정수를 가져온다
/// </summary>
/// <param name="minInclusive"></param>
/// <param name="maxExclusive"></param>
/// <returns>[minInclusive, maxExclusive) 범위의 무작위 정수</returns>
int32 Random_GetNumberFromRange(int32 minInclusive, int32 maxExclusive);


/// <summary>
/// 무작위 실수를 가져온다
/// </summary>
/// <param name="minInclusive"></param>
/// <param name="maxExclusive"></param>
/// <returns>[minInclusive, maxExclusive] 범위의 무작위 실수</returns>
float Random_GetFNumberFromRange(float minInclusive, float maxInclusive);