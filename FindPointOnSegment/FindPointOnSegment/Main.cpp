#include <iostream>
#include <map>
#include <math.h>

enum Point
{
	A, B, C
};

bool checkPoint(std::map<int, float> pointX, std::map<int, float> pointY)
{
	float value = pointX[Point::A] * pointY[Point::B] + pointX[Point::B] * pointY[Point::C] + pointX[Point::C] * pointY[Point::A] - 
		pointX[Point::C] * pointY[Point::B] - pointX[Point::A] * pointY[Point::C] - pointX[Point::B] * pointY[Point::A];
	return value != 0 ? true : false;
}

bool checkIsOnSegment(std::map<int, float> pointX, std::map<int, float> pointY)
{
	if (pointX[Point::C] >= std::fmin(pointX[Point::A], pointX[Point::B]) && pointX[Point::C] <= std::fmax(pointX[Point::A], pointX[Point::B]) && 
		pointY[Point::C] >= std::fmin(pointY[Point::A], pointY[Point::B]) && pointY[Point::C] <= std::fmax(pointY[Point::A], pointY[Point::B]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	std::map<int, float> pointX;
	std::map<int, float> pointY;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Podaj wspolzedne " << i << " punktu\n";
		std::cin >> pointX[i];
		std::cin >> pointY[i];
		std::cout << "\n";
	}

	if (checkPoint(pointX, pointY))
	{
		std::cout << "Punkt C nie nalezy do odcinka AB\n";
	}
	else if(checkIsOnSegment(pointX, pointY))
	{
		std::cout << "Punkt C nalezy do odcinka AB\n";
	}
	else
	{
		std::cout << "Punkt C nie nalezy do odcinka AB\n";
	}

	return 0;
}