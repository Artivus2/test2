﻿// header.h: включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
// Файлы заголовков Windows
#include <windows.h>
// Файлы заголовков среды выполнения C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <ctime>
#include <string>
#include <sstream> 
#include <vector> 
#include <winsock2.h> // Winsock header
#include <ws2tcpip.h>  // Additional Winsock functions (e.g., inet_pton)
#include <thread>
#include <cmath>
#include <iomanip>
#include <conio.h>
