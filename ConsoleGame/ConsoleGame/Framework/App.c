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
    sprintf_s(str, sizeof(str), "���� �Է� ����");
    
    if (Input_GetKey(VK_UP))
    {
        sprintf_s(str, sizeof(str), "���� ȭ��ǥ ����");
    }
    if (Input_GetKey(VK_DOWN))
    {
        sprintf_s(str, sizeof(str), "�Ʒ��� ȭ��ǥ ����");
    }

    if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT))
    {
        sprintf_s(str, sizeof(str), "����, ������ ȭ��ǥ ���ÿ� ����");
    }
    
    // short : 2����Ʈ
    // 0000 0000 0000 0000 : Ű�� ���� ���� -> 0x0000
    // 1000 0000 0000 0000 : Ű�� ���� ���� -> 0x8000
    // 1000 0000 0000 0001 : Ű�� ��� ���� ���� -> 0x8001 (���⸻��)
    
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