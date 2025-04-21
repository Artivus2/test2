// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include <string.h>
#include "framework.h"
#include "WindowsProject1.h"
#include "commctrl.h"
#pragma comment(lib, "comctl32.lib")


#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

HWND labelX = NULL;
HWND labelY = NULL;
int xPosAbout(0), yPosAbout(0), xPos(0), yPos(0);

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ButtonProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwData);
WNDPROC OldButtonProc;

//drag&drop
bool isDragging = false; // Флаг, указывающий, что происходит перетаскивание
POINT dragOffset;       // Смещение мыши относительно верхнего левого угла кнопки



/// <summary>
/// наши функции
/// </summary>
/// <param name="hwnd"></param>
int board[16] = {};
int etalon[16] = {};
wchar_t buffer[256];


void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

int randomfill() {
	srand(time(NULL));
	int k = 0;
	
	for (int i = 0; i <= 15; i++) {
		board[i] = i;
		etalon[i] = i+1;
	}
	etalon[15] = 0;
	while (k <= 15) {
		swap(&board[rand() % 15], &board[rand() % 15]);
		k += 1;
	}
	
	return 0;
}

LPCWSTR setText(int a) {
    
    wsprintfW(buffer, L"%d", a);
    if (a == -1) {
        wsprintfW(buffer, L"-", a);
    }
    if (a==0) {
    wsprintfW(buffer, L" ", a);
    }
    return ::buffer;
    
     }

void printTable(HWND hwnd) {
    
    
    int x(0), y(0);


    for (int i = 0; i <= 15; i++) {

        if (i == 4 || i == 8 || i == 12) {
            y += 70;
            x = 0;
        }
      
        
        CreateWindowW(
            L"BUTTON",  // Предопределенный класс кнопки
            setText(board[i]), // Текст кнопки
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Стиль кнопки
            50 + x,         // Положение по X
            50 + y,         // Положение по Y
            50,        // Ширина
            50,         // Высота
            hwnd,       // Родительское окно
            NULL,   // Идентификатор кнопки
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), // Дескриптор приложения
            NULL);      // Дополнительные параметры
        x += 70;

    };
}

bool manualswap(HWND hwnd, int x) {
    	int temp;
    	int indexCH = 0, indexO = 0;
    	for (int i = 0; i < 16; i++) {
    		if (board[i] == x) {
    			indexCH = i;
    			break;
    		}
    	}
    
    	for (int i = 0; i < 16; i++) {
    		if (board[i] == 0) {
    			indexO = i;
    			break;
    		}
    	}
        //MessageBoxW(hwnd, std::to_wstring(x).c_str(), std::to_wstring(indexCH).c_str(), MB_OK);
    	//******************* 0,4,8,12 �����, 3,7,11,15 - ������
    	bool canswap = false;
    
    	
    	if (indexCH == 0 || indexCH == 4 || indexCH == 8 || indexCH == 12) {
    		if (board[indexCH + 1] == 0) {
    			canswap = true;
    		}
    	}
    	if (indexCH == 15 || indexCH == 11 || indexCH == 7 || indexCH == 3) {
    		if (board[indexCH - 1] == 0) {
    			canswap = true;
    		}
    	}
    	if (indexCH > 0 && indexCH < 3 || indexCH > 4 && indexCH < 7 || indexCH > 8 && indexCH < 11 || indexCH > 12 && indexCH < 15) {
    			if (board[indexCH - 1] == 0 || board[indexCH + 1] == 0) {
    				canswap = true;
    			}
    		
    		}
    	if (indexCH >= 0 && indexCH <= 3) {
    		if (board[indexCH + 4] == 0) {
    			canswap = true;
    		}
    	}
    	if (indexCH >= 12 && indexCH <= 15) {
    		if (board[indexCH - 4] == 0) {
    			canswap = true;
    		}
    	}
    	if (indexCH >= 4 && indexCH <= 11) {
    		if (board[indexCH - 4] == 0 || board[indexCH + 4] == 0) {
    			
    			canswap = true;
    		}
    	}
    
    	if (canswap == true) {
    		temp = board[indexCH];
    		board[indexCH] = board[indexO];
            board[indexO] = temp;
            return true;
        //SetWindowTextW(hButton, setText(board[indexO]));
        //if (hButtonNull) {
        //SetWindowTextW(hButtonNull, setText(board[indexCH]));
                    //}
    
    		
    
    	}
        return false;
    
    }


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.
    randomfill();

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, CW_USEDEFAULT, 380, 430, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//





LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //int buttonid = LOWORD(lParam);
    int x(0);
    bool result(false);
    wchar_t text[3];
    HWND hButton = (HWND)lParam;
    HWND hButtonNull;
    switch (message)
        {
        
    case WM_COMMAND:
    {
        GetWindowTextW(hButton, text, sizeof(text) / sizeof(text[0]));
        x = _wtoi(text);
        //MessageBoxW(hWnd, L"Вы нажали кнопку!", std::to_wstring(x).c_str(), MB_OK);
        result = manualswap(hWnd, x);
        if (result) {
            //SetWindowTextW(hButton, setText(-1));
            hButtonNull = FindWindowExW(hWnd, NULL, L"BUTTON", L" ");
            SetWindowTextW(hButtonNull, setText(x));
            SetWindowTextW(hButton, L" ");
            //LPCWSTR bufer0 = setText(x);
            //SetWindowTextW(hButton, bufer0);
            ////MessageBoxW(hWnd, L"Вы нажали кнопку!", bufer0, MB_OK);
            //LPCWSTR buferx = setText(x);
            //hButtonNull = FindWindowExW(hWnd, NULL, L"BUTTON", L"X");
            ////MessageBoxW(hWnd, L"Вы нажали кнопку!", buferx, MB_OK);
            //SetWindowTextW(hButtonNull, buferx);
            //bufer0 = setText(0);
            //SetWindowTextW(hButton, bufer0);
        }



        int wmId = LOWORD(wParam);
       
        switch (wmId)
        {
        case IDM_NEWGAME:
            //DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            MessageBoxW(hWnd, L"Вы нажали кнопку!", L"NEWGAME", MB_OK);
            break;
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        break;
    }
    //case WM_PAINT:
    //    {
    //        PAINTSTRUCT ps;
    //        HDC hdc = BeginPaint(hWnd, &ps);
    //        // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
    //        EndPaint(hWnd, &ps);
    //    }
    //    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_CREATE: {
        // Создание кнопки
        //LPCWSTR b = L"1";


        printTable(hWnd);



        return 0;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


//LPCWSTR ToString(long num) {
//    wchar_t snum;
//    swprintf_s(&snum, 8, L"%l", num);
//    std::wstring wnum = snum;
//    return wnum.c_str();
//}

 //Обработчик сообщений для окна "О кнопке".
LRESULT CALLBACK ButtonProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwData) 
{
    POINT cursorPos;
    //HWND labelX = GetDlgItem(HWND_TOP, IDC_X);
    //HWND labelY = GetDlgItem(HWND_TOP, IDC_Y);

    switch (uMsg)
    {
    case WM_LBUTTONUP:
        //MessageBoxW(hwnd, L"Вы нажали кнопку!", L"отжата ЛКП", MB_OK);
        if (isDragging) {
            isDragging = false;
            
            ReleaseCapture(); // Освобождаем захват мыши
        }
        //POINT cursorPos;
        //GetCursorPos(&cursorPos); // Получаем позицию курсора в экранных координатах
        //ScreenToClient(hwnd, &cursorPos); // Преобразуем координаты курсора в координаты относительно кнопки

        ////    //    // Проверяем, находится ли курсор внутри области кнопки
        //RECT buttonRect;
        //GetClientRect(hwnd, &buttonRect);
        //if (PtInRect(&buttonRect, cursorPos)) {
        //    isDragging = true;
        //    dragOffset = cursorPos; // Запоминаем смещение
        //    SetCapture(hwnd); // Захватываем мышь
        //}
        //for (int i = 0; i < 100; i++) {
        /*SetWindowPos(hwnd, HWND_TOP,
            xPosAbout - xPos,
            yPosAbout - yPos, 0, 0, SWP_NOSIZE);*/
        //Sleep(1);
        //}*/
        //ReleaseCapture();
        return 0;
    case WM_LBUTTONDOWN:
        
        //if (isDragging && xPos > 0 && xPos <100) {
        //    SetCapture(hwnd); // Захватываем мышь
        //    SetWindowPos(hwnd, HWND_TOP,
        //        xPosAbout - xPos,
        //        yPosAbout - yPos, 0, 0, SWP_NOSIZE);
         /*isDragging = false;*/
         //SetCapture(hwnd); // Захватываем мышь
        //}
        //
                    // Проверяем, нажата ли кнопка мыши над кнопкой
                    //MessageBoxW(hDlg, L"Вы нажали кнопку!", L"нажата ЛКП", MB_OK);
                    //SetWindowTextW(hwnd, L"Нажата");
                //if (hButton != NULL && (HWND)wParam == hDlg) { // Проверяем, что нажали ЛКМ
                    //    //MessageBoxW(hDlg, L"Вы нажали кнопку!", L"нажата ЛКП2222", MB_OK);
                //    POINT cursorPos;
                //    GetCursorPos(&cursorPos); // Получаем позицию курсора в экранных координатах
                //    ScreenToClient(hwnd, &cursorPos); // Преобразуем координаты курсора в координаты относительно кнопки

                //////    //    // Проверяем, находится ли курсор внутри области кнопки
                //    RECT buttonRect;
                //    GetClientRect(hwnd, &buttonRect);
                //    if (PtInRect(&buttonRect, cursorPos)) {
                //            isDragging = true;
                //            dragOffset = cursorPos; // Запоминаем смещение
                //            SetCapture(hwnd); // Захватываем мышь
                //        }
                ////    
                //return 0;        
    case WM_MOUSEMOVE: {
        isDragging = true;
        //MessageBoxW(hwnd, L"Вы нажали кнопку!", L"нажата ЛКП", MB_OK);
        xPos = LOWORD(lParam);  // Получаем X-координату
        yPos = HIWORD(lParam);  // Получаем Y-координату
        //POINT cursorPos;
        //GetCursorPos(&cursorPos); // Получаем позицию курсора в экранных координатах
        //ScreenToClient(hwnd, &cursorPos); // Преобразуем координаты курсора в координаты относительно кнопки
        //std::wstring xStr = std::to_wstring(cursorPos.x);
        //std::wstring yStr = std::to_wstring(cursorPos.y);
        //SetWindowText(labelY, yStr.c_str());
        //SetWindowText(labelX, xStr.c_str());
        //swprintf_s(&snum, 8, L"%l", num);


            if (isDragging) {
            //    
            //    GetCursorPos(&cursorPos);
            //    ScreenToClient(hwnd, &cursorPos); // Преобразуем координаты в координаты относительно окна
                SetWindowPos(hwnd, HWND_TOP,
                    xPosAbout,
                    yPosAbout, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
                // Устанавливаем новую позицию кнопки
                
            }
            //return 0;
    }
        return DefSubclassProc(hwnd, uMsg, wParam, lParam);   // Передаем сообщение дальше

    default:
        return DefSubclassProc(hwnd, uMsg, wParam, lParam);
    }
}


 //Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    //HWND hButton = (HWND)(wParam);
    HWND hButton = GetDlgItem(hDlg, IDOK);
    labelX = GetDlgItem(hDlg, IDC_X);
    labelY = GetDlgItem(hDlg, IDC_Y);
    //DWORD style = GetWindowLong(labelX, GWL_STYLE);
    SetWindowSubclass(hButton, ButtonProc, 1, 0);
    
    switch (message)
    {
    
    

    case WM_INITDIALOG:
        return (INT_PTR)TRUE;


    case WM_MOUSEMOVE: {

        
        xPosAbout = LOWORD(lParam);  // Получаем X-координату
        yPosAbout = HIWORD(lParam);  // Получаем Y-координату
        
        //std::wstring xStr = std::to_wstring(xPos);
        //std::wstring yStr = std::to_wstring(yPos);
        
        POINT cursorPos;
        GetCursorPos(&cursorPos); // Получаем позицию курсора в экранных координатах
        ScreenToClient(hDlg, &cursorPos); // Преобразуем координаты курсора в координаты относительно кнопки
        std::wstring xStr = std::to_wstring(cursorPos.x);
        std::wstring yStr = std::to_wstring(cursorPos.y);
        SetWindowText(labelY, yStr.c_str());
        SetWindowText(labelX, xStr.c_str());
        

        //MessageBoxW(hDlg, L"Вы нажали кнопку!", L"отжата1", MB_OK);

    }

    case WM_COMMAND:
        int wmId = LOWORD(wParam);

        //switch (wmId)
        //{
        //

        

        //case WM_LBUTTONUP:
        //    if (isDragging) {
        //        isDragging = false;
        //        ReleaseCapture(); // Освобождаем захват мыши
        //    }
        //    return 0;

        //}
        if (wmId == IDOK) {
            isDragging = false;
        }
        //    HWND hwndLabel = GetDlgItem(hDlg, IDC_STATIC2);
        //    DWORD style = GetWindowLong(hwndLabel, GWL_STYLE);
        //    if (style & WS_VISIBLE) {
        //        // Скрываем text
        //        ShowWindow(hwndLabel, SW_HIDE);
        //        
        //    }
        //    else {
        //        // Отображаем label
        //        ShowWindow(hwndLabel, SW_SHOW);
        //        
        //    }
        //}
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
            
    return (INT_PTR)FALSE;
}
