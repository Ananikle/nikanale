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
 * \brief Удаление всех столбцов содержащих элемент кратный 5.
 * \param matr - Указатель на матрицу.
 * \param n - Количество строк матрицы.
 * \param m - Количество столбцов матрицы.
 */
void DelColumnFive(int** matr, const size_t n, size_t& m);

/**
 * \brief Удаление k столбца, содержащего элемент кратный 5.
 * \param matr - Указатель на матрицу.
 * \param n - Количество строк матрицы.
 * \param m - Количество столбцов матрицы.
 * \param k - Столбец, который удаляем в результату работы функции.
 */
void DelColumn(int** matr, const size_t n, size_t& m, const size_t k);

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
    size_t n, m, key; //n-количетсво строк(высота), m-количество столбцов(ширина)
    int size_n, size_m;
    FillMethod fm;

    cout << "Введите размеры матрицы: ";
    cin >> size_n >> size_m;

    while(size_n<1 || size_m<1) {
        cout << "Размеры должны быть положительными! Введите размеры: ";
        cin >> size_n >> size_m;
    };

    n = size_n;
    m = size_m;

    int** matr = new int*[n];
    for (size_t i = 0; i < n; i++)
        matr[i] = new int[m];

    do {
        cout << "\nЗаполнить матрицу:\n - 0. С клавиатуры\n - 1. Случайными числами\n\nВведите опцию: ";
        cin >> key;
    } while (key < 0 || key>1);
    fm = FillMethod(key);

    const int left = -100;
    const int right = 200;

    if (fm == FillMethod::KEYBORD)
        FillMatrKeyboard(matr, n, m);
    else
        FillMatrRandom(matr, n, m, left, right);

    PrintMatr(matr, n, m);

    cout << "Заменяем отрицательные на нули: " << endl;
    ReplaceNegative(matr, n, m);

    PrintMatr(matr, n, m);

    cout << "Удаляем столбцы, содержащие элементы, кратные пяти: " << endl;
    DelColumnFive(matr, n, m);
    PrintMatr(matr, n, m);





    if (matr != nullptr) {
        for (size_t i = 0; i < n; i++) {
            if (matr[i] != nullptr)
                delete[] matr[i];
        }
        delete[] matr;
        matr = nullptr;
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

void DelColumnFive(int** matr, const size_t n, size_t& m) {
    bool f;
    for (int j = m - 1; j >= 0; j--) {
        f = false; //элемента нет
        for (size_t i = 0; i < n; i++) {
            if (matr[i][j] % 5 == 0) {
                f = true;
                break;
            }
        }
        if (f) DelColumn(matr, n, m, j);
    }
}

void DelColumn(int** matr, const size_t n, size_t& m, const size_t k) { //удалить k-й столбец
    for (size_t i = 0; i < n; i++) {
        for (size_t j = k; j < m - 1; j++)
            matr[i][j] = matr[i][j + 1];
    }
    m--;
}