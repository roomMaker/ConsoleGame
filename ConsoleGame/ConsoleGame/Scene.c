#include "Scene.h"
#include "Common.h"

#include "Text.h"
#include "Input.h"
#include "Renderer.h"

Scene g_Scene;

static ESceneType s_nextScene = 0;

Text str[128];

typedef struct tagTitleSceneData
{
	Text TitleText[128];
}TitleSceneData;

void titleSceneInit(void)
{
	g_Scene.Data = malloc(sizeof(TitleSceneData));
}

void titleSceneUpdate(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	TextCopyWithWhite(data->TitleText, L"테일즈런너");

	if (Input_GetKey(VK_SPACE))
	{
		TextCopy(data->TitleText, L"메롱");
	}
}

void titleSceneRender(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;
	Renderer_DrawText(data->TitleText, TextLen(data->TitleText), 0, 0);
}

void titleSceneRelease(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

bool Scene_IsSetNextScene(void)
{
	if (SCENE_NULL == s_nextScene)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Scene_SetNextScene(int32 scene)
{
	assert(s_nextScene != SCENE_NULL);
	assert(SCENE_NULL <= scene && scene < SCENE_MAX);
	// 다음 씬 지정하기
	s_nextScene = scene;
}

void scene_Change(void) // 중요!!
{
	assert(s_nextScene == SCENE_NULL);
	// 이전 씬을 정리 -> Release() 호출
	Release(g_Scene);
	// 다음에 로드할 씬에 맞춰서 gScene을 구성해야함
	g_Scene.Update = s_nextScene;
	// 다음 씬을 초기화 -> Init() 호출
	Init();
	// s_nextScene = 0;
	s_nextScene = 0;
}