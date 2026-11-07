#include <stdio.h>
#include <stdlib.h>

enum IncreaseOption {
    N_TIMES = 1,
    TWO_N_TIMES = 2,
    THREE_N_TIMES = 3
};

/**
 * @brief Считывает число с клавиатуры
 *
 * @return Считанное число типа double
 */
double GetValue();

/**
 * @brief Вычисляет значение A, увеличенное в N, 2N или 3N раз
 *
 * @param a Исходное значение числа
 * @param n Коэффициент увеличения
 * @param choice Выбранный вариант увеличения (1, 2 или 3)
 * @return Результат вычисления
 */
double GetResult(const double a, const double n, const int choice);

/**
 * @brief Считывает и проверяет выбор пользователя
 *
 * @return Выбранный вариант увеличения (1, 2 или 3)
 */
int GetChoice();

/**
 * @brief Точка входа в программу
 *
 * @return 0, если программа выполнена корректно
 */
int main()
{
    printf("Введите значение A: ");
    double a = GetValue();

    printf("Введите значение N: ");
    double n = GetValue();

printf("Выберите вариант увеличения:\n");
    printf("%d - в N раз\n", N_TIMES);
    printf("%d - в 2N раз\n", TWO_N_TIMES);
    printf("%d - в 3N раз\n", THREE_N_TIMES);

    int choice = GetChoice();

    double result = GetResult(a, n, choice);

    printf("Результат: %g\n", result);

    return 0;
}

double GetValue()
{
    double value = 0;

    if (scanf("%lf", &value) != 1) {
        printf("Ошибка: неверный ввод\n");
        exit(1);
    }

    return value;
}

int GetChoice()
{
    int choice = 0;

    if (scanf("%d", &choice) != 1) {
        printf("Ошибка: неверный выбор\n");
        exit(1);
    }

    return choice;
}

double GetResult(const double a, const double n, const int choice)
{
    switch (choice)
    {
    case N_TIMES:
        return a * n;
        
    case TWO_N_TIMES:
        return a * n * 2;
    
    case THREE_N_TIMES:
        return a * n * 3;

    default:
        printf("Ошибка\n");
        exit(1);

    }
}
