/*
File's Title: MazeSolver.cpp
Name: Leman Yan
Class: CS_235
Professor: Tiziana Ligorio
Date: 11/03/18
Maze Solver
Purpose: Project 4 - Find a solution to a maze read from an input file
and prints a solution to the standard output
*/

#include <fstream>

#include <iostream>

#include "MazeSolver.h"

#include <string>

using namespace std;

							//public


//constructor
//pre: input file is in correct format with first two values being integers
//      followed by valid maze characters in {'_', '*','$'}
//post: if inuput file cannot be read outputs "Cannot read from input_file"
//      otherwise sets maze_rows_ and maze_columns_ from the first two values in input file
//      and allocates two 2-dimesional array of size maze_rows_ and maze_columns_
//      both maze_ and solution_ are initialized with characters read from input

    
MazeSolver::MazeSolver(std::string input_file)
{
	ifstream fin(input_file);	//fin=file input
		if (fin.fail()) 
		{
		   std::cerr << "Cannot read from "<<input_file<<std::endl;
		   std::exit(1); // exit if failed to open the file
		}
	
	fin >> maze_rows_ >> maze_columns_;
	initializeMaze(maze_rows_ , maze_columns_);
	fillMaze(fin);
	maze_ready=true;
	initializeSolution();

	fin.close();

}

/*
//free the allocated memory
for( int i = 0 ; i < ROWS ; i++ )
delete [] dynamicArray[i] ;
delete [] dynamicArray ;
*/


// destructor
//post: deletes maze_ and solution_
MazeSolver::~MazeSolver()
{
if((maze_!=nullptr) && (solution_!=nullptr))	//Check if maze_ and solution_ are dynamically allocated
	{
		for(int i=0; i< maze_rows_ ; i++)
		{
			delete [] maze_[i];
		}			
			delete [] maze_;

		for(int i=0; i< maze_rows_ ; i++)
		{
			delete [] solution_[i];
		}
			delete [] solution_;
	}
}
    
    
//return: true if maze has been initialized, false otherwise
bool MazeSolver::mazeIsReady()
{
	return maze_ready;
}
    
/*
While the stack is not empty
	If your current position is an exit ($)
		Print “Found exit!!!” and return true
	Else if the current position is extensible
		Push all positions reachable by moving one step SOUTH and one
		step EAST from the point on which you are standing on the stack.
		Mark you current position as PATH ( > ) on the solution
		Move forward by setting the current position to the one at the
		top of the stack.
	Else (if you cannot move forward)
		Mark your current position as VISITED (X) on the maze
		Mark your current position as BACKTRACKED (@) on the solution
		Pop the stack //BACKTRACK STEP
		If the stack is not empty
			Move forward by setting the current position to the one at
			the top of the stack.
		Else (if the stack is empty)
		Print “This maze has no solution.” and return false
*/

//pre: maze_ has been initialized with valid character values in {'_', '*','$'}
//post: solution_ has been marked with '>' signs along the path to the exit
//      prints "Found the exit!!!" if exit is found
//      or "This maze has no solution." if no exit could be found
//return: true if exit is found, false otherwise
bool MazeSolver::solveMaze()
{
	if(backtrack_stack_.empty() == 1)
	{
		cout<<"This maze has no solution."<<endl;
		return false;
	}

	Position currentPos;  
	currentPos.row=backtrack_stack_.top().row;
	currentPos.column=backtrack_stack_.top().column;

	while(backtrack_stack_.empty() != 1)
	{
		if( maze_[currentPos.row][currentPos.column] == '$' )
		{
			cout<<"Found the exit!!!"<<endl;
			return 1;
		}
		else if( extendPath(currentPos) )
		{
			solution_[currentPos.row][currentPos.column]='>';
			currentPos=backtrack_stack_.top();
		}
		else //Can't move so need to backtrack
		{

			maze_[currentPos.row][currentPos.column]='X';
			solution_[currentPos.row][currentPos.column]='@';
			backtrack_stack_.pop();
			if( backtrack_stack_.empty() != 1)
			{
				currentPos=backtrack_stack_.top();
			}
			else
			{
				cout<<"This maze has no solution."<<endl;
				solution_[0][0]='@';
				return false;
			}
		}

	}

	return false;
}
   
/*
Print (cout) “The solution to this maze is:” followed by the solution on a new line.
To output the solution simply loop through solution_ and print every character
separated by a space ( ‘ ‘ )
Print each row on a new line. 
*/
    
//post: prints the solution to the standard output stream
//      with single space character between each maze character
//      and each maze row on a new line
void MazeSolver::printSolution()
{
	cout<<"The solution to this maze is:"<<endl;
	for( int row=0; row<maze_rows_ ; row++)
	{
		for( int column=0; column < maze_columns_ ; column++)
		{
			cout<<solution_[row][column]<<' ';
		}
		cout<<endl;
	}
}

    
    
    //PRIVATE MEMBER FUNCTIONS (helper functions)
   

/*
//Create your pointer
int **ptr;
//Assign first dimension
ptr = new int*[5];
//Assign second dimension
for(int i = 0; i < 5; i++)
	ptr[i] = new int[5];
*/

