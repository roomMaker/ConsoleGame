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

	TextCopyWithWhite(data->TitleText, L"�������");

	if (Input_GetKey(VK_SPACE))
	{
		TextCopy(data->TitleText, L"�޷�");
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
	// ���� �� �����ϱ�
	s_nextScene = scene;
}

void scene_Change(void) // �߿�!!
{
	assert(s_nextScene == SCENE_NULL);
	// ���� ���� ���� -> Release() ȣ��
	Release(g_Scene);
	// ������ �ε��� ���� ���缭 gScene�� �����ؾ���
	g_Scene.Update = s_nextScene;
	// ���� ���� �ʱ�ȭ -> Init() ȣ��
	Init();
	// s_nextScene = 0;
	s_nextScene = 0;
}