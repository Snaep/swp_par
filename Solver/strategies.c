#include "strategies.h"


//Function to test for possible Numbers in cell
//Gets Sudoku, x and y position
int Strategy_SinglePossibility ( Sudoku* sud, int x, int y )
{
	unsigned int i;
	int possibility;

	possibility = 0;

	for ( i = 1; i <= sud->length; i++ )
	{//go throught all possible Numbers from 1 to N
		if ( sud->grid[y][x][i] == CELL_POSSIBLE )
		{
			if ( possibility != 0 ) return 0;
			possibility = i;
		}
	}
	if ( possibility != 0 )//if only one number is possible 
		Sudoku_SetCell ( sud, x, y, possibility );//set number

	return 1;
}
//Function to test for missing numbers in column
//Gets Sudoku and Column to search in
int Strategy_MissingCol ( Sudoku* sud, int x )
{
	unsigned int i;
	int possibility;

	possibility = 0;
	for ( i = 1; i <= sud->length; i++ )
	{//cycle trought all numbers per cell 
		if ( sud->contains[CONTAINS_COL][x][i] == FALSE )
		{
			if ( possibility != 0 ) return 0;//if more than one number possible return 
			possibility = i;	//else save number as possible
		}
	}

	for ( i = 0; i < sud->length; i++ )
	{
		if ( sud->grid[i][x][CELL_VALUE] == 0 )
		{//search empty cells
			Sudoku_SetCell ( sud, x, i, possibility );//set number
			return 1;
		}
	}

	_tprintf ( _T ( "reached unreachable statement\r\nModule: %s\r\nLine:%i\r\nDescription:\
																																																																																																																						  \r\nCol is missing 1 value but no cell is empty\r\n" ), __FILE__, __LINE__ );

	return 0;
}
//Function to test for missing numbers in Row
//Gets Sudoku and Row to search in 
int Strategy_MissingRow ( Sudoku* sud, int y )
{
	unsigned int i;
	int possibility;

	possibility = 0;
	for ( i = 1; i <= sud->length; i++ )
	{//cycle trought row 
		if ( sud->contains[CONTAINS_ROW][y][i] == FALSE )
		{//search for possible numbers 
			if ( possibility != 0 ) return 0;//if more than one number possible return 
			possibility = i;//else save number as possible
		}
	}

	for ( i = 0; i < sud->length; i++ )
	{
		if ( sud->grid[y][i][CELL_VALUE] == 0 )
		{//cycle trought possible numbers 
			Sudoku_SetCell ( sud, i, y, possibility );//set number
			return 1;
		}
	}

	_tprintf ( _T ( "reached unreachable statement\r\nModule: %s\r\nLine:%i\r\nDescription:\
																																																																																																																						  \r\nRow is missing 1 value but no cell is empty\r\n" ), __FILE__, __LINE__ );

	return 0;
}
//Function to find missing numbers in Box
//Gets Sudoku and x,y Pos
int Strategy_MissingBox ( Sudoku* sud, int x, int y )
{
	unsigned int i, j, bi;
	int possibility;

	bi = ( y / sud->length_of_box ) * sud->length_of_box + x / sud->length_of_box;//get position on top left 

	possibility = 0;
	for ( i = 1; i <= sud->length; i++ )
	{//search in x 
		if ( sud->contains[CONTAINS_BOX][bi][i] == FALSE )
		{//cycle trought possible numbers
			if ( possibility != 0 ) return 0;//if more than one possible numbers found return 
			possibility = i;//else save number as possible
		}
	}

	for ( j = y; j < y + sud->length_of_box; j++ )
	{//search in y 
		for ( i = x; i < x + sud->length_of_box; i++ )
		{//cycle trought numbers
			if ( sud->grid[j][i][CELL_VALUE] == 0 )
			{//test if number is possible
				Sudoku_SetCell ( sud, i, j, possibility );//set number
				return 1;
			}
		}
	}

	_tprintf ( _T ( "reached unreachable statement\r\nModule: %s\r\nLine:%i\r\nDescription:\
																																																																																																																						  				  \r\nBox is missing 1 value but no cell is empty\r\n" ), __FILE__, __LINE__ );

	return 0;
}

