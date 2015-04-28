#include "solver.h"


//Solver for Sudoku
//Gets Sudoku and the strategies to use
int SolveSequential ( Sudoku* sud, unsigned int strategies )
{
	int x, y, i;
	int changes;

	do
	{
		changes = 0;

		if ( ( strategies & STRAT_SINGLE_POSSIBILITY ) != 0 )
		{
			for ( x = 0; x < sud->length; x++ )
			{
				for ( y = 0; y < sud->length; y++ )
				{
					if ( sud->grid[y][x][0] == 0 ) changes += Strategy_SinglePossibility ( sud, x, y );
				}
			}
		}

		if ( ( strategies & ( STRAT_MISSING_COL | STRAT_MISSING_COL ) ) != 0 )
		{
			for ( i = 0; i < sud->length; i++ )
			{
				if ( strategies & STRAT_MISSING_COL ) changes += Strategy_MissingCol ( sud, i );
				if ( strategies & STRAT_MISSING_ROW ) changes += Strategy_MissingRow ( sud, i );
			}
		}

		if ( strategies & STRAT_MISSING_BOX )
		{
			for ( x = 0; x < sud->length; x += sud->length_of_box )
			{
				for ( y = 0; y < sud->length; y += sud->length_of_box )
				{
					changes += Strategy_MissingBox ( sud, x, y );
				}
			}
		}

	} while ( changes != 0 );

	return changes;
}





static Solver solver[] = {
	&SolveSequential
};

Solver GetSolver ( unsigned int parallelization )
{
	if ( parallelization >= sizeof( solver ) / sizeof( Solver ) ) return NULL;
	return solver[parallelization];
}


int logic_solve ( Sudoku* sud )
{
	int change = 1;
	int wert = 0;
	int x, y;
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
		for ( x = 0; x < sud->length; x++ )//count empty cells
		{
			for ( y = 0; y < sud->length; y++ )
			{
				if ( sud->grid[y][x][0] == 0 )
				{
					empty++;
				}
			}
		}
		if ( empty == 0 )//If none empty return 
		{
			return 0;//Solved
		}
		for ( i = 0; i < RULE_CNT; i++ )//Loop trought rules
		{
			for ( x = 0; x < sud->length; x++ )//loop trought c positions
			{
				for ( y = 0; y < sud->length; y++ ) //Loop trought y positions
				{
					change = rules[i] ( sud, x, y );
				}
			}
			if ( change )
			{
				break;
			}
		}
		if ( !change )
		{
			return 1;//Not solvable
		}
	}
}