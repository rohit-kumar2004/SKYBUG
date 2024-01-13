#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "---------" << endl;
    }
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Check diagonal (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Check diagonal (top-right to bottom-left)
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // If there is an empty cell, the game is not a draw
            }
        }
    }
    return true; // All cells are filled, the game is a draw
}

// Function to play the Tic-Tac-Toe game
void playTicTacToe() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize 3x3 board with empty cells
    char currentPlayer = 'X';

    while (true) {
        // Display the current state of the board
        printBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Update the board with the player's move
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check for a win
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check for a draw
            if (checkDraw(board)) {
                printBoard(board);
                cout << "The game is a draw!" << endl;
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

int main() {
    while (true) {
        playTicTacToe();

        // Ask if the players want to play again
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }

    return 0;
}
