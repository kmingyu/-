#include <conio.h>

#include "game.h"

#define WIDTH 64
#define HEIGHT 18

int main(void) {

	bool god = true;
	while (god) {

		bool play = false;

		setWindowSize(WIDTH, HEIGHT);
		setTextColor(WHITE, WHITE);
		consoleClear({ 0, 0 }, { WIDTH + 1, HEIGHT + 1 });

		srand(time(NULL));
		for (int i = 0; i < 10; i++) {
			barrier[i].pos = (i == 0) ? 54 : (barrier[i - 1].pos + barrier[i - 1].len) + (rand() % 3 + 5) * 2;
			barrier[i].len = rand() % 3 + 1;
		}

		setTextColor(WHITE, DARK_GREY);
		consoleClear({ 0, HEIGHT - 4 }, { WIDTH + 1, HEIGHT + 1 });

		setTextColor(DARK_BLUE, WHITE);
		moveCursor(10, HEIGHT - 5);
		printf("▣");

		Title({ 17, 2 });

		setTextColor(BLACK, WHITE);
		moveCursor(21, 11);
		printf("시작하려면 점프하세요!");

		if (_getch() == ' ') {
			consoleClear({ 0, 0 }, { WIDTH + 1, 12 });
			play = true;
		}

		while (play) {
			if (!game()) {
				moveCursor(28, 6);
				printf("GAME OVER");
				moveCursor(27, 8);
				printf("ReTry? (Y/N)");

				char ch = _getch();
				if (ch == 'n' || ch == 'N') {
					play = false;
					god = false;
				}
				else {
					play = false;
				}
			}
		}
	}
	return 0;
}