#include "App.h"

bool App_Init()
{
	return true;
}

int32 App_Run()
{
	//Game Loop : 게임을 동작시키는 루프, 프레임(Frame) 이라고도 한다.
	while (true)
	{
		processInput();
		update();
		render();
	}

	return 0;
}