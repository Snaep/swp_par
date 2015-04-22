#include "strategies.h"


//Function to test for possible Numbers in cell
//Gets Sudoku, x and y position
int Strategy_SinglePossibility(Sudoku* sud, int x, int y) {
	unsigned int i;
	int possibility;

	possibility = 0;

	for (i = 1; i <= sud->length; i++) {//go throught all possible Numbers from 1 to N
		if (sud->grid[y][x][i] == CELL_POSSIBLE) {
			if (possibility != 0) return 0;
			possibility = i;
		}
	}

	Sudoku_SetCell(sud, x, y, possibility);//set possible numbers 
	return 1;
}
//Function to test for missing numbers in column
//Gets Sudoku and Column to search in
int Strategy_MissingCol(Sudoku* sud, int x) {
	unsigned int i;
	int possibility;

	possibility = 0;
	for (i = 1; i <= sud->length; i++) {//cycle trought all numbers per cell 
		if (sud->contains[CONTAINS_COL][x][i] == FALSE) {
			if (possibility != 0) return 0;//if none number possible return 
			possibility = i;	//else save number as possible
		}
	}

	for (i = 0; i < sud->length; i++) {
		if (sud->grid[i][x][CELL_VALUE] == 0) {//search empty cells
			Sudoku_SetCell(sud, x, i, possibility);//set possible numbers  
			return 1;
		}
	}

	_tprintf(_T("reached unreachable statement\r\nModule: %s\r\nLine:%i\r\nDescription:\
								  \r\nCol is missing 1 value but no cell is empty\r\n"), __FILE__, __LINE__);

	return 0;
}
//Function to test for missing numbers in Row
//Gets Sudoku and Row to search in 
int Strategy_MissingRow(Sudoku* sud, int y) {
	unsigned int i;
	int possibility;

	possibility = 0;
	for (i = 1; i <= sud->length; i++) {//cycle trought row 
		if (sud->contains[CONTAINS_ROW][y][i] == FALSE) {//search for possible numbers 
			if (possibility != 0) return 0;//if no number possible return 
			possibility = i;//else save number as possible
		}
	}

	for (i = 0; i < sud->length; i++) {
		if (sud->grid[y][i][CELL_VALUE] == 0) {//cycle trought possible numbers 
			Sudoku_SetCell(sud, i, y, possibility);//fill numbers in 
			return 1;
		}
	}

	_tprintf(_T("reached unreachable statement\r\nModule: %s\r\nLine:%i\r\nDescription:\
								  \r\nRow is missing 1 value but no cell is empty\r\n"), __FILE__, __LINE__);

	return 0;
}
//Function to find missing numbers in Box
//Gets Sudoku and x,y Pos
int Strategy_MissingBox(Sudoku* sud, int x, int y) {
	unsigned int i, j, bi;
	int possibility;

	bi = (y / sud->length_of_box) * sud->length_of_box + x / sud->length_of_box;//get position on top left 

	possibility = 0;
	for (i = 1; i <= sud->length; i++) {//search in x 
		if (sud->contains[CONTAINS_BOX][bi][i] == FALSE) {//cycle trought possible numbers
			if (possibility != 0) return 0;//if no possible nuimbers found return 
			possibility = i;//else save number as possible
		}
	}

	for (j = y; j < y + sud->length_of_box; j++) {//search in y 
		for (i = x; i < x + sud->length_of_box; i++) {//cycle trought numbers
			if (sud->grid[j][i][CELL_VALUE] == 0) {//test if number is possible
				Sudoku_SetCell(sud, i, j, possibility);//set numbers as possible
				return 1;
			}
		}
	}

	_tprintf(_T("reached unreachable statement\r\nModule: %s\r\nLine:%i\r\nDescription:\
								  				  \r\nBox is missing 1 value but no cell is empty\r\n"), __FILE__, __LINE__);

	return 0;
}