#include <stdio.h>
#include <math.h>

/*
* @brief рассчитывает функцию A по заданной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double GetA(const double x, const double y, const double z);

/*
* @brief рассчитывает функцию B по заданной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double GetB(const double x, const double y, const double z);

/*
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main()
{
	const double X = 1.426;
	const double Y = -1.22;
	const double Z = 3.5;
	printf("a = %lf\n", GetA(X, Y, Z));
	printf("b = %lf\n", GetB(X, Y, Z));
	return 0;
}

double GetA(const double x, const double y, const double z)
{
	return (2*cos(x - M_PI/6))/(0.5 + sin(y)*sin(y));
}

double GetB(const double x, const double y, const double z)
{
	return 1 + (z*z)/(3+z*z/5);
}
