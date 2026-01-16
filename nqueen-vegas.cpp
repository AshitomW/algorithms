#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

class NQueensLasVegas {
    int n;
    std::vector<int> board; // board[row] = col
    std::mt19937 rng;

public:
    NQueensLasVegas(int size) : n(size), board(size), rng(std::random_device{}()) {}

    bool isSafe(int row, int col) {
        for (int i = 0; i < row; ++i) {
            int placedCol = board[i];
            // Check column and diagonals
            if (placedCol == col || 
                abs(placedCol - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }

    bool solve() {
        int attempts = 0;
        while (true) {
            attempts++;
            if (tryPlaceQueens()) {
                std::cout << "Solved in " << attempts << " restarts!" << std::endl;
                return true;
            }
        }
    }

    bool tryPlaceQueens() {
        for (int row = 0; row < n; ++row) {
            std::vector<int> safeColumns;
            
            // Find all available safe spots in this row
            for (int col = 0; col < n; ++col) {
                if (isSafe(row, col)) {
                    safeColumns.push_back(col);
                }
            }

            // If no safe spots, this run failed (Las Vegas restart point)
            if (safeColumns.empty()) return false;

            // Pick a random safe column
            std::uniform_int_distribution<int> dist(0, safeColumns.size() - 1);
            board[row] = safeColumns[dist(rng)];
        }
        return true;
    }

    void printBoard() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << (board[i] == j ? " Q " : " . ");
            }
            std::cout << "\n";
        }
    }
};

int main() {
    int n = 8; 
    NQueensLasVegas solver(n);

    if (solver.solve()) {
        solver.printBoard();
    }

    return 0;
}
