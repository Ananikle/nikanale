#include <iostream>
#include <cmath>

using namespace std;

double InputSide();

bool IsTriangle(double const A, double const B, double const C);

bool IsAcuteAngle(double const A, double const B, double const C);

int main() {
	setlocale(0, "");
	
	const auto SideA = InputSide();
	const auto SideB = InputSide();
	const auto SideC = InputSide();
	
	if (IsTriangle(SideA, SideB, SideC)){
		cout << "Треугольник с данными сторонами существует" << endl;
		if (IsAcuteAngle(SideA, SideB, SideC))
			cout << "Треугольник остроугольный" << endl;
		else
			cout << "Треугольник не остроугольный" << endl;
	}
	else 
		cout << "Не существует треугольника с данными сторонами" << endl;
	
	system("pause");
	return 0;
}

double InputSide() {
	double side;
	cout << "Введите сторону треугольника: ";
	cin >> side;
	
	return side;
}

bool IsTriangle(double const a, double const b, double const c) {
	return (a + b > c) && (b + c > a) && (a + c > b);
}

bool IsAcuteAngle(double const a, double const b, double const c) {
	return (pow(b, 2) + pow(c, 2) - pow(a, 2) > 0) && (pow(a, 2) + pow(b, 2) - pow(c, 2) > 0) && (pow(a, 2) + pow(c, 2) - pow(b, 2) > 0);
}
