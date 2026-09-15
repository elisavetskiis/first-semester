#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* @brief считывает введённое значение и проверяет его на корректность
* @return считанное значение
*/
double GetValue();

/*
* @brief проверяет, что значение больше 0
* @param value - проверяемое значение
*/
void CheckValue(const double value);

/*
* @brief рассчитывает площадь треугольника по данным сторонам
* @param a - первая сторона
* @param b - вторая сторона
* @param c - угол между сторонами
* @return площадь треугольника
*/
double GetAreaOfTriangle(const double a, const double b, const double c);

/*
* @brief рассчитывает величину третьей стороны треугольника по двум сторонам и углу
* @param a - первая сторона
* @param b - вторая сторона
* @param c - угол между сторонами
* @return значение третьей стороны треугольника
*/
double GetThirdSideOfTriangle(const double a, const double b, const double c);

/*
* @brief рассчитывает радиус описанной окружности
* @param a - первая сторона
* @param b - вторая сторона
* @param c - угол между сторонами
* @return значение радиуса описанной окружности 
*/
double GetRadiusOfCircumscribedFigure(const double third_side, const double c);

/*
* @brief точка входа в программу
* @return возвращает 0, если программа выполненна корректно
*/
int main()
{
	printf("Enter side a:\n ");
	double a = GetValue();
	CheckValue(a);

	printf("Enter side b:\n ");
	double b = GetValue();
	CheckValue(b);

	printf("Enter angle c:\n ");
	double c_deg = GetValue();
	CheckValue(c_deg);

	double c = c_deg * M_PI / 180; 
	double third_side = GetThirdSideOfTriangle(a, b, c);

	printf("Area of the triangle: %.2lf\n", GetAreaOfTriangle(a, b, c));
	printf("Value of the third side of the triangle: %.2lf\n", GetThirdSideOfTriangle(a, b, c));
	printf("Radius of the circumscribed figure: %.2lf\n", GetRadiusOfCircumscribedFigure(third_side, c));
	return 0;
}

double GetValue()
{
	double value = 0;
	if (!scanf("%lf", &value))
	{
		printf("Error: incorrect type\n");
		exit(1);
	}
	return value;
}

void CheckValue(const double value)
{
	if (value <= 0)
	{
		printf("Error: value need be positive or not be 0\n");
		exit(1);
	}
}

double GetAreaOfTriangle(const double a, const double b, const double c)
{
	return 0.5 * a * b * sin(c);
}

double GetThirdSideOfTriangle(const double a, const double b, const double c)
{
	return sqrt(a * a + b * b - 2 * a * b * cos(c));
}

double GetRadiusOfCircumscribedFigure(const double third_side, const double c)
{
	return third_side/(2 * sin(c));
}
