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
/// 다음 씬으로 전환될 예정인가?
/// </summary>
/// <returns>다음 씬으로 전환될 예정이면 true, 아니면 false</returns>
bool Scene_IsSetNextScene(void);

/// <summary>
/// 다음 씬을 지정한다.
/// </summary>
/// <param name="scene">씬</param>
void Scene_SetNextScene(ESceneType scene);

/// <summary>
/// 씬 전환
/// </summary>
/// <param name="scene"></param>
void scene_Change(void);