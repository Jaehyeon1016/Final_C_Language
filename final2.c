
#include <stdio.h>
#include <conio.h>
#include <process.h>


int score = 0, a = 3, star = 1, lp=100;
int map[19][19] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1,1,1,1,1,1,1,1,1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 2,0,0,0,0,0,0,0,0,1},
	{1, 0, 1, 0, 1, 1, 1, 1, 1, 1,1,1,1,1,1,1,1,0,1},
	{1, 0, 1, 0, 1, 0, 1, 0, 2, 0,0,0,1,0,0,0,0,0,1},
	{1, 2, 1, 0, 1, 0, 1, 0, 1, 0,1,1,1,0,1,1,1,0,1},
	{1, 0, 0, 2, 1, 2, 0, 0, 1, 0,0,0,1,0,0,0,1,0,1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1,1,0,1,1,1,0,1,0,1},
	{1, 0, 1, 0, 0, 0, 0, 2, 1, 0,0,0,0,0,1,0,1,0,1},
	{1, 2, 1, 0, 1, 0, 1, 0, 1, 0,1,1,1,1,1,0,1,0,1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0,0,0,1,0,0,0,1,0,1},
	{1, 0, 1, 1, 1, 0, 1, 0, 1, 0,1,0,1,0,1,1,1,0,1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0,1,0,1,0,1,0,1,0,1},
	{1, 1, 1, 0, 1, 0, 1, 0, 1, 1,1,0,1,0,1,0,1,0,1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 0,1,0,1,0,1,0,1,0,1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 0,1,0,1,0,1,0,1,0,1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0,0,0,1,0,1,0,0,0,1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1,1,0,1,0,1,1,1,1,1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,1,0,0,0,0,0,7},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1,1,1,1,1,1,1,1,1},
};
void print_maze() {
	system("cls");
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			//printf("%d ", map[i][j]);
			if (map[i][j] == 1) {
				printf("■");
			}else if(map[i][j] == 0 || map[i][j] == 7) {
				printf("  ");
			}
			else if (map[i][j] == 9) {
				printf("◎");
			}
			else{
				printf("★");
			}
		}
		printf("\n");
	}
	printf("score : %d", score);
	printf("\nLife Point: %d", lp);
}
void clear() {
	system("cls");
	printf("Congratulation! You cleared the maze.\n");
	printf("score : %d", score);
	printf("\nLife Point: %d", lp);
	a = 4;
}

void lose() {
	system("cls");
	printf("You died lonely in the maze...\n");
	printf("score : %d", score);
	printf("\nLife Point: %d", lp);
	a = 4;
}

void quiz() {
	int ans;
	int b = 4;
	while (b == 4) {
		switch (star) {
		case 1:
			printf("\nQ: When is the foundation day of Cooper Union? \n");
			printf("\n");
			printf("1:1920  2:1867  3:1859  4:1923 \n");
			scanf_s("%d", &ans);
			if (ans == 3) {
				printf("Correct.");
				score += 5;
				lp += 10;
				b = 5;
				break;
			}
			else if (ans == 2 || ans == 1 || ans == 4) {
				printf("Wrong.");
				lp -= 4;
				b = 5;
				break;
			}
			else {
				printf("Invalid input. Type Again.");
				break;
			}
		case 2:
			printf("\nQ: What is the longest that an elephant has ever lived? (That we know of) \n");
			printf("\n");
			printf("1:86  2:57  3:103  4:33 \n");
			scanf_s("%d", &ans);
			if (ans == 1) {
				printf("Correct.");
				score += 5;
				lp += 10;
				b = 5;
				break;
			}
			else if (ans == 2 || ans == 3 || ans == 4) {
				printf("Wrong.");
				lp -= 4;
				b = 5;
				break;
			}
			else {
				printf("Invalid input. Type Again.");
				break;
			}
		case 3:
			printf("\nQ: In darts, what's the most points you can score with a single throw? \n");
			printf("\n");
			printf("1:20  2:50  3:60  4:100 \n");
			scanf_s("%d", &ans);
			if (ans == 3) {
				printf("Correct.");
				score += 5;
				lp += 10;
				b = 5;
				break;
			}
			else if (ans == 2 || ans == 4 || ans == 1) {
				printf("Wrong.");
				lp -= 4;
				b = 5;
				break;
			}
			else {
				printf("Invalid input. Type Again.");
				break;
			}
		default:
			printf("\nNo quiz.");
			b = 5;
			break;
			
		}
	}
	star++;

}

void special(int* a) {
	
	if (*a == 2) {
		
		quiz();
	
	}
	lp--;
	*a = 9;
}

int main()
{
	int x = 1, y = 1, z;
	int key;
	while (a < 4) {
		printf("Type 1 to play the game. : \n");
		scanf_s("%d", &z);
		if (z == 1) {
			break;
		}
		else {
			printf("%s", "Invalid value. Type again.\n");
		}
	}

	map[x][y] = 9;
	print_maze();

	while (a < 4) {
		if (_kbhit()) {
			key = _getch();
			if (key == 224 || key == 0) {
				key = _getch();
				switch (key) {
				case 72: // up
					if (map[x - 1][y] == 1) break;
					map[x][y] = 0;
					special(&map[x - 1][y]);
					x--;
					if (lp <= 0) { lose(); break; }
					print_maze();
					break;
				case 75: // left
					if (map[x][y - 1] == 1) break;
					map[x][y] = 0;
					special(&map[x][y - 1]);
					y--;
					if (lp <= 0) { lose(); break; }
					print_maze();
					break;
				case 77: // right
					if (map[x][y + 1] == 1) break;
					if (map[x][y + 1] == 7) { clear(); break; }
					map[x][y] = 0;
					special(&map[x][y + 1]);
					y++;
					if (lp <= 0) { lose(); break; }
					print_maze();
					break;
				case 80: // down
					if (map[x + 1][y] == 1) break;
					map[x][y] = 0;
					special(&map[x + 1][y]);
					x++;
					if (lp <= 0) { lose(); break; }
					print_maze();
					break;
				}
			}

		}

	}
}


