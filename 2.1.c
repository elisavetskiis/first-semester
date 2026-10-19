#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief считывает число
 * 
 * @return считанное число 
 */
double GetValue();


/**
 * @brief вычисляет и выводит значения A, увеличенные в N, 2N и 3N раз
 *
 * @param a - исходное значение числа
 * @param n - коэффициент увеличения
 * @return посчитанные числа
 */
double GetResult(const double a, const double n);

/**
 * @brief точка входа в программу
 * 
 * @return возвращает 0, если программа выполнена корректно 
 */
int main(){
    printf("введите значение A: ");
    double a = GetValue();

    printf("во сколько раз увеличить?: ");
    double n = GetValue();

    GetResult(a, n);

    return 0;
}



double GetValue()
{
    double value = 0;
    if(scanf("%lf", &value) != 1){
        printf("ошибка, неверный ввод");
        exit(1);       
    } else{
        return value;
    }
}


double GetResult(const double a, const double n)
{
    double result = 0;

    for(int i = 1; i<=n; i++){
        result = a * n * i;
        printf("A увеличено в %dN раз: %g\n", i, result);
    }
    return result;
}

