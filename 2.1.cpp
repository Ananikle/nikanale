#include <iostream>
#include <string>

using namespace std;

/**
 * \brief Перечисляемый тип вычеслений, для которых считаем площадь и объем.
 */ 
enum class Cube
{
	/**
	 * \brief Неправильно сформированный выбор.
	 */
	none,
	
	/**
	 * \brief Выбранный расчет -- площадь грани.
	 */
	square,
	
	/**
	 * \brief Выбранный расчет -- площадь полной поверхности.
	 */
	area,
	
	/** 
	 * \brief Выбранный расчет -- объем.
	 */
	capacity,
};

/**
 * \brief Функция расчета площади грани куба.
 * \param a сторона куба.
 * \return Площадь гарни куба.
 */
double GetCubeSquare(const double a);

/**
 * \brief Функция расчета площади полной поверхности куба.
 * \param a сторона куба.
 * \return Площадь полной поверхности куба.
 */
double GetCubeArea(const double a);

/**
 * \brief Функция расчета объема куба.
 * \param a сторона куба.
 * \return Объем куба.
 */
double GetCubeCapacity(const double a);

/**
 * \brief Ввод стороны куба.
 * \param message Разъясняющая надпись.
 * \param out Произвольный поток вывода.
 * \param in Произвольный поток ввода.
 * \return Сторону куба.
 */
double ReadSide(const string& message = "", ostream& out = cout, istream& in = cin);


/**
 * \brief 
 * \param message Сообщение для пользователя.
 * \param out Произвольный поток вывода.
 * \param in Произвольный поток ввода.
 * \return Выбор пользователя.
 */
Cube ReadUserChoice(const string& message = "", ostream& out = cout, istream& in = cin);

/**
 * \brief Точка вход в программу
 * \return Код ошибки, если 0 - успешное выполнение
 */
int main() 
{
	setlocale(LC_ALL, "Russian");
	
	const auto message = "Выберите, что посчитать: "
	    + to_string(static_cast<int>(Cube::square)) + " - площадь грани,"
		+ to_string(static_cast<int>(Cube::area)) + " - площадь полной поверхности,"
		+ to_string(static_cast<int>(Cube::capacity)) + " - объем";
		
	const auto cube = ReadUserChoice(message);
	
	switch (cube) 
  {
		case Cube::square: 
    {
			const auto side = ReadSide("Введите сторону куба = ");
			
			const auto squareCube = GetCubeSquare(side);
			cout << "\nПлощадь грани куба " << squareCube << endl;
			break;
		}
		case Cube::area: 
    {
			const auto side = ReadSide("Введите сторону куба = ");
			
			const auto areaCube = GetCubeArea(side);
			cout << "\nПлощадь полной поверхности " << areaCube << endl;
			break;
		}
		case Cube::capacity: 
    {
			const auto side = ReadSide("Введите сторону куба = ");
			
			const auto capacityCube = GetCubeCapacity(side);
			cout << "\nОбъем " << capacityCube << endl;
			break;
		}
	default:
	    cout << "ошибка!";
	}
	
	system("pause");
	return 0;
}

double GetCubeSquare(const double a) 
{
	return a * a;
}

double GetCubeArea(const double a) 
{
	return 6 * a * a;
}

double GetCubeCapacity(const double a) 
{
	return a * a * a;
}

double ReadSide(const string& message, ostream& out, istream& in) {
	out << message;
	double side;
	in >> side;
	return side;
}

Cube ReadUserChoice(const string& message, ostream& out, istream& in) 
{
	out << message;
	int userInput;
	in >> userInput;
	return static_cast<Cube>(userInput);
}