#include "Scene.h"
#include "Common.h"

#include "Framework/Text.h"
#include "Framework/Input.h"
#include "Framework/Renderer.h"
#include "Framework/Timer.h"

#include "Player.h"

Scene g_Scene;

static ESceneType s_nextScene = SCENE_NULL;

void setCoord(COORD* coord, int16 x, int16 y)
{
	coord->X = x;
	coord->Y = y;
}

#pragma region TitleScene
typedef struct tagTitleSceneData
{
	Text TitleText[3][128];
	COORD TitleCoords[3];
} TitleSceneData;



void reset_title(TitleSceneData* data)
{
	TextCopyWithWhite(data->TitleText[0], L"스페이스키를");
	TextCopyWithWhite(data->TitleText[1], L"누르면");
	TextCopyWithWhite(data->TitleText[2], L"다음으로 넘어갑니다.");

	setCoord(&data->TitleCoords[0], 10, 0);
	setCoord(&data->TitleCoords[1], 25, 10);
	setCoord(&data->TitleCoords[2], 35, 20);
}

void init_title(void)
{
	g_Scene.Data = malloc(sizeof(TitleSceneData));

	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	reset_title(data);
}

void update_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	if (data->TitleCoords[0].Y < 10)
	{
		static float elapsedTime;

		elapsedTime += Timer_GetDeltaTime();
		if (elapsedTime >= 0.3f)
		{
			elapsedTime = 0.0f;
			
			++data->TitleCoords[0].Y;
		}
	}

	if (data->TitleCoords[2].Y > 10)
	{
		static float elapsedTime;

		elapsedTime += Timer_GetDeltaTime();
		if (elapsedTime >= 0.3f)
		{
			elapsedTime = 0.0f;

			--data->TitleCoords[2].Y;
		}
	}

	if (Input_GetKeyDown('R'))
	{
		reset_title(data);
	}

	if (Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_MAIN);
	}

	if (Input_GetKeyDown('T'))
	{
		Scene_SetNextScene(SCENE_EXTRA);
	}
}

void render_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 3; ++i)
	{
		Text* text = data->TitleText[i];
 		int32 len = TextLen(text);
		COORD coord = data->TitleCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y);
	}
}

void release_title(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

#pragma endregion

#pragma region MainScene

typedef struct tagMainSceneData
{
	Player	Player;
} MainSceneData;

void init_main(void)
{
	g_Scene.Data = malloc(sizeof(MainSceneData));

	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Init(&data->Player);
}

void update_main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Update(&data->Player);
}

void render_main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Render(&data->Player);
}

void release_main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Release(&data->Player);

	SafeFree(g_Scene.Data);
}
#pragma endregion

#pragma region extraScene
void init_extra(void)
{

}

void update_extra(void)
{
	

}

void render_extra(void)
{
	Text text[128];
	TextCopy(text, L"GAME OVER", TEXT_COLOR_GREEN);
	
	Renderer_DrawText(text, TextLen(text), 20, 10);
}

void release_extra(void)
{

}
#pragma endregion

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

void Scene_SetNextScene(ESceneType scene)
{
	assert(s_nextScene == SCENE_NULL);
	assert(SCENE_NULL < scene && scene < SCENE_MAX);

	s_nextScene = scene;
}

void Scene_Change(void)
{
	assert(s_nextScene != SCENE_NULL);

	if (g_Scene.Release)
	{
		g_Scene.Release();
	}

	switch (s_nextScene)
	{
	case SCENE_TITLE:
		g_Scene.Init = init_title;
		g_Scene.Update = update_title;
		g_Scene.Render = render_title;
		g_Scene.Release = release_title;
		break;
	case SCENE_MAIN:
		g_Scene.Init = init_main;
		g_Scene.Update = update_main;
		g_Scene.Render = render_main;
		g_Scene.Release = release_main;
		break;
	case SCENE_EXTRA:
		g_Scene.Init = init_extra;
		g_Scene.Update = update_extra;
		g_Scene.Render = render_extra;
		g_Scene.Release = release_extra;
		break;
	}

	g_Scene.Init();

	s_nextScene = SCENE_NULL;
}