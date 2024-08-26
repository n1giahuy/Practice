#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Global variables and constants
char board[3][3];          // The game board, a 3x3 grid
const char PLAYER = 'X';   // Player's marker
const char COMPUTER = 'O'; // Computer's marker

// Function prototypes
void resetBoard();        // Initializes or resets the game board
void printBoard();        // Prints the current state of the game board
int checkFreeSpaces();    // Checks and returns the number of free spaces on the board
void playerMove();        // Handles the player's move
void computerMove();      // Handles the computer's move
char checkWinner();       // Checks if there's a winner or a tie
void printWinner(char);   // Prints the result of the game

int main() {
    char winner = ' ';    // Variable to store the winner ('X', 'O', or ' ')
    char response;        // Variable to store user's response for playing again

    // Main game loop
    do {
        winner = ' ';     // Reset winner at the beginning of each game
        response = ' ';   // Reset response

        resetBoard();     // Initialize the board for a new game

        // Game loop for each move until there is a winner or the board is full
        while (winner == ' ' && checkFreeSpaces() != 0) {
            printBoard();  // Print the current state of the board

            playerMove();  // Get the player's move
            winner = checkWinner(); // Check if the player has won
            if (winner != ' ' || checkFreeSpaces() == 0) {
                break;  // Exit loop if there's a winner or no free spaces left
            }

            computerMove(); // Get the computer's move
            winner = checkWinner(); // Check if the computer has won
            if (winner != ' ' || checkFreeSpaces() == 0) {
                break;  // Exit loop if there's a winner or no free spaces left
            }
        }

        printBoard();   // Print the final state of the board
        printWinner(winner); // Print the result of the game

        // Ask if the player wants to play again
        printf("\nWould you like to play again? (Y/N): ");
        getchar();     // Clear newline character left by previous input
        scanf("%c", &response); // Get the player's response
        response = toupper(response); // Convert response to uppercase

    } while (response == 'Y'); // Repeat if the player wants to play again

    printf("Thanks for playing!"); // End message
    return 0;
}

// Initializes or resets the game board
void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' '; // Set each cell to empty space
        }
    }
}

// Prints the current state of the game board
void printBoard() {
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Checks and returns the number of free spaces on the board
int checkFreeSpaces() {
    int freeSpaces = 9; // Start with the maximum number of spaces

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') { // If the cell is not empty
                freeSpaces--; // Decrease the count of free spaces
            }
        }
    }

    return freeSpaces; // Return the number of free spaces
}

// Handles the player's move
void playerMove() {
    int x, y;

    do {
        printf("Enter row# (1-3): ");
        scanf("%d", &x);
        x--; // Convert to zero-based index
        printf("Enter column# (1-3): ");
        scanf("%d", &y);
        y--; // Convert to zero-based index

        if (board[x][y] != ' ') {
            printf("Invalid move! \n"); // Notify if the cell is already occupied
        } else {
            board[x][y] = PLAYER; // Make the move
            break; // Exit loop after a valid move
        }
    } while (board[x][y] != ' '); // Continue until a valid move is made
}

// Handles the computer's move
void computerMove() {
    srand(time(0)); // Seed the random number generator
    int x, y;

    if (checkFreeSpaces() > 0) {
        do {
            x = rand() % 3; // Random row
            y = rand() % 3; // Random column
        } while (board[x][y] != ' '); // Continue until an empty cell is found

        board[x][y] = COMPUTER; // Make the move
    } else {
        printWinner(' '); // Print tie if no spaces left
    }
}

// Checks if there's a winner or a tie
char checkWinner() {
    // Check rows for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0]; // Return winner if a row is filled
        }
    }

    // Check columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i]; // Return winner if a column is filled
        }
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0]; // Return winner if diagonal from top-left to bottom-right is filled
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2]; // Return winner if diagonal from top-right to bottom-left is filled
    }

    return ' '; // Return ' ' if no winner yet
}

// Prints the result of the game
void printWinner(char winner) {
    if (winner == PLAYER) {
        printf("YOU WIN! "); // Player wins
    } else if (winner == COMPUTER) {
        printf("YOU LOSE! "); // Computer wins
    } else {
        printf("IT'S A TIE! "); // No winner, it's a tie
    }
}
