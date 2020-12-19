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
------------------

## Code

These are headers in my code. The second one allows me to use getch and kbhit later which accept the keyboard input and check it.

``` c
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "final.h"
```

This part defines the type of variables(stores score and the number of quizzes solved) and array, set the size of array, and assigns the number. 

```c
int score = 0; int star = 1;
int map[11][11] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 2,1},
	{1, 0, 1, 1, 1, 0, 1, 0, 1, 1,1},
	{1, 0, 1, 0, 0, 0, 1, 0, 2, 0,1},
	{1, 2, 1, 0, 1, 1, 1, 1, 1, 0,1},
	{1, 0, 1, 2, 1, 2, 1, 0, 0, 0,1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0,1},
	{1, 0, 1, 0, 0, 0, 1, 2, 1, 0,1},
	{1, 2, 1, 1, 1, 1, 1, 0, 1, 0,1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0,0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1}
};
```

This code is used to erase all of the printed stuffs on the window before I print the changed maze due to character's movement.

```c
system("cls");
```

This icons are used to make maze looks clear.

```c 
printf("■"); // wall
printf("  "); // road
printf("◎"); // character
printf("★"); // quiz
```

Using switch, I printed the quiz and store input value and check whether it's correct or not. 

```c
switch(star){
case 1:
	printf("\nQ: What is your name? \n");
	printf("\n");
	printf("1:  2:  3:  4: \n");
	scanf_s("%d", &ans);
	if (ans == 1) {
	printf("Correct.");
	score++;
	;
	break;
	}
}
```

kbhit checks whether the keyboard is pushed or not. getch stores the ASCII code of the pushed key.

After that, variable key is equal to ASCII code of pushed key.

```c
	if(_kbhit()) {
		key = _getch();
	}
```

Switch is used to embody direction key. Pointer is used to move the character by replacing the value which stored in the adress of next movement array to 9(symbolizes the charater in my code). 

``` c
switch (key) {
case 72: // up
	if (map[x - 1][y] == 1) break;
	if (x == 0) { clear(); break; }
	map[x][y] = 0;
	special(&map[x - 1][y]);
	x--;
	print_maze();
	break;
}
```

-------------

## Error

The problem that I couldn't solve was there is an error if I type string value instead of number when the code asks for the number input.
