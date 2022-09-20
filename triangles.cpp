#include <iostream>

//task 1

/*int main() { 
	int n;
	std::cout << "Enter n (height of the triangles): ";
	std::cin >> n;
	
	if (n > 25)
		return -1;

	for (int i = 1; i <= n; ++i) { //от единицы, потому что иначе пропуск 1 строки
		for (int j = 0; j < i; ++j)
			std::cout << "*";
		std::cout << std::endl;
	}
	return 0;
}

//task 2

int main() {
	int n;

	std::cout << "Enter n (height of the triangles): ";
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n - i; ++j) 
			std::cout << " ";
		for (int j = n - i; j <= n + i; ++j)
			std::cout << "*";
		for (int j = n + i + 1; j < 2 * n; ++j)
			std::cout << " ";
		std::cout << std::endl;
	}

	return 0;
}

//task 3

int main() {
	int n;
	std::cout << "Enter n (half of the figure): ";
	std::cin >> n;

	for (int i = 0; i < n; ++i){
		for (int j = 1; j < n - i; ++j)
			std::cout << ' ';
		for (int j = n - 2 * i; j <= n; ++j)
			std::cout << '*';
		std::cout << std::endl;
	}

	for (int i = n - 1; i > 0; --i){
		for (int j = 1; j <= n - i; ++j)
			std::cout << ' ';
		for (int j = n - 2 * i; j < n - 1; ++j)
			std::cout << '*';
		std::cout << std::endl;
	}

	return 0;
}

//task 4 

int main() {
	int n, a;
	std::cout << "Enter n (half of the figure): ";
	std::cin >> n;
	std::cout << "Enter the amount of rhombus: ";
	std::cin >> a;

	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < a; ++k) {
			for (int j = 1; j < n - i; ++j)
				std::cout << " ";
			for (int j = n - 2 * i; j <= n; ++j)
				std::cout << "*";
			for (int j = 1; j < n - i; ++j)
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	for (int i = n - 1; i > 0; --i) {
		for (int k = 0; k < a; ++k) {
			for (int j = 1; j <= n - i; ++j)
				std::cout << " ";
			for (int j = n - 2 * i; j < n - 1; ++j)
				std::cout << "*";
			for (int j = 1; j <= n - i; ++j)
				std::cout << " ";
		}
		std::cout << std::endl;
	}


	return 0;
}

//task 5

int main() {
	int n;
	std::cout << "Enter n (half of the figure): ";
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= n - i; ++j) {
			std::cout << " ";
		}
		for (int j = n - 2 * i; j <= n + 1; ++j) {
			if (j % 2 == 0) {
				std::cout << " ";
			}
			else
				std::cout << "*";
		}
		std::cout << std::endl;
	}
	for (int i = n -1; i >= 0; --i) {
		for (int j = 1; j <= n - i + 1; ++j) {
			std::cout << " ";
		}
		for (int j = n - 2 * i; j <= n; ++j) {
			if (j % 2 == 0) {
				std::cout << " ";
			}
			else
				std::cout << "*";
		}
		std::cout << std::endl;
	}

	return 0;
}*/

//task 6

int main() {
	int n;
	std::cout << "Enter n (half of the figure): ";
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= n - i; ++j)
			if (j != n - i)
				std::cout << " ";
			else
				std::cout << " *";
		for (int j = n - 2 * i; j < n - 1; ++j)
			std::cout << " ";
		if(i != 0)
		std::cout << "*";
		std::cout << std::endl;
	}
	for (int i = n - 2; i >= 0; --i) {
		for (int j = 1; j <= n - i; ++j)
			if (j != n - i)
				std::cout << " ";
			else
				std::cout << " *";
		for (int j = n - 2 * i; j < n - 1; ++j)
			std::cout << " ";
		if (i != 0)
			std::cout << "*";
		std::cout << std::endl;
	}

	return 0;
}