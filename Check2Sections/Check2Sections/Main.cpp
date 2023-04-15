#include <iostream>
#include <map>
#include <math.h>
#include <vector>

std::map<int, float> pointX;
std::map<int, float> pointY;

enum Point
{
	A, B, C, D
};

float crossProduct(int X, int Y, int Z)
{
	float x1 = pointX[Z] - pointX[X], y1 = pointY[Z] - pointY[X];
	float x2 = pointX[Y] - pointX[X], y2 = pointY[Y] - pointY[X];
	return (x1 * y2) - (x2 * y1);
}

bool checkIsOnSegment(int X, int Y, int Z)
{
	return (pointX[Z] >= std::fmin(pointX[X], pointX[Y]) && pointX[Z] <= std::fmax(pointX[X], pointX[Y]) &&
		pointY[Z] >= std::fmin(pointY[X], pointY[Y]) && pointY[Z] <= std::fmax(pointY[X], pointY[Y])) ? true : false;
}

bool checkSegments()
{
	std::vector <float> vectors;
	vectors.push_back(crossProduct(Point::C, Point::D, Point::A));
	vectors.push_back(crossProduct(Point::C, Point::D, Point::B));
	vectors.push_back(crossProduct(Point::A, Point::B, Point::C));
	vectors.push_back(crossProduct(Point::A, Point::B, Point::D));

	if ((vectors[0] > 0 && vectors[1] < 0 || vectors[0] < 0 && vectors[1] > 0) && (vectors[2] > 0 && vectors[3] < 0 || vectors[2] < 0 && vectors[3] > 0))
		return true;

	for (auto i = 0; i < vectors.size(); i++)
	{
		if (i <= 1)
			return vectors[i] == 0 && checkIsOnSegment(Point::C, Point::D, i) ? true : false;
		if (i >= 2)
			return vectors[i] == 0 && checkIsOnSegment(Point::A, Point::B, i) ? true : false;
	}

	return false;
}

char whatPoint(int index)
{
	switch (index)
	{
	case 1:
		return 'A';
		break;
	case 2:
		return 'B';
		break;
	case 3:
		return 'C';
		break;
	case 4:
		return 'D';
		break;
	default:
		
		break;
	}
}

int main()
{

	for (int i = 0; i < 4; i++)
	{
		std::cout << "Podaj wspolzedne punktu: " << whatPoint(i+1) << "\n";
		std::cin >> pointX[i];
		std::cin >> pointY[i];
		std::cout << "\n";
	}

	if (checkSegments())
	{
		std::cout << "Odcinki AB i CD sie przecinaja\n";
	}
	else
	{
		std::cout << "Odcinki AB i CD sie nie przecinaja\n";
	}

	return 0;
}