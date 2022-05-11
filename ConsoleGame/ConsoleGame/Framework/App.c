#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"

bool App_Init()
{
    if (false == Renderer_Init())
    {
        return false;
    }

    return true;
}

void processInput()
{

}

float elapsedTime;
bool canShow = false;
void update()
{
    // 비례식
    // 프레임 : 시간
    // 1 : deltaTime = fps : 1
    // 1 = deltaTime * fps
    // fps = 1 / deltaTime
    //char str[128] = "";
    //sprintf_s(str, sizeof(str), "현재 FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
    //Renderer_DrawText(str, strlen(str));
    elapsedTime += DELTA_TIME;
    if (elapsedTime >= 0.5)
    {
        elapsedTime = 0.0f;
        canShow = !canShow;
        
    }
    if (canShow)
    {
        Renderer_DrawText("이 텍스트는 깜빡입니다.", sizeof("이 텍스트는 깜빡입니다."));
    }
    
    // 0.5초마다 깜빡이는 텍스트를 만드시오.
    // DeltaTime +=

    // short : 2바이트
    // 0000 0000 0000 0000 : 키가 떼진 상태 -> 0x0000
    // 1000 0000 0000 0000 : 키가 눌린 상태 -> 0x8000
    // 1000 0000 0000 0001 : 키가 계속 눌린 상태 -> 0x8001 (쓰기말기)
    //GetAsyncKeyState();
}

void render()
{
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