#define USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;
/**
 * \brief функция ввода данных
 * \parama x 
 * \return Введенное значение
 */
double InputValue();

/**
 * \brief функция расчета среднего арифметического кубов
 * \param x
 * \param y
 * \return расчет кубов среднего арифметического
 */ 
double Average(const double x, const double y);

/** 
 * \brief функция расчета среднего квадратичного 
 * \param x
 * \param y 
 * \return среднее квадратичное
 */
double Geometric(const double x, const double y);

int main() 
{
	const double x = InputValue();
	const double y = InputValue();
	
	const auto a = Average(x, y);
	const auto b = Geometric(x, y);
	
	cout << "x = " << x << ", y = " << y << '\n';
	cout << "a = " << a << ", b = " << b << '\n';
	
	system("pause");
	return 0;
}

double inputValue() 
{
	double z;
	cout << "input value: " << '\n';
	cin >> z;
	
	return z;
}

double Average(const double x, const double y) 
{
	return (pow(x, 3) + pow(y, 3)) / 2;
}

double Geometric(const double x, const double y)
{
	return sqrt(x * y);
}