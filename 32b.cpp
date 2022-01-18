#include <iostream>

/**
 * \brief Пользовательский ввод необходимой точности вычисления.
 * \param message Мотивационное сообщение.
 * \return Точность вычисления.
 * \exception std::invalid_argument  В случае, если размер последовательности меньше 1.
 */
double Epsilon(const std::string& message);

/**
 * \brief Рассчитывает сумму последовательность с точностью (\a eps).
 * \param eps Точность вычисления.
 * \return Сумма последовательности.
 */
double SequenceSum(const double eps);

/**
 * \brief Рассчитывает значение рекуррентного члена в зависимости от индекса (\a index).
 * \param index Индекс, номер итерации.
 * \return Значение рекуррентного члена.
 */
double RecurrentMember(const size_t index) noexcept;

/**
 * \brief Точка входа в программу.
 * \return 0 – в случае успеха,<br/>1 – в противном случае.
 */
int main() noexcept
{
    try
    {
        setlocale(LC_ALL, "Russian");
        const auto eps = Epsilon("Введите точность вычислений ");
        const double Sum = SequenceSum(eps);
        std::cout << "Сумма последовательности c точностью " << eps << " равна: " << Sum << std::endl;
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

double SequenceSum(const double eps) {
    size_t i = 0;
    double Sum = 0;
double Current = eps + 1;
    while (abs(Current) >= eps) {
        if (i == 0) {
            Current = 1;
        }
        else {
            Current *= RecurrentMember(i - 1);
        }
        Sum += Current;
        i++;
    }
    return Sum;
}

double Epsilon(const std::string& message)
{
    std::cout << message;
    double eps = 0;
    std::cin >> eps;
    if (eps < 0)
    {
        throw std::invalid_argument ("Значение должно быть больше 0!");
    }

    return eps;
}

double RecurrentMember(const size_t index) noexcept
{
    return (pow(index+2,3)/((index+1)pow(index,3));
}

