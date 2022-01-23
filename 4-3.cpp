#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

/**
 * \brief Ввод элементов матрицы с клавиатуры.
 * \param matr - Указатель на матрицу.
 * \param n - Количество строк.
 * \param m - Количество столбцов.
 */
void FillMatrKeyboard(int** matr, const size_t n, const size_t m);

/**
 * \brief Заполнение элементов матрицы случайными числами.
 * \param matr - Указатель на матрицу.
 * \param n - Количество строк матрицы.
 * \param m - Количество столбцов матрицы.
 * \param min - Левая граница диапазона случайных чисел.
 * \param max - Правая граница диапазона случайных чисел.
 */
void FillMatrRandom(int** matr, const size_t n, const size_t m, const int min, const int max);

/**
 * \brief Вывод элементов матрицы в консоль.
 * \param matr - Указатель на матрицу.
 * \param n - Количество строк матрицы.
 * \param m - Количество столбцов матрицы.
 */
void PrintMatr(int** matr, const size_t n, const size_t m);

/**
 * \brief Замена отрицательных элементов матрицы на 0.
 * \param matr - Указатель на матрицу.
 * \param n - Количество строк матрицы.
 * \param m - Количество столбцов матрицы.
 */
void ReplaceNegative(int** matr, const size_t n, const size_t m);


/**
 * \brief Количество столбцов, не содержащих элемент кратный 5.
 * \param matr - Указатель на матрицу.
 * \param n - Количество строк старой матрицы.
 * \param m - Количество столбцов старой матрицы.
 * \return - Количество столбцов новой матрицы.
 */
size_t NewNumberColumns(int** matr, const size_t n, const size_t m);

/**
 * \brief Удаление всех столбцов содержащих элемент кратный 5.
 * \param matr - Указатель на матрицу.
 * \param n - Количество строк старой матрицы.
 * \param m - Количество столбцов старой матрицы.
 * \param m1 - Количество столбцов новой матрицы.
 * \return - Адрес новой матрицы.
 */
int** DelColumnFive(int** matr, const size_t n, const size_t m, const size_t m1);



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
    size_t n, m, key; //n-количетсво строк(высота), m-количество столбцов(ширина)
    int size_n, size_m;

    cout << "Введите размеры матрицы: ";
    cin >> size_n >> size_m;

    while (size_n < 1 || size_m < 1) {
        cout << "Размеры должны быть положительными! Введите размеры: ";
        cin >> size_n >> size_m;
    };

    n = size_n;
    m = size_m;

    int** matr = new int* [n];
    for (size_t i = 0; i < n; i++)
        matr[i] = new int[m];

    do {
        cout << "Заполнить массив:\n -" << static_cast<int>(FillMethod::KEYBORD) << ". С клавиатуры\n -" << static_cast<int>(FillMethod::RANDOM) << ". Случайными числами\n\nВведите опцию: ";
        cin >> key;
    } while (key != static_cast<int>(FillMethod::KEYBORD) && key != static_cast<int>(FillMethod::RANDOM));


    const int left = -100;
    const int right = 200;

    if (key == static_cast<int>(FillMethod::KEYBORD))
        FillMatrKeyboard(matr, n, m);
    else
        FillMatrRandom(matr, n, m, left, right);

    PrintMatr(matr, n, m);

    cout << "Заменяем отрицательные на нули: " << endl;
    ReplaceNegative(matr, n, m);

    PrintMatr(matr, n, m);

    cout << "Удаляем столбцы, содержащие элементы, кратные пяти: " << endl;
    size_t m1 = NewNumberColumns(matr, n, m);
    int** matr1 = DelColumnFive(matr, n, m, m1);
    PrintMatr(matr1, n, m1);

    if (matr != nullptr) {
        for (size_t i = 0; i < n; i++) {
            if (matr[i] != nullptr)
                delete[] matr[i];
        }
        delete[] matr;
        matr = nullptr;
    }

    if (matr1 != nullptr) {
        for (size_t i = 0; i < n; i++) {
            if (matr1[i] != nullptr)
                delete[] matr1[i];
        }
        delete[] matr1;
        matr1 = nullptr;
    }
    return 0;
}

void FillMatrKeyboard(int** matr, const size_t n, const size_t m) {
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++) {
            cout << "matr[" << i << "][" << j << "]: ";
            cin >> matr[i][j];
        }
    cout << endl;
}

void FillMatrRandom(int** matr, const size_t n, const size_t m, const int min, const int max) {
    random_device rd;
    mt19937 gen(rd());
    const uniform_int_distribution<int> dist(min, max);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            matr[i][j] = dist(gen);
}

void PrintMatr(int** matr, const size_t n, const size_t m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++)
            cout << setw(5) << matr[i][j];
        cout << endl;
    }
    cout << endl;
}

void ReplaceNegative(int** matr, const size_t n, const size_t m) {
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (matr[i][j] < 0)
                matr[i][j] = 0;
}

size_t NewNumberColumns(int** matr, const size_t n, const size_t m) {
    size_t m1 = 0; //количество столбцов в новой матрице
    for (size_t j = 0; j < m; j++) { //бежим по индексам столбцов
        bool flag = true; //столбец не удалять
        size_t i = 0; //текущий номер строки
        while (flag && i < n) {
            if (matr[i][j] % 5 == 0) {
                flag = false;
            }
            i++;
        }
        if (flag) m1++;
    }
    return m1;
}

int** DelColumnFive(int** matr, const size_t n, const size_t m, const size_t m1) {
    int** matr1 = new int* [n];
    for (size_t i = 0; i < n; i++)
        matr1[i] = new int[m1];

    size_t k = 0;
    for (size_t j = 0; j < m; j++) { //бежим по индексам столбцов
        bool flag = true; //столбец не удалять
        size_t i = 0; //текущий номер строки
        while (flag && i < n) {
            if (matr[i][j] % 5 == 0) {
                flag = false;
            }
            i++;
        }
        if (flag) {
            for (size_t i = 0; i < n; i++) {
                matr1[i][k] = matr[i][j];
            }
            k++;
        }
    }
    return matr1;
}
