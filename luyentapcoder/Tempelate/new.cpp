#include<iostream>
#include<string>

using namespace std;

template <typename T>
struct Point {
	T x;
	T y;
};

int main()
{
	Point<int> point;
	point.x = 10;
	point.y = 20;
	cout << point.x << "  " << point.y << "\n";

	Point<string> point_2;
	point_2.x = "30";
	point_2.y = "40";
	cout << point_2.x << "  " << point_2.y << "\n";


}