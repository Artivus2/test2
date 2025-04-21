//#include <windows.h>
//#include <iostream>
//#include <string>
//
////#define UNICODE
////#define _UNICODE
//// Глобальные переменные
//HINSTANCE hInst;
//
//wchar_t buffer[256];  
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
//LPCWSTR setText(int a){
//
//         
//      wsprintfW(buffer, L"%d", a);
//      
//      if (a==0) {
//        wsprintfW(buffer, L" ", a);
//      }
//
//
//      return buffer;
//
// }
//
//
//void manualswap(HWND hwnd, int buttonid) {
//	int temp;
//	int indexCH = 0, indexO = 0;
//  //HWND hButtonNull = FindWindowExW(hwnd, NULL, L"BUTTON", L"0");
//	for (int i = 0; i < 16; i++) {
//		if (board[i] == buttonid) {
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
//	//******************* 0,4,8,12 �����, 3,7,11,15 - ������
//	bool canswap = false;
//
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
//			
//			canswap = true;
//		}
//	}
//
//	if (canswap == true) {
//		temp = board[indexCH];
//		board[indexCH] = board[indexO];
//    //SetWindowTextW(hButton, setText(board[indexO]));
//    //if (hButtonNull) {
//    //SetWindowTextW(hButtonNull, setText(board[indexCH]));
//                //}
//
//		board[indexO] = temp;
//
//	}
//
//}
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
//
//
//void printTable(HWND hwnd) {
//  int x(0), y(0);
//  
//  
//  for (int i = 0; i <= 15; i++) {
//    
//    if (i == 4 || i == 8 || i == 12) {
//      y += 70;
//      x = 0;
//    }
//    
//    //if (x >= 240) x = 0;
//    CreateWindowW(
//                L"BUTTON",  // Предопределенный класс кнопки
//                setText(board[i]), // Текст кнопки
//                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Стиль кнопки
//                50 + x,         // Положение по X
//                50 + y,         // Положение по Y
//                50,        // Ширина
//                50,         // Высота
//                hwnd,       // Родительское окно
//                NULL,   // Идентификатор кнопки
//                (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), // Дескриптор приложения
//                NULL);      // Дополнительные параметры
//    x+=70;
//    
//    };
//	}
//  
//  
//// Прототипы функций
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
//// Точка входа в приложение
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nShowCmd) {
//    hInst = hInstance;
//    randomfill();
//    // Регистрация класса окна
//    const char CLASS_NAME[] = "SampleWindowClass";
//
//    WNDCLASS wc = {};
//    wc.lpfnWndProc = WindowProc;
//    wc.hInstance = hInstance;
//    //wc.lpszClassName("SampleWindowClass");
//
//    RegisterClass(&wc);
//
//    // Создание окна
//    HWND hwnd = CreateWindowW(
//        L"SampleWindowClass",                    // Имя класса
//        L"Пятнашки 4Х4",          // Заголовок окна
//        WS_OVERLAPPEDWINDOW,           // Стиль окна
//        CW_USEDEFAULT, CW_USEDEFAULT,   // Положение
//        380, 380,                      // Размер
//        NULL,                          // Родительское окно
//        NULL,                          // Меню
//        hInstance,                    // Дескриптор приложения
//        NULL                           // Дополнительные параметры
//    );
//
//
//    if (hwnd == NULL) {
//        return 0;
//    }
//
//    ShowWindow(hwnd, nShowCmd);
//    
//
//    // Основной цикл сообщений
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0) && checkGame() == false) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//    return 0;
//}
//
//// Обработчик сообщений окна
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    
//    int buttonid = LOWORD(lParam);
//    HWND hButton = (HWND)lParam;
//    int x;
//    wchar_t text[3];
//    switch (uMsg) {
//        case WM_DESTROY:
//            PostQuitMessage(0);
//            return 0;
//
//        case WM_COMMAND:
//            //MessageBoxW(hwnd, L"Вы нажали кнопку!", std::to_wstring(buttonid).c_str(), MB_OK);
//            
//            GetWindowTextW(hButton, text, sizeof(text)/ sizeof (text[0]));
//            
//            if (text[0]) {
//              x = 0;
//              
//            } else {
//              
//              int x = _wtoi(text);
//              manualswap(hwnd, x);
//            }
//
//            MessageBoxW(hwnd, L"Вы нажали кнопку!",  std::to_wstring(x).c_str(), MB_OK);
//            
//            // if (buttonid >= 1000 && buttonid <= 1015) { // Если нажата кнопка
//                
//            //     HWND hButton = FindWindowExW(hwnd, NULL, L"BUTTON", buffer);
//                
//            //     //перемещение в цикле анимация
//            //     //SetWindowPos(hButton, NULL, 300,300,100,100, SWP_NOZORDER);
//            
//                
//                
//
//                
//
//            //   }
//            return 0;
//        
//
//        case WM_CREATE: {
//            // Создание кнопки
//            //LPCWSTR b = L"1";
//            
//            
//            printTable(hwnd);
//            
//            
//            
//            return 0;
//        }
//        
//    }
//    return DefWindowProc(hwnd, uMsg, wParam, lParam);
//}
