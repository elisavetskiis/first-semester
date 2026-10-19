#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief получает числа и проверяет их корректность
 * 
 * @return полученное значение
 */
double GetValue();

/**
 * @brief табуляция функции
 * 
 * @param start - начало интервала
 * @param end - коцен интервала 
 * @param step - шаг интервала
 */
void Result(const double start, const double end, const double step);

void Limit();

/**
 * @brief точка входа в программу
 * 
 * @return при успешном выполнении возвращает 0
 */
int main()
{
    printf("введите начало интервала: ");
    double start = GetValue();
    printf("введите конец интервала: ");
    double end = GetValue();
    printf("введите шаг интервала: ");
    double step = GetValue();   

    Result(start, end, step);

    return 0;
}

double GetValue()
{
    double value = 0;
    if(scanf("%lf", &value) != 1){
            printf("ошибка: неверный ввод");
            exit(1);
    }
    return value;
}

void Limit(const double start, const double end, const double step)
{
    if (step <= 0 || start > end){
        printf("Ошибка: неверный шаг или интервал\n");
        exit(1);
    }
}

void Result(const double start, const double end, const double step)
{
    Limit(start, end, step);

    for(double x = start; x < end; x += step){
        if(x > 1){
            printf("x = %.2f, функция не определена\n", x);

        }else{
            double y = sqrt(1-x) - cos(sqrt(1-x));
            printf("x = %.2f y = %.2f\n", x, y);
        }
    }
}
