#include <stdio.h>

int location = 0;
int occupied[25];


int ifOccupied(int move, int occupied[25])
{
    int i;

    for(i = 0; i < 25; i++)
    {
        if(move == occupied[i])
        {
            return 1;
        }
    }
    return 0;
}


void print(int occupied[25])
{
    int i;

    for(i = 0; i < 25; i++)
    {
        printf("%d ", occupied[i]);
    }
    printf("\n");
}


int checkCapacity(int occupied[25])
{
    int i;

    for(i = 0; i < 25; i++)
    {
        if(occupied[i] == 0)
        {
            return 1;
        }
    }
    return 0;
}


void knightsTour(int spot, int j, int i, int grid[5][5])
{
    if(checkCapacity(occupied) == 0)
    {
        print(occupied);
        return;
    }
    else
    {
        if(j - 2 >= 0 && i - 1 >= 0)
        {
            if(location <  25 && ifOccupied(grid[j - 2][i - 1], occupied) == 0)
            {
                occupied[location] = grid[j - 2][i - 1];
                location++;

                knightsTour(grid[j - 2][i - 1], j - 2, i - 1, grid);
                location--;

                occupied[location] = 0;
            }
        }

        if(j - 1 >= 0 && i - 2 >= 0)
        {
            if(location <  25 && ifOccupied(grid[j - 1][i - 2], occupied) == 0)
            {
                occupied[location] = grid[j - 1][i - 2];
                location++;

                knightsTour(grid[j - 1][i - 2], j - 1, i - 2, grid);
                location--;

                occupied[location] = 0;
            }
        }

        if(j + 1 < 5 && i - 2 >= 0)
        {
            if(location <  25 && ifOccupied(grid[j + 1][i - 2], occupied) == 0)
            {
                occupied[location] = grid[j + 1][i - 2];
                location++;

                knightsTour(grid[j + 1][i - 2], j + 1, i - 2, grid);
                location--;

                occupied[location] = 0;
            }
        }

        if(j + 2 < 5  && i - 1 >= 0)
        {
            if(location <  25 && ifOccupied(grid[j + 2][i - 1], occupied) == 0)
            {
                occupied[location] = grid[j + 2][i - 1];
                location++;

                knightsTour(grid[j + 2][i - 1], j + 2, i - 1, grid);
                location--;

                occupied[location] = 0;
            }
        }

        if(j + 2 < 5 && i + 1 < 5)
        {
            if(location <  25 && ifOccupied(grid[j + 2][i + 1], occupied) == 0)
            {
                occupied[location] = grid[j + 2][i + 1];
                location++;

                knightsTour(grid[j + 2][i + 1], j + 2, i + 1, grid);
                location--;

                occupied[location] = 0;
            }
        }

        if(j + 1 < 5 && i + 2 < 5)
        {
            if(location <  25 && ifOccupied(grid[j + 1][i + 2], occupied) == 0)
            {
                occupied[location] = grid[j + 1][i + 2];
                location++;

                knightsTour(grid[j + 1][i + 2], j + 1, i + 2, grid);
                location--;

                occupied[location] = 0;
            }
        }

        if(j - 1 >= 0 && i + 2 < 5)
        {
            if(location <  25 && ifOccupied(grid[j - 1][i + 2], occupied) == 0)
            {
                occupied[location] = grid[j - 1][i + 2];
                location++;

                knightsTour(grid[j - 1][i + 2], j - 1, i + 2, grid);
                location--;

                occupied[location] = 0;
            }
        }

        if(j - 2 >= 0 && i + 1  < 5)
        {
            if(location <  25 && ifOccupied(grid[j - 2][i + 1], occupied) == 0)
            {
                occupied[location] = grid[j - 2][i + 1];
                location++;

                knightsTour(grid[j - 2][i + 1], j - 2, i + 1, grid);
                location--;

                occupied[location] = 0;
            }
        }
    }

    if(checkCapacity(occupied) == 1)
    {
        occupied[location - 1] = 0;
    }

}


void createGrid(int grid[5][5])
{
    int i, j;
    int k = 1;

    for(j = 0; j < 5; j++)
    {
        for(i = 0; i < 5; i++)
        {
            grid[j][i]= k;
            k++;
        }
    }
}


int main(int argc, char *argv[])
{
    int grid[5][5];
    int j, i;

    createGrid(grid);

    for(j = 0; j < 5; j++)
    {
        for(i = 0; i < 5; i++)
        {
            if(grid[j][i] % 2)
            {
                int r;

                for(r = 0; r < 25; r++)
                {
                    occupied[r] = 0;
                }

                occupied[location]=grid[j][i];
                location++;

                knightsTour(grid[j][i], j,i,grid);

                location = 0;
            }
        }
    }
    return 0;
}