#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Считывает целое положительное число и проверяет корректность ввода
 *
 * @return Считанное целое число
 */
int GetValue();

/**
 * @brief Считывает положительное вещественное число и проверяет корректность ввода
 *
 * @return Считанное вещественное число
 */
double GetDouble();

/**
 * @brief Вычисляет и выводит сумму первых n членов последовательности
 *
 * @param n - количество членов последовательности
 */
void ResultA(const int n);

/**
 * @brief Вычисляет и выводит сумму членов последовательности,
 * модуль которых не меньше заданного числа e
 *
 * @param e - минимальное значение модуля члена последовательности
 */
void ResultB(const double e);

/**
 * @brief Находит натуральное число N, при котором произведение
 * предыдущего и следующего за N чисел равно 2208
 */
void ResultC();

/**
 * @brief Вычисляет рекуррентный коэффициент для получения
 * следующего члена последовательности
 *
 * @param k - номер текущего члена последовательности
 * @return Коэффициент перехода к следующему члену последовательности
 */
double GetCOef(const int k);

/**
 * @brief Точка входа в программу
 *
 * @return 0, если программа выполнена корректно
 */
int main()
{
    printf("Программа 1\n");
    printf("Введите число n: ");
    int n = GetValue();

    ResultA(n);

    printf("Программа 2\n");
    printf("Введите число e: ");
    double e = GetDouble();

    ResultB(e);

    ResultC();
    return 0;
}

int GetValue()
{
    int value = 0;
    if(scanf("%d", &value) != 1 || value <= 0){
        printf("ошибка: неверный ввод");
        exit(1);
    }
    return value;
}

double GetDouble()
{
    double value = 0;
    if(scanf("%lf", &value) != 1 || value <= 0 || !isfinite(value)){
        printf("ошибка: неверный ввод");
        exit(1);
    }
    return value;
}

void ResultA(const int n)
{
    double term = -0.5;
    double sum = 0;

    for(int k = 1; k <= n; k++){
        sum += term;
        term *= GetCOef(k);
    }
    printf("Сумма = %g\n", sum);
}

double GetCOef(const int k)
{
    return -(k+1.0)/(k*(k+2.0));
}

void ResultB(const double e)
{
    double term = -0.5;
    double sum = 0;
    int k = 1;

    while(fabs(term) >= e){
        sum += term;
        term *= GetCOef(k);
        k++;
    }
    printf("Сумма = %g\n", sum);
}

void ResultC()
{
    const int target = 2208;
    for(int n = 1; n <= target; n++){
        if((n - 1) * (n + 1) == target){
            printf("Доп задание: N = %d\n", n);
        }
    }
}
