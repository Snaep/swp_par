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
int rule1 ( Sudoku* sud, int x, int y )
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
					if ( sud->grid[y][i][z + 1] )
					{
						return 0;//Retrun if there are more than one possible position for z in row 
					}
				}
			}
		}
		Sudoku_SetCell ( sud, x, y, z );
		return 1;
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
		return 1;
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
		return 1;
	}

}

int rule4 ( Sudoku* sud, int x, int y )
{
	int iX, iY;
	int i, j, k;
	int cnt = 0;

	for ( i = 0; i < NUM_ELEMENTS; i++ )
	{
		for ( j = 0; j < sud->length; j++ )
		{
			for ( k = 1; k <= sud->length; k++ )
			{
				cnt += sud->contains[i][j][k];//count number of possible candidates
			}
		}
	}
	if ( cnt == 1 )//if only one possible candidate 
	{
		for ( i = 0; i < sud->length; i++ )
		{
			if ( sud->grid[y][x][i + 1] == 1 )
			{
				Sudoku_SetCell ( sud, x, y, sud->grid[y][x][i + 1] );	//set as value
				return 1;
			}
		}
	}
	return 0;
}


//naked pairs row
int rule5( Sudoku* sud, int x, int y ) {
	int i, j;
	int cellIsEqual;
	int exitLoop;
	int changed; //rerturn value if set was found
	int needed_cellcount; //required no of cells in neighbourhood with same possibilities
	int found_neighbours; //no of cells in neighbourhood with same possibilities
	int* relevant_neighbours; //position of relevant cells in neighbourhood


	relevant_neighbours = sud->buffer;
	needed_cellcount = 0;
	changed = FALSE;

	//count no of possibilities for current cell
	needed_cellcount = 0;
	for( i = 1; i <= sud->length; i++ ) {
		needed_cellcount += ( sud->grid[y][x][i] == CELL_POSSIBLE );
	}

	//find cells with same possibilities in row
	for( i = 0; i < sud->length; i++ ) {
		if( i == x ) continue;

		//check if cell has equal possibilities
		cellIsEqual = TRUE;
		for( j = 1; j <= sud->length; j++ ) {
			if( sud->grid[y][i][j] != sud->grid[y][x][j] ) {
				cellIsEqual = FALSE;
				break;
			}
		}
		//if possibilities match, mark cell as relevant
		if( cellIsEqual ) relevant_neighbours[found_neighbours++] = i;

		//done if max no of cells with same possibilities is reached
		if( found_neighbours == needed_cellcount ) break;
	}

	if( found_neighbours != needed_cellcount ) return 0;

	//delete possibilities from current neighbourhood
	exitLoop = FALSE;
	for( i = 0; i < sud->length; i++ ) {
		//check if current cell is a relevant cell
		for( j = 0; j < found_neighbours; j++ ) {
			if( i == j ) { //if current cell is relevant cell, dont delete possibilities
				exitLoop = TRUE;
				break;
			}
		}
		if( exitLoop ) continue;
		//delete all possibilities from cell 
		//that can be placed in relevant cell set
		for( j = 1; j <= sud->length; j++ ) {
			if( sud->grid[y][i][j] == CELL_POSSIBLE && sud->grid[y][x][j] == CELL_POSSIBLE ) {
				changed = TRUE;
				sud->grid[y][i][j] = CELL_IMPOSSIBLE;
			}
		}
	}


	return changed;
}
//naked pairs col
int rule6( Sudoku* sud, int x, int y ) {
	int i, j;
	int cellIsEqual;
	int exitLoop;
	int changed; //rerturn value if set was found
	int needed_cellcount; //required no of cells in neighbourhood with same possibilities
	int found_neighbours; //no of cells in neighbourhood with same possibilities
	int* relevant_neighbours; //position of relevant cells in neighbourhood


	relevant_neighbours = sud->buffer;
	needed_cellcount = 0;
	changed = FALSE;

	//count no of possibilities for current cell
	needed_cellcount = 0;
	for( i = 1; i <= sud->length; i++ ) {
		needed_cellcount += ( sud->grid[y][x][i] == CELL_POSSIBLE );
	}

	//find cells with same possibilities in col
	for( i = 0; i < sud->length; i++ ) {
		if( i == y ) continue;

		//check if cell has equal possibilities
		cellIsEqual = TRUE;
		for( j = 1; j <= sud->length; j++ ) {
			if( sud->grid[i][x][j] != sud->grid[y][x][j] ) {
				cellIsEqual = FALSE;
				break;
			}
		}
		//if possibilities match, mark cell as relevant
		if( cellIsEqual ) relevant_neighbours[found_neighbours++] = i;

		//done if max no of cells with same possibilities is reached
		if( found_neighbours == needed_cellcount ) break;
	}

	if( found_neighbours != needed_cellcount ) return 0;

	//delete possibilities from current neighbourhood
	exitLoop = FALSE;
	for( i = 0; i < sud->length; i++ ) {
		//check if current cell is a relevant cell
		for( j = 0; j < found_neighbours; j++ ) {
			if( i == j ) { //if current cell is relevant cell, dont delete possibilities
				exitLoop = TRUE;
				break;
			}
		}
		if( exitLoop ) continue;
		//delete all possibilities from cell 
		//that can be placed in relevant cell set
		for( j = 1; j <= sud->length; j++ ) {
			if( sud->grid[i][x][j] == CELL_POSSIBLE && sud->grid[y][x][j] == CELL_POSSIBLE ) {
				changed = TRUE;
				sud->grid[i][x][j] = CELL_IMPOSSIBLE;
			}
		}
	}


	return changed;
}
//naked pair box
int rule7( Sudoku* sud, int x, int y ) {
	int i, j, k, l, p;
	int cellIsEqual;
	int exitLoop;
	int changed; //rerturn value if set was found
	int needed_cellcount; //required no of cells in neighbourhood with same possibilities
	int found_neighbours; //no of cells in neighbourhood with same possibilities
	int* relevant_neighbours; //position of relevant cells in neighbourhood


	relevant_neighbours = sud->buffer;
	needed_cellcount = 0;
	changed = FALSE;

	//count no of possibilities for current cell
	needed_cellcount = 0;
	for( i = 1; i <= sud->length; i++ ) {
		needed_cellcount += ( sud->grid[y][x][i] == CELL_POSSIBLE );
	}

	//find cells with same possibilities in box
	for( i = k = x - x % sud->length_of_box; i < k + sud->length_of_box; i++ ) {
		for( j = l = y - y % sud->length_of_box; j < l + sud->length_of_box; j++ ) {
			if( i == x && j == y ) continue;


			//check if cell has equal possibilities
			cellIsEqual = TRUE;
			for( p = 1; p <= sud->length; p++ ) {
				if( sud->grid[j][i][p] != sud->grid[y][x][p] ) {
					cellIsEqual = FALSE;
					break;
				}
			}

			//if possibilities match, mark cell as relevant
			if( cellIsEqual ) {
				relevant_neighbours[found_neighbours++] = i;
				relevant_neighbours[found_neighbours++] = j;
			}

			//done if max no of cells with same possibilities is reached
			if( found_neighbours / 2 == needed_cellcount ) break;
		}
	}

	if( found_neighbours / 2 != needed_cellcount ) return 0;

	//delete possibilities from current neighbourhood
	exitLoop = FALSE;

	for( i = k = x - x % sud->length_of_box; i < k + sud->length_of_box; i++ ) {
		for( j = l = y - y % sud->length_of_box; j < l + sud->length_of_box; j++ ) {
			for( p = 0; p < found_neighbours; p += 2 ) {
				if( relevant_neighbours[p] == i && relevant_neighbours[p + 1] == j ) {//if current cell is relevant cell, dont delete possibilities
					exitLoop = TRUE;
					break;
				}
			}

			if( exitLoop ) continue;

			//delete all possibilities from cell 
			//that can be placed in relevant cell set
			for( p = 1; p <= sud->length; p++ ) {
				if( sud->grid[j][i][p] == CELL_POSSIBLE && sud->grid[y][x][p] == CELL_POSSIBLE ) {
					changed = TRUE;
					sud->grid[j][i][p] = CELL_IMPOSSIBLE;
				}
			}
		}
	}

	return changed;
}

int rule8 ( Sudoku* sud, int x, int y )
{
	int box_coord_X, box_coord_Y;//variables to calculate number of box

	box_coord_X = x % sud->length_of_box;
	box_coord_Y = y % sud->length_of_box;

	
}