#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>


#define FIELD_WIDTH 50	// ���� ���� - ����
#define FIELD_HEIGHT 25	// ���� ���� - ����

void gotoXY(int x, int y);
int preyX(void);
int preyY(void);

int prey_m, prey_x, prey_y = 0;


// �ܼ� â �� Ŀ�� �̵�
void gotoXY(int x, int y) {
	COORD pos; //COORD ����ü�� pos�� ���� 
	
	pos.X = x + 20;
	pos.Y = y + 6;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //���� �� �ܼ� ȭ�� ���ۿ��� Ŀ�� ��ġ�� �������ִ� �Լ�
	// GetStdHandle(STD_OUTPUT_HANDLE) : �ܼ� â ȭ�� ���ۿ� ���� ǥ�� ��� �ڵ�
	// pos : X,Y�� ��ǥ ���� ����
}

void filed() { // ���� ����
	
	gotoXY(18, -3);
	printf("������ ����");

	for (int i = 1; i < FIELD_WIDTH; i++)
	{
		gotoXY(i, -5);
		printf("��");
	}
	
	for (int i = 1; i < FIELD_WIDTH; i++)
	{
		gotoXY(i, 0);
		printf("��");
		gotoXY(i, FIELD_HEIGHT);
		printf("��");
	}
	
	for (int i = 1; i < FIELD_HEIGHT; i++)
	{
		gotoXY(0, i);
		printf("��");
		gotoXY(FIELD_WIDTH, i);
		printf("��");
	}

	gotoXY(0, 0);
	printf("��");

	gotoXY(0, FIELD_HEIGHT);
	printf("��");

	gotoXY(FIELD_WIDTH, 0);
	printf("��");

	gotoXY(FIELD_WIDTH, FIELD_HEIGHT);
	printf("��");

	gotoXY(FIELD_WIDTH, 30);
	printf("\n");
}

void prey() {
	if (prey_m == 0) { //prey_m�� �ʱⰪ�� 0�̹Ƿ� ó������ ������ ��µȴ�
		//���� ���� x, y��ǥ�� food_x, food_y�� ���� ����.
		prey_x = preyX();
		prey_y = preyY();

		gotoXY(prey_x, prey_y);
		printf("��"); //������ �����ߴ� x, y��ǥ�� ���̸� �ѷ���
	}
}

int preyX(void) {
	prey_x = (rand() % 20 + 2) * 2 - 1;
	
	return prey_x;
}

int preyY(void) {
	prey_y = rand() % 20 + 2;

	return prey_y;
}

int main() {
	
	srand((unsigned int)time(NULL)); // seed ������ ���� �ð����� �ο�
	system("mode con:cols=90 lines=50");

	filed();
	prey();

}