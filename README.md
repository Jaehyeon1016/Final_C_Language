# Jaehyeon Park Final C Project

In this project, I made a maze game using C language.

The workspace is Visual Studio(Windows).

In this game, there is a multiple choice quiz and a score.

My plan was:

 * print 15x15 maze
 * Blinded map system
 * move character up, down, left, right
 * Events including treasure box, quizzes, monster
 * Store score and Life Point
 * Checkpoint

Done so far:

 * print 11x11 maze
 * move character
 * Quizzes
 * store score
------------------

##Code

These are headers in my code. The second one allows me to use getch and kbhit later which accept the keyboard input and check it.

''' c
#include <stdio.h>
#include <conio.h>
'''

This part defines the type of variables(stores score and the number of quizzes solved) and array, set the size of array, and assigns the number. 

''' c
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
'''

This code is used to erase all of the printed stuffs on the window before I print the changed maze due to character's movement.

''' C
system("cls");
'''

This icons are used to make maze looks clear.

''' C
printf("■"); // wall
printf("  "); // road
printf("◎"); // character
printf("★"); // quiz
'''

Using switch, I printed the quiz and store input value and check whether it's correct or not. 

'''
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
'''

kbhit checks whether the keyboard is pushed or not. getch stores the ASCII code of the pushed key.

After that, variable key is equal to ASCII code of pushed key.

''' C
	if(_kbhit()) {
		key = _getch();
	}
'''

Switch is used to embody direction key. Pointer is used to move the character by replacing the value which stored in the adress of next movement array to 9(symbolizes the charater in my code). 

''' c
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
'''
------------

##Error

There was compile error due to missing semicolon or bracket and logical error due to wrong position of defining variable. The problem that I couldn't solve was there is an error if I type string value instead of number when the code asks for the number input.

