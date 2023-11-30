 // Headers
#include <cassert>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>

using namespace std; 


// check if the chessboard is valid so far, for row in [0,lastPlacedRow]
bool boardIsValidSoFar(int lastPlacedRow, const std::vector<int>& gameBoard)
{
    const auto N = gameBoard.size(); 
    int lastPlacedColumn = gameBoard[lastPlacedRow];

    // Check against other queens
    for (int row = 0; row < lastPlacedRow; ++row)
    {
        if (gameBoard[row] == lastPlacedColumn) // same column, fail!
            return false;
        // check the 2 diagonals
        const auto col1 = lastPlacedColumn - (lastPlacedRow - row);
        const auto col2 = lastPlacedColumn + (lastPlacedRow - row);
        if (gameBoard[row] == col1 || gameBoard[row] == col2)
            return false;
    }
    return true;
}

// A recursive function to calculate solutions
void calculateSolutionsRecursive(int writeToRow, std::vector<int>& gameBoard, int N, std::vector<std::vector<int>>& solutions)
{
    // for each column
    for (int i = 0; i < N; ++i)
    {
        // set queen at the current column, at the specified row (writeToRow variable)
        gameBoard[writeToRow] = i;
        // if the board is valid so far
        if (boardIsValidSoFar(writeToRow, gameBoard))
        {
            const auto nextWriteToRow = writeToRow + 1;
            if (nextWriteToRow != N) // haven't filled the chessboard yet, so fill the next row
                calculateSolutionsRecursive(nextWriteToRow, gameBoard, N, solutions);
            else // filled the chessboard, so save the solution
                solutions.push_back(gameBoard);
        }
    }
}

// Calculate all solutions given the size of the chessboard
void calculateAllSolutions(int N, bool print)
{
    std::vector<std::vector<int>> solutions;
    std::vector<int> gameBoard(N, 0);
    
    auto start_time = std::chrono::high_resolution_clock::now();

    calculateSolutionsRecursive(0, gameBoard, N, solutions);

    auto end_time = std::chrono::high_resolution_clock::now();
    auto execution_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
   
    printf("N=%d, solutions=%d, execution time=%lld milliseconds\n", N, int(solutions.size()), execution_time);
    
    if (print)
    {
        std::string text;
        text.resize(N * (N + 1)+1); // we know exactly how many characters we'll need: one for each place at the board, and N newlines (at the end of each row). And one more newline to differentiate from other solutions
        text.back() = '\n'; // add extra line at the end
        for (const auto& solution : solutions)
        {
            for (int i = 0; i < N; ++i)
            {
                auto queenAtRow = solution[i];
                for (int j = 0; j < N; ++j)
                    text[i * (N+1) + j] = queenAtRow == j ? 'X' : '.';
                text[i * (N + 1) + N] = '\n';
            }
            std::cout << text << "\n";
        }
    }
}


int main(int argc, char** argv)
{
    for (int N = 4; N < 13; ++N)
        calculateAllSolutions(N, false);
}