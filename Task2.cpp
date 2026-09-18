#include <iostream>
#include <vector>

using namespace std;

// Function to print the current state of the 3x3 board
void displayBoard(const vector<char>& board) {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
    cout << "\n";
}

// Function to check if a player has won the game
bool checkWin(const vector<char>& board, char player) {
    // Rows
    if ((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player))
        return true;
    
    // Columns
    if ((board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player))
        return true;
    
    // Diagonals
    if ((board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player))
        return true;

    return false;
}

// Function to check if the board is completely full (Draw condition)
bool checkDraw(const vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false; // Found an empty spot
        }
    }
    return true;
}

int main() {
    // Initialize the board positions with numbers 1 to 9
    vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentPlayer = 'X';
    bool gameRunning = true;

    cout << "=================================\n";
    cout << "    Welcome to C++ Tic-Tac-Toe   \n";
    cout << "=================================\n";
    cout << "Player 1 [X]  -  Player 2 [O]\n";

    while (gameRunning) {
        displayBoard(board);
        
        int choice;
        cout << "Player " << currentPlayer << ", enter a number (1-9): ";
        cin >> choice;

        // Input validation: Check if choice is between 1-9 and the spot isn't already taken
        if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            cout << "Invalid move! Please select an available slot between 1 and 9.\n";
            continue;
        }

        // Apply the player's move
        board[choice - 1] = currentPlayer;

        // Check for victory
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Congratulations! Player " << currentPlayer << " wins!\n";
            gameRunning = false;
        } 
        // Check for a tie
        else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw! Well played both.\n";
            gameRunning = false;
        } 
        // Switch turns
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}