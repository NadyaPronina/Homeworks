#include <iostream>
#include<cmath>
//task 1
/*

int main() {
	unsigned char sym = 0;

	do {
		std::cout <<static_cast<int>(sym) << std::endl;
		sym++;
	} while (sym > 0);

	return 0;
}
*/

//task 2
/*
int main() {
	setlocale(LC_ALL, "rus");

	double a, b, c, D, x1, x2;

	std::cout << "Введите коэффициенты a,b,c: " << std::endl;
	std::cout << std::endl << "a = ";
	std::cin >> a;
	std::cout << std::endl << "b = ";
	std::cin >> b;
	std::cout << std::endl << "c = ";
	std::cin >> c;
	std::cout << std::endl;

	D = b * b - 4 * a * c;

	if (D < 0)
		std::cout << "Уравнение решений не имеет!" << std::endl;
	else if (D >= 0) {
		x1 = (-b + sqrt(D)) / 2.0 * a;
		std::cout << "x1 = " << x1 << std::endl;
		x2 = (-b - sqrt(D)) / 2.0 * a;
		std::cout << "x2 = " << x2;
	}
	return 0;
}
*/

//task 3
/*
int main() {
	setlocale(LC_ALL, "rus");

	double insrad, outrad, x, y;

	std::cout << "Введите размер наибольшего радиуса: ";
	std::cin >> outrad;
	std::cout << "Введите размер наименьшего радиуса: ";
	std::cin >> insrad;
	std::cout << "Введите координату х: ";
	std::cin >> x;
	std::cout << "Введите координату y: ";
	std::cin >> y;

	double diff = sqrt(x * x + y * y);

	if (diff<outrad && diff>insrad)
		std::cout << "Точка находится между двумя окружностями" << std::endl;
	else
		std::cout<< "Точка не находится между двумя окружностями" << std::endl;

	return 0;

}
*/


//task 4
/*

int main() {
	setlocale(LC_ALL, "rus");

	double eps, x, S = 0.0, val=1.0;

	std::cout << "Введите х (-1;1): ";
	std::cin >> x;
	std::cout << "Введите eps: ";
	std::cin >> eps;
	if (x < -1 || x>1) {
		std::cout << "Введите х в необходимом промежутке (-1;1)";
		return -1;
	}
	while (abs(val) > eps) {
		S += val;
		val *= x;
	}
	std::cout << "Сумма = " << S << std::endl;
	std::cout << "Сравнение: " << 1 / (1 - x) << std::endl;

	return 0;
}
*/

//task 5
/*
int main() {
	setlocale(LC_ALL, "rus");

	double a, b, c, d, x;

	std::cout << "Введите а:";
	std::cin >> a;
	std::cout << "Введите b: ";
	std::cin >> b;
	std::cout << "Введите c: ";
	std::cin >> c;
	std::cout << "Введите d: ";
	std::cin >> d;
	std::cout << "Введите x: ";
	std::cin >> x;

	std::cout << "y = " << (x - a) * (d - c) / (b - a) + c << std::endl;
	return 0;
}*/


//TASK 6
/*
bool heart(double x, double y) {
	return ((x * x + y * y - 1) * (x * x + y * y - 1) * (x * x + y * y - 1) - x * x * y * y * y <= 0);

}

int main() {
	for (int y = 20; y >= 0; —y) {
		for (int x = 0; x < 41; ++x) {
			if (heart(-1.5 + 3. / 40. * (double)x, -1.5 + 3. / 20. * (double)y))
				std::cout << "*";
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}
	return 0;
}
*/

//task 7
/*
int main() {
	setlocale(LC_ALL, "rus");
	int R, counter = 0;
	std::cout << "Введите целочисленный радиус, меньший 1млн: ";
	std::cin >> R;
	std::cout << std::endl;

	if (R > pow(10, 6))
		return -1;

	for (int i = -R; i <= R; ++i)
		for (int j = -R; j <= R; ++j) {
			if (i * i + j * j <= R * R)
				++counter;
		}

	std::cout << "Количество точек внутри и на границе окружности равно: " << counter << std::endl;
	return 0;

}
*/

//task 8
/*
int main() {
	for (int i = 1; i < 101; ++i) {
		if (i % 3 == 0) {
			std::cout << "Foo" << std::endl;
		}
		else if (i % 5 == 0) {
			std::cout << "Bar" << std::endl;
		}
		else if (i % 3 == 0 && i % 5 == 0)
			std::cout << "FooBar" << std::endl;
		else if (i % 3 > 0 && i % 5 > 0)
			std::cout << i << std::endl;
	}
	return 0;
}
*/