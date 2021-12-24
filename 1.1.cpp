#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>


using namespace std;

/*
* \brief находит значение a
* \param x Значение x
* \param y Значение z
* \param z Значение y
* \return Значение a
*/
double getA(const double x, const double y, const double z);

/*
* \brief Находит значение b
* \param x Значение y
* \param y Значение x
* \param z Значение z
* \return Значение b
*/
double getB(const double x, const double y, const double z);

/*
* \brief Вход в программу 
* \return в случае успеха, возвращает 0
*/

int main() {
	const double x = 2.2;
	const double y = 9.2;
	const double z = 10.2;


	const auto a = getA(x, y, z);
	const auto b = getB(x, y, z);

	std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	
	system("pause");
	return 0;
}

double getA(const double x, const double y, const double z) {
	return log(z + pow(x, 2)) + pow(sin(x / y), 2);
}

double getB(const double x, const double y, const double z) {
	return exp(-z) * ((x + sqrt(x + y)) / (x - sqrt(fabs(x - y))));
}