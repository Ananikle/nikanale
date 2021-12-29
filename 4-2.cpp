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
 * \brief Замена минимального по модулю отрицательного числа.
 * \param arr - Указатель на массив.
 * \param n - Размер массива.
 */
void ReplaceMin(int* arr, const size_t n);

/**
 * \brief Удаление элементов оканчивающихся на 0.
 * \param arr - Указатель на массив.
 * \param n - Размер массива.
 */
void DelLastZeros(int* arr, size_t& n);

/**
 * \brief Формирование нового массива по заданным правилам.
 * \param arr - Указатель на массив.
 * \param n - Размер массива.
 */
int* FormNewArray(const int* arr, const size_t n);

enum class FillMethod { //перечислимый тип
    /**
     * \brief Заполнение элементов массива с клавиатуры.
     */
    KEYBORD,

    /**
     * \brief Заполнение элементов массива случайными числами.
     */
     RANDOM
};

int main()
{
    setlocale(LC_ALL, "rus");
    size_t n, key;
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    while (size < 1) {
        cout << "Размер должен быть положительным! Введите размер: ";
        cin >> size;
    };

    n = size;
    int* arr = new int[n];

    do {
        cout << "Заполнить массив:\n -" << static_cast<int>(FillMethod::KEYBORD) << ". С клавиатуры\n -" << static_cast<int>(FillMethod::RANDOM) << ". Случайными числами\n\nВведите опцию: ";
        cin >> key;
    } while (key != static_cast<int>(FillMethod::KEYBORD) && key != static_cast<int>(FillMethod::RANDOM));

    const int left = -100;
    const int right = 200;

    if (key == static_cast<int>(FillMethod::KEYBORD))
        FillArrayKeyboard(arr, n);
    else
        FillArrayRandom(arr, n, left, right);

    PrintArray(arr, n);

    ReplaceMin(arr, n);
    PrintArray(arr, n);

    DelLastZeros(arr, n);
    PrintArray(arr, n);

    int* arr2 = FormNewArray(arr, n);
    cout << "Сформированный массив: " << endl;
    PrintArray(arr2, n);

    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }

    if (arr2 != nullptr) {
        delete[] arr2;
        arr2 = nullptr;
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

void ReplaceMin(int* arr, const size_t n) {
    int ind = -1; //не найден отрицательный

    for (size_t i = 0; i < n; i++)
        if (arr[i] < 0 && (ind == -1 || arr[i] > arr[ind]))
            ind = i;

    if (ind == -1)
        cout << "Отрицательный элемент не найден" << endl;
    else {
        cout << "Минимальный по модулю отрицательный элемент " << arr[ind] << " заменен на первый " << arr[0] << endl;
        arr[ind] = arr[0];
    }
}

void DelLastZeros(int* arr, size_t& n) {
    cout << "Удаляем элементы, оканчивающиеся на 0" << endl;
    for (int i = n - 1; i >= 0; i--)
        if (arr[i] % 10 == 0) {
            for (int j = i; j < n - 1; j++)
                arr[j] = arr[j + 1];
            n--;
        }
}

int* FormNewArray(const int* arr, const size_t n) {
    int* arr2 = new int[n];
    for (size_t i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            arr2[i] = i * arr[i];
        else
            arr2[i] = -arr[i];
    return arr2;
}