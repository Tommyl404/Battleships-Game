#include <stdio.h>
#include <math.h>
#include <windows.h>
#include<stdlib.h>

void red()//make printf color red
{
	printf("\033[1;31m");
}
void purple()//make printf color purple
{
	printf("\033[0;35m");
}
void resetColor() //reset printf color to defalt
{
	printf("\033[0m");
}
void createGrid(char grid[10][10])//create the grid 
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
			grid[i][k] = '-';

	}

	return;
}
void printGrid(char grid[10][10])//when you need to print the grid
{
	printf("  ");
	for (int i = 0; i < 10; i++)
		printf("%i ", i);
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%i", i);
		for (int k = 0; k < 10; k++)
			printf(" %c", grid[i][k]);
		printf("\n");
	}

	return;




}
void printGridRed(char grid[10][10])//when you need to print the grid
{
	printf("  ");
	for (int i = 0; i < 10; i++)
		printf("%i ", i);
	printf("\n");


	for (int i = 0; i < 10; i++)
	{
		printf("%i", i);

		red();
		for (int k = 0; k < 10; k++)
			printf(" %c", grid[i][k]);
		printf("\n");
		resetColor();
	}
	return;




}
void printGridPurple(char grid[10][10])//when you need to print the grid
{
	printf("  ");
	for (int i = 0; i < 10; i++)
		printf("%i ", i);
	printf("\n");


	for (int i = 0; i < 10; i++)
	{
		printf("%i", i);

		purple();
		for (int k = 0; k < 10; k++)
			printf(" %c", grid[i][k]);
		printf("\n");
		resetColor();
	}
	return;




}
void yDemoPlacemant(char grid[10][10], int Ycordi, int Xcordi, int size, char ship)//vertical placement
{
	for (int k = 0; k < size; k++)
		grid[Ycordi + k][Xcordi] = ship;

	printGrid(grid);
	return;

}
void xDemoPlacemant(char grid[10][10], int Ycordi, int Xcordi, int size, char ship)//demo for the grid for all Ycordi choose of the player, make him see what he choose before takeing the call.
{
	for (int k = 0; k < size; k++)
		grid[Ycordi][Xcordi + k] = ship;

	printGrid(grid);
	return;

}
void printTheGameRed(char map[10][10], char grid[10][10])
{
	printGrid(map);
	printf("----------------------------\n");
	printGridRed(grid);
	printf("\n");
	red();
	printf("Red team's turn.\n");
	resetColor();
}
void printTheGamePurple(char map[10][10], char grid[10][10])
{
	printGrid(map);
	printf("----------------------------\n");
	printGridPurple(grid);
	printf("\n");
	purple();
	printf("Purple team's turn.\n");
	resetColor();
}
int placeCarrier(char grid[10][10])
{
	char ship = 'C';
	int errorFlag = 0; //when it's 1 rebound the loop and change it to 0
	int size = 5;
	char enter;
	int Ycordi;
	int Xcordi;
	do
	{
		
		errorFlag = 0;
		printf("For Vertical enter '1'\nFor Horizontal enter '2'\n");
		scanf_s(" %c", &enter);
		if (enter != '1' && enter != '2')
			errorFlag = 1;
	} while (errorFlag == 1);

	if (enter == '1')//Vertical placemant remember to make him choose again if the player picks a y cordi that is higher value then 5
	{

		printf("Choose the X coordinate for the Carrier: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Xcordi);
			if (Xcordi > 9 || Xcordi < 0)
			{

				printf("invalde X coordinate, Try to choose a value that is between 9 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		printf("Choose the Y coordinate for the Carrier: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Ycordi);
			if (Ycordi > 5 || Ycordi < 0)
			{
				printf("invalde Y coordinate, Try to choose a value that is between 5 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		for (int k = 0; k < size; k++)
		{
			if (grid[Ycordi + k][Xcordi] != '-')
			{
				printf("A Ship is currently placed there, try something else.\n");
				Sleep(750);
				return 1;
			}

		}

		yDemoPlacemant(grid, Ycordi, Xcordi, size, ship);


	}
	else if (enter == '2')
	{
		printf("Choose the X coordinate for the Carrier: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Xcordi);
			if (Xcordi > 5 || Xcordi < 0)
			{

				printf("invalde X coordinate, Try to choose a value that is between 5 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		printf("Choose the Y coordinate for the Carrier: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Ycordi);
			if (Ycordi > 9 || Ycordi < 0)
			{
				printf("invalde Y coordinate, Try to choose a value that is between 9 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		for (int k = 0; k < size; k++)
		{
			if (grid[Ycordi][Xcordi + k] != '-')
			{
				printf("A Ship is currently placed there, try something else.\n");
				Sleep(750);
				return 1;
			}

		}
		xDemoPlacemant(grid, Ycordi, Xcordi, size, ship);
	}
}
int placeBattleShip(char grid[10][10])
{
	char ship = 'B';
	int errorFlag = 0; //when it's 1 rebound the loop and change it to 0
	int size = 4;
	char enter;
	int Ycordi;
	int Xcordi;
	do
	{
		printGrid(grid);
		errorFlag = 0;
		printf("For Vertical enter '1'\nFor Horizontal enter '2'\n");
		scanf_s(" %c", &enter);
		if (enter != '1' && enter != '2')
			errorFlag = 1;
	} while (errorFlag == 1);

	if (enter == '1')//Vertical placemant remember to make him choose again if the player picks a y cordi that is higher value then 5
	{
		printf("Choose the X coordinate for the Battle-Ship: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Xcordi);
			if (Xcordi > 9 || Xcordi < 0)
			{

				printf("invalde X coordinate, Try to choose a value that is between 9 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		printf("Choose the Y coordinate for the Battle-Ship: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Ycordi);
			if (Ycordi > 6 || Ycordi < 0)
			{
				printf("invalde Y coordinate, Try to choose a value that is between 6 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		for (int k = 0; k < size; k++)
		{
			if (grid[Ycordi + k][Xcordi] != '-')
			{
				printf("A Ship is currently placed there, try something else.\n");
				Sleep(750);
				return 1;
			}

		}

		yDemoPlacemant(grid, Ycordi, Xcordi, size, ship);


	}
	else if (enter == '2')
	{
		printf("Choose the X coordinate for the Battle-Ship: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Xcordi);
			if (Xcordi > 6 || Xcordi < 0)
			{

				printf("invalde X coordinate, Try to choose a value that is between 6 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		printf("Choose the Y coordinate for the Battle-Ship: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Ycordi);
			if (Ycordi > 9 || Ycordi < 0)
			{
				printf("invalde Y coordinate, Try to choose a value that is between 9 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		for (int k = 0; k < size; k++)
		{
			if (grid[Ycordi][Xcordi + k] != '-')
			{
				printf("A Ship is currently placed there, try something else.\n");
				Sleep(750);
				return 1;
			}

		}

		xDemoPlacemant(grid, Ycordi, Xcordi, size, ship);
	}

}
int placeSubmarine(char grid[10][10])
{
	char ship = 'S';
	int errorFlag = 0; //when it's 1 rebound the loop and change it to 0
	int size = 3;
	char enter;
	int Ycordi;
	int Xcordi;
	do
	{
		printGrid(grid);
		errorFlag = 0;
		printf("For Vertical enter '1'\nFor Horizontal enter '2'\n");
		scanf_s(" %c", &enter);
		if (enter != '1' && enter != '2')
			errorFlag = 1;
	} while (errorFlag == 1);

	if (enter == '1')//Vertical placemant remember to make him choose again if the player picks a y cordi that is higher value then 5
	{
		printf("Choose the X coordinate for the Submarine: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Xcordi);
			if (Xcordi > 9 || Xcordi < 0)
			{

				printf("invalde X coordinate, Try to choose a value that is between 9 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		printf("Choose the Y coordinate for the Submarine: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Ycordi);
			if (Ycordi > 7 || Ycordi < 0)
			{
				printf("invalde Y coordinate, Try to choose a value that is between 7 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		for (int k = 0; k < size; k++)
		{
			if (grid[Ycordi + k][Xcordi] != '-')
			{
				printf("A Ship is currently placed there, try something else.\n");
				Sleep(750);
				return 1;
			}

		}

		yDemoPlacemant(grid, Ycordi, Xcordi, size, ship);


	}
	else if (enter == '2')
	{
		
		printf("Choose the X coordinate for the Submarine: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Xcordi);
			if (Xcordi > 7 || Xcordi < 0)
			{

				printf("invalde X coordinate, Try to choose a value that is between 7 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		printf("Choose the Y coordinate for the Submarine: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Ycordi);
			if (Ycordi > 9 || Ycordi < 0)
			{
				printf("invalde Y coordinate, Try to choose a value that is between 9 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		for (int k = 0; k < size; k++)
		{
			if (grid[Ycordi][Xcordi + k] != '-')
			{
				printf("A Ship is currently placed there, try something else.\n");
				Sleep(750);
				return 1;
			}

		}

		xDemoPlacemant(grid, Ycordi, Xcordi, size, ship);
	}

}
int placeDestroyer(char grid[10][10])
{
	char ship = 'D';
	int errorFlag = 0; //when it's 1 rebound the loop and change it to 0
	int size = 2;
	char enter;
	int Ycordi;
	int Xcordi;
	do
	{
		printGrid(grid);
		errorFlag = 0;
		printf("For Vertical enter '1'\nFor Horizontal enter '2'\n");
		scanf_s(" %c", &enter);
		if (enter != '1' && enter != '2')
			errorFlag = 1;
	} while (errorFlag == 1);

	if (enter == '1')//Vertical placemant remember to make him choose again if the player picks a y cordi that is higher value then 5
	{
		printf("Choose the X coordinate for the Destroyer: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Xcordi);
			if (Xcordi > 9 || Xcordi < 0)
			{

				printf("invalde X coordinate, Try to choose a value that is between 9 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		printf("Choose the Y coordinate for the Destroyer: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Ycordi);
			if (Ycordi > 8 || Ycordi < 0)
			{
				printf("invalde Y coordinate, Try to choose a value that is between 8 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		for (int k = 0; k < size; k++)
		{
			if (grid[Ycordi + k][Xcordi] != '-')
			{
				printf("A Ship is currently placed there, try something else.\n");
				Sleep(750);
				return 1;
			}

		}

		yDemoPlacemant(grid, Ycordi, Xcordi, size, ship);


	}
	else if (enter == '2')
	{
		printf("Choose the X coordinate for the Destroyer: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Xcordi);
			if (Xcordi > 8 || Xcordi < 0)
			{

				printf("invalde X coordinate, Try to choose a value that is between 8 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		printf("Choose the Y coordinate for the Destroyer: \n");
		do
		{
			errorFlag = 0;
			scanf_s("%i", &Ycordi);
			if (Ycordi > 9 || Ycordi < 0)
			{
				printf("invalde Y coordinate, Try to choose a value that is between 9 to 0\n");
				errorFlag = 1;
			}
		} while (errorFlag == 1);

		for (int k = 0; k < size; k++)
		{
			if (grid[Ycordi][Xcordi + k] != '-')
			{
				printf("A Ship is currently placed there, try something else.\n");
				Sleep(750);
				return 1;
			}

		}

		xDemoPlacemant(grid, Ycordi, Xcordi, size, ship);
	}

}
void yEDemoPlacemant(char grid[10][10], int Ycordi, int Xcordi, int size, char ship)//vertical placement
{
	for (int k = 0; k < size; k++)
		grid[Ycordi + k][Xcordi] = ship;

	//printGrid(grid);
	return;

}
void xEDemoPlacemant(char grid[10][10], int Ycordi, int Xcordi, int size, char ship)//demo for the grid for all Ycordi choose of the player, make him see what he choose before takeing the call.
{
	for (int k = 0; k < size; k++)
		grid[Ycordi][Xcordi + k] = ship;

	//printGrid(grid);
	return;

}
void democreateEGrid(char Egrid[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
			Egrid[i][k] = '-';

	}
	yEDemoPlacemant(Egrid, 1, 1, 5, 'C');
	yEDemoPlacemant(Egrid, 7, 1, 3, 'S');
	yEDemoPlacemant(Egrid, 1, 3, 2, 'D');
	yEDemoPlacemant(Egrid, 7, 3, 2, 'D');
	xEDemoPlacemant(Egrid, 0, 6, 4, 'B');
	xEDemoPlacemant(Egrid, 4, 6, 4, 'B');
	xEDemoPlacemant(Egrid, 6, 4, 3, 'S');
	//printGrid(Egrid);
}
int updateMap(char grid2[10][10], char map[10][10], int counter, int dice)
{
	int Xcordi = 0;
	int Ycordi = 0;
	int errorFlag = 0;
	int tryAgain = 0;
	int moreTurns = 0;
	//do
	//{
		moreTurns = 0;
		do
		{
			tryAgain = 0;
			Xcordi = 0;
			Ycordi = 0;
			//printGrid(map);
			
			printf("Choose the X coordinate:\n");
			do
			{
				errorFlag = 0;
				scanf_s("%i", &Xcordi);
				if (Xcordi > 9 || Xcordi < 0)
				{

					printf("invalde X coordinate, Try to choose a value that is between 9 to 0\n");
					errorFlag = 1;
				}
			} while (errorFlag == 1);

			printf("Choose the Y coordinate: \n");
			do
			{
				errorFlag = 0;
				scanf_s("%i", &Ycordi);
				if (Ycordi > 9 || Ycordi < 0)
				{
					printf("invalde Y coordinate, Try to choose a value that is between 9 to 0\n");
					errorFlag = 1;
				}
			} while (errorFlag == 1);

			if (map[Ycordi][Xcordi] != '-')
			{
				printf("You can't hit a place you already checked, Try again!\n");
				tryAgain = 1;
				Sleep(800);
				system("cls");
				if ((dice % 2) == 0)//red team's turn
				{
					printTheGameRed(map, grid2);
				}
				else//purple team's turn
				{
					printTheGamePurple(map, grid2);
				}
			}
		} while (tryAgain == 1);







		if (grid2[Ycordi][Xcordi] == '-' && map[Ycordi][Xcordi] == '-')//empty space and not checked
		{
			map[Ycordi][Xcordi] = 'O';
			printf("Miss! Now it's the enemy's turn!");
			return counter;
		}
		if (grid2[Ycordi][Xcordi] == 'C' && map[Ycordi][Xcordi] == '-')//C in Egrid and not checked
		{
			map[Ycordi][Xcordi] = 'X';
			grid2[Ycordi][Xcordi] = 'X';
			printf("Hit! You got another turn!");
			counter = counter++;
			if (counter == 23)
				return 24; //that means that the player wiped all enemys ships and wins
			else
				return counter;
		}
		if (grid2[Ycordi][Xcordi] == 'B' && map[Ycordi][Xcordi] == '-')//B in Egrid and not checked
		{
			map[Ycordi][Xcordi] = 'X';
			grid2[Ycordi][Xcordi] = 'X';
			printf("Hit! You got another turn!");
			counter = counter++;
			if (counter == 23)
				return 24; //that means that the player wiped all enemys ships and wins
			else
				return counter;
		}
		if (grid2[Ycordi][Xcordi] == 'S' && map[Ycordi][Xcordi] == '-')//S in Egrid and not checked
		{
			map[Ycordi][Xcordi] = 'X';
			grid2[Ycordi][Xcordi] = 'X';
			printf("Hit! You got another turn!");
			counter = counter++;
			if (counter == 23)
				return 24; //that means that the player wiped all enemys ships and wins
			else
				return counter;
		}
		if (grid2[Ycordi][Xcordi] == 'D' && map[Ycordi][Xcordi] == '-')//D in Egrid and not checked
		{
			map[Ycordi][Xcordi] = 'X';
			grid2[Ycordi][Xcordi] = 'X';
			printf("Hit! You got another turn!");
			counter = counter++;
			if (counter == 23)
				return 24; //that means that the player wiped all enemys ships and wins
			else
				return counter;
		}
		Sleep(800);
		system("cls");
	//} while (moreTurns == 1);
}
void playerCreateBored(char grid[10][10])
{
	int flag = 0;

	printf("Placeing the Carrier (5 blocks)\n");
	do
	{
		flag = placeCarrier(grid);
		system("cls");
	} while (flag == 1); //Placing the Carrier (size 5 blocks)
	flag = 0;


	//Placing the Battleships (size 4 blocks)
	for (int i = 0; i < 2; i++)
	{

		printf("Placeing the %i Battle-Ship (4 blocks)\n", (i + 1));
		do
		{
			flag = placeBattleShip(grid);
			system("cls");
		} while (flag == 1);
		flag = 0;
	}

	//Placing the Submarines (size 3 blocks)
	for (int i = 0; i < 2; i++)
	{

		printf("Placeing the %i Submarine (3 blocks)\n", (i + 1));
		do
		{
			flag = placeSubmarine(grid);
			system("cls");
		} while (flag == 1);
		flag = 0;
	}

	//Placing the Destroyers (size 2 blocks)
	for (int i = 0; i < 2; i++)
	{

		printf("Placeing the %i Destroyer (2 blocks)\n", (i + 1));
		do
		{
			flag = placeDestroyer(grid);
			system("cls");
		} while (flag == 1);
		flag = 0;
	}



}
int rollForStart()//this will tell who is the frist team to start the battle
{
	int dice = 100;
	dice = (rand() % 2);

	if (dice == 0)
	{
		red();
		printf("Red team is starting this battle.\n");
		resetColor();
		return dice;
	}
	else
	{
		purple();
		printf("Purple team is starting this battle.\n");
		resetColor();
		return dice;
	}
}
void setFontSize(int a, int b)

{

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();

	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);

	GetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

	lpConsoleCurrentFontEx->dwFontSize.X = a;

	lpConsoleCurrentFontEx->dwFontSize.Y = b;

	SetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

}
void manu()
{
	puts(
		"      ______         __   __   __         _______ __     __              \n"
		"      |   __ \.---.-.|  |_|  |_|  |.-----.|     __|  |--.|__|.-----.-----.\n"
		"      |   __ <|  _  ||   _|   _|  ||  -__||__     |     ||  ||  _  |__ --|\n"
		"      |______/|___._||____|____|__||_____||_______|__|__||__||   __|_____|\n"
		"                                                             |__|         \n"
	);


}