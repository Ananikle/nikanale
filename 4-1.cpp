#include <iostream>
#include <random>

using namespace std;

/**
 * \brief Ввод элементов массива с клавиатуры.
 * \param arr - Указатель на массив.
 * \param n - Размер массива.
 */
void FillArrayKeyboard(int* arr, const size_t n);

/**
 * \brief Заполнение элементов массива случайными числами.
 * \param arr - Указатель на массив.
 * \param n - Размер массива.
 * \param min - Левая граница диапазона случайных чисел.
 * \param max - Правая граница диапазона случайных чисел.
 */
void FillArrayRandom(int* arr, const size_t n, const int min, const int max);

/**
 * \brief Вывод элементов массива в консоль.
 * \param arr - Указатель на массив.
 * \param n - Размер массива.
 */
void PrintArray(const int* arr, const size_t n);

/**
 * \brief Подсчет суммы четных элементов массива, больших заданного числа.
 * \param arr - Указатель на массив.
 * \param n - Размер массива.
 * \param c - Заданное число.
 * \return Искомая сумма.
 */
int SumTask(const int* arr, const size_t n, const int c);

/**
 * \brief Перемножение четных положительных элементов массива на значение последнего элемента.
 * \param arr - Указатель на массив.
 * \param n - Размер массива.
 */
void MultLast(int* arr, const size_t n);

/**
 * \brief Нахождение индекса первой пары элементов массива противоположных знаков.
 * \param arr - Указатель на массив.
 * \param n - Размер массива.
 * \return Индекс первого элемента искомой пары.
 */
int PosPair(const int* arr, const size_t n);

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
    int size;
    FillMethod fm;

    cout << "Введите размер массива: ";
    cin >> size;

    while(size<1) {
        cout << "Размер должен быть положительным! Введите размер: ";
        cin >> size;
    };

    n = size;
    int* arr = new int[n];

    do {
        cout << "\nЗаполнить массив:\n - 0. С клавиатуры\n - 1. Случайными числами\n\nВведите опцию: ";
        cin >> key;
    } while (key < 0 || key>1);
    fm = FillMethod(key);

    const int left = -100;
    const int right = 200;

    if (fm == FillMethod::KEYBORD)
        FillArrayKeyboard(arr, n);
    else
        FillArrayRandom(arr, n, left, right);

    PrintArray(arr, n);

    int c;
    cout << "Введите заданное число: ";
    cin >> c;
    cout << "Сумма четных элементов, больших заданного числа: " << SumTask(arr, n, c) << endl;

    cout << "Умножаем все четные положительные на последний элемент..." << endl << endl;
    MultLast(arr, n);
    PrintArray(arr, n);

    int position = PosPair(arr, n);
    if (position == -1)
        cout << "Пары элементов с разными знаками не найдено" << endl;
    else
        cout << "Индекс пары элементов с разными знаками: " << position << endl;

    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }

    return 0;
}

void FillArrayKeyboard(int* arr, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }
    cout << endl;
}

void FillArrayRandom(int* arr, const size_t n, const int min, const int max) {
    random_device rd;
    mt19937 gen(rd());
    const uniform_int_distribution<int> dist(min, max);

    for (size_t i = 0; i < n; i++)
        arr[i] = dist(gen);
}

void PrintArray(const int* arr, const size_t n) {
    for (size_t i = 0; i < n; i++)
        cout << "arr[" << i << "]: " << arr[i] << endl;
    cout << endl;
}

int SumTask(const int* arr, const size_t n, const int c) {
    int sum = 0;
    for (size_t i = 0; i < n; i++)
        if (arr[i] % 2 == 0 && arr[i] > c)
            sum += arr[i];
    return sum;
}

void MultLast(int* arr, const size_t n) {
    for (size_t i = 0; i < n; i++)
        if (arr[i] % 2 == 0 && arr[i] > 0)
            arr[i] *= arr[n - 1];
}

int PosPair(const int* arr, const size_t n) {
    for (size_t i = 0; i < n - 1; i++)
        if (arr[i] * arr[i + 1] < 0)
            return i;
    return -1;
}