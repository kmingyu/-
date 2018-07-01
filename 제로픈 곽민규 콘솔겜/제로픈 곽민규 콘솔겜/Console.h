#pragma once

//cpp에서 쓰이는 입출력 헤더파일
#include <iostream>
#include <Windows.h>

using namespace std;

// 커서 이동 함수
void moveCursor(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 적용
}

// 커서 표시 여부 설정 함수
void visibleCursor(bool visible = true) {
	CONSOLE_CURSOR_INFO curinfo; // 커서 구조체

	curinfo.dwSize = 10;
	curinfo.bVisible = visible; // 버퍼 표시 여부

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo); // 적용
}

// 콘솔 초기화
void consoleClear(COORD startPos = { 0, 0 }, COORD endPos = { 100, 100 }) {
	for (int y = startPos.Y; y < endPos.Y; y++) {
		moveCursor(startPos.X, y);
		for (int x = startPos.X; x < endPos.X; x++) {
			cout << ' ';
		}
	}
}