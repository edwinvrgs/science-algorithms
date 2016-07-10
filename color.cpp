#include <ctype.h> 
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include <iostream>
using namespace std;

#define BLACK 0
#define BLUE 1
#define GREE 2
#define WATER 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_WATER 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define SHINY_WHITE 15

void color(int fondo, int letra)
{	
	int x = fondo * 16 + letra;
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), x); 
} 
