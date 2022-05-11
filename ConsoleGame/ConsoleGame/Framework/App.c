#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"

bool App_Init()
{
    if (false == Renderer_Init())
    {
        return false;
    }

    if (false == Input_Init())
    {
        return false;
    }

    return true;
}

void processInput()
{
    Input_Update();
}

float elapsedTime;
bool canShow = false;

char str[128];
void update()
{
    sprintf_s(str, sizeof(str), "현재 입력 없음");
    
    if (Input_GetKey(VK_UP))
    {
        sprintf_s(str, sizeof(str), "위쪽 화살표 눌림");
    }
    if (Input_GetKey(VK_DOWN))
    {
        sprintf_s(str, sizeof(str), "아래쪽 화살표 눌림");
    }

    if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT))
    {
        sprintf_s(str, sizeof(str), "왼쪽, 오른쪽 화살표 동시에 눌림");
    }
    
    // short : 2바이트
    // 0000 0000 0000 0000 : 키가 떼진 상태 -> 0x0000
    // 1000 0000 0000 0000 : 키가 눌린 상태 -> 0x8000
    // 1000 0000 0000 0001 : 키가 계속 눌린 상태 -> 0x8001 (쓰기말기)
    
}

void render()
{
    Renderer_DrawText(str, strlen(str));
    Renderer_Flip();
}

void cleanup()
{
    Renderer_Cleanup();
}

int32 App_Run()
{
    atexit(cleanup);

    Timer_Init(60);

    // Game Loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
    while (true)
    {
        if (Timer_Update())
        {
            processInput();      // 입력 처리
            update();         // 게임 업데이트
            render();         // 게임 출력
        }
        //Timer_Update();
        // DeltaTime : 프레임 간의 시간. 이전 프레임으로부터 현재 프레임을 시작할 때 까지의 시간
       
    }

    return 0;
}