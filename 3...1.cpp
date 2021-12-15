#include<iostream>
#include<cmath>

using namespace std;
/**
 * \brief функция для расчета значений табуляции.
 * \x начало интервала.
 * \return значение табуляции.
*/
double Function(double x);
/**
 * \brief Возможность выполнения функции.
 * \return в случае успеха, возвращает 1)
*/

int main(){
	double x = 0.5;
	const auto z = 1;
	const auto step = 0.05;


  system("pause");
	return 0;
}

double Function(double x){
	return x + cos(pow(x, 0.52) + 2);
}

