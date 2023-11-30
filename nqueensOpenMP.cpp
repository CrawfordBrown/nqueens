#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <omp.h>
#include <cstdio>
#include <chrono>

bool boardIsValidSoFar(int lastPlacedRow, const std::vector<int>& gameBoard)
{
    const auto N = gameBoard.size();
    int lastPlacedColumn = gameBoard[lastPlacedRow];

    for (int row = 0; row < lastPlacedRow; ++row)
    {
        if (gameBoard[row] == lastPlacedColumn)
            return false;

        const auto col1 = lastPlacedColumn - (lastPlacedRow - row);
        const auto col2 = lastPlacedColumn + (lastPlacedRow - row);
        if (gameBoard[row] == col1 || gameBoard[row] == col2)
            return false;
    }
    return true;
}

void calculateSolutionsIterative(int N, int row, std::vector<std::vector<int>>& solutions)
{
    std::stack<std::pair<int, std::vector<int>>> stateStack;
    stateStack.push({row, std::vector<int>(N, -1)});

    while (!stateStack.empty())
    {
        auto [currentRow, gameBoard] = stateStack.top();
        stateStack.pop();

        for (int i = 0; i < N; ++i)
        {
            gameBoard[currentRow] = i;
            if (boardIsValidSoFar(currentRow, gameBoard))
            {
                if (currentRow + 1 != N)
                {
                    stateStack.push({currentRow + 1, gameBoard});
                }
                else
                {
                    solutions.push_back(gameBoard);
                }
            }
        }
    }
}

void calculateAllSolutions(int N, bool print)
{
    std::vector<std::vector<int>> solutions;

    #pragma omp parallel for
    for (int row = 0; row < N; ++row)
    {
        std::vector<std::vector<int>> localSolutions;
        for (int i = 0; i < N; ++i)
        {
            calculateSolutionsIterative(N, i, localSolutions);
        }

        #pragma omp critical
        {
            solutions.insert(solutions.end(), localSolutions.begin(), localSolutions.end());
        }
    }

    if (print)
    {
{
        std::string text;
        text.resize(N * (N + 1) + 1);
        text.back() = '\n';
        for (const auto &solution : solutions)
        {
            for (int i = 0; i < N; ++i)
            {
                auto queenAtRow = solution[i];
                for (int j = 0; j < N; ++j)
                    text[i * (N + 1) + j] = queenAtRow == j ? 'X' : '.';
                text[i * (N + 1) + N] = '\n';
            }
            std::cout << text << "\n";
        }
    }    }
}

int main(int argc, char **argv)
{
    omp_set_max_active_levels(2);
    auto start_time = omp_get_wtime();

#pragma omp parallel for
    for (int N = 4; N < 13; ++N)
    {
        auto loop_start_time = omp_get_wtime();

#pragma omp parallel for
        for (int row = 0; row < N; ++row)
        {
            std::vector<std::vector<int>> solutions;
            calculateAllSolutions(N, false);
        }

        auto loop_end_time = omp_get_wtime();
        auto loop_execution_time = loop_end_time - loop_start_time;

#pragma omp critical
        std::cout << "Execution time for N=" << N << ": " << loop_execution_time << " seconds\n";
    }

    auto end_time = omp_get_wtime();
    auto execution_time = end_time - start_time;

    std::cout << "Total execution time: " << execution_time << " seconds\n";

    return 0;
}





