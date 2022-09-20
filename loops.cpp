#include <iostream>
#include <cmath>
/*
// task 1
int main() {
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;
	double S = 0.0;
	for (int i = 1; i <= n; ++i) {
		S += 1.0 / i;
	}

	std::cout << "S = " << S;
	return 0;
}

//task 2

int main() {
	double S = 0.0, a = 2.0;
	int n = 0, tmp = 1;

	std::cout << "Enter n: ";
	std::cin >> n;

	while (tmp <= n) {
		S += 1 / a;
		a *= a;
		tmp++;
	}
	S = S + 1;

	std::cout << "S = " << S;

	return 0;
}

//task 3

int main() {
	int n, x;
	double S = 0.0;

	std::cout << "Enter n: ";
	std::cin >> n;
	std::cout << "Enter x: ";
	std::cin >> x;

	for (int i = 0; i <= n; ++i) {
		x = sin(x);
		S += x;
	}
	std::cout << "S = " << S;

}

//task 4

int main() {
	int N = 0, check = 1;
	double eps, pi = 0.0;
	std::cout << "Enter eps: ";
	std::cin >> eps;

	while (eps < 1.0 / (static_cast<double> (N) * 2.0 + 1.0)) {
		pi += check / (static_cast<double> (N) * 2.0 + 1.0);
		N += 1;
		check *= -1;
	}
	std::cout << "pi = " << pi << std::endl;
	std::cout << "N = " << N << std::endl;
	
	return 0;
}

//task 5

int main() {
	double eps, dx, x1, x2;

	std::cout << "Enter eps: ";
	std::cin >> eps;
	std::cout << "Enter dx: ";
	std::cin >> dx;
	std::cout << "Enter x1': ";
	std::cin >> x1;
	std::cout << "Enter x2: ";
	std::cin >> x2;

	double x = x1;

	while (x <= x2) {
		double top = x;
		int bottom = 1, a = -1;
		double S = x;
		double current = x;

		for (int i = 1; std::abs(current) > eps; i += 2, a*=(-1)) {
			bottom *= (i + 1) * (i + 2);
			top *= x * x;
			current = top / bottom;
			S += current * a;
			}
			std::cout << "x = " << x << "  f(x) = " << S << "   sin(x) = " << sin(x) << std::endl;
			x += dx;
		}

		return 0;
}

//task 6

int main() {
	int n, count = 0;

	std::cout << "Enter natural n :";
	std::cin >> n;

	int max = 1;
	while (n > 1) {
		n = (n % 2 == 0) ? n / 2 : (n * 3) + 1;

		if (n > max)
			max = n;
		else
			max = max;
		count++;
	}
	std::cout << " max = " << max << "  the amount of steps: " << count;
	return 0;
}

//task 7

int main() {
	int N;
	double count = 0.0, R, x = 0., y = 0. ;

	std::cout << "Enter N: ";
	std::cin >> N;
	std::cout << "Enter R: ";
	std::cin >> R;

	for (int i = 0; i < N; ++i) {
		double x = (double)rand() / RAND_MAX;
		double y = (double)rand() / RAND_MAX;
		if (x * x + y * y <= R * R)
			++count;
	}
	std::cout << "The result = " << count / N << std::endl;
	return 0;
}

//task 8

int main() {
	int n;
	int Sum = 0, Mult = 1;
	std::cout << "Enter n: ";
	std::cin >> n;

	while (n > 0) {
		Sum += n % 10;
		Mult *= n % 10;
		n /= 10;
	}
	std::cout << "Summa = " << Sum << " \nMultiplication = " << Mult << std::endl;

	return 0;
}*/

//task 9
/*
int main() {
	int n;

	std::cout << "Enter n: ";
	std::cin >> n;

	int tmp = 1;
	
	while (tmp <= n)
		tmp *= 2;

	std::cout << "the result: ";

	while (tmp > 1) {
		tmp /= 2;
		int chast = n / tmp;
		std::cout << chast;
		n %= tmp;
	}
	
	return 0;
}

//task 10

void convert(int dig) {
	if (dig == 0) {
		return;
	}

	//int tmp = dig % 16;     // –≈ ”–—»я
	//dig /= 16;
	//convert(dig);
	//if (tmp > 9)
		//std::cout << (char)(tmp + 55);
	//else
		//std::cout << tmp;
//}
	int tmp = 1;
	while (tmp <= dig) {
		tmp *= 16; //возведение в степень дл€ дальнейшего сравнени€
	}
	while (tmp > 1) {
		tmp /= 16; // типа корень
		int chast = dig / tmp;
		if (chast > 0) {
			if (chast > 9)
				std::cout << (char)(chast + 55);
			else
				std::cout << chast;
			dig %= tmp;
		}
		else
			std::cout << "0";
	}
}

int main() {
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;

	std::cout << "result = ";
	convert(n);
	return 0;
}

//TASK 12

int main() {
	int n, a;
	std::cout << "Enter number: ";
	std::cin >> n;
	std::cout << "Enter the base (2-16): ";
	std::cin >> a;

	if (a < 2 || a > 16) {
		std::cout << "u are wrong. the base is from 2 to 16! ";
		return -1;
	}

	if (n == 0)
		return -1;

	std::cout << "The result: ";

	int tmp = 1;

	while (tmp <= n)
		tmp *= a; //степень

	while (tmp > 1) {
		tmp /= a;
		int chast = n / tmp;
		if (a > 9) {
			if (chast > 9) {
				std::cout << (char)(chast + 55);
			}
			else {
				std::cout << chast;
			}
			n %= tmp;
		}

		else if (a <= 9 && a >= 2) {
			std::cout << chast;
			n %= tmp;
		}
	}
	return 0;

}*/

//task 13

void ToRoman1(int number)
{
	if ((number < 0) || (number > 3999)) std::cout<< "insert value betwheen 1 and 3999";
	else {
		if (number < 1) return;
		if (number >= 1000) { std::cout << "M"; return ToRoman1(number - 1000); }
		if (number >= 900) { std::cout << "CM"; return ToRoman1(number - 900); }
		if (number >= 500) { std::cout << "D"; return ToRoman1(number - 500); }
		if (number >= 400) { std::cout << "CD"; return ToRoman1(number - 400); }
		if (number >= 100) { std::cout << "C"; return ToRoman1(number - 100); }
		if (number >= 90) { std::cout << "XC"; return ToRoman1(number - 90); }
		if (number >= 50) { std::cout << "L"; return ToRoman1(number - 50); }
		if (number >= 40) { std::cout << "XL"; return ToRoman1(number - 40); }
		if (number >= 10) { std::cout << "X"; return ToRoman1(number - 10); }
		if (number >= 9) { std::cout << "IX"; return ToRoman1(number - 9); }
		if (number >= 5) { std::cout << "V"; return ToRoman1(number - 5); }
		if (number >= 4) { std::cout << "IV"; return ToRoman1(number - 4); }
		if (number >= 1) { std::cout << "I"; return ToRoman1(number - 1); }
	}
}

int main() {
	int n;
	std::cout << "Enter the number: ";
	std::cin >> n;

	std::cout << "The result: ";
	ToRoman1(n);

}