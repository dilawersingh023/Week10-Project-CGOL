/*
 ============================================================================
 Name        : COGL.c
 Author      : Dilawer
 Version     :
 Copyright   : Your copyright notice
 Description : Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>

int row_size, col_size, as, row_alive, col_alive, generations;              // Declaring the variables to be use in the program
void NextGeneration(int a[row_size][col_size], int row_size, int col_size);    // Declaring the function NextGeneration

int main()
    {

	printf("Enter the size of row\n");
	scanf("%d", &row_size);                // Ask for the size of the row for the array
	printf("Enter the size of column\n");
	scanf("%d", &col_size);                // Ask for the number of columns in the array

    // Initializing the 2D array with given number of rows and column
   int a[row_size][col_size];

   for(int p = 0; p<row_size; p++){
	   for(int q = 0; q<col_size; q++){
		   a[p][q] = 0;                    // Giving the 0 value to the complete array at initial stage
	   }
   }

   printf("Enter the number of alive cells\n");
   scanf("%d", &as);         // Ask the user for the number of alive cells that he wants to enter

   for(int o = 0; o<as; o++){               // Ask for the coordinates of alive cells
	   printf("Enter the row of alive cell\n");
	   scanf("%d", &row_alive);
	   printf("Enter the column of alive cell\n");
	   scanf("%d", &col_alive);
	   a[row_alive][col_alive] = 1;         // Make the cell alive at the coordinate entered by the user

   }
        // Displaying the grid
        printf("Initial State\n");     //Prints the initial state of CGOL
        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                if (a[i][j] == 0)
                    printf("0");        //Prints the '0' if the cell is dead
                else
                    printf("1");        //Prints the '1' if the cell is alive
            }
           printf("\n");
        }
       printf("\n");
        NextGeneration(a, row_size, col_size);     // Calling the function NextGeneration
    }


    void NextGeneration(int a[row_size][col_size], int row_size, int col_size)       //Method to imply all the four rules and
                                                                                     //to print the as many number of generations
    {

        int no = 1;
    	int b[row_size][col_size];                   // Declaring the another array to store the values

    printf("Enter the number of generations\n");
    scanf("%d", &generations);                        // Ask the user for the number of generations to be displayed
    printf("\n");

    for(int g = 0; g<generations; g++){        // Loop to print the number of generations
        for (int l = 1; l < row_size ; l++)     // Loop through every row
        {
            for (int m = 1; m < col_size ; m++) // Loop through every cell
            {

            	 int numOfAliveNeighbours = 0;            //Initializing the variable to count the number of alive neighbors


            if(l == 0){                     // condition to check if the cell is in the top row
            	for (int i = 0; i <= 1; i++)            //Loop through every row near the alive cell
            	   for (int j = -1; j <= 1; j++)        //Loop through every cell near the alive cell
            	     numOfAliveNeighbours += a[l + i][m + j];   //Counting number of neighbours that are alive

           	         numOfAliveNeighbours -= a[l][m];       //subtracting the alive cell for which we are checking the alive neighbours
            }


            else if(l == 0 && m == 0){      // Condition to check if the cell is at top-left
            	for (int i = 0; i <= 1; i++)            //Loop through every row near the alive cell
            	   for (int j = 0; j <= 1; j++)        //Loop through every cell near the alive cell
            	     numOfAliveNeighbours += a[l + i][m + j];   //Counting number of neighbours that are alive

            	     numOfAliveNeighbours -= a[l][m];       //subtracting the alive cell for which we are checking the alive neighbours

            }


            else if(m == 0){                // Condition to check if the cell is in the first column
            	for (int i = -1; i <= 1; i++)            //Loop through every row near the alive cell
            	   for (int j = 0; j <= 1; j++)        //Loop through every cell near the alive cell
            	     numOfAliveNeighbours += a[l + i][m + j];   //Counting number of neighbours that are alive

            	     numOfAliveNeighbours -= a[l][m];       //subtracting the alive cell for which we are checking the alive neighbours

            }


            else if(m == 0 && l == row_size - 1){       // Condition to check if the cell is at bottom-left
            	for (int i = -1; i < 1; i++)            //Loop through every row near the alive cell
            	   for (int j = 0; j <= 1; j++)        //Loop through every cell near the alive cell
            	     numOfAliveNeighbours += a[l + i][m + j];   //Counting number of neighbours that are alive

            	     numOfAliveNeighbours -= a[l][m];       //subtracting the alive cell for which we are checking the alive neighbours

            }

            else if(l == row_size - 1){                 // Condition to check if the cell is at the bottom
            	for (int i = -1; i < 1; i++)            //Loop through every row near the alive cell
            	   for (int j = -1; j <= 1; j++)        //Loop through every cell near the alive cell
            	     numOfAliveNeighbours += a[l + i][m + j];   //Counting number of neighbours that are alive

            	     numOfAliveNeighbours -= a[l][m];       //subtracting the alive cell for which we are checking the alive neighbours

            }

            else if(l == row_size -1 && m == col_size -1){     // Condition to check if the cell is at the bottom-right
            	for (int i = -1; i < 1; i++)            //Loop through every row near the alive cell
            	   for (int j = -1; j < 1; j++)        //Loop through every cell near the alive cell
            	     numOfAliveNeighbours += a[l + i][m + j];   //Counting number of neighbours that are alive

            	     numOfAliveNeighbours -= a[l][m];       //subtracting the alive cell for which we are checking the alive neighbours

            }

            else if(m == col_size -1 ){                  // Condition to check if the cell is in the last columns
            	for (int i = -1; i <= 1; i++)            //Loop through every row near the alive cell
            	   for (int j = -1; j < 1; j++)        //Loop through every cell near the alive cell
            	     numOfAliveNeighbours += a[l + i][m + j];   //Counting number of neighbours that are alive

            	     numOfAliveNeighbours -= a[l][m];       //subtracting the alive cell for which we are checking the alive neighbours

            }

            else if(l == 0 && m == col_size - 1){       // Condition to check if the cell at the top-right
            	for (int i = 0; i <= 1; i++)            //Loop through every row near the alive cell
            	   for (int j = -1; j < 1; j++)        //Loop through every cell near the alive cell
            	     numOfAliveNeighbours += a[l + i][m + j];   //Counting number of neighbours that are alive

            	     numOfAliveNeighbours -= a[l][m];       //subtracting the alive cell for which we are checking the alive neighbours

            }

            else {
            	for (int i = -1; i <= 1; i++)            //Loop through every row near the alive cell
            	   for (int j = -1; j <= 1; j++)        //Loop through every cell near the alive cell
            	     numOfAliveNeighbours += a[l + i][m + j];   //Counting number of neighbours that are alive

            	     numOfAliveNeighbours -= a[l][m];       //subtracting the alive cell for which we are checking the alive neighbours

            }

    // Applying all the 4 rules of Conway's Game of Life

                // Cell dies due to less than 2 neighbors
                if ((a[l][m] == 1) && (numOfAliveNeighbours < 2))
                    b[l][m] = 0;

                // Cell dies due to over population
                else if ((a[l][m] == 1) && (numOfAliveNeighbours > 3))
                    b[l][m] = 0;

                // A new cell is born
                else if ((a[l][m] == 0) && (numOfAliveNeighbours == 3))
                    b[l][m] = 1;

                // Remains the same
                else
                    b[l][m] = a[l][m];
            }
        }


        printf("%d Generation:\n", no);          //Prints the Generations of CGOL after applying all the rules
            no++;
        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                if (a[i][j] == 0)
                   printf("0");        //Prints "0" for every dead cell
                else
                    printf("1");       //Prints "1" for every alive cell
            }
            printf("\n");
        }
        printf("\n");
    }
    }


