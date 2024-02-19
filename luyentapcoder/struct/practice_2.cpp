/*#include<iostream>
#include<cmath>
using namespace std;

struct point {
	float x, y, z;
};

float cal(point M,point N) {
	float length;
	float cals = (M.x - N.x) * (M.x - N.x) + (M.y - N.y) * (M.y - N.y) + (M.z - N.z) * (M.z - N.z);
	length = sqrt(cals);
	return length;
}

float length_A(point A) {
	float length = sqrt(A.x * A.x + A.y * A.y + A.z * A.z);
	return length;
}

float length_AB(point A, point B) {
	return cal(A, B);
}


float length_OI(point A, point B) {
	float x = (A.x + B.x) / 2;
	float y = (A.y + B.y) / 2;
	float z = (A.z + B.z) / 2;
	float length = sqrt(x*x + y*y + z*z);
	return length;
}

float length_OG(point A, point B,point C) {
	float x = (A.x + B.x + C.x) / 3;
	float y = (A.y + B.y + C.y) / 3;
	float z = (A.z + B.z + C.z) / 3;
	float length = sqrt(x * x + y * y + z * z);
	return length;
}

float S(point A, point B, point C) {
	float AB = cal(A, B);
	float AC = cal(A, C);
	float BC = cal(B, C);
	float p = (AB + AC + BC) / 2;
	float s = sqrt(p * (p - AB) * (p - AC) * (p - BC));
	return s;
}
int main()
{
	point A, B, C;
	std::cout << "Nhap diem A: "; std::cin >> A.x >> A.y >> A.z;
	std::cout << "Nhap diem B: "; std::cin >> B.x >> B.y >> B.z;
	std::cout << "Nhap diem C: "; std::cin >> C.x >> C.y >> C.z;
	std::cout << "Ket qua 1: " << length_A(A) << "\n";
	std::cout << "Ket qua 2: " << length_AB(A, B) << "\n";
	std::cout << "Ket qua 4: " << length_OI(A, B) << "\n";
	std::cout << "Ket qua 5: " << length_OG(A, B, C) << "\n";
	std::cout << "Ket qua 6: " << S(A, B, C) << "\n";
}*/