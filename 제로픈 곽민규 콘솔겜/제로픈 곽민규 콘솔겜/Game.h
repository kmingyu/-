#pragma once

#include "UI.h"
#include <stdlib.h>
#include <time.h>

#define GAME_SPEED 40

typedef struct {

	int pos;
	int len;

}spike;

spike barrier[10] = { 0 };
int playerY = 13, jumpCool = 0, score = 0;
bool nowJump = false, canJump = true;

//Title 저장 함수
int Tit[7][15] = {

{ 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
{ 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
{ 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1 },
{ 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
{ 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
{ 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1 }

};

//Title 출력 함수
void Title(COORD pos) {
	moveCursor(pos.X, pos.Y);
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 15; x++) {
			if (Tit[y][x]) {
				setTextColor(BLACK, BLACK);
				cout << "  ";
			}
			else {
				setTextColor(WHITE, WHITE);
				cout << "  ";
			}
		}
		moveCursor(pos.X, pos.Y + y + 1);
	}
}

//장애물 출력하는 함수
void printBarrier(void) {
	for (int i = 0; i < 10; i++) {
		if (barrier[i].pos > 54) {
			break;
		}
		
		moveCursor(10 + barrier[i].pos, 13);
		for (int j = 0; j < barrier[i].len; j++) {
			cout << "▲";
		}
	}
}

//랜덤으로 장애물 생성하는 함수
void randBarrier(void) {
	barrier[9].len = rand() % 3 + 1;
	barrier[9].pos = barrier[8].pos + barrier[8].len + (rand() % 3 + 5) * 2 + 1;
}

//장애물이 화면 밖으로 나가면 순서대로 밀어주는 함수 
void pushBarrier(void){
	for (int i = 1; i < 10; i++) {
		barrier[i - 1] = barrier[i];
	}
}

//플레이어 점프 함수
bool game(void) {
	if (playerY==13) {
		for (int i = 0; i < 3; i++) {
			if (barrier[i].pos <= 0 && barrier[i].pos+barrier[i].len * 2 >= 0) {
				score = 0;
				return false;
			}
		 }
	}


	if (canJump) {
		if (_kbhit()) {
			char ch = _getch();
			if (ch == ' ') {
				canJump = true;
				nowJump = true;
			}
		}
	}

	if (nowJump == true) {
		switch (jumpCool) {
		case 0:
			moveCursor(10, playerY);
			printf("  ");
			playerY--;
			jumpCool++;
			break;
		case 1:
			moveCursor(10, playerY);
			printf("  ");
			playerY--;
			jumpCool++;
			break;
		case 3:
			moveCursor(10, playerY);
			printf("  ");
			playerY--;
			jumpCool++;
			break;
		case 7:
			moveCursor(10, playerY);
			printf("  ");
			playerY++;
			jumpCool++;
			break;
		case 8:
			moveCursor(10, playerY);
			printf("  ");
			playerY++;
			jumpCool++;
			break;
		case 9:
			moveCursor(10, playerY);
			printf("  ");
			playerY++;
			canJump = true;
			nowJump = false;
			jumpCool = 0;
			break;
		default:
			jumpCool++;
			break;
		}
	}

	setTextColor(BLACK, WHITE);
	printBarrier();
	setTextColor(DARK_BLUE,WHITE);
	moveCursor(10, playerY);
	printf("▣");

	for (int i = 0; i < 10; i++) {
		barrier[i].pos--;
		if (barrier[i].pos == -10) {
			pushBarrier();
			randBarrier();
		}
	}

	moveCursor(2, 1);
	printf("Score: %d", score);

	Sleep(GAME_SPEED);

	score += 10;

	return true;
}