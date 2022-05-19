#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>


#define FIELD_WIDTH 50	// 게임 영역 - 가로
#define FIELD_HEIGHT 25	// 게임 영역 - 세로

void gotoXY(int x, int y);
int preyX(void);
int preyY(void);

int prey_m, prey_x, prey_y = 0;


// 콘솔 창 속 커서 이동
void gotoXY(int x, int y) {
	COORD pos; //COORD 구조체를 pos로 선언 
	
	pos.X = x + 20;
	pos.Y = y + 6;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //지정 된 콘솔 화면 버퍼에서 커서 위치를 설정해주는 함수
	// GetStdHandle(STD_OUTPUT_HANDLE) : 콘솔 창 화면 버퍼에 대한 표준 출력 핸들
	// pos : X,Y의 좌표 정보 저장
}

void filed() { // 게임 영역
	
	gotoXY(18, -3);
	printf("지렁이 게임");

	for (int i = 1; i < FIELD_WIDTH; i++)
	{
		gotoXY(i, -5);
		printf("─");
	}
	
	for (int i = 1; i < FIELD_WIDTH; i++)
	{
		gotoXY(i, 0);
		printf("─");
		gotoXY(i, FIELD_HEIGHT);
		printf("─");
	}
	
	for (int i = 1; i < FIELD_HEIGHT; i++)
	{
		gotoXY(0, i);
		printf("│");
		gotoXY(FIELD_WIDTH, i);
		printf("│");
	}

	gotoXY(0, 0);
	printf("┌");

	gotoXY(0, FIELD_HEIGHT);
	printf("└");

	gotoXY(FIELD_WIDTH, 0);
	printf("┐");

	gotoXY(FIELD_WIDTH, FIELD_HEIGHT);
	printf("┘");

	gotoXY(FIELD_WIDTH, 30);
	printf("\n");
}

void prey() {
	if (prey_m == 0) { //food_switch의 초기값이 0이므로 처음에는 무조건 출력된다
		//먹이 랜덤 x, y좌표를 food_x, food_y에 각각 저장.
		prey_x = preyX();
		prey_y = preyY();

		gotoXY(prey_x, prey_y);
		printf("♣"); //위에서 저장했던 x, y좌표에 먹이를 뿌려줌
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

	system("mode con:cols=90 lines=50");

	filed();
	prey();

}