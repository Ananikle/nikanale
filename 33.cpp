#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * \brief Pеализация функции вычисления арктангенса.
 * \param x - Аргумент функции.
 * \param e - Точность вычислений.
 * \return Значение суммы последовательности слагаемых.
 */
double myatan(const double x, const double e);


/**
 * \brief Вывод в консоль таблицы значений из трех столбцов.
 * \param a - Левая граница интервала.
 * \param b - Правая граница интервала.
 * \param h - Шаг изменения аргумента.
 * \param e - Точность вычислений.
 */
void table(const double a, const double b, const double h, const double e);

int main() {
	const double a = -1;
	const double b = -0.1;
	const double h = 0.1;
	const double e = pow(40, -5);
	
	table(a, b, h, e);
	return 0;
}

double myatan(const double x, const double e) 
{
	double term = x; 
	double sum = term; 
	double denom = 1; 

	while (abs(term) >= e) 
  {
		term *= (-1) * x * x * denom / (denom + 2);
		denom += 2;
		sum += term;
	}
	return sum;
}

void table(const double a, const double b, const double h, const double e) 
{
	cout << setw(20) << "x" << setw(20) << "arctg(x)" << setw(20) << "arctg'(x)" << endl;
	for (double x = a; x <= b; x += h)
		cout << setw(20) << x << setw(20) << atan(x) << setw(20) << myatan(x, e) << endl;
}