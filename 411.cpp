#include <iostream>
#include <random>

using namespace std;

/**
 * \brief Ввод элементов массива с клавиатуры.
 * \param a - Указатель на массив.
 * \param n - Размер массива.
 */
void FillArrayKeyboard(int* a, const size_t n);

/**
 * \brief Заполнение элементов массива случайными числами.
 * \param a - Указатель на массив.
 * \param n - Размер массива.
 * \param min - Левая граница диапазона случайных чисел.
 * \param max - Правая граница диапазона случайных чисел.
 */
void FillArrayRandom(int* a, const size_t n, const int min, const int max);

/**
 * \brief Вывод элементов массива в консоль.
 * \param a - Указатель на массив.
 * \param n - Размер массива.
 */
void PrintArray(const int* a, const size_t n);

/**
 * \brief Подсчет суммы четных элементов массива, больших заданного числа.
 * \param a - Указатель на массив.
 * \param n - Размер массива.
 * \param c - Заданное число.
 * \return Искомая сумма.
 */
int SumTask(const int* a, const size_t n, const int c);

/**
 * \brief Перемножение четных положительных элементов массива на значение последнего элемента.
 * \param a - Указатель на массив.
 * \param n - Размер массива.
 */
void MultLast(int* a, const size_t n);

/**
 * \brief Нахождение индекса первой пары элементов массива противоположных знаков.
 * \param a - Указатель на массив.
 * \param n - Размер массива.
 * \return Индекс первого элемента искомой пары.
 */
int PosPair(const int* a, const size_t n);

/**
 * \brief Перечислимый тип методов заполнения.
 */
enum class FillMethod { //перечислимый тип
    /**
     * \brief Заполнение элементов массива с клавиатуры.
     */
    KEYBORD = 0,

    /**
     * \brief Заполнение элементов массива случайными числами.
     */
     RANDOM = 1
};

int main()
{
    setlocale(LC_ALL, "rus");
    size_t n, key;
    FillMethod fm;
    cout << "Введите размер массива: ";
    cin >> n;
    int* a = new int[n];

    do {
        cout << "\nЗаполнить массив:\n - 0. С клавиатуры\n - 1. Случайными числами\n\nВведите опцию: ";
        cin >> key;
    } while (key < 0 || key>1);
    fm = FillMethod(key);

    if (fm == FillMethod::KEYBORD)
        FillArrayKeyboard(a, n);
    else
        FillArrayRandom(a, n, -100, 200);

    PrintArray(a, n);

    int c;
    cout << "Введите заданное число: ";
    cin >> c;
    cout << "Сумма четных элементов, больших заданного числа: " << SumTask(a, n, c) << endl;

    cout << "Умножаем все четные положительные на последний элемент..." << endl << endl;
    MultLast(a, n);
    PrintArray(a, n);

    int d = PosPair(a, n);
    if (d == -1)
        cout << "Пары элементов с разными знаками не найдено" << endl;
    else
        cout << "Индекс пары элементов с разными знаками: " << d << endl;

    if (a != nullptr){
        delete[] a;
        a = nullptr;
    }

    return 0;
}

void FillArrayKeyboard(int* a, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
    cout << endl;
}

void FillArrayRandom(int* a, const size_t n, const int min, const int max) {
    random_device rd;
    mt19937 gen(rd());
    const uniform_int_distribution<int> dist(min, max);

    for (size_t i = 0; i < n; i++)
        a[i] = dist(gen);
}

void PrintArray(const int* a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        cout << "a[" << i << "]: " << a[i] << endl;
    cout << endl;
}

int SumTask(const int* a, const size_t n, const int c) {
    int sum = 0;
    for (size_t i = 0; i < n; i++)
        if (a[i] % 2 == 0 && a[i] > c)
            sum += a[i];
    return sum;
}

void MultLast(int* a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        if (a[i] % 2 == 0 && a[i] > 0)
            a[i] *= a[n - 1];
}

int PosPair(const int* a, const size_t n) {
    for (size_t i = 0; i < n - 1; i++)
        if (a[i] * a[i + 1] < 0)
            return i;
    return -1;
}