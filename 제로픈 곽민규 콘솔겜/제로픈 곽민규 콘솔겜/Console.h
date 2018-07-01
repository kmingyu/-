#pragma once

//cpp���� ���̴� ����� �������
#include <iostream>
#include <Windows.h>

using namespace std;

// Ŀ�� �̵� �Լ�
void moveCursor(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // ����
}

// Ŀ�� ǥ�� ���� ���� �Լ�
void visibleCursor(bool visible = true) {
	CONSOLE_CURSOR_INFO curinfo; // Ŀ�� ����ü

	curinfo.dwSize = 10;
	curinfo.bVisible = visible; // ���� ǥ�� ����

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo); // ����
}

// �ܼ� �ʱ�ȭ
void consoleClear(COORD startPos = { 0, 0 }, COORD endPos = { 100, 100 }) {
	for (int y = startPos.Y; y < endPos.Y; y++) {
		moveCursor(startPos.X, y);
		for (int x = startPos.X; x < endPos.X; x++) {
			cout << ' ';
		}
	}
}