int logic_solve ( Sudoku* sud )
{
	int change = 1;
	int wert = 0;
	int iX, iY;
	int i;
	int empty;
	int rc;

	rules[0] = rule1;
	rules[1] = rule2;
	rules[2] = rule3;
	rules[3] = rule4;
	rules[4] = rule5;
	rules[5] = rule6;

	while ( change )
	{
		change = 0;
		empty = 0;
		for ( iX = 0; iX < sud->length; iX++ )//count empty cells
		{
			for ( iY = 0; iY < sud->length; iY++ )
			{
				if ( sud->grid[iY][iX][0] == 0 )
				{
					empty++;
				}
			}
		}
		if ( empty == 0 )//If none empty return 
		{
			return 1;//Solved
		}
		for ( i = 0; i < RULE_CNT; i++ )
		{
			if ( !change )
			{
				rc = rules[i] ( sud );
			}
		}
		if ( !change )
		{
			return 0;//Not solvable
		}
	}
}
int rule1 ( Sudoku* sud, int x, int y )
{

	int z;
	int i;

	for ( x = 0; x < sud->length; x++ )//loop trought all cells in x direction
	{
		for ( y = 0; y < sud->length; y++ )//loop trought all cells in y direction
		{
			if ( sud->grid[y][x][0] == 0 )//Search only in empty cells
			{
				for ( z = 1; z < sud->length; z++ )//loop trought possible candidates
				{
					if ( sud->grid[y][x][z + 1] )//check if z is candidate for cell[iX][iY]
					{
						for ( i = 0; i < sud->length; i++ )
						{
							if ( sud->grid[y][i][z + 1] )
							{
								return 0;//Retrun if there are more than one possible position for z in row 
							}
						}
					}
				}
				Sudoku_SetCell ( sud, x, y, z );
			}
		}
	}
}

int rule2 ( Sudoku* sud, int x, int y )
{
	int z;
	int i;

	if ( sud->grid[y][x][0] == 0 )//Search only in empty cells
	{
		for ( z = 1; z < sud->length; z++ )//loop trought possible candidates
		{
			if ( sud->grid[y][x][z + 1] )//check if z is candidate for cell[iX][iY]
			{
				for ( i = 0; i < sud->length; i++ )
				{
					if ( sud->grid[i][x][z + 1] )
					{
						return 0;//Retrun if there are more than one possible position for z in column 
					}
				}
			}
		}
		Sudoku_SetCell ( sud, x, y, z );
	}
}

int rule3 ( Sudoku* sud, int x, int y )
{
	int z;
	int i;
	int box_cnt_X, box_cnt_Y;


	if ( sud->grid[y][x][0] == 0 )//Search only in empty cells
	{
		for ( z = 1; z < sud->length; z++ )//loop trought possible candidates
		{
			if ( sud->grid[y][x][z + 1] )//check if z is candidate for cell[iX][iY]
			{
				for ( i = 0; i < sud->length_of_box; i++ )
				{
					for ( int j = 0; j < sud->length_of_box; j++ )
					{
						box_cnt_X = x % sud->length_of_box;
						box_cnt_Y = y % sud->length_of_box;

						if ( sud->grid[i + ( box_cnt_Y * ( sud->length_of_box - 1 ) )][j + ( box_cnt_X * ( sud->length_of_box - 1 ) )][z + 1] )
						{
							return 0;//Retrun if there are more than one possible position for z in column 
						}
					}
				}
			}
		}

		Sudoku_SetCell ( sud, x, y, z );
	}

}
int rule4 ( Sudoku* sud, int x, int y )
{
	int iX, iY;

	for ( iX = 0; iX < sud->length; iX++ )
	{
		for ( iY = 0; iY < sud->length; iY++ )
		{
			for ( int i = 0; i < sud->length; i++ )
			{
				for ( )
					sud->contains[i][][];
			}
		}
	}
}


/*
Es wird eine Menge M mit benach-
barten Elementen mit gleichen Kandidatenlisten gebildet. Die Elemente m�ssen
in totaler Nachbarschaft stehen, also jedes Element muss Nachbarelement jedes
anderen Elementes sein. Sollte es nun genau soviele Elemente in M geben wie
es Elemente in jeder Kandidatenliste gibt, so folgt daraus dass diese Kandida-
ten einzig auf die Elemente der Menge M zuzuordnen sind. Alle weiteren totalen
Nachbarelemente k�nnen jedes Element aus den Kandidatenlisten von M von ihrer
Kandidatenliste streichen
*/
int rule5( Sudoku* sud, int x, int y ) {
	int i;
	int possible_count;

	//bestimme Anzahl und M�glichkeiten f�r aktuelle Zelle
	possible_count = 0;
	for( i = 1; i <= sud->length; i++ ) if( sud->grid[y][x][i] == CELL_POSSIBLE ) sud->buffer[possible_count++] = i;


}