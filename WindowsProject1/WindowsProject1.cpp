﻿// WindowsProject1.cpp : Определяет точку входа для приложения.
//https://github.com/Artivus2/test2

#include <string.h>
#include "framework.h"
#include "WindowsProject1.h"
#include "commctrl.h"
//#include "Student.h"
#include "drob.h"
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "Ws2_32.lib")

using namespace std;

//todo
class SocketClient {

};

class SocketServer {

};

class Fifteens {

};

class PingPong {

};





#define MAX_LOADSTRING 100




// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

HWND labelX = NULL;
HWND labelY = NULL;
HWND labelMainX{ NULL };
HWND labelMainY{ NULL };
HWND labelPX{ NULL };
HWND labelPY{ NULL };
//HWND buttons[16];
vector<HWND> buttons;
int xPosAbout{ 0 }, yPosAbout{ 0 }, xPos{ 0 }, yPos{ 0 };

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Pingpong(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Drobi(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ButtonProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwData);
LRESULT CALLBACK    ButtonProcLeft(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwData);
LRESULT CALLBACK    ButtonProcRight(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwData);
LRESULT CALLBACK    ButtonAll(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwData);


//drag&drop
bool isDragging{ false }; // Флаг, указывающий, что происходит перетаскивание
POINT dragOffset;       // Смещение мыши относительно верхнего левого угла кнопки


//int ServerBoard[16];
struct BoardData {
    int board[16] = {};
    //bool Enable = true;
};

bool isPingpong(false);
bool is15(false);
// bool isSeaBattle(false); todo

//структура данных для передачи по winsocket pingpong
struct PingPongData {
    int x1, x2; //координаты доски игрока А и Б по горизонали
    int y1, y2; //по вертикали
    int circleX = 500;         // X-координата центра круга
    int circleY = 200;         // Y-координата центра круга
    int circleRadius = 20;      // Радиус круга
    //double angle = 0.0;         // Угол для кругового движения
    int speedX = 4;             // Скорость движения (угловая)
    int speedY = 4;
    int centerX, centerY;      // Центр, относительно которого движется круг
    int scoreA, scoreB; //счет игры
    bool startingBall = false;
    bool turnx1 = false;
    bool turnx2 = true;
    //todo положение сетки
};

PingPongData pingServer;
PingPongData pingClient;

BoardData boardOnServer; //на сервере
BoardData dataToReceive; //на клиент
int etalon[16] = {};
wchar_t buffer[256];
int sendX(-1);

const int SERVER_PORT = 27000;
const char* SERVER_ADDRESS = "192.168.0.201"; // Localhost
const int BUFFER_SIZE = 512;
bool serverStarted(false);
//bool isServer(false);
//bool* px = &isServer;

SOCKET listenSocket, clientSocket, clientSocket1; //clientsocket1 это клиент

bool startServer(HWND hWnd);
bool listenServer(HWND hWnd);
bool listenClient(HWND hWnd);
bool startClient(HWND hWnd);
bool runBall(HWND hDlg, WPARAM wParam, LPARAM lParam);
int iResult, iResult1;


LPCWSTR setText(int a) {

    wsprintfW(buffer, L"%d", a);
    if (a == -1) {
        wsprintfW(buffer, L"-", a);
    }
    if (a == 0) {
        wsprintfW(buffer, L" ", a);
    }
    return ::buffer;

}





void HandleWinsockError(const char* operation, HWND hwnd) {
    DWORD error = WSAGetLastError();
    if (error != 0) {
        size_t operationLength = strlen(operation);
        std::wstring wOperation(operationLength, L' ');
        //mbstowcs(&wOperation[0], operation, operationLength);
        //MessageBoxW(hwnd, wsprintfW(buffer, L"%d", operation), L"Ошибка", MB_OK);
        //MessageBoxW(hwnd, setText((int)operationLength), L"Server", MB_OK);
        //std::cerr << "Winsock error during " << operation << ": " << error << std::endl;
        
        // Optionally, format the error message using FormatMessage
    }
}



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
        boardOnServer.board[i] = i;
		etalon[i] = i+1;
	}
	etalon[15] = 0;
	while (k <= 15) {
		swap(&boardOnServer.board[rand() % 15], &boardOnServer.board[rand() % 15]);
		k += 1;
	}
    dataToReceive = boardOnServer;
    
	
	return 0;
}



void printTable(HWND hwnd) {
    
    labelMainX = CreateWindowExW(
        0, L"STATIC", L"X",
        WS_CHILD | WS_VISIBLE | SS_LEFT, // Стили окна
        10, 10, 30, 25,             // Позиция и размеры
        hwnd, NULL, NULL, NULL
    );
    labelMainY = CreateWindowExW(
        0, L"STATIC", L"Y",
        WS_CHILD | WS_VISIBLE | SS_LEFT, // Стили окна
        10, 35, 300, 25,             // Позиция и размеры
        hwnd, (HMENU)IDC_MYLABEL_Y, NULL, NULL
    );
    
    int x(0), y(0);
    
    buttons.resize(16);


    for (int i = 0; i <= 15; i++) {

        if (i == 4 || i == 8 || i == 12) {
            y += 70;
            x = 0;
        }
      
        
        buttons[i] = CreateWindowW(
            L"BUTTON",  // Предопределенный класс кнопки
            setText(boardOnServer.board[i]), // Текст кнопки
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Стиль кнопки
            50 + x,         // Положение по X
            80 + y,         // Положение по Y
            50,        // Ширина
            50,         // Высота
            hwnd,       // Родительское окно
            (HMENU)2000+i,   // Идентификатор кнопки
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), // Дескриптор приложения
            NULL);      // Дополнительные параметры
        x += 70;
        SetWindowSubclass(buttons[i], ButtonAll, 1, 0);
    };
}

