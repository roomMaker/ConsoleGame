#include "Input.h"
#include "Common.h"

#define IS_KEY_DOWN(vkey) (0x8000 & GetAsyncKeyState(vkey))
// 이전 프레임의 키 상태
bool s_prevKeyStates[256];

// 현재 프레임의 키 상태
bool s_currentKeyStates[256];

//uint8 s_key[2];
//uint8 s_oldDown;
//uint8 s_newDown;
// 입력부를 초기화한다.
bool Input_Init(void)
{
	return true;
}

// 입력부를 업데이트한다.
// 이전 프레임의 키 내용 저장 및 현재 프레임의 키 상태를 가져와야 함.
void Input_Update(void)
{
	memcpy(s_prevKeyStates, s_currentKeyStates, sizeof(s_currentKeyStates));

	for (int32 vkey = 0; vkey < 256; ++vkey)
	{
		if (IS_KEY_DOWN(vkey))
		{
			s_currentKeyStates[vkey] = true;
		}
		else
		{
			s_currentKeyStates[vkey] = false;
		}
	}
}

// 현재 프레임에 키가 눌렸다면 true, 아니면 false
// vkey : 가상 키코드
bool Input_GetKeyDown(uint8 vkey)
{
	if (false == s_prevKeyStates[vkey] && true == s_currentKeyStates[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
	/*if (GetAsyncKeyState(vkey) & 0x8000)
	{
		return true;
	}
		return false;*/
}

// 현재 프레임에 키가 떼졌다면 true, 아니면 false
// vkey : 가상 키코드
bool Input_GetKeyUp(uint8 vkey)
{
	if (true == s_prevKeyStates[vkey] && false == s_currentKeyStates[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
	/*if (GetAsyncKeyState(vkey) & 0x0000)
	{
		return true;
	}
		return false;*/
}

// 이전 프레임과 현재 프레임에 모두 키가 눌렸다면 true, 아니면 false
// vkey : 가상 키코드
bool Input_GetKey(uint8 vkey)
{
	if (true == s_prevKeyStates[vkey] && true == s_currentKeyStates[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
	/*s_newDown = vkey;
	s_oldDown = s_newDown;
	if (GetAsyncKeyState(s_newDown) & 0x8000 && GetAsyncKeyState(s_oldDown) & 0x8000)
	{
		return true;
	}
	return false;*/
	
}