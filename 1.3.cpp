#define USE_MATH_DEFINES
#include <iostream>
#include <cmath>


using namespace std;
/**
 * \brief функция расчета потенциальная энергия
 * \param x
 * \param y
 * \return потенциальную энергию
 */
double PotentialEnergy(const double x, const double k);

double InputValue();

int main() {
	const double x = InputValue();
	const double k = InputValue();
	const double Wp = PotentialEnergy(x, k);
	
	cout << "x = " << x << ", k = " << k << '\n';
	cout << "Wp = " << Wp << '\n';
	
	system("pause");
	return 0;
}

double InputValue(){
	double value;
	cout << "Введите значение: ";
	cin >> value;
	return value;
}

double PotentialEnergy(const double x, const double k) 
{
	return (k * pow(x, 2)) / 2;
}