// g++ main.cpp ComplexNumbers.cpp ComplexNumbers.h -o ödev3
#include <iostream>
#include <vector>
#include "ComplexNumbers.h"
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	vector <ComplexNumbers> numbers;
	int i = 0;
	char control;
	ComplexNumbers p1(5);

	cout << p1;
	while(1)
	{
		ComplexNumbers p1;
		cout << "Lütfen karmaşık sayilarinizi giriniz" << endl;
		cout << "Ve durmak için H'ye devam için S'ye basınız" << endl;
		cin >> control;
		if(control == 'S' || control == 'e')
		{
			cin >> p1;
			numbers.push_back(p1);
			cout << "Karmaşık sayiniz:" << numbers.at(i);
			i++;
		}
		else
			break;
	}
	cout << "Ortalama:" << numbers[0].average(numbers);
}
