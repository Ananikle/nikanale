#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <cmath>

using namespace std;

double RamifiedProcess(double const x, double const a);

double Equation1(double const x, double const a);
/**
*\brief функция выполняет вычисление при x*a<1
*\param const a - константа
*\param x - число, вводимое пользователем
*\return возвращает значение функции 
**/

double Equation2(double const x, double const a);
/**
*\brief функция выполняет вычисление при a*x>=1
*\param const a - константа
*\param x - число, вводимое пользователем
*\return возвращает значение функции 
**/

double InputValue();
/**
* brief точка входа в программу
* \return возвращает 0 ы случае успешного выполнения
**/

int main()
{
	setlocale(0, "");
	const double x = InputValue();
	const double a = 0.3;
	
	cout << RamifiedProcess(x, a) << endl;
	system("pause");
	return 0;
}

double InputValue(){
	double value;
	cout << "Введите число: ";
	cin >> value;
	return value;
}

double RamifiedProcess(double const x, double const a)
{
	if (a * x < 1)
		return Equation1(x, a);
	else 
		return Equation2(x, a);
}

double Equation1(double const x, double const a)
{
	return a * sin((pow(x, 2) + 1) / 10);
}

double Equation2(double const x, double const a)
{
	return a * cos((x - 1) / 10);
}