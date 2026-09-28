#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define RHO_ALUMINUM 0.028

/**
 * @brief считает сопротивление на основе полученных данных 
 * 
 * @param s - площадь поперечного сечения в мм^2
 * @param l - длина провода в метрах
 * @return значение сопротивления
 */
double GetWireResistance(const double s, const double l);

/**
 * @brief Считывает число из консоли и проверяет совпадение типа
 * 
 * @return считанное значение 
 */
double ReadDouble();

/**
 * @brief проверяет корректность ввода 
 * 
 * @param корректное полученное занчение
 */
double GetValidValue();

/**
 * @brief точка входа в программу
 * 
 * @return возвращает 0, если программа выполнена корректно 
 */
int main()
{
    printf("Введите длину в метрах: ");
    double l = GetValidValue();
    
    printf("Введите площадь сечения в мм^2: ");
    double s = GetValidValue();

    printf("Сопротивление равно: %.3f Ом ", GetWireResistance(s, l));

    return 0;
}

double ReadDouble()
{   
    double value = 0;
    if(scanf("%lf", &value) != 1){
        printf("Error: incorrect type\n");
        exit(1);
    }
    return value;
}

double GetValidValue()
{
    double value = ReadDouble();
    if(value <= 0){
        printf("Error: incorrect type (must be positive number)\n");
        exit(1);
    }
    return value;
}



double GetWireResistance(const double s, const double l)
{

    return RHO_ALUMINUM * (l / s);
}
