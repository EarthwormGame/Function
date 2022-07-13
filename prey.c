#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>


#define FIELD_WIDTH 50   // ���� ���� - ����s
#define FIELD_HEIGHT 25   // ���� ���� - ����
#define MAP_X 3
#define MAP_Y 2

void gotoXY(int x, int y, char* s);
void reset();
int preyX(void);
int preyY(void);

int prey_m, prey_x, prey_y = 0;
int key, score;



// �ܼ� â �� Ŀ�� �̵�
void gotoXY(int x, int y, char* s) {
    COORD pos; //COORD ����ü�� pos�� ���� 

    pos.X = x + 20;
    pos.Y = y + 6;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //���� �� �ܼ� ȭ�� ���ۿ��� Ŀ�� ��ġ�� �������ִ� �Լ�
    // GetStdHandle(STD_OUTPUT_HANDLE) : �ܼ� â ȭ�� ���ۿ� ���� ǥ�� ��� �ڵ�
    // pos : X,Y�� ��ǥ ���� ����
    printf("%s", s);
}



void filed() { // ���� ����

    for (int i = 1; i < FIELD_WIDTH; i++)
    {
        gotoXY(i, 0, "��");
        gotoXY(i, FIELD_HEIGHT, "��");
    }

    for (int i = 1; i < FIELD_HEIGHT; i++)
    {
        gotoXY(0, i, "��");
        gotoXY(FIELD_WIDTH, i, "��");
    }

    gotoXY(0, 0, "��");

    gotoXY(0, FIELD_HEIGHT, "��");

    gotoXY(FIELD_WIDTH, 0, "��");

    gotoXY(FIELD_WIDTH, FIELD_HEIGHT, "��");

    gotoXY(FIELD_WIDTH, 30, "\n");
}


void title() {

    filed();

    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 5, "��������������������������������������������������������");
    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 6, "��         S N A K E        ��");
    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 7, "��������������������������������������������������������");

    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 9, " [ PRESS ANY KEY TO START ] ");
    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 13, "   �� ESC : Quit              ");

    while (1) {
        if (_kbhit()) { //Ű�Է¹��� 
            key = _getch();
            if (key == 27) {
                exit(0); // ESCŰ�� ���� 
            }
            else {
                break; //�ƴϸ� �׳� ��� ���� 
            }
        }
        gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 9, " [ PRESS ANY KEY TO START ] ");
        Sleep(400);
        gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 9, "                            ");
        Sleep(400);
    }

    reset();
}


void prey() {

    gotoXY(MAP_X - 2.5, MAP_Y + FIELD_HEIGHT, " YOUR SCORE: "); //����ǥ�� 
    printf("%3d, LAST SCORE: %3d, BEST SCORE: %3d", score, score, score);

    while (1) {

        if (prey_m == 0) { //prey_m�� �ʱⰪ�� 0�̹Ƿ� ó������ ������ ��µȴ�
           //���� ���� x, y��ǥ�� food_x, food_y�� ���� ����.
            prey_x = preyX();
            prey_y = preyY();

            gotoXY(prey_x, prey_y, "��"); // x, y��ǥ�� ���̸� �ѷ���
            prey_m++;
        }
        else if (prey_m == 1)
        {
            for (int prey = 0; prey < prey_m; prey++)
            {
                prey_x = preyX();
                prey_y = preyY();

                gotoXY(prey_x, prey_y, "��"); // x, y��ǥ�� ���̸� �ѷ���

            }
            prey_m++;
        }
        else {
            printf("���̴� �ִ� 2������ �����˴ϴ�.");
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


void reset() {
    system("cls");

    filed();

    while (_kbhit()) _getch();

    score = 0;
    prey();
}

void gameOver() {

    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 5, "��������������������������������������������������������");
    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 6, "��       GAME OVER        ��");
    gotoXY(MAP_X + (FIELD_WIDTH / 2) - 15, MAP_Y + 7, "��������������������������������������������������������");

}

int main() {

    srand((unsigned int)time(NULL)); // seed ������ ���� �ð����� �ο�
    system("mode con:cols=90 lines=50"); // �ܼ�â ũ�� 

    filed();
    title();


}