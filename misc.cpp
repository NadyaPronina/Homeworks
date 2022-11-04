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

	std::cout << "Ââåäèòå êîýôôèöèåíòû a,b,c: " << std::endl;
	std::cout << std::endl << "a = ";
	std::cin >> a;
	std::cout << std::endl << "b = ";
	std::cin >> b;
	std::cout << std::endl << "c = ";
	std::cin >> c;
	std::cout << std::endl;

	D = b * b - 4 * a * c;

	if (D < 0)
		std::cout << "Óðàâíåíèå ðåøåíèé íå èìååò!" << std::endl;
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

	std::cout << "Ââåäèòå ðàçìåð íàèáîëüøåãî ðàäèóñà: ";
	std::cin >> outrad;
	std::cout << "Ââåäèòå ðàçìåð íàèìåíüøåãî ðàäèóñà: ";
	std::cin >> insrad;
	std::cout << "Ââåäèòå êîîðäèíàòó õ: ";
	std::cin >> x;
	std::cout << "Ââåäèòå êîîðäèíàòó y: ";
	std::cin >> y;

	double diff = sqrt(x * x + y * y);

	if (diff<outrad && diff>insrad)
		std::cout << "Òî÷êà íàõîäèòñÿ ìåæäó äâóìÿ îêðóæíîñòÿìè" << std::endl;
	else
		std::cout<< "Òî÷êà íå íàõîäèòñÿ ìåæäó äâóìÿ îêðóæíîñòÿìè" << std::endl;

	return 0;

}
*/


//task 4
/*

int main() {
	setlocale(LC_ALL, "rus");

	double eps, x, S = 0.0, val=1.0;

	std::cout << "Ââåäèòå õ (-1;1): ";
	std::cin >> x;
	std::cout << "Ââåäèòå eps: ";
	std::cin >> eps;
	if (x < -1 || x>1) {
		std::cout << "Ââåäèòå õ â íåîáõîäèìîì ïðîìåæóòêå (-1;1)";
		return -1;
	}
	while (abs(val) > eps) {
		S += val;
		val *= x;
	}
	std::cout << "Ñóììà = " << S << std::endl;
	std::cout << "Ñðàâíåíèå: " << 1 / (1 - x) << std::endl;

	return 0;
}
*/

//task 5
/*
int main() {
	setlocale(LC_ALL, "rus");

	double a, b, c, d, x;

	std::cout << "Ââåäèòå à:";
	std::cin >> a;
	std::cout << "Ââåäèòå b: ";
	std::cin >> b;
	std::cout << "Ââåäèòå c: ";
	std::cin >> c;
	std::cout << "Ââåäèòå d: ";
	std::cin >> d;
	std::cout << "Ââåäèòå x: ";
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
	int R, res = 0;
	std::cout << "Введите целочисленный радиус, меньший 1млн: ";
	std::cin >> R;
	std::cout <<std::endl;

	if (R > 1000000)
		return -1;
	for (int i = 0; i <= R; ++i)
		res += (int)sqrt(R * R - i * i);
	res = 4 * res + 1;

	std::cout << "Количество точек внутри и на границе окружности равно: " << res << std::endl;
	return 0;
}


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