bool manualswap(HWND hwnd, int x) {
    	int temp;
    	int indexCH = 0, indexO = 0;
    	for (int i = 0; i < 16; i++) {
    		if (boardOnServer.board[i] == x) {
    			indexCH = i;
    			break;
    		}
    	}
    
    	for (int i = 0; i < 16; i++) {
    		if (boardOnServer.board[i] == 0) {
    			indexO = i;
    			break;
    		}
    	}
        //MessageBoxW(hwnd, std::to_wstring(x).c_str(), std::to_wstring(indexCH).c_str(), MB_OK);
    	//******************* 0,4,8,12 �����, 3,7,11,15 - ������
    	bool canswap = false;
    
    	
    	if (indexCH == 0 || indexCH == 4 || indexCH == 8 || indexCH == 12) {
    		if (boardOnServer.board[indexCH + 1] == 0) {
    			canswap = true;
    		}
    	}
    	if (indexCH == 15 || indexCH == 11 || indexCH == 7 || indexCH == 3) {
    		if (boardOnServer.board[indexCH - 1] == 0) {
    			canswap = true;
    		}
    	}
    	if (indexCH > 0 && indexCH < 3 || indexCH > 4 && indexCH < 7 || indexCH > 8 && indexCH < 11 || indexCH > 12 && indexCH < 15) {
    			if (boardOnServer.board[indexCH - 1] == 0 || boardOnServer.board[indexCH + 1] == 0) {
    				canswap = true;
    			}
    		
    		}
    	if (indexCH >= 0 && indexCH <= 3) {
    		if (boardOnServer.board[indexCH + 4] == 0) {
    			canswap = true;
    		}
    	}
    	if (indexCH >= 12 && indexCH <= 15) {
    		if (boardOnServer.board[indexCH - 4] == 0) {
    			canswap = true;
    		}
    	}
    	if (indexCH >= 4 && indexCH <= 11) {
    		if (boardOnServer.board[indexCH - 4] == 0 || boardOnServer.board[indexCH + 4] == 0) {
    			
    			canswap = true;
    		}
    	}
    
    	if (canswap == true) {
    		temp = boardOnServer.board[indexCH];
            boardOnServer.board[indexCH] = boardOnServer.board[indexO];
            boardOnServer.board[indexO] = temp;
            dataToReceive = boardOnServer;
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

    

    ////Student std1{ "петров", 3, new int[3] {3,4,5} };
    ////Student std2{ "иавнов", 3, new int[3] {4,4,6} };
    //Student std1;
    ////strcpy_s(std1.name, 20, );
    //std1.setName("Петров В.В.");
    //std1.marks[0] = 10;
    //std1.marks[1] = 10;
    //std1.marks[2] = 9;
    //double aver = std1.getAver();
    //Student std2("Иванов В.В.");
    ////std2.setName("Иванов В.В.");
    //std2.marks[0] = 9;
    //std2.marks[1] = 7;
    //std2.marks[2] = 9;
    //aver = std2.getAver();

    //
    //
    ////// выполнение метода об
    //std1.getAver();
    //std2.getAver();

    
    //std1.Print(aver);


    /*Point p1;
    p1.max1;
    Point p2;
    p2.max1;*/

    /*Student* students = new Student[2]
    {
        {"Студент 1", 3, new int[3] { 10, 10, 9 }},
        {"Студент 2", 3, new int[3] { 8, 10, 8 }}
    };*/

    //delete std1;
    //delete[] students;
    //LittleStudent littl1;
    string stroka1;
    
    
    

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
            if (serverStarted) {
                listenServer(msg.hwnd);
                
            }
            listenClient(msg.hwnd);
            //std2.labelInline = labelMainX;
            //std2.getName();
            
            
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
       CW_USEDEFAULT, CW_USEDEFAULT, 380, 480, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

bool listenClient(HWND hWnd) {
    
    int iResultOtServer = recv(clientSocket1, (char*)&boardOnServer, sizeof(BoardData), 0);
    /*if (!serverStarted) {
        MessageBoxW(hWnd, setText(buffer[0]), L"client", MB_OK);
    }*/
    
    
    /*for (int i = 0; i <= 16; i++) {
        HWND hwndButtonById = GetDlgItem(hWnd, 2000 + i * 4);
        SetWindowText(hwndButtonById, setText(boardOnServer.board[i]));

    }*/
    if (iResultOtServer > 0) {
        SetWindowTextW(labelMainY, setText(boardOnServer.board[1]));
        
        /*for (int i = 0; i < 16; i++) {
            HWND hwndButtonById = GetDlgItem(hWnd, 2000 + i * 4);
            SetWindowText(hwndButtonById, setText(boardOnServer.board[i]));

        }*/

    }
    else if (iResultOtServer == 0) {
        // Соединение закрыто клиентом
        SetWindowTextA(labelMainY, "result0");
        //std::cout << "Соединение с клиентом закрыто" << std::endl;
        
    }
    else {
        if (WSAGetLastError() != WSAEWOULDBLOCK) {
            HandleWinsockError("recv", hWnd);
            SetWindowTextA(labelMainY, "ошибка сокета");
            //closesocket(currentClientSocket);
        }
        SetWindowTextW(labelMainY, setText(iResultOtServer));
    }

        
    Sleep(10);
    //SetWindowTextA(labelMainY, "клиент активен");
    //MessageBoxW(hWnd, L"цикл клиента", L"client", MB_OK);

    
    return true;
}

bool listenServer(HWND hWnd) {

    

    
    std::vector<SOCKET> clientSockets; // Keep track of connected clients.
    u_long iMode = 1;
    //while (true) {
        // Принять входящее соединение (неблокирующее)
        sockaddr_in clientAddress;
        int clientAddressLength = sizeof(clientAddress);
        clientSocket = accept(listenSocket, (sockaddr*)&clientAddress, &clientAddressLength);

        if (clientSocket != INVALID_SOCKET) {
            //std::cout << "Принято новое соединение" << std::endl;
            //MessageBoxW(hWnd, L"Принято новое соединение", L"server!", MB_OK);
            clientSockets.push_back(clientSocket);
            //MessageBoxW(hWnd, L"ПРИНЯТ клиент", L"server", MB_OK);

            // Set new client socket to non-blocking mode as well
            iResult = ioctlsocket(clientSocket, FIONBIO, &iMode);
            if (iResult == SOCKET_ERROR) {
                
                HandleWinsockError("ioctlsocket to set non-blocking mode for client", hWnd);
                //closesocket(clientSocket);
                // Consider removing the client socket from the vector here if needed.
            }
        }
        else {
            if (WSAGetLastError() != WSAEWOULDBLOCK) {
                
                HandleWinsockError("accept (non-blocking)", hWnd); // Log the error, but don't exit.
            }
        }

        // Обработка данных от клиентов (неблокирующая)
        
        
        for (auto it = clientSockets.begin(); it != clientSockets.end(); ) {
            SOCKET currentClientSocket = *it;
            //char buffer[BUFFER_SIZE];
            //iResult = recv(currentClientSocket, buffer, BUFFER_SIZE - 1, 0);
            iResult = recv(currentClientSocket, (char*)&dataToReceive, sizeof(BoardData), 0);
            
            if (iResult > 0) {
                dataToReceive = boardOnServer;
                //MessageBoxW(hWnd, setText(boardOnServer.board[0]), L"server", MB_OK);
                SetWindowTextW(labelMainY, setText(boardOnServer.board[0]));
                //buffer[iResult] = '\0'; // Null-terminate the received data
                //std::cout << "Получено от клиента: " << buffer << std::endl;
                // todo board[16] >> buffer;
                
                
                // Отправляем данные обратно клиенту (эхо-сервер)

               
                if (is15) {
                    // перерисовал сервер
                    
                    dataToReceive = boardOnServer;
                    int iResult2 = send(currentClientSocket, (char*)&boardOnServer, sizeof(BoardData), 0);
                    
                    if (iResult2 > 0) {
                        //MessageBoxW(hWnd, setText(boardOnServer.board[1]), L"server", MB_OK);
                    }
                    
                    /*for (int i = 0; i <= 16; i++) {
                        HWND hwndButtonById = GetDlgItem(hWnd, 2000 + i * 4);
                        SetWindowText(hwndButtonById, setText(boardOnServer.board[i]));

                    }*/
                }
                else if (isPingpong) {
                    iResult = send(currentClientSocket, (char*)&pingServer, sizeof(PingPongData), 0);
                    pingServer.startingBall = true;
                }
                //MessageBoxW(hWnd, L"Старт игры", L"Уведомление", MB_OK);
                
                

                //todo обрабабывем сообщения от клиента

                if (iResult == SOCKET_ERROR) {
                    HandleWinsockError("send", hWnd);
                }
            }
            else if (iResult == 0) {
                // Соединение закрыто клиентом
                SetWindowTextA(labelMainY, "result0");
                //std::cout << "Соединение с клиентом закрыто" << std::endl;
                //closesocket(currentClientSocket);
                //it = clientSockets.erase(it); // Удаляем сокет из вектора
                //continue; // Skip to the next client.
            }
            else {
                if (WSAGetLastError() != WSAEWOULDBLOCK) {
                    HandleWinsockError("recv", hWnd);
                    //closesocket(currentClientSocket);
                    //it = clientSockets.erase(it);
                    //continue;
                }
                SetWindowTextA(labelMainY, "erroorrrrr");
            }
            ++it; // Advance the iterator only if the socket wasn't erased.
        }

        // Небольшая задержка (для уменьшения нагрузки на процессор)
        Sleep(10);
        //MessageBoxW(hWnd, L"Слушает", L"server", MB_OK);
        SetWindowTextA(labelMainY, "сервер слушает");
        return 0;
}

bool startServer(HWND hWnd) {
    
    
        WSADATA wsaData;
        
        
        // Инициализация Winsock
        iResult = WSAStartup(MAKEWORD(2, 2), &wsaData); //серверный 
        if (iResult != 0) {
            //std::cerr << "WSAStartup failed: " << iResult << std::endl;
            MessageBoxW(hWnd, L"WSAStartup failed", L"server!", MB_OK);
            return 1;
        }


        listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (listenSocket == INVALID_SOCKET) {
            HandleWinsockError("socket creation", hWnd);
            WSACleanup();
            return 1;
        }
        // Настройка адреса сервера
        sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(SERVER_PORT);
        inet_pton(AF_INET, SERVER_ADDRESS, &(serverAddress.sin_addr));

        iResult = bind(listenSocket, (sockaddr*)&serverAddress, sizeof(serverAddress));
        if (iResult == SOCKET_ERROR) {
            HandleWinsockError("bind", hWnd);
            closesocket(listenSocket);
            WSACleanup();
            return 1;
        }

        // Перевод сокета в режим прослушивания
        iResult = listen(listenSocket, SOMAXCONN); //SOMAXCONN - максимально возможное число подключений
        if (iResult == SOCKET_ERROR) {
            HandleWinsockError("listen", hWnd);
            closesocket(listenSocket);
            WSACleanup();
            return 1;
        }

        

        u_long iMode = 1; // 1 = non-blocking
        iResult = ioctlsocket(listenSocket, FIONBIO, &iMode);
        if (iResult == SOCKET_ERROR) {
            HandleWinsockError("ioctlsocket to set non-blocking mode", hWnd);
            closesocket(listenSocket);
            WSACleanup();
            return 1;
        }


        //MessageBoxW(hWnd, L"Socket готов к приему подключений", L"server!", MB_OK);
        //listenServer(hWnd, listenSocket, iResult);
        // Завершение работы Winsock
        /*closesocket(listenSocket);
        WSACleanup();*/
        serverStarted = true;
        //isServer = true;

        return 0;
    

}

bool sendMessageToClient(HWND hWnd) {
    iResult1 = send(clientSocket, (char*)&boardOnServer, sizeof(BoardData), 0);
    
    
    if (is15) {
        //MessageBoxW(hWnd, setText(sizeof(BoardData)), L"server", MB_OK);
        //MessageBoxW(hWnd, setText(sizeof(iResult)), L"client", MB_OK);
        iResult = recv(clientSocket, (char*)&boardOnServer, sizeof(BoardData), 0);
        for (int i = 0; i <= 16; i++) {
            HWND hwndButtonById = GetDlgItem(hWnd, 2000 + i * 4);
            SetWindowText(hwndButtonById, setText(boardOnServer.board[i]));

        }

    }
    return true;
}

bool sendMessageToServer(HWND hWnd) {
    
    int iResultToServer;
    if (is15) {
        //MessageBoxW(hWnd, setText(sizeof(dataToReceive)), L"client", MB_OK);
        iResultToServer = send(clientSocket1, (char*)&boardOnServer, sizeof(BoardData), 0);
    }
    else if (isPingpong) {
        //MessageBoxW(hWnd, setText(sizeof(dataToReceive)), L"ping", MB_OK);
        iResultToServer = send(clientSocket1, (char*)&pingServer, sizeof(PingPongData), 0);
    }
    
    if (iResultToServer == SOCKET_ERROR) {
        HandleWinsockError("send", hWnd);
        SetWindowTextA(labelMainY, "erroorrrrr-client");
        return 1;
    }
    
    //char buffer[BUFFER_SIZE];

    /*if (is15) {
        MessageBoxW(hWnd, setText(sizeof(iResult)), L"client", MB_OK);
        iResult = recv(clientSocket, (char*)&boardOnServer, sizeof(BoardData), 0);

        for (int i = 0; i <= 16; i++) {
            HWND hwndButtonById = GetDlgItem(hWnd, 2000 + i * 4);
            SetWindowText(hwndButtonById, setText(dataToReceive.board[i]));

        }
    }
    else if (isPingpong) {
        iResult = recv(clientSocket, (char*)&pingClient, sizeof(PingPongData), 0);
    }*/

    //if (iResult > 0) {
    //    //buffer[iResult] = '\0';
    //    if (is15) {
    //        //for (int i = 0; i < 16; i++) {
    //        //boardOnServer = dataToReceive;
    //        //MessageBoxW(hWnd, setText(sizeof(dataToReceive)), L"client_ответ", MB_OK);

    //        //}
    //        SetWindowTextA(labelMainY, "получил данные");
    //    }
    //    else if (isPingpong) {
    //        pingServer = pingClient;
    //    }
    //}
    /*closesocket(listenSocket);
    WSACleanup();*/
    return true;
}


bool startClient(HWND hWnd) {
    //DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            //MessageBoxW(hWnd, L"Вы нажали кнопку!", L"NEWGAME", MB_OK);
            //клиент
    WSADATA wsaData;
    
    //int iResult1;
    
    

    // Инициализация Winsock
    iResult1 = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult1 != 0) {
        //std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    // Создание сокета клиента
    clientSocket1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket1 == INVALID_SOCKET) {
        HandleWinsockError("socket creation", hWnd);
        WSACleanup();
        return 1;
    }

    // Настройка адреса сервера
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &(serverAddress.sin_addr));

    // Подключение к серверу
    iResult1 = connect(clientSocket1, (sockaddr*)&serverAddress, sizeof(serverAddress));
    //
    if (iResult1 == SOCKET_ERROR) {
        HandleWinsockError("connect", hWnd);
        
        closesocket(clientSocket1);
        WSACleanup();
        return 1;
    }
    MessageBoxW(hWnd, L"Ошибок нет", L"client", MB_OK);
    //MessageBoxW(hWnd, setText(sizeof(dataToReceive)), L"client", MB_OK);
    //подключились 
    //SetWindowTextA(labelMainY, "Подключились");
    //char* prt =  (LPCWSTR)sendX;
    //

    //iResult1 = send(clientSocket1, (char*)&dataToReceive, sizeof(BoardData), 0);
    sendMessageToServer(hWnd);
    if (iResult1 == SOCKET_ERROR) {
        HandleWinsockError("send", hWnd);
        return 1;
    }

    //closesocket(clientSocket1);
    //WSACleanup();
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //int buttonid = LOWORD(lParam);
    int x(0), x1(0);
    bool result(false);
    wchar_t text[3];
    wchar_t textXY[3];
    HWND hButton = (HWND)lParam;
    HWND hButtonNull;
    int buttonId = LOWORD(wParam);
    
    
    switch (message)
        {
        
    case WM_MOUSEMOVE: {
        //startServer(hWnd);
    }
    case WM_COMMAND:
    {


        GetWindowTextW(hButton, text, sizeof(text) / sizeof(text[0]));
        x = _wtoi(text);
        //SetWindowText(labelMainY, setText(buttonId));
        //MessageBoxW(hWnd, L"Вы нажали кнопку!", std::to_wstring(x).c_str(), MB_OK);
        result = manualswap(hWnd, x); //boardonserver обновилась
        sendX = x;
        if (result) {
            

            
            //SetWindowTextW(hButton, setText(-1));
            hButtonNull = FindWindowExW(hWnd, NULL, L"BUTTON", L" ");
            SetWindowTextW(hButtonNull, setText(x));
            SetWindowTextW(hButton, L" ");
            POINT cursorPos;
            GetCursorPos(&cursorPos); // Получаем позицию курсора в экранных координатах
            ScreenToClient(hButton, &cursorPos); // Преобразуем координаты курсора в координаты относительно кнопки
            
            /*for (int i = 0; i <= 15; i++) {
                HWND hwndButtonById = GetDlgItem(hWnd, 2000 + i * 4);
                SetWindowText(hwndButtonById, setText(boardOnServer.board[i]));

            }*/
            //iResult1 = send(clientSocket1, (char*)&boardOnServer, sizeof(BoardData), 0);
            
            is15 = true;
            sendMessageToServer(hWnd);
            /*for (int i = 0; i <= 15; i++) {
                HWND hwndButtonById = GetDlgItem(hWnd, 2000 + i * 4);
                SetWindowText(hwndButtonById, setText(boardOnServer.board[i]));

            }*/
            
            

             

            

        }
        //*px = false;
        //todo выявить клиент или сервер


        int wmId = LOWORD(wParam);

        switch (wmId)
        {
        case IDM_PINGPONG: {
            DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Pingpong);
            break;
        }


        case IDM_DROBI: {
            DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Drobi);
            break;
        }

        case IDM_NEWGAME: {
            startServer(hWnd);
            is15 = true;
            /*char str[20];
            itoa(65, str, 8);*/
            

        }
                        break;

        case IDM_CONGAME: {
            
            is15 = true;
            startClient(hWnd);
            //sendMessageToServer(hWnd);
            
            /*if (is15) {
                for (int i = 0; i <= 16; i++) {
                    HWND hwndButtonById = GetDlgItem(hWnd, 2000 + i * 4);
                    SetWindowText(hwndButtonById, setText(boardOnServer.board[i]));
                }
            }*/
            

        }
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
    }
        break;
    

    case WM_DESTROY:
            PostQuitMessage(0);
            break;

    case WM_CREATE: {

            printTable(hWnd);
            //MessageBoxW(hWnd, setText(sizeof(boardOnServer)), L"server", MB_OK);
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

LRESULT CALLBACK ButtonAll(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwData)
{
    POINT cursorPos;
    xPos = LOWORD(lParam);  // Получаем X-координату
    yPos = HIWORD(lParam);  // Получаем Y-координату
    int buttonId = GetDlgCtrlID(hwnd);
    
    switch (uMsg)
    {
        case WM_MOUSEMOVE: {
            
            POINT cursorPos = { xPos, yPos };
            std::wstring xStr = std::to_wstring(xPos);
            std::wstring yStr = std::to_wstring(yPos);
            //SetWindowText(labelMainX, setText(xPos));
            //SetWindowText(labelMainY, setText(yPos));
            HWND hwndUnderMouse = ChildWindowFromPointEx(hwnd, cursorPos, CWP_ALL);
            //SetWindowText(labelMainX, setText(buttonId));
            //SetWindowText(labelMainY, setText(buttonId));


        }
        return DefSubclassProc(hwnd, uMsg, wParam, lParam);   // Передаем сообщение дальше

    default:
        return DefSubclassProc(hwnd, uMsg, wParam, lParam);
    }
}
LRESULT CALLBACK ButtonProcLeft(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwData)
{
    HWND hwndParentOfButton = GetParent(hwnd);
    
    switch (uMsg) {
    case WM_LBUTTONDOWN:
        //MessageBoxW(hwnd, L"LEFT", L"server", MB_OK);
        // Проверяем, нажата ли кнопка мыши над кнопкой
        if (hwnd != NULL) {
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            ScreenToClient(hwnd, &cursorPos); // Преобразуем в координаты относительно кнопки

            // Проверяем, находится ли курсор внутри области кнопки
            RECT buttonRect;
            GetClientRect(hwnd, &buttonRect);
            if (PtInRect(&buttonRect, cursorPos)) {
                isDragging = true;
                dragOffset = cursorPos; // Запоминаем смещение
                SetCapture(hwnd); // Захватываем мышь
            }
        }
        return 0;

    case WM_MOUSEMOVE:
        if (isDragging) {
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            ScreenToClient(hwndParentOfButton, &cursorPos); // Преобразуем в координаты относительно родительского окна

            // Устанавливаем новую позицию кнопки
            SetWindowPos(hwnd, NULL,
                cursorPos.x - dragOffset.x,
                cursorPos.y - dragOffset.y,
                0, 0, SWP_NOSIZE | SWP_NOZORDER);
            pingServer.x1 = cursorPos.x - dragOffset.x + 20;
            pingServer.y1 = cursorPos.y - dragOffset.y; // 20x80
        }
        return 0;

    case WM_LBUTTONUP:
        if (isDragging) {
            isDragging = false;
            ReleaseCapture(); // Освобождаем захват мыши
        }
        return 0;
        return DefSubclassProc(hwnd, uMsg, wParam, lParam);   // Передаем сообщение дальше

    default:
        return DefSubclassProc(hwnd, uMsg, wParam, lParam);
    }
}

LRESULT CALLBACK ButtonProcRight(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwData)
{
    HWND hwndParentOfButton = GetParent(hwnd);
    switch (uMsg) {
        
    case WM_LBUTTONDOWN:
        //MessageBoxW(hwnd, L"RIGHT", L"server", MB_OK);
        // Проверяем, нажата ли кнопка мыши над кнопкой
        if (hwnd != NULL) {
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            ScreenToClient(hwnd, &cursorPos); // Преобразуем в координаты относительно кнопки

            // Проверяем, находится ли курсор внутри области кнопки
            RECT buttonRect;
            GetClientRect(hwnd, &buttonRect);
            if (PtInRect(&buttonRect, cursorPos)) {
                isDragging = true;
                dragOffset = cursorPos; // Запоминаем смещение
                SetCapture(hwnd); // Захватываем мышь
            }
        }
        return 0;

    case WM_MOUSEMOVE:
        if (isDragging) {
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            ScreenToClient(hwndParentOfButton, &cursorPos); // Преобразуем в координаты относительно родительского окна

            // Устанавливаем новую позицию кнопки
            SetWindowPos(hwnd, NULL,
                cursorPos.x - dragOffset.x,
                cursorPos.y - dragOffset.y,
                0, 0, SWP_NOSIZE | SWP_NOZORDER);
            pingServer.x2 = cursorPos.x - dragOffset.x;
            pingServer.y2 = cursorPos.y - dragOffset.y; // 20x80
        }
        return 0;

    case WM_LBUTTONUP:
        if (isDragging) {
            isDragging = false;
            ReleaseCapture(); // Освобождаем захват мыши
        }
        return 0;
        return DefSubclassProc(hwnd, uMsg, wParam, lParam);   // Передаем сообщение дальше

    default:
        return DefSubclassProc(hwnd, uMsg, wParam, lParam);
    }
}




 //Обработчик сообщений для окна "О кнопке".
LRESULT CALLBACK ButtonProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwData) 
{
    HWND hwndParentOfButton = GetParent(hwnd);
    switch(uMsg) {
        case WM_LBUTTONDOWN:
        
        // Проверяем, нажата ли кнопка мыши над кнопкой
        if (hwnd != NULL) {
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            ScreenToClient(hwnd, &cursorPos); // Преобразуем в координаты относительно кнопки

            // Проверяем, находится ли курсор внутри области кнопки
            RECT buttonRect;
            GetClientRect(hwnd, &buttonRect);
            if (PtInRect(&buttonRect, cursorPos)) {
                isDragging = true;
                dragOffset = cursorPos; // Запоминаем смещение
                SetCapture(hwnd); // Захватываем мышь
            }
        }
        return 0;

    case WM_MOUSEMOVE:
        
        if (isDragging) {
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            ScreenToClient(hwndParentOfButton, &cursorPos); // Преобразуем в координаты относительно родительского окна

            // Устанавливаем новую позицию кнопки
            SetWindowPos(hwnd, NULL,
                cursorPos.x - dragOffset.x,
                cursorPos.y - dragOffset.y,
                0, 0, SWP_NOSIZE | SWP_NOZORDER);
        }
        return 0;

    case WM_LBUTTONUP:
        if (isDragging) {
            isDragging = false;
            ReleaseCapture(); // Освобождаем захват мыши
        }
        return 0;
        return DefSubclassProc(hwnd, uMsg, wParam, lParam);   // Передаем сообщение дальше

    default:
        return DefSubclassProc(hwnd, uMsg, wParam, lParam);
    }
}


//функция движение мяча по экрану
bool runBall(HWND hDlg, WPARAM wParam, LPARAM lParam) {
    if (pingServer.startingBall) 
    { 
        SetTimer(hDlg, 1000, 20, NULL);
        isPingpong = true;
        is15 = false;
        return true; 
    }
    else {
        KillTimer(hDlg, 1000);
        return false;
    }
    
}


//Обработчик сообщений для окна "О pingpong".
INT_PTR CALLBACK Pingpong(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    HWND ButtonLeft = GetDlgItem(hDlg, IDLEFT);
    SetWindowSubclass(ButtonLeft, ButtonProcLeft, 1, 0);
    HWND ButtonRight = GetDlgItem(hDlg, IDRIGHT);
    SetWindowSubclass(ButtonRight, ButtonProcRight, 1, 0);
    switch (message)
    {
    
    case WM_INITDIALOG:
        RECT rect;
        GetClientRect(hDlg, &rect);
        pingServer.centerX = (rect.right - rect.left) / 2;
        pingServer.centerY = (rect.bottom - rect.top) / 2;
        
        //return TRUE;
        return (INT_PTR)TRUE;

    case WM_TIMER: {
        // Обновление координат круга
        
        pingServer.circleX += pingServer.speedX; 
        pingServer.circleY += pingServer.speedY;

        // Получение размеров окна
        RECT rect;
        GetClientRect(hDlg, &rect);

        // Проверка границ (отражение от стенок)
        //if (pingServer.circleX - pingServer.circleRadius < 0) {
        //    //pingServer.circleX = pingServer.circleRadius;
        //    pingServer.speedX = -pingServer.speedX;
        //}

        if (pingServer.circleX + pingServer.circleRadius > rect.right) {
            //pingServer.circleX = rect.right - pingServer.circleRadius;
            pingServer.speedX = -pingServer.speedX;
        }

        if (pingServer.circleX - pingServer.circleRadius < rect.left) {
            //pingServer.circleX = rect.right - pingServer.circleRadius;
            pingServer.speedX = -pingServer.speedX;
        }

        //if (pingServer.circleY - pingServer.circleRadius < 0) {
        //    //pingServer.circleY = pingServer.circleRadius;
        //    pingServer.speedY = -pingServer.speedY;
        //}

        if (pingServer.circleY + pingServer.circleRadius > rect.bottom) {
            //pingServer.circleY = rect.bottom - pingServer.circleRadius;
            pingServer.speedY = -pingServer.speedY;
        }

        if (pingServer.circleY - pingServer.circleRadius < rect.top) {
            //pingServer.circleY = rect.bottom - pingServer.circleRadius;
            pingServer.speedY = -pingServer.speedY;
        }

        if (pingServer.turnx1 == true && pingServer.turnx2 == false && pingServer.circleX <= pingServer.x1 + 20 && pingServer.circleY >= pingServer.y1 && pingServer.circleY <= pingServer.y1 + 80) {
            pingServer.speedX = -pingServer.speedX;
            pingServer.turnx1 = false;
            pingServer.turnx2 = true;

        }

        if (pingServer.turnx1 == false && pingServer.turnx2 == true && pingServer.circleX >= pingServer.x2 - 20 && pingServer.circleY >= pingServer.y2 && pingServer.circleY <= pingServer.y2 + 80) {
            pingServer.speedX = -pingServer.speedX;
            pingServer.turnx1 = true;
            pingServer.turnx2 = false;
        }

        // Перерисовка окна
        InvalidateRect(hDlg, NULL, TRUE); // Помечаем окно как требующее перерисовки

        // СИНХРОНИЗАЦИЯ ДАННЫХ клиента и сервера
        pingClient = pingServer;

        sendMessageToServer(hDlg);

        return TRUE;
    }
    case WM_PAINT: {
        // Рисование круга
        /*SetWindowText(labelPX, setText(pingServer.circleX));
        SetWindowText(labelPY, setText(pingServer.circleY));*/
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hDlg, &ps);

        // Выбор кисти и пера
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));  // Красная кисть
        HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0)); // Черное перо

        HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);

        // Рисование круга
        Ellipse(hdc, pingServer.circleX - pingServer.circleRadius, pingServer.circleY - pingServer.circleRadius,
            pingServer.circleX + pingServer.circleRadius, pingServer.circleY + pingServer.circleRadius);

        // Возвращаем старые кисть и перо
        SelectObject(hdc, hOldBrush);
        SelectObject(hdc, hOldPen);

        // Удаляем созданные объекты GDI
        DeleteObject(hBrush);
        DeleteObject(hPen);

        EndPaint(hDlg, &ps);

        
        return TRUE;
    }
    case WM_CREATE:
    {
        
        
        //labelPX = CreateWindowExW(
        //    0, L"STATIC", L"1111",
        //    WS_CHILD | WS_VISIBLE | SS_LEFT, // Стили окна
        //    10, 10, 30, 25,             // Позиция и размеры
        //    hDlg, (HMENU)IDC_MYLABEL_X1, NULL, NULL
        //);
        //labelPY = CreateWindowExW(
        //    0, L"STATIC", L"1111",
        //    WS_CHILD | WS_VISIBLE | SS_LEFT, // Стили окна
        //    10, 35, 300, 25,             // Позиция и размеры
        //    hDlg, (HMENU)IDC_MYLABEL_Y1, NULL, NULL
        //);
    }
    case WM_DESTROY:
        KillTimer(hDlg, 1000);
        PostQuitMessage(0);
        return TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK) {
            //MessageBoxW(hDlg, L"Вы нажали кнопку!", L"start", MB_OK);
            pingServer.startingBall = !pingServer.startingBall;
            runBall(hDlg, wParam, lParam);
            // Интервал 20 мс
        }

        /*if (LOWORD(wParam) == IDLEFT) {
            
            }*/

        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        
        break;
    }
    return (INT_PTR)FALSE;
}
 //Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

    HWND hwndButton = (HWND)lParam;
    SetWindowSubclass(hwndButton, ButtonProc, 1, 0);
    switch (message) {
    
    case WM_COMMAND: {
        if (LOWORD(wParam) == IDOK) {
            //MessageBoxW(hDlg, L"Вы нажали кнопку!", L"start", MB_OK);
            // функция расчета дробей
            
            MessageBoxW(hDlg, L"About", L"start", MB_OK);
            EndDialog(hDlg, LOWORD(wParam));

        }
        break;
    }
    case WM_DESTROY:
        EndDialog(hDlg, LOWORD(wParam));
        //PostQuitMessage(0);

        //return 0;

    case WM_INITDIALOG:
        return (INT_PTR)TRUE;



    default:
        return DefWindowProc(hDlg, message, wParam, lParam);
    }


    return (INT_PTR)FALSE;

}


