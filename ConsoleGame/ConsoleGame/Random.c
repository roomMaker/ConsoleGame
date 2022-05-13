#include "Common.h"
#include "Random.h"
 
#define beakman 1000000
int32 s_minInclusive, s_maxExclusive;
// 랜덤 초기화
bool Random_Init()
{
	srand(time(NULL));
}

// [) -> [ == 포함 ( == 비포함

/// 무작위 정수를 가져온다 -21억 ~ 21억

int32 s_randNumber;

int32 Random_GetNumberFromRange(int32 minInclusive, int32 maxExclusive)
{
	
	s_randNumber = maxExclusive - (rand() << 15|rand()) % (maxExclusive - minInclusive);

	return s_randNumber;
}
// -100~100   100 - rand() % 201;

// 무작위 실수를 가져온다
float s_randfNumber;
int32 intger1, intger2;
float Random_GetFNumberFromRange(float minInclusive, float maxExclusive)
{
	intger1 = minInclusive * beakman;
	intger2 = maxExclusive * beakman;
	s_randfNumber = intger2 - (rand() << 16 | rand()) % (intger2 - intger1);
		//s_randfNumber = maxExclusive - rand() % (maxExclusive - minInclusive);
		//s_randfNumber = ((maxExclusive - minInclusive) / rand()) * 100;
	return s_randfNumber / beakman;
}