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
    // ��ʽ�
    // ������ : �ð�
    // 1 : deltaTime = fps : 1
    // 1 = deltaTime * fps
    // fps = 1 / deltaTime
    //char str[128] = "";
    //sprintf_s(str, sizeof(str), "���� FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
    //Renderer_DrawText(str, strlen(str));
    elapsedTime += DELTA_TIME;
    if (elapsedTime >= 0.5)
    {
        elapsedTime = 0.0f;
        canShow = !canShow;
        
    }
    if (canShow)
    {
        Renderer_DrawText("�� �ؽ�Ʈ�� �����Դϴ�.", sizeof("�� �ؽ�Ʈ�� �����Դϴ�."));
    }
    
    // 0.5�ʸ��� �����̴� �ؽ�Ʈ�� ����ÿ�.
    // DeltaTime +=

    // short : 2����Ʈ
    // 0000 0000 0000 0000 : Ű�� ���� ���� -> 0x0000
    // 1000 0000 0000 0000 : Ű�� ���� ���� -> 0x8000
    // 1000 0000 0000 0001 : Ű�� ��� ���� ���� -> 0x8001 (���⸻��)
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

    // Game Loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
    while (true)
    {
        if (Timer_Update())
        {
            processInput();      // �Է� ó��
            update();         // ���� ������Ʈ
            render();         // ���� ���
        }
        //Timer_Update();
        // DeltaTime : ������ ���� �ð�. ���� ���������κ��� ���� �������� ������ �� ������ �ð�
       
    }

    return 0;
}