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
 * @brief считывает данное значение и проверяет корректность 
 * 
 * @return считанное значение 
 */
double GetValue();

/**
 * @brief проверяет корректность ввода 
 * 
 * @param value - проверяемое занчение
 */
double CheckValue();

/**
 * @brief точка входа в программу
 * 
 * @return возвращает 0, если программа выполнена корректно 
 */
int main()
{
    printf("Введите длину в метрах: ");
    double l = GetValue();
    
    printf("Введите площадь сечения в мм^2: ");
    double s = GetValue();

    printf("Сопротивление равно: %.3f Ом ", GetWireResistance(s, l));

    return 0;
}

double CheckValue()
{   
    double value = 0;
    if(scanf("%lf", &value) != 1){
        printf("Error: incorrect type\n");
        exit(1);
    }
    return value;
}

double GetValue()
{
    double value = CheckValue();
    if(value <= 0){
        printf("Error: incorrect type (must be positive number)");
        exit(1);
    }
    return value;
}



double GetWireResistance(const double s, const double l)
{

    return RHO_ALUMINUM * (l / s);
}
