
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Вычисляет значение исходной функции
 *
 * @param x - аргумент функции
 * @return Значение функции 0.5 * ln(x)
 */
double GetFunction(const double x);

/**
 * @brief Вычисляет сумму ряда с заданной точностью
 *
 * @param x - аргумент ряда
 * @param eps - заданная точность вычисления
 * @return Приближенное значение суммы ряда
 */
double GetSum(const double x, const double eps);

/**
 * @brief Вычисляет коэффициент для следующего члена ряда
 *
 * @param i - номер текущего члена ряда
 * @return Коэффициент рекуррентной формулы
 */
double GetCoef(const int i);

/**
 * @brief Считывает вещественное число и проверяет корректность ввода
 *
 * @return Считанное вещественное число
 */
double GetValue();

/**
 * @brief Проверяет корректность интервала и заданной точности
 *
 * @param start - начало интервала
 * @param end - конец интервала
 * @param step - шаг интервала
 * @param eps - заданная точность вычисления
 */
void CheckValues(const double start, const double end, const double step, const double eps);

 /**
 * @brief Точка входа в программу
 *
 * @return 0, если программа выполнена корректно
 */
int main()
{
    printf("Введите начало интервала: ");
    const double start = GetValue();

    printf("Введите конец интервала: ");
    const double end = GetValue();

    printf("Введите шаг интервала: ");
    const double step = GetValue();

    printf("Введите точность: ");
    const double eps = GetValue();

    CheckValues(start, end, step, eps);


    printf("x\t\tf(x)\t\tS(x)\n");

    for(int i = 0; start + i * step <= end; i++){
        const double x = start + i * step;

        printf("%.2f\t\t%.4f\t\t%.4f\n",
               x, GetFunction(x), GetSum(x, eps));
    }

    return 0;
}

double GetValue()
{
    double value = 0;

    if (scanf("%lf", &value) != 1 || !isfinite(value)) {
        printf("Ошибка: неверный ввод\n");
        exit(1);
    }

    return value;
}

double GetFunction(const double x){
    return 0.5 * log(x);
}

double GetSum(double x, const double eps){
    
    double a = (x - 1)/(x + 1);
    double q = a;
    double sum = 0;

    for(int i = 0; fabs(a)/(1 - q*q) >= eps; i++){
        sum += a;
        a *= GetCoef(i) * q*q;
    }

    return sum;
}

double GetCoef(const int i){
    return (2.0*i + 1.0)/(2.0*i + 3.0);
}

void CheckValues(const double start, const double end, const double step, const double eps)
{
    if (start <= 0 || end < start || step <= 0 || eps <= 0) {
        printf("Ошибка: неверные параметры\n");
        exit(1);
    }
}
