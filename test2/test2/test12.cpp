
#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main_12() {

	system("chcp 1251");
	srand(time(NULL));
	/*int max_num(0), min_num(0);
	int ar[] = { 23,-11,9,-18,-25, -4, 1, 421, 776, 34, 65};
	
	for (int i = 0; i < size(ar); i++) {
		if (ar[i] >= max_num) max_num = ar[i];
		if (ar[i] <= min_num) min_num = ar[i];
			
	}
	cout << min_num << " : " << max_num;*/

	/*int size1 = 8;
	bool findneg1 = false;
	double arr[] = { -5.7, 6.0, 2, 0, -4.7, 6, 8.1, -4};
	double positive = 0;
	double negative = 0;
	for (int i = 0; i < size1 ; i++)
	{
		if (arr[i] > 0)	positive = arr[i];

		if (arr[i] < 0 && !findneg1)
		{
			negative = arr[i];
			findneg1 = true;
		}
	}

	cout << "Last positive number: " << positive <<	endl;
	cout << "First negatine number: " << negative << endl;*/
	
	/*int count_people(0), number;

	const int size1 = 40;

	int ar[size1];
	int padik[] = {0,0,0,0};

	for (int i = 0; i < size1; i++) {
		ar[i] = 1 + rand() % (5);
		cout << ar[i] << "("<<i+1<<"), ";
	}
	cout << "ВВедите номер квариры: \n";
	cin >> number;
	cout << "Кол-во жильцов в данной квартире: " << ar[number - 1] << endl;
	if ((number - 1) % 2 == 0) {
		cout << "1 Соседи из: "<< number + 1 << "квариры, кол-во человек: " << ar[number] << endl;
	}
	else {
		cout << "2 Соседи из: " << number - 1 << " квариры, кол-во человек: " << ar[number - 2] << endl;
	}
	
	
	for (int j = 0; j < size1; j++) {
		if (j < 10) padik[0] += ar[j];
		if (j >=10 && j < 20) padik[1] += ar[j];
		if (j >=20 && j < 30) padik[2] += ar[j];
		if (j >=30) padik[3] += ar[j];
		
	}
	cout << "1 подьезд: " << padik[0] << endl;
	cout << "2 подьезд: " << padik[1] << endl;
	cout << "3 подьезд: " << padik[2] << endl;
	cout << "4 подьезд: " << padik[3] << endl;

	for (int i = 0; i < size1; i++) {
		if (ar[i] >= 5) cout << "Квартира №: " << i + 1 << ", кол-во чел: " << ar[i] << endl;
	}*/
	
	/*int max1(0), max2(0), temp1(0), temp2(0);
	int ar[] = { 1000, 1100, 1200, 1300, 2300, 2350, 2360, 2300 };

	for (int i = 0; i < size(ar); i++) {
		
		for (int j = 0; j < size(ar); j++) {
			if (max1 <= ar[j])
			{
				max1 = ar[j];
				temp1 = j;
			}
		}
		if (max2 <= ar[i] && i != temp1) {
			max2 = ar[i];
			temp2 = i;
		}
	}
	cout << max1 << " : " << max2;*/

	const int size1 = 40;

	int ar[size1];

	int	count_numbers(0);
	for (int i = 0; i < size1; i++) {
		ar[i] = 1 + rand() % (20);
		cout << ar[i] << " , ";
	}
	cout << endl;
	cout << endl;



	for (int i = 1; i < 21; i++) {
		count_numbers = 0;
		for (int j = 0; j < size(ar); j++) {
			if (ar[j] == i) {
				count_numbers++; 
				
			}
			
		}
		if (count_numbers >= 2) {
			cout << i << " " << "(" << count_numbers << ") ";

		}
	}

	return 0;


	
}