void GetTextFromEditControl(HWND hwndEdit) {
    int len = GetWindowTextLength(hwndEdit) + 1;
    TCHAR* buff = new TCHAR[len];

    GetWindowText(hwndEdit, buff, len);

    // Используйте buff здесь, например, выведите его в MessageBox
    std::wstring text = buff;
    MessageBox(NULL, text.c_str(), L"Текст из Edit Control", MB_OK);

    delete[] buff;
}


INT_PTR CALLBACK Drobi(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
    {
        wchar_t text[3];
        int xn{ 0 }, xd{ 0 }, yn{ 0 }, yd{ 0 }, sn{ 0 }, sd{ 0 };
        //HWND hwndButton = (HWND)lParam;
        HWND edit1n = GetDlgItem(hDlg, IDC_EDIT1);
        HWND edit1d = GetDlgItem(hDlg, IDC_EDIT2);
        HWND edit2n = GetDlgItem(hDlg, IDC_EDIT3);
        HWND edit2d = GetDlgItem(hDlg, IDC_EDIT4);

        switch (message) {

        case WM_COMMAND: {
            if (LOWORD(wParam) == IDC_OK1) {
                if (edit1n && edit1d && edit2n && edit2d) {
                    GetWindowTextW(edit1n, text, sizeof(text) / sizeof(text[0]));
                    xn = _wtoi(text);
                    GetWindowTextW(edit1d, text, sizeof(text) / sizeof(text[0]));
                    xd = _wtoi(text);
                    GetWindowTextW(edit2n, text, sizeof(text) / sizeof(text[0]));
                    yn = _wtoi(text);
                    GetWindowTextW(edit2d, text, sizeof(text) / sizeof(text[0]));
                    yd = _wtoi(text);

                    Drob drob1(xn, xd);
                    Drob drob2(yn, yd);

                    Drob sum = drob1 + drob2;

                    //доделать switch по listbox

                    //вывод текста в SETWINDOWTEXT
                    
                    HWND nom = GetDlgItem(hDlg, IDC_STATIC_3N);
                    HWND dom = GetDlgItem(hDlg, IDC_STATIC_3D);
                    SetWindowTextW(nom, setText(sum.numerator));
                    SetWindowTextW(dom, setText(sum.denominator));
                    

                    //Drob difference = drob1 - drob2;
                    //Drob product = drob1 * drob2;
                    //Drob quotient = drob1 / drob2;

                }
                else {
                    MessageBox(NULL, L"Ошибка: Не удалось получить handle Edit Control.", L"Ошибка", MB_OK | MB_ICONERROR);
                }
                //MessageBoxW(hDlg, L"Вы нажали кнопку!", L"start", MB_OK);
                // функция расчета дробей
                //MessageBoxW(hDlg, L"Расчет", L"start", MB_OK);

            }

            if (LOWORD(wParam) == IDCANCEL  ) {
                //MessageBoxW(hDlg, L"Вы нажали кнопку!", L"start", MB_OK);
                // функция расчета дробей

                //MessageBoxW(hDlg, L"drobi", L"отмена", MB_OK);
                EndDialog(hDlg, LOWORD(wParam));

            }
            break;
        }

        case WM_DESTROY:
            EndDialog(hDlg, LOWORD(wParam));
            //PostQuitMessage(0);

            //return 0;

        case WM_INITDIALOG:
            return (INT_PTR)TRUE;



        default:
            return DefWindowProc(hDlg, message, wParam, lParam);
        }


        return (INT_PTR)FALSE;

    
    
  


}
