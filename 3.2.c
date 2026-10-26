#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief считывает введенное исло 
 * 
 * @return считанное число
 */
int GetValue();

/**
 * @brief считывает введенное дробное число 
 * 
 * @return считанное число 
 */
double GetDouble();

/**
 * @brief вычисляет сумму первых n членов последовательности
 * 
 * @param n - кол-во элементов последовательности 
 */
void ResultA(const int n);

/**
 * @brief вычислить сумму всех членов последовательности, по модулю не меньших заданного числа e
 * 
 * @param e - заданное число 
 */
void ResultB(const double e);


/**
 * @brief точка взода в программу
 * 
 * @return 0 если программа выполнена корректно
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

    term = -term * (k+1)/(k*(k+2.0));
   }
   printf("Сумма = %g\n", sum);
   
}


void ResultB(const double e){
    double term = -0.5;
    double sum = 0;
    int k = 1;

    while(fabs(term) >= e){
        sum+=term;
        term = -term * (k+1)/(k*(k+2.0));
        k++;
    }
    printf("Сумма = %g\n", sum);
}
