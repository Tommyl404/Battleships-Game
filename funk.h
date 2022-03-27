#pragma once

void createGrid(char grid[10][10]);
void democreateEGrid(char Egrid[10][10]);
void printGrid(char grid[10][10]);
void printGridRed(char grid[10][10]);
void printGridPurple(char grid[10][10]);
void printTheGameRed(char map[10][10], char grid[10][10]);
void printTheGamePurple(char map[10][10], char grid[10][10]);
int placeCarrier(char grid[10][10]);
int placeBattleShip(char grid[10][10]);
int placeSubmarine(char grid[10][10]);
int placeDestroyer(char grid[10][10]);
void yDemoPlacemant(char grid[10][10], int Ycordi, int Xcordi, int size, char ship);
void xDemoPlacemant(char grid[10][10], int Ycordi, int Xcordi, int size, char ship);
void red();
void purple();
void resetColor();
int updateMap(char grid2[10][10], char map[10][10], int counter, int dice);
void playerCreateBored(char grid[10][10]);
int rollForStart();
void setFontSize(int a, int b);