#include <iostream>
#include <vector>
using namespace std;

const int PLAYER_X = 1;
const int PLAYER_O = 2;
const int EMPTY = 0;
int row, col;
int board[3][3];

//#include <iostream>
//#include <windows.h> 
//#include <string>
//#include <stdlib.h>
//#include <time.h>
//#include <chrono>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//
//bool TURN(true);
//int win0(2); // 2 для 0
//int winX(1); // 1 для Х
//
////int start(int a);
//void redraw(int desk[3][3]);
//bool check_game(int desk[3][3], bool game_over);
//bool legal_player_move();
//
//int evaluate(int desk[3][3]);
//int minimax(int desk[3][3], int depth, bool isMax);
//bool isMovesLeft(int desk[3][3]);
//
//
//int main() {
//	system("chcp 1251");
//	int desk1[3][3]{};
//	bool game_over(false);
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			desk1[j][i] = 0;
//		}
//		cout << endl;
//	}
//	int x, y; // с клавиатуры
//		
//	redraw(desk1);
//	do {
//
//		if (TURN == true) {
//			cin >> x >> y;
//			if (desk1[x - 1][y - 1] == 0) {
//				desk1[x - 1][y - 1] = 1;
//				if (legal_player_move() == true) {
//					game_over = check_game(desk1, game_over);
//					cout << "gameover " << game_over << endl;
//				}
//			}
//		}
//		else {
//			game_over = check_game(desk1, game_over);
//			cout << "gameover2 " << game_over << endl;
//		}	
//		cout << "turn " << TURN << endl;
//		//system("cls");
//		redraw(desk1);
//	} while (game_over == false);
//	
//	return 0;
//
//}
//
//bool check_game(int arr[3][3], bool game_over) {
//	
//	int a(0), b(0), count(0), find(0), c(0);
//	/*int arr2[3][3] = {};
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			arr2[i][j] = arr[i][j];
//		}
//	}*/
//	cout << "gameover in check game " << game_over << ":" << TURN << endl;
//	cout << "проверка ходов";
//
//	//int result(0), temp(0);
//
//	//c = evaluate(arr);
//
//	
//	cout << "c is " << c << endl;
//	if (c != 0) return true;
//	// самый простой вариант
//	if (game_over == false) {
//		/*for (int j = 0; j < 3; j++) {
//			for (int i = 0; i < 3; i++) {
//				if (arr[j][i] == 0) {
//					arr[j][i] = 2;
//					find = 1;
//					break;
//				}
//			}
//			if (find == 1) break;
//		}*/
//		int bestVal = -1000;
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				if (arr[i][j] == 0) {
//					arr[i][j] = 2;
//					int moveVal = minimax(arr, 0, false);
//					cout << moveVal << " предрасчет: " << endl;
//					arr[i][j] = 0;
//
//					if (moveVal > bestVal) {
//						a = i;
//						b = j;
//						bestVal = moveVal;
//					}
//				}
//			}
//		}
//		cout << "a: " << a << ", b: " << b << endl;
//		arr[a][b] = 2;
//
//		TURN = true;
//	}
//
//	return false;
//};
//
//bool legal_player_move() {
//
//	if (TURN == true) {
//		TURN = false;
//		return true;
//	}
//	else {
//		TURN = true;
//		return true;
//	}
//	
//
//	return true;
//};
//
//void redraw(int arr[3][3]) {
//
//	int coordX, coordY;
//	char s('+');
//	int a = 42, b = 19;
//	int x(0), y(0);
//	
//	for (int i = 1; i <= b; i++) {
//		for (int j = 1; j <= a; j++) {
//			if (j >= 1 && j < a / 3) x = 0;
//			else if (j >= a / 3 && j < 2 * a / 3) x = 1;
//			else if (j >= 2 * a / 3 && j <= a) x = 2;
//			if (i >= 1 && i < b / 3 + 1) y = 0;
//			else if (i >= b / 3 && i < 2 * b / 3) y = 1;
//			else if (i >= 2 * b / 3 + 1 && i <= b) y = 2;
//			coordX = 4 + 6 * (y);
//			coordY = 7 + 14 * (x);
//			if (i == 1 || i == b) cout << s;
//			else if (i == coordX && j == coordY) { 
//				if (arr[x][y] == 0) cout << " ";
//				if (arr[x][y] == 1) cout << "X";
//				if (arr[x][y] == 2) cout << "O";
//				}
//			else if (i == 1 || i == b / 3 + 1) cout << s;
//			else if (i == 1 || i == 2 * b / 3 + 1) cout << s;
//			else if (j == 1 || j == a / 3) cout << s;
//			else if (j == 1 || j == 2 * a / 3) cout << s;
//			else if (j == 1 || j == a) cout << s;
//			else cout << " ";
//		}
//		cout << endl;
//	}
//	
//	
//	}
//
//int evaluate() {
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << board[j][i] << " ";
//        }
//        cout << endl;
//    }
//    for (int x = 0; x < 3; x++) {
//
//        //вертикаль
//        if (board[x][0] == 1 && board[x][1] == 1 && board[x][2] == 1) {
//            cout << "выиграл игрок вертикаль" << endl;
//            return 10;
//        }
//        if (board[x][0] == 2 && board[x][1] == 2 && board[x][2] == 2) {
//            cout << "выиграл пк вертикаль" << endl;
//            return -10;
//        }
//    }
//
//    for (int y = 0; y < 3; y++) {
//        //горизонталь
//        if (board[0][y] == 1 && board[1][y] == 1 && board[2][y] == 1) {
//            cout << "выиграл игрок горизонталь" << endl;
//            return 10;
//        }
//        if (board[0][y] == 2 && board[1][y] == 2 && board[2][y] == 2) {
//            cout << "выиграл пк горизонталь" << endl;
//            return -10;
//        }
//    }
//
//    //главная диагональ
//    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
//        cout << "выиграл игрок главная диагональ" << endl;
//        return 10;
//    }
//    if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) {
//        cout << "выиграл пк главная диагональ" << endl;
//        return -10;
//    }
//
//
//    //вторичная диагональ
//    if (board[2][0] == 1 && board[1][1] == 1 && board[0][2] == 1) {
//        cout << "выиграл игрок вторичная диагональ" << endl;
//        return 10;
//    }
//    if (board[2][0] == 2 && board[1][1] == 2 && board[0][2] == 2) {
//        cout << "выиграл пк вторичная диагональ" << endl;
//        return -10;
//    }
//
//    return 0;
//}
//
//}
//
//
//bool isMovesLeft(int desk[3][3]) {
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < 3; j++)
//			if (desk[j][i] == 0)
//				cout << "свободные ходы: " << i << "," << j << endl;
//				return true;
//	return false;
//}
//
//int minimax(int desk[3][3], int depth, bool isMax) {
//	int score = evaluate(desk);
//	cout << score << " расчет" << endl;
//	if (score == 10) return score - depth;
//	if (score == -10) return score + depth;
//	if (!isMovesLeft(desk)) return 0;
//	Sleep(500);
//	if (isMax) {
//		int best = -1000;
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				if (desk[i][j] == 0) {
//					desk[i][j] = 1; //
//					best = max(best, minimax(desk, depth + 1, !isMax));
//					cout << best << " best min " << endl;
//					desk[i][j] = 0;
//				}
//			}
//		}
//		return best;
//	}
//	else {
//		int best = 1000;
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				if (desk[i][j] == 0) {
//					desk[i][j] = 2;
//					best = min(best, minimax(desk, depth + 1, !isMax));
//					cout << best << " best max " << endl;
//					desk[i][j] = 0;
//				}
//			}
//		}
//		return best;
//	}
//}
//
//
//
//
//
//






void init() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = EMPTY;
    }

void printBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << board[j][i] << " ";
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
        //cout << "score " << score << endl;
        if (score == 10) return 10 - depth;
        if (score == -10) return depth - 10;
        /*if (score == 10) return 10;
        if (score == -10) return - 10;*/
        /*if (score == 10) return 10 + depth;
        if (score == -10) return 10 - depth;*/

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

    int findBestMove() {
        int bestVal = -1000;
        row = -1;
        col = -1;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    int moveVal = minimax(0, false);
                    board[i][j] = EMPTY;

                    if (moveVal > bestVal) {
                        row = i;
                        col = j;
                        bestVal = moveVal;
                    }
                }
            }
        }
        board[row][col] = PLAYER_O;
        cout << "bestVal" << bestVal << endl;
        return bestVal;
    }
//};

int main_xo() {
        init();
        int TURN(true);
        int x, y;
        int game_over(0);
        while (game_over == 0 && !isMovesLeft() == 0) {

            if (TURN == false) {
                findBestMove();
                TURN = true;
            }
            else {
                cin >> x >> y;
                board[x - 1][y - 1] = PLAYER_X;
                TURN = false;
            }
            

            printBoard();
            cout << endl;
            //cout << "The best move is: Row " << row + 1 << ", Column " << col + 1 << endl;
            
            
            game_over = evaluate();
            cout << "game_over: " << game_over << endl;

        }
        

        return 0;
    }