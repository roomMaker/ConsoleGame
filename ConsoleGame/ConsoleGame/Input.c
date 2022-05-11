#include "Input.h"
#include "Common.h"

#define IS_KEY_DOWN(vkey) (0x8000 & GetAsyncKeyState(vkey))
// ���� �������� Ű ����
bool s_prevKeyStates[256];

// ���� �������� Ű ����
bool s_currentKeyStates[256];

//uint8 s_key[2];
//uint8 s_oldDown;
//uint8 s_newDown;
// �Էºθ� �ʱ�ȭ�Ѵ�.
bool Input_Init(void)
{
	return true;
}

// �Էºθ� ������Ʈ�Ѵ�.
// ���� �������� Ű ���� ���� �� ���� �������� Ű ���¸� �����;� ��.
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

// ���� �����ӿ� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
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

// ���� �����ӿ� Ű�� �����ٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
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

// ���� �����Ӱ� ���� �����ӿ� ��� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
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