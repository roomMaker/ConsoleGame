#pragma once

#include "Type.h"
#include "Text.h"

/// <summary>
/// �������� �ʱ�ȭ�Ѵ�.
/// </summary>
/// <returns>�ʱ�ȭ�� ���������� true, �ƴϸ� false</returns>
bool	Renderer_Init(void);

/// <summary>
/// �������� �����Ѵ�.
/// </summary>
void	Renderer_Cleanup(void);

/// <summary>
/// ȭ���� �ٲ۴�.
/// </summary>
void	Renderer_Flip(void);


void Renderer_DrawText(const Text* text, int32 numberOfChar, int32 x, int32 y);