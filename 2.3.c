#include <stdio.h>
#include <stdlib.h>
/**
 * @brief получает числа и проверяет их корректность
 * 
 * @return полученное значение
 */
double GetValue();

/**
 * @brief По заданным трем числам определяет, является ли сумма каких-либо из них положительной.
 * 
 * @param num1 - считанное число
 * @param num2 - считанное число
 * @param num3 - считанное число
 */
void Result(const double num1, const double num2, const double num3);

/**
 * @brief точка входа в программу
 * 
 * @return 0 при успешном выполнении программы
 */
int main()
{
    printf("Введите первое число: ");
    double num1 = GetValue();
    printf("Введите второе число: ");
    double num2 = GetValue();
    printf("Введите третье число: ");
    double num3 = GetValue();

    Result(num1, num2,  num3);

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

void Result(const double num1, const double num2, const double num3){

    double numbers[] = {num1, num2, num3};

    int found = 0;
    for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 3; j++){
            if (numbers[i]+numbers[j] > 0){
                printf("сумма чисел %.2f и %.2f положительна и равна %.2f \n", numbers[i], numbers[j], numbers[i]+numbers[j]);
                found = 1;
                
            }
        }
    }
    if(found == 0){
        printf("Положительных сумм пар чисел нет\n");
    }
}
