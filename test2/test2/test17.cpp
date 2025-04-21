#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;



void difdates2 (int y1, int m1, int d1, int y2, int m2, int d2){
	
	tm timeinfo = tm();
	timeinfo.tm_year = y1 - 1900;   // year: 2024
	timeinfo.tm_mon = m1 - 1;      // month: january
	timeinfo.tm_mday = d1;     // day: 1st
	timeinfo.tm_hour = 12;
	time_t tt1 = mktime(&timeinfo);
	system_clock::time_point tp1 = system_clock::from_time_t(tt1);
	cout << tt1 << " Дата1" << endl;
	timeinfo.tm_year = y2 - 1900;   // year:
	timeinfo.tm_mon = m2 - 1;      // month: 
	timeinfo.tm_mday = d2;     // day: 
	time_t tt2 = mktime(&timeinfo);
	system_clock::time_point tp2 = system_clock::from_time_t(tt2);
	cout << tt2 << " Дата2" << endl;
	system_clock::duration d = tp1 - tp2;
	typedef duration<int, ratio<60 * 60 * 24>> days_type;
	days_type ndays = duration_cast<days_type> (d);

	// display result:
	cout << ndays.count() << " days have passed since Дата 2";
	cout << endl;

	time_t t1 = time(NULL);
	tm t = *localtime(&t1);

	// Вывод текущего времени в формате 06:59:08
	printf("%.4d-%.2d-%.2d %.2d:%.2d:%.2d\n",t.tm_year+1900, t.tm_mon+1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);

}

template <typename T> double AVG(T arr[]) {
	float Pol(0),Otr(0), Nuls(0);
	for (int i = 0; i < 15; i++) {
		if (arr[i] > 0) Pol++;
		if (arr[i] < 0) Otr++;
		if (arr[i] == 0) Nuls++;
	}
	cout << endl;
	cout << Pol << " " << Otr << " " << Nuls;
	
	return Pol, Otr, Nuls;
}



int main_17()
{
	system("chcp 1251");
	//difdates2(2024, 12, 20, 2021, 12, 20);
	
	srand(time(NULL));
	const int x = 15;
	int arr[x];

	for (int i = 0; i < x; i++) {
		
		arr[i] = -1000 + rand() % (2000);
		cout << arr[i] << "(" << i << ") ";
	}

	double res1;
	res1 = AVG(arr);

	

	return 0;
}

