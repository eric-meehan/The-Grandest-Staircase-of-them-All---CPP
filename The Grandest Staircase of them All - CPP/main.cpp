/*
 Eric Meehan
 2020-11-20
 
 The Grandest Staircase of them All
 */

#include <iostream>
#include <string>

// Function Prototypes
int * * GenerateMatrix(int);
void InitializeMatrix(int * *, int);
void CalculateDistinctPartitions(int * *, int);

int main(int argc, const char * argv[]) {
    // The user may specify n through command line arguments
    int n;
    if (argc > 1)
    {
        // This argument will need to be cast as an integer
        try
        {
            n = std::stoi(argv[1]);
        }
        catch (std::invalid_argument)
        {
            std::cout << "Invalid input, using default argument 200." << std::endl;
            n = 200;
        }
    }
    else
    {
        n = 200;
    }
    // This problem is essentially Euler's distinct partition problem, which can be solved using a matrix.
    int * * m = GenerateMatrix(n);
    // Initialize the matrix cells
    InitializeMatrix(m, n);
    // Calculate the number of distinct partitions for each cell
    CalculateDistinctPartitions(m, n);
    // The number of distinct partitions is stored in the second to last cell
    std::cout << m[n][n - 1] << std::endl;
    return 0;
}

int * * GenerateMatrix(int n)
{
    // Generates a matrix with n columns and n + 1 rows
    int * * m = new int * [n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        m[i] = new int[n];
    }
    return m;
}

void InitializeMatrix(int * * m, int n)
{
    // Given that a number can be be partitioned at least once when the largest acceptable partition number is greater than or equal to itself, these cells are initialized to one.
    for (int row = 0; row < n + 1; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (row <= column)
            {
                m[row][column] = 1;
            }
            else{
                m[row][column] = 0;
            }
        }
    }
}

void CalculateDistinctPartitions(int * * m, int n)
{
    // For each cell, accumulate the total number of distinct partitions by collecting the sum from each diagonal starting at the top of the respective column, moving 'south-west' through the matrix.
    for (int row = 3; row < n + 1; row++)
    {
        for (int column = 2; column < n; column++)
        {
            // The diagonal summation can be further abstracted by adding the previous cell to the one in m[row - column][column - 1]
            m[row][column] = m[row][column - 1];
            if (row >= column)
            {
                m[row][column] += m[row - column][column - 1];
            }
        }
    }
}
