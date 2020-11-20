/*
 Eric Meehan
 2020-11-20
 
 The Grandest Staircase of them All
 */

#include <iostream>

int main(int argc, const char * argv[]) {
    // This problem is essentially Euler's distinct partition problem.
    // To solve it, an n by n+1 matrix is generated with rows representing the number to be partitioned and columns representing the largest acceptable number in a given partition.
    int n = 200;
    int m[n + 1][n];
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
    // The number of distinct partitions is stored in the second to last cell
    std::cout << m[n][n - 1] << std::endl;
    return 0;
}
