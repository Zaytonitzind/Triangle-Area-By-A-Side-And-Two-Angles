#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

double triangleArea(double angleA, double angleB, double sideC)
{
	return 0.5* pow(sideC, 2)*sin(angleB*M_PI / 180)  * sin(angleA*M_PI / 180) / sin(angleA * M_PI / 180 + angleB * M_PI / 180);
}

void check(double angleA, double angleB, double sideC)
{
	double angleC = 180 - angleA - angleB;
	cout << "First angle is " << angleA << endl;
	cout << "Second angle is " << angleB << endl;
	cout << "Third angle is " << angleC << endl;
	double sideB = sideC * sin(angleB * M_PI / 180) / sin(angleC * M_PI / 180);
	double sideA = sideC * sin(angleA * M_PI / 180) / sin(angleC * M_PI / 180);
	cout << "First side is " << sideA << endl;
	cout << "Second side is " << sideB << endl;
	cout << "Third side is " << sideC << endl;
	cout << "First area = " << triangleArea(angleA, angleB, sideC) << endl;
	cout << "Second area = " << triangleArea(angleB, angleC, sideA) << endl;
	cout << "Third area = " << triangleArea(angleA, angleC, sideB) << endl;
}

int main()
{
	pair <double, double> angle;
	double side;
	char checker;
	do {
		cout << "Enter first angle: ";
		cin >> angle.first;
		cout << "Enter second angle: ";
		cin >> angle.second;
		cout << "Enter side between two angles: ";
		cin >> side;
		if (angle.first <= 0 || angle.second <= 0 || side <= 0) {
			system("cls");
			cout << "Enter numbers greater than 0\n";
		}
	} while (angle.first <= 0 || angle.second <= 0 || side <= 0);
	cout << "Area of triangle is " << triangleArea(angle.first, angle.second, side) << endl;
	cout << "Check all? y/n ";
	cin >> checker;
	switch (checker)
	{
	case 'y':
		check(angle.first, angle.second, side);
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}