#include <iostream>
#include <vector>
using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

struct Move {
    int row, col;
};

class TicTacToe {
public:
    char board[3][3];

    TicTacToe() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = EMPTY;
    }

    void printBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }

    bool isMovesLeft() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == EMPTY)
                    return true;
        return false;
    }

    int evaluate() {
        // Check rows, columns, and diagonals for a win
        for (int row = 0; row < 3; row++) {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                if (board[row][0] == PLAYER_X) return +10;
                else if (board[row][0] == PLAYER_O) return -10;
            }
        }
        for (int col = 0; col < 3; col++) {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                if (board[0][col] == PLAYER_X) return +10;
                else if (board[0][col] == PLAYER_O) return -10;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == PLAYER_X) return +10;
            else if (board[0][0] == PLAYER_O) return -10;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == PLAYER_X) return +10;
            else if (board[0][2] == PLAYER_O) return -10;
        }
        return 0;
    }

    int minimax(int depth, bool isMax) {
        int score = evaluate();

        if (score == 10) return score - depth;
        if (score == -10) return score + depth;
        if (!isMovesLeft()) return 0;

        if (isMax) {
            int best = -1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == EMPTY) {
                        board[i][j] = PLAYER_X;
                        best = max(best, minimax(depth + 1, !isMax));
                        board[i][j] = EMPTY;
                    }
                }
            }
            return best;
        }
        else {
            int best = 1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == EMPTY) {
                        board[i][j] = PLAYER_O;
                        best = min(best, minimax(depth + 1, !isMax));
                        board[i][j] = EMPTY;
                    }
                }
            }
            return best;
        }
    }

    Move findBestMove() {
        int bestVal = -1000;
        Move bestMove = { -1, -1 };

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X;
                    int moveVal = minimax(0, false);
                    board[i][j] = EMPTY;

                    if (moveVal > bestVal) {
                        bestMove.row = i;
                        bestMove.col = j;
                        bestVal = moveVal;
                    }
                }
            }
        }
        return bestMove;
    }
};

int main_20() {
    TicTacToe game;
    game.printBoard();
    Move bestMove = game.findBestMove();
    cout << "The best move is: Row " << bestMove.row << ", Column " << bestMove.col << endl;
    return 0;
}