#include <stdio.h>
#include <stdlib.h>

// Function declarations
void printBoard();
int checkWin();
void resetBoard();

// Global board array
char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {
    int player = 1, input, status = -1;
    char mark;

    resetBoard();
    
    while (status == -1) {
        printBoard();
        player = (player % 2 == 0) ? 2 : 1;
        mark = (player == 1) ? 'X' : 'O';  // Player 1: X, Player 2: O
        
        printf("\n\t Player %d, enter your move (1-9): ", player);
        scanf("%d", &input);

        if (input < 1 || input > 9 || board[input] == 'X' || board[input] == 'O') {
            printf("\n\t ⚠️ Invalid move! Try again.\n");
            continue;
        }

        board[input] = mark;
        status = checkWin();

        if (status == 1) {
            printBoard();
            printf("\n\t 🎉 Congratulations! Player %d wins! 🎉\n", player);
            break;
        } else if (status == 0) {
            printBoard();
            printf("\n\t 🤝 It's a draw!\n");
            break;
        }

        player++;
    }
    return 0;
}

// Function to print the Tic-Tac-Toe board
void printBoard() {
    system("clear"); // Use "cls" for Windows

    printf("\n\t==================================\n");
    printf("\t|        ** TIC TAC TOE **       |\n");
    printf("\t==================================\n\n");
    printf("\t Player 1: X  |  Player 2: O \n\n");

    // Print board with X and O
    printf("\t      %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
    printf("\t    -----|-----|-----\n");
    printf("\t      %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
    printf("\t    -----|-----|-----\n");
    printf("\t      %c  |  %c  |  %c  \n", board[7], board[8], board[9]);

    printf("\n");
}

// Function to check for a win or draw
int checkWin() {
    int winPatterns[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Rows
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Columns
        {1, 5, 9}, {3, 5, 7}  // Diagonals
    };
    
    for (int i = 0; i < 8; i++) {
        if (board[winPatterns[i][0]] == board[winPatterns[i][1]] && 
            board[winPatterns[i][1]] == board[winPatterns[i][2]]) {
            return 1;
        }
    }
    
    for (int i = 1; i <= 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return -1; // Continue playing
        }
    }
    return 0; // Draw
}

// Function to reset the board
void resetBoard() {
    for (int i = 1; i <= 9; i++) {
        board[i] = '0' + i;
    }
}
