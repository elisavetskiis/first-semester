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
	const double X = 0.5;
	const double Y = 0.05;
	const double Z = 0.7;
	printf("a = %lf\n", GetA(X, Y, Z));
	printf("b = %lf\n", GetB(X, Y, Z));
	return 0;
}

double GetA(const double x, const double y, const double z)
{
	return (x*x*(x+1))/(y - sin(x+z)*sin(x+z));
}

double GetB(const double x, const double y, const double z)
{
	double cos_val = cos((x+y)*(x+y));
	return sqrt((x*y)/z) + cos_val*cos_val;
}