//pre: rows and columns are positive integers
//post: allocates maze_ with rows and columns
//called by constructor
void MazeSolver::initializeMaze(int rows, int columns)
{
	if( rows>0 && columns>0)
	{
		
		maze_ = new char*[rows];
		for(int i = 0; i < rows; i++)
		{
			maze_[i] = new char[columns];
		}

	}

}
    
//pre: maze_ has been allocated with the correct number of rows and columns read from input file
//post: fills in maze_ with characters read from input file
//called by constructor
void MazeSolver::fillMaze(std::ifstream& input_stream)
{
	for( int rows=0 ; rows < maze_rows_ ; rows++)
	{
		for( int columns=0 ; columns < maze_columns_ ; columns++)
		{
			input_stream >> maze_[rows][columns];

		}

	}

}
    
//pre: maze_ has been initialized with valid character values in {'_', '*','$'}
//     start position is always [0][0]
//post: initializes solution_ with a copy of maze_
//      initializes backtrack_stack_  with all viable paths from position [0][0]
//      and mark the current position as visited ( '>' ) on solution_
//called by constructor
void MazeSolver::initializeSolution()
{
	copyMazetoSolution();
	Position pos;

	if( maze_[1][0] == '_') //Check South
	{
		pos.row=1;
		pos.column=0;
		backtrack_stack_.push(pos);
	
	}

	if( maze_[0][1] == '_')	//Check East
	{
		pos.row=0;
		pos.column=1;
		backtrack_stack_.push(pos);

	}
	
	solution_[0][0]='>';

}
    
//pre: maze_ has been properly initialized
//post: allocates solution_ to the correct number of rows and columns
//      and copies the contents of maze_ into solution_
//called by initializeSolution()
void  MazeSolver::copyMazetoSolution()
{
	if( maze_rows_>0 && maze_columns_>0)
	{
		
		solution_ = new char*[maze_rows_ ];
		for(int i = 0; i < maze_rows_; i++)
		{
			solution_[i] = new char[maze_columns_];
		}

	}

	for(int rows=0 ; rows < maze_rows_ ; rows++)
	{
		for(int columns=0 ; columns < maze_columns_ ; columns++)
		{
			solution_[rows][columns]=maze_[rows][columns];
		} 
	}
}
    
/*
solveMaze will make use of the helper function bool extendPath(Position
current_position);
This method will take the current_position and push on the stack all positions that are
extensible (that it can “move into”) from the current position.
The pseudocode for extendPath is:
 If your current position is extensible in direction SOUTH
 Push the position extending SOUTH onto the stack
 extended is true
 If your current position is extensible in direction EAST
 Push the position extending EAST onto the stack
 extended is true
 Return extended
Keep in mind that, although it would still be correct to invert the order here, for this
project YOU MUST EXTEND FIRST SOUTH THEN EAST to get full credit. 
*/

//pre: current_position is a valid position on the maze_
//post: adds all positions extensible from current_position to backtrack_stack_
//return: true if path was extended, false otherwise
//called by solveMaze()
bool MazeSolver::extendPath(Position current_position)
{
	bool extended=false;

	if( isExtensible( current_position , SOUTH) == 1 )
	{
		backtrack_stack_.push(getNewPosition(current_position , SOUTH) );
		extended=true;
	}

	if( isExtensible( current_position , EAST) == 1 )
	{
		backtrack_stack_.push(getNewPosition(current_position , EAST) );
		extended=true;
	}

	return extended;


}
   
/*
extendPath will use helper functions:
Position getNewPosition(Position old_position, direction dir);
bool isExtensible(Position current_position, direction dir); 
*/

//pre: old_position is a Position initialized with row and column to valid positions in maze_ and it is extensible in direction dir
//return: a new Position on the maze moving in direction dir from old_position
//called by extendPath()
Position MazeSolver::getNewPosition(Position old_position, direction dir)	
{
	Position newPos;



	if( dir == SOUTH)
	{
		newPos.column=old_position.column;
		newPos.row=old_position.row+1;
		return newPos;
	}
	else
	{
		newPos.column=old_position.column+1;
		newPos.row=old_position.row;
		return newPos;
	}
	
}

/*
A position is extensible if from the current position you can move either SOUTH or
EAST by moving into a position marked as ‘ _ ‘ or ‘ $ ‘ on the maze_. Make sure you
keep in mind the boundaries of the matrices here and don’t try to access indices
outside of the maze_
*/
    
//checks if the path can be extended in maze_ from position current_position in direction dir
//return: true if path can be extended given current_position and dir, false otherwise
//called by extendPath
bool MazeSolver::isExtensible(Position current_position, direction dir)
{
	if( dir==SOUTH ) 
	{
		if( current_position.row  != maze_rows_-1 ) 
		{
			if( (maze_[current_position.row+1][current_position.column] == '_') || (maze_[current_position.row+1][current_position.column] == '$' ) )
			{

				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;

		}

	}
	else if( dir==EAST )
	{		
		if( current_position.column != maze_columns_-1)
		{
			if( (maze_[current_position.row][current_position.column+1] == '_') || (maze_[current_position.row][current_position.column+1] == '$' ) )
			{

				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;

		}
	}
	else
	{

		return false;
	}
	

}




















