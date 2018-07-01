#pragma once
#include "Console.h"

//�� �̸� ����
typedef enum  {
	BLACK, DARK_BLUE, DARK_GREEN, DARK_AQUA, DARK_RED, PURPLE, DARK_YELLOW, GREY, DARK_GREY, VIOLET, GREEN, AQUA, RED, PINK, YELLOW, WHITE
}color;

// ���� �� ����
void setTextColor(color text = WHITE, color background = BLACK) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (background << 4)); // ����
}

// ��Ʈ ���� �Լ�
void setFontStyle(unsigned int fontsize = 15, bool bold = false) {
	CONSOLE_FONT_INFOEX fontinfo; // ���� ����ü

	fontinfo.cbSize = sizeof(fontinfo); // ����ü ũ��
	fontinfo.dwFontSize.Y = fontsize; // ���� ũ��

									  // ���� �β�
	if (bold == false)
		fontinfo.FontWeight = 400; // ���� ����
	else
		fontinfo.FontWeight = 700; // �β��� ����

	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), true, &fontinfo); // ����
}

// â ũ�� ���� �Լ�
void setWindowSize(short x, short y) {
	SMALL_RECT windowsize = { 0, 0, x, y }; // ũ�� ���� (ũ�� ����: 1byte ����)
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &windowsize); // ����
}