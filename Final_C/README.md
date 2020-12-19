# Jaehyeon Park Final C Project

In this project, I made a maze game using C language.

The workspace is Visual Studio(Windows). It only works in Windows.

In this game, there is a multiple choice quiz and a score.

My plan was[Maze Game](https://docs.google.com/document/d/15ru-1l4GXbCBTrwk78bKu-uxLmtw2U4cIsW8N4xNYrw/edit):

What I have done in this code:
 * print 19x19 maze
 * move character up, down, left, right
 * Events including treasure box, quizzes, Nymph
 * Store score and Life Point

The player gets 50 life points(LP) at the start, and player loses 1 LP for every movement. When LP becomes 0, the code will break. The player can get LP and score through events:
 * Quiz - Correct => +50 score & +10 LP / Wrong => -4 LP
 * Treasure Box - Open => +10 score or -4 LP
 * Nymph - give 5LP => +25 ~ 1 LP

------------------

## Code

These are headers in my code. The second one allows me to use getch and kbhit later which accept the keyboard input and check it. process.h allows me to use system(), and time.h and stdlib.h allows me to use rand() and srand(time()). windows.h allows me to use Sleep();

``` c
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "final.h"
```

This part defines the type of variables(stores score and the number of quizzes solved) and array, set the size of array, and assigns the number, which are located in final.h file. It shows 19x19 maze.

```c
int num, num2, num3, ans, answ, score = 0, a = 3, lp = 50;

int map[19][19] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
	{1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 2, 0, 0, 0, 1, 0, 0, 2, 0, 0, 1},
	{1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 1, 2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
	{1, 0, 1, 2, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 1, 2, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 2, 1},
	{1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 0, 2, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1},
	{1, 1, 1, 0, 1, 0, 1, 2, 1, 1, 1, 2, 1, 0, 1, 0, 1, 0, 1},
	{1, 2, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0, 1, 2, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 2, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
	{1, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 2, 0, 0, 7},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
```

This code is used to erase all of the printed stuffs on the window before I print the changed maze due to player's movement.

```c
system("cls");
```

The code below prints out the maze with the icons which makes the maze looks more clear. It prints out the score and life point too.

```c 
void print_maze() {
	system("cls");
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			//printf("%d ", map[i][j]);
			if (map[i][j] == 1) {
				printf("■");
			}
			else if (map[i][j] == 0 || map[i][j] == 7) {
				printf("  ");
			}
			else if (map[i][j] == 9) {
				printf("◎");
			}
			else {
				printf("★");
			}
		}
		printf("\n");
	}
	printf("score : %d", score);
	printf("\nLife Point: %d\n", lp);

}
```

This code shows the message if the player lose or win the game. It prints out the score and life point.

```c
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
	printf("\nLife Point: 0");
	a = 4;
}
```

When the player encounter the event(star), this code randomly prints out one of the quiz, treasure box, nymph, or nothing. srand(time(0)) revieves the seed value and change the startpoint of random number table, which makes the rand() to give the number randomly. The randomly chosen number which is between 1-18 goes through the switch and give one event. The random function is used two times more when the contents of the treasure box is decided and when the amount of LP given by Nymph is decided.

```c
void quiz() {
	int b = 5;
	srand(time(0));
	num = rand() % 18 +1;
	while (b > 4) {
		switch (num) {
		case 1:
			printf("\nQ: When is the foundation day of Cooper Union? \n");
			printf("\n");
			printf("1:1920  2:1867  3:1859  4:1923 \n");
			scanf_s("%d", &ans);
			if (ans == 3) {
				printf("Correct.");
				score += 5;
				lp += 10;
				b = 3;
				Sleep(2000);
				break;

			}
			else if (ans == 2 || ans == 1 || ans == 4) {
			printf("Wrong.");
			lp -= 4;
			b = 3;
			Sleep(2000);
			break;
			}
			else {
			printf("Invalid input. Type Again.\n");
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
				b = 3;
				Sleep(2000);
				break;
			}
			else if (ans == 2 || ans == 3 || ans == 4) {
				printf("Wrong.");
				lp -= 4;
				b = 3;
				Sleep(2000);
				break;
			}
			else {
				printf("Invalid input. Type Again.\n");
				break;
			}
		case 3:
			printf("\nQ: In darts, what's the most points you can score with a single throw? \n");
			printf("\n");
			printf("1:20  2:50  3:60  4:100 \n");
			scanf_s("%d", &ans);
			if (ans == 3) {
				printf("Correct.");
				score += 50;
				lp += 10;
				b = 3;
				Sleep(2000);
				break;
			}
			else if (ans == 2 || ans == 4 || ans == 1) {
				printf("Wrong.");
				lp -= 4;
				b = 3;
				Sleep(2000);
				break;
			}
			else {
				printf("Invalid input. Type Again.\n");
				break;
			}
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
			printf("You found a treasure box. Are you gonna open it? y/n: \n");
			scanf_s(" %c", &answ);
			if (answ == 'y') {
				num2 = rand() % 2 + 1;
				if (num2 == 1) {
					printf("There were a lump of gold and one chocolate bar!(+10 scores)\n");
					score += 10;
					Sleep(2000);
				}
				else {
					printf("It was a treasure monster! Run away!(-4 LP) \n");
					lp -= 4;
					Sleep(2000);
				}
				b = 3;
				break;
			}
			else if (answ == 'n') {
				b = 3;
				break;
			}
			else {
				printf("Invalid input. Type Again.\n");
				break;
			}
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			printf("You found a nymph. Are you gonna give 5 scores to get treatment? y/n: \n");
			scanf_s(" %c", &answ);
			if (answ == 'y') {
				if (score < 5) {
					printf("You don't have enough score to give.\n", num3);
					b = 3;
					break;
				}
				else {

					score -= 5;
					num3 = rand() % 25 + 1;
					lp += num3;
					printf("You got %d life points.\n", num3);
					b = 3;
					Sleep(2000);
					break;
				}
			}
			else if (answ == 'n') {
				b = 3;
				break;
			}
			else {
				printf("Invalid input. Type Again.\n");
				break;
			}
		default:
			printf("\nNothing happened.");
			b = 3;
			Sleep(2000);
			break;

		}
	}
	
}
```

## Main()

This code is in the main(), and it gives the introduction of the game. When the player press 1, the game starts.

``` c
int x = 1, y = 1, z;
	int key;
	while (a < 4) {
		printf("Welcome to the Maze Game. \n");
		printf("You are now trapped in the maze.\n");
		printf("Various events will happen when you encounter the star.\n");
		printf("There is a Life Point(LP) and a score. You will lose 1 LP for every movement, and when LP becomes 0, you will die...\n");
		printf("But don't worry! You can get LP and score through the events.\n");
		printf("\n");
		printf("Quiz - Correct => +50 score & +10 LP / Wrong => -4 LP\n");
		printf("\n");
		printf("Treasure Box - Open => +10 score or -4 LP\n");
		printf("\n");
		printf("Nymph - give 5LP => +25 ~ 1 LP\n");
		printf("\n");
		Sleep(4000);
		printf("\n");
		printf("Type 1 to play the game. : \n");
		scanf_s("%d", &z);
		if (z == 1) {
			break;
		}
		else {
			printf("%s", "Invalid value. Type again.\n");
		}
	}

```
This code is used to embody direction key. kbhit checks whether the keyboard is pushed or not. getch stores the ASCII code of the pushed key. After that, variable key is equal to ASCII code of pushed key. If the array value become 7, then the player clears the game. If LP become equal or less than 0, then the player loses the game.

```
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
```

With the code above, the code below is used to make the player move. Pointer is used to move the character by replacing the value which stored in the adress of next movement array to 9(symbolizes the player in my code).

``` c
void special(int* a) {

	if (*a == 2) {

		quiz();

	}
	lp--;
	*a = 9;
	
}
```


-------------

## Error

The problem that I couldn't solve was there is an error if I type string value instead of number when the code asks for the number input.

