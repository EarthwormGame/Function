#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>


#define FIELD_WIDTH 50   // 게임 영역 - 가로s
#define FIELD_HEIGHT 25   // 게임 영역 - 세로
#define MAP_X 3
#define MAP_Y 2


void gotoXY(int x, int y, char* s);
void reset();
void prey();
void gameOver();

int preyX(void);
int preyY(void);

int prey_m, prey_x, prey_y = 0;
int key, score;



// 콘솔 창 속 커서 이동
void gotoXY(int x, int y, char* s) {
    COORD pos; //COORD 구조체를 pos로 선언 

    pos.X = x + 20;
    pos.Y = y + 6;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //지정 된 콘솔 화면 버퍼에서 커서 위치를 설정해주는 함수
    // GetStdHandle(STD_OUTPUT_HANDLE) : 콘솔 창 화면 버퍼에 대한 표준 출력 핸들
    // pos : X,Y의 좌표 정보 저장
    printf("%s", s);
}



void filed() { // 게임 영역

    for (int i = 1; i < FIELD_WIDTH; i++)
    {
        gotoXY(i, 0, "─");
        gotoXY(i, FIELD_HEIGHT, "─");
    }

    for (int i = 1; i < FIELD_HEIGHT; i++)
    {
        gotoXY(0, i, "│");
        gotoXY(FIELD_WIDTH, i, "│");
    }

    gotoXY(0, 0, "┌");

    gotoXY(0, FIELD_HEIGHT, "└");

    gotoXY(FIELD_WIDTH, 0, "┐");

    gotoXY(FIELD_WIDTH, FIELD_HEIGHT, "┘");

    gotoXY(FIELD_WIDTH, 30, "\n");
}


void title() {

    filed();

    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 5, "┌──────────────────────────┐");
    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 6, "│         S N A K E        │");
    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 7, "└──────────────────────────┘");

    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 9, " [ PRESS ANY KEY TO START ] ");
      
    while (1) {
        if (_kbhit()) { //키입력받음 
            key = _getch();
            if (key == 27) {
                exit(0); // ESC키면 종료 
            }
            else {
                break; //아니면 그냥 계속 진행 
            }
        }
        gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 9, " [ PRESS ANY KEY TO START ] ");
        Sleep(400);
        gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 9, "                            ");
        Sleep(400);
    }

    reset();
}


void timer() {
    for (int sec = 10; sec > -1; sec--)
    {
        gotoXY(MAP_X - 2, MAP_Y + FIELD_HEIGHT, " TIME: ");
        printf("%d초..", sec);
        Sleep(1000);

        if (sec == 0)
        {

            gameOver();

        }
    }
}

void reset() {
    system("cls");

    filed();

    while (_kbhit()) _getch();

    prey_m = 0;
    score = 0;

    prey();
    timer();
}

void gameOver() {
    system("cls");
    filed();

    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 5, "┌──────────────────────────┐");
    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 6, "│         GAME OVER        │");
    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 7, "└──────────────────────────┘");

    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 10, MAP_Y + 9, "YOUR SCORE : ");
    printf(" %d ! ", score);

    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 13, "   ◇ SPACE BAR : Restart");
    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 14, "   ◇ ESC : Quit");

    while (1)
    {

        if (_kbhit()) { //키입력받음 
            key = _getch();
            if (key == 32) { // spacebar 누르면 재시작
                reset();
            }
            else if (key == 27) {
                exit(1); //ESC 키 누르면 종료
            }
        }
    }
}


void prey() {

    gotoXY(MAP_X + 8, MAP_Y + FIELD_HEIGHT, "          "); //점수표시 
    printf("SCORE: %3d", score);

    while (1) {

        if (prey_m == 0) { //prey_m의 초기값이 0이므로 처음에는 무조건 출력된다
           //먹이 랜덤 x, y좌표를 food_x, food_y에 각각 저장.
            prey_x = preyX();
            prey_y = preyY();

            gotoXY(prey_x, prey_y, "♣"); // x, y좌표에 먹이를 뿌려줌
            prey_m++;
        }
        else if (prey_m == 1)
        {
            for (int prey = 0; prey < prey_m; prey++)
            {
                prey_x = preyX();
                prey_y = preyY();

                gotoXY(prey_x, prey_y, "♣"); // x, y좌표에 먹이를 뿌려줌

            }
            prey_m++;
        }
        else {
            printf("먹이는 최대 2개까지 생성됩니다.");
        }
        break;
    }

}

int preyX() {
    prey_x = (rand() % 20 + 2) * 2 - 1;

    return prey_x;
}

int preyY() {
    prey_y = rand() % 20 + 2;

    return prey_y;
}

void noCunsor() { // 콘솔창의 커서 숨김
    HANDLE console;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    console = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = 0;
}

int main() {

    
    srand((unsigned int)time(NULL)); // seed 값으로 현재 시간값을 부여
    system("mode con:cols=90 lines=50"); // 콘솔창 크기 

    noCunsor();

    filed();
    title();


}