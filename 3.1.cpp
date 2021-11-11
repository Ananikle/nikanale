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
bool NoDecision(double x);
/**
 * \brief Вход в программу.
 * \return в случае успеха, возвращает 0.
*/
int main(){
	double x = 0.5;
	const auto z = 1;
	const auto step = 0.05;
	
	for (x; x <= z; x += step){
		if (NoDecision(x))
		    cout << "x: " << x << " y: " << Function(x) << endl; 
	}
	
	system("pause");
	return 0;
}

double Function(double x){
	return x + cos(pow(x, 0.52) + 2);
}

bool NoDecision(double x){
	return (1/(x + cos(pow(x, 0.52) + 2))) != 0;
}