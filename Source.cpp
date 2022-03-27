#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "funk.h"
#include<stdlib.h>

//welcome back Tommy.
//This is what you need to do now
//make the game a 2 - player's game
//


int main()
{
	red();
	puts(
		"       ______         __   __   __         _______ __     __              \n"
		"      |   __ \.---.-.|  |_|  |_|  |.-----.|     __|  |--.|__|.-----.-----.\n"
		"      |   __ <|  _  ||   _|   _|  ||  -__||__     |     ||  ||  _  |__ --|\n"
		"      |______/|___._||____|____|__||_____||_______|__|__||__||   __|_____|\n"
		"                                                             |__|         \n"
	);
	setFontSize(18,18);//set the font size of the term (you need to find another answer for this problem)
	printf("Hello and welcome to Battleship!\n");
	resetColor();
	Sleep(1000); //wait for 1000 ms
	system("cls");//clear screen from output

	//this is the first set up for the game, make the gird and get things ready.
	int flag = 0;
	int dice;
	char grid[10][10];
	char grid2[10][10];
	char Egrid[10][10];
	char map2[10][10];
	char map[10][10];
	int counter = 0;//if counter ever reach 23 the player red wins
	int counter2 = 0;//if counter2 ever reach 23 the player purple wins
	int counterOld = 0;
	int counter2Old = 0;
	createGrid(grid);
	createGrid(grid2);
	createGrid(map);
	createGrid(map2);
	
	printGrid(grid);
	playerCreateBored(grid);//placemant of units in grid
	printGridRed(grid);//print in red the bored of player1
	printf("\n");


	red();
	printf("Welcome Admiral to the red team, it's an honor to be led by you! To victory!\n");
	Sleep(800);
	resetColor();

	printf("\n");
	Sleep(350);
	printf("\n");
	Sleep(350);
	printf("\n");
	Sleep(350);

	system("cls");

	printGrid(grid2);
	playerCreateBored(grid2);//placemant of uints in board of player2
	printGridPurple(grid2);
	printf("\n");

	purple();
	printf("Welcome Admiral to the purple team, it's an honor to be led by you! To victory!\n");
	Sleep(800);
	resetColor();

	printf("\n");
	Sleep(350);
	printf("\n");
	Sleep(350);
	printf("\n");
	Sleep(350);

	system("cls");

	dice = rollForStart();
	Sleep(1000);
	system("cls");

	for (int i = 1; i < 61; i++, dice++)
	{
		if ((dice % 2) == 0)//if even it's red team's turn
		{
			
			do//red team's turn.
			{
				printTheGameRed(map, grid);
				counterOld = counter;
				counter = updateMap(grid2, map, counter, dice);
				if (counter == 24)
				{
					red();
					printf("Red team wins!");
					resetColor();
					i = 100;// makes the loop stops
				}
				else
				{
					Sleep(750);
					system("cls");

				}
				

			} while (counter != 24 && counter != counterOld);
		}
		if ((dice % 2) == 1)//if odd it's purple team's turn
		{
			
			do// purple team's turn.
			{
				printTheGamePurple(map2, grid2);
				counter2Old = counter2;
				counter2 = updateMap(grid, map2, counter2,dice);
				if (counter2 == 24)
				{
					purple();
					printf("Purple team wins!.\n");
					resetColor();
					i = 100;//makes the loop stops
				}
				else
				{
					Sleep(750);
					system("cls");
				}

			} while (counter2 != 24 && counter2 != counter2Old);
		}
	}
}
