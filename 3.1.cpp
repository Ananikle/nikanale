#include<iostream>
#include<cmath>

using namespace std;

/**
 * \brief функция для расчета заначений
 * \x начало интервала
 * \return значение
*/

double Function(double x);
/**
 * \brief выполняет функцию
 * \return в случае успеха, возвращает 1
*/

bool NoDecision(double x);
/**
 * \brief Вход в программу
 * \return в случае успеха, возвращает 0
*/

int main(){
	double x = 0.5;
	const auto z = 1;
	const auto step = 0.05;
	
	for (x; x <= z; x += step){
		if (NoDecision(x)){
        cout <<"Нет решений" <<endl;
		    cout << "x: " << x << " y: " << Function(x) << endl; 
    }else
      return 0;
  }
	
	system("pause");
	return 0;
}

double Function(double x){
	return x + cos(pow(x, 0.52) + 2);
}

bool NoDecision(double x){
	return (1/(x + cos(pow(x, 0.52) + 2)));
}