#include "App.h"

bool App_Init()
{
	return true;
}

int32 App_Run()
{
	//Game Loop : ������ ���۽�Ű�� ����, ������(Frame) �̶�� �Ѵ�.
	while (true)
	{
		processInput();
		update();
		render();
	}

	return 0;
}