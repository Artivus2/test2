//#include <iostream>
//#include <windows.h> 
//#include <string>
//#include <stdlib.h>
//#include <time.h>
//#include <chrono>
//#include <iomanip>
//
//using namespace std;
//
//
//int board[16] = {};
//int etalon[16] = {};
//
//void swap(int* a, int* b) {
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//
//}
//
//
//void manualswap(int* z) {
//	int temp;
//	int indexCH = 0, indexO = 0;
//	for (int i = 0; i < 16; i++) {
//		if (board[i] == *z) {
//			indexCH = i;
//			break;
//		}
//	}
//
//	for (int i = 0; i < 16; i++) {
//		if (board[i] == 0) {
//			indexO = i;
//			break;
//		}
//	}
//
//	//******************* 0,4,8,12 слева, 3,7,11,15 - справа
//	bool canswap = false;
//
//	cout << board[indexCH - 4] << " " << board[indexCH + 4] << endl;
//	
//	if (indexCH == 0 || indexCH == 4 || indexCH == 8 || indexCH == 12) {
//		if (board[indexCH + 1] == 0) {
//			canswap = true;
//		}
//	}
//	if (indexCH == 15 || indexCH == 11 || indexCH == 7 || indexCH == 3) {
//		if (board[indexCH - 1] == 0) {
//			canswap = true;
//		}
//	}
//	if (indexCH > 0 && indexCH < 3 || indexCH > 4 && indexCH < 7 || indexCH > 8 && indexCH < 11 || indexCH > 12 && indexCH < 15) {
//			if (board[indexCH - 1] == 0 || board[indexCH + 1] == 0) {
//				canswap = true;
//			}
//		
//		}
//	if (indexCH >= 0 && indexCH <= 3) {
//		if (board[indexCH + 4] == 0) {
//			canswap = true;
//		}
//	}
//	if (indexCH >= 12 && indexCH <= 15) {
//		if (board[indexCH - 4] == 0) {
//			canswap = true;
//		}
//	}
//	if (indexCH >= 4 && indexCH <= 11) {
//		if (board[indexCH - 4] == 0 || board[indexCH + 4] == 0) {
//			//cout << board[indexCH-4] << " " << board[indexCH + 4] << endl;
//			canswap = true;
//		}
//	}
//
//	if (canswap == true) {
//		temp = board[indexCH];
//		board[indexCH] = board[indexO];
//		board[indexO] = temp;
//	}
//	
//
//
//	
//
//
//}
//
//
//
//int randomfill() {
//	srand(time(NULL));
//	int k = 0;
//	
//	for (int i = 0; i <= 15; i++) {
//		board[i] = i;
//		etalon[i] = i+1;
//	}
//	etalon[15] = 0;
//	while (k <= 15) {
//		swap(&board[rand() % 15], &board[rand() % 15]);
//		k += 1;
//	}
//	
//	return 0;
//}
//
//bool checkGame() {
//	
//
//	for (int i = 0; i < 16; i++) {
//		
//		if (board[i] != etalon[i]) {
//			return false;
//			
//		}
//		
//	}
//
//	return true;
//
//}
//
//
//void printTable() {
//	for (int i = 1; i <= 16; i++) {
//		if (board[i-1] <= 9) {
//			cout << board[i-1] << "  ";
//		} else cout << board[i-1] << " ";
//		if (i % 4 == 0) cout << endl;
//	}
//
//	/*for (int i = 1; i <= 16; i++) {
//		if (etalon[i - 1] <= 9) {
//			cout << etalon[i - 1] << "  ";
//		}
//		else cout << etalon[i - 1] << " ";
//		if (i % 4 == 0) cout << endl;
//	}*/
//}
//
//
//int main_ff() {
//	system("chcp 1251");
//	randomfill();
//	int x;
//	do {
//		//system("cls");
//		printTable();
//
//		cout << "Введите число: " << endl;
//		cin >> x;
//
//		manualswap(&x);
//
//	} while (checkGame() == false);
//	
//	cout << "Игра завершена";
//	
//	
//	
//	return 0;
//
//}
