#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD CursorPosition = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
int main()
{     //게임 함수 입력 이후에 좌표설정해서 위치 정할 것
    int hour, min, sec;
    hour = 0;
    min = 0;
    sec = 30;

    int before_start();

    int before_start(); {
        srand((int)time(NULL));
        for (int sec = 3; sec > 0; sec--)
        {
            gotoxy(0, 5);
            printf("게임시작 %d초전..", sec);
            Sleep(1000);
        }
    }

    while (1) { //타이머와 게임화면 동시 진행
        system("cls");
        printf("%02d:%02d:%02d", hour, min, sec);
        sec--;
        if (sec == 60) { min++;     sec = 0; }
        if (min == 60) { hour++;    min = 0; }
        if (hour == 24) { hour = min = sec = 0; }
        if (sec == 0)
            break;
        Sleep(1000);
    }
    return 0;
}
