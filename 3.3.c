
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Вычисляет значение исходной функции
 *
 * @param x - аргумент функции
 * @return Значение функции 0.5 * ln(x)
 */
double GetFunction(double x);

/**
 * @brief Вычисляет сумму ряда с заданной точностью
 *
 * @param x - аргумент ряда
 * @return Приближенное значение суммы ряда
 */
double GetSum(double x);

/**
 * @brief Вычисляет коэффициент для следующего члена ряда
 *
 * @param i - номер текущего члена ряда
 * @return Коэффициент рекуррентной формулы
 */
double GetCoef(const int i);

/**
 * @brief Точка входа в программу
 *
 * @return 0, если программа выполнена корректно
 */
int main()
{
    double start = 0.2;
    double end = 1.0;
    double step = 0.1;

    printf("x\t\tf(x)\t\tS(x)\n");

    for(int i = 0; start + i * step <= end; i++){
        double x = start + i * step;

        printf("%.2f\t\t%.4f\t\t%.4f\n",
               x, GetFunction(x), GetSum(x));
    }

    return 0;
}

double GetValue(){
    double value = 0;
    if(scanf("%lf", &value) != 1){
        printf("Ошибка: неверный ввод");
        exit(1);
    }
    return value;
}

int GetInt(){
    int value = 0;
    if(scanf("%d", &value) != 1){
        printf("Ошибка: неверный ввод");
        exit(1);
    }
    return value;
}

double GetFunction(double x){
    return 0.5 * log(x);
}

double GetSum(double x){
    const double EPS = 0.0001;
    double a = (x - 1)/(x + 1);
    double q = a;
    double sum = 0;

    for(int i = 0; fabs(a)/(1 - q*q) >= EPS; i++){
        sum += a;
        a *= GetCoef(i) * q*q;
    }

    return sum;
}

double GetCoef(const int i){
    return (2.0*i + 1.0)/(2.0*i + 3.0);
}
