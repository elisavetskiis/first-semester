#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Считывает число из консоли и проверяет совпадение типа
 * 
 * @return считанное значение 
 */
double ReadValue();

/**
 * @brief проверяет корректность ввода 
 * 
 * @param корректное полученное занчение
 */
double GetValue();

/**
 * @brief считает функцию 
 * 
 * @param a - константа
 * @param x - вводимое пользователем число
 * @return результат вычислений функции 
 */
double CountingFunction(const double a, const double x);

/**
 * @brief точка входа в программу
 * 
 * @return возвращает 0 при успешном выполнении программы
 */
int main()
{
    const double a = 1.5;
    
    printf("введите х: ");
    double x = GetValue();
    
    printf("y = %.3f", CountingFunction(a, x));


    return 0;
}


double ReadValue(){
    double x = 0;
    if(scanf("%lf", &x) != 1){
        exit(1);
        printf("Ошибка: неверный ввод");
    }

    return x;
}

double GetValue(){
    double value = ReadValue();
    if(value <= 0){
        printf("ошибка: число должно быть положительно");
        exit(1);
    }
    
    return value;
}

double CountingFunction(const double a, const double x){

    if(a*x < 1){
        return a*x - log(a*x);
    }else return a*x+log(a*x);
}
