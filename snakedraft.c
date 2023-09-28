#include <stdio.h>
#include <conio.h> // _kbhit() _getch()
#include <windows.h> // Sleep()
#include <unistd.h> // system("cls")


	//THIS PROGRAM IS SUPPOSED TO MAKE A 2D ARRAY, PRINT A SNAKE WITHIN IT, MOVE IT, EAT FOOD AND GROW FROM IT
	
	//SO FAR I CANT GET THE SNAKE TO MOVE PLUS THERE'S A CONSTANT FLICKERING. (I HAVENT ADDED THE LOGIC FOR IT TO EAT AND GROW) 
	
	// WHATEVER IS INCLUDED IN HERE IS WHAT I CAN USE, I CAN'T USE OTHER METHODS SUCH AS STRUCT E.T.C TO SOLVE THIS

#define UPDATER 150

#define BOARD_SIZE_ROW	30
#define BOARD_SIZE_COL	30

int snakeX[BOARD_SIZE_ROW * BOARD_SIZE_COL];
int snakeY[BOARD_SIZE_ROW * BOARD_SIZE_COL];
char Board[BOARD_SIZE_ROW][BOARD_SIZE_COL];
char userInput = 'a';
int snakeLength = 1;
//int snakeX, snakeY;
//int cmd = 0;

void getUserInput() {
    if (_kbhit())
	 {
        userInput = _getch();

        // Check if the input is one of the allowed keys
        if (userInput == 'a' || userInput == 'A' || userInput == 'd' || userInput == 'D' ||
            userInput == 'w' || userInput == 'W' || userInput == 's' || userInput == 'S' ||
            userInput == 'q' || userInput == 'Q')
		{
            // Do nothing, the input is valid
        } 
		else
		{
            userInput = ' '; // Invalid input, keep the last direction
        }
    }
}

void init() // an initialization screen
{
    printf(" +...........................+\n"); 
    printf(" |  ENGINEERING PROJECT 1    |\n");
    printf(" +...........................+\n");

    printf("press any key to start the program\n");
    printf("press 'a' to move to the left\n");
    printf("press 'd' to move to the right\n");
    printf("press 'w' to move up\n");
    printf("press 's' to move down\n");
    printf("press 'q' to end the program\n");
}

void resetBoard() // PRINTS THE BOARD
{
	for( int i = 0; i < BOARD_SIZE_ROW; i++ )
	{
		for(int j = 0; j < BOARD_SIZE_COL; j++)
		{
			if(i == 0 || i == BOARD_SIZE_ROW - 1 || j == 0 || j == BOARD_SIZE_COL - 1)
			{
				Board[i][j] = '#';	//border
			}
			else if( i == snakeX[0] && j == snakeY[0])
			{
				Board[i][j] = '<'; // snake's head
			}
			else
			{
				Board[i][j] = ' '; // inside the 2D
			}
			printf("%c", Board[i][j]);
		}
		printf("\n");
	}

}

void moveSnake()
{
	int	newX = snakeX[0];
	int newY = snakeY[0];
	
	switch(userInput) // DIRECTION
	{
		case 'w':
		case 'W':
			newY--;
			break;
		case 's':
		case 'S':
			newY++;
			break;
		case 'a':
		case 'A':
			newX--;
			break;
		case 'd':
		case 'D':
			newX++;
			break;
	}
	
	 // Wrap around the board if the new position is out of bounds
    if (newX == 0)
	{
        newX = BOARD_SIZE_ROW - 1;
    } 
	else if (newX == BOARD_SIZE_ROW)
	{
        newX = 1;
    }
    else if (newY == 0) 
	{
        newY =  BOARD_SIZE_COL - 1;
    } 
	else if (newY == BOARD_SIZE_COL)
	{
        newY = 1;
    }
    
     // Update the snake's body positions
    int prevX = snakeX[0]; 				
    int prevY = snakeY[0];
    int tempX, tempY;
    snakeX[0] = newX;
    snakeY[0] = newY;

    for (int i = 1; i < snakeLength; i++) 
	{
        tempX = snakeX[i];
        tempY = snakeY[i];
        snakeX[i] = prevX;
        snakeY[i] = prevY;
        prevX = tempX;
        prevY = tempY;
    }
}

int main()
{
	// pick a VALID spot to start where the snake will start from
	snakeX[0] = BOARD_SIZE_ROW / 2;
	snakeY[0] = BOARD_SIZE_COL / 2;
	init();
	_getch(); 
	
	//  Program Loop
	while(1)
	{	
		getUserInput();
	//	system("cls");
		
			// reset the board to default empty 
		resetBoard();
		moveSnake();
		
		system("cls"); // Clear the screen
        for (int i = 0; i < BOARD_SIZE_ROW; i++)  // UPDATE THE POSITION OF THE SNAKE
		{ 
            for (int j = 0; j < BOARD_SIZE_COL; j++)
			{
                printf("%c", Board[i][j]);
            }
            
            printf("\n");
        }

	 	if(userInput == 'q' || userInput == 'Q')
        {
            printf("\n You have exited the program successfully  BYE!\n");
            break; // gives the loop a way out
        }
		
		
		// TO DO: move the snake to the new position
		
		
		
		// TO DO: clear the screen of all contents
		
		
		// TO DO: draw the current state of the board
		
		
		
		Sleep(UPDATER);	// sleep for the specified amount of time
			
	}		
	return 0;
}

