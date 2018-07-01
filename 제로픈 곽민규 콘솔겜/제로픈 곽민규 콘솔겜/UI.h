#pragma once
#include "Console.h"

//색 이름 지정
typedef enum  {
	BLACK, DARK_BLUE, DARK_GREEN, DARK_AQUA, DARK_RED, PURPLE, DARK_YELLOW, GREY, DARK_GREY, VIOLET, GREEN, AQUA, RED, PINK, YELLOW, WHITE
}color;

// 글자 색 설정
void setTextColor(color text = WHITE, color background = BLACK) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (background << 4)); // 적용
}

// 폰트 설정 함수
void setFontStyle(unsigned int fontsize = 15, bool bold = false) {
	CONSOLE_FONT_INFOEX fontinfo; // 글자 구조체

	fontinfo.cbSize = sizeof(fontinfo); // 구조체 크기
	fontinfo.dwFontSize.Y = fontsize; // 글자 크기

									  // 글자 두께
	if (bold == false)
		fontinfo.FontWeight = 400; // 보통 글자
	else
		fontinfo.FontWeight = 700; // 두꺼운 글자

	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), true, &fontinfo); // 적용
}

// 창 크기 설정 함수
void setWindowSize(short x, short y) {
	SMALL_RECT windowsize = { 0, 0, x, y }; // 크기 지정 (크기 단위: 1byte 문자)
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &windowsize); // 적용
}