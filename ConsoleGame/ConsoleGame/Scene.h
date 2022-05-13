#pragma once

#include "Type.h"

typedef struct tagScene
{
	void (*Init)(void);
	void (*Update)(void);
	void (*Render)(void);
	void (*Release)(void);
	void* Data;

}Scene;

typedef enum tagSceneType
{
	SCENE_NULL,
	SCENE_TITLE,
	SCENE_MAX
} ESceneType;

extern Scene g_Scene;

/// <summary>
/// ���� ������ ��ȯ�� �����ΰ�?
/// </summary>
/// <returns>���� ������ ��ȯ�� �����̸� true, �ƴϸ� false</returns>
bool Scene_IsSetNextScene(void);

/// <summary>
/// ���� ���� �����Ѵ�.
/// </summary>
/// <param name="scene">��</param>
void Scene_SetNextScene(ESceneType scene);

/// <summary>
/// �� ��ȯ
/// </summary>
/// <param name="scene"></param>
void scene_Change(void);