#include <iostream>

void snakeArray(int** A, int n, bool flag) {				//task3
	int counter = 1;
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0) {
				for (int j = 0; j < n; ++j, ++counter) {
					if (flag == true) { A[i][j] = counter; }
					else { A[j][i] = counter; }
				}
			}
			else {
				for (int j = n - 1; j >= 0; --j, ++counter){
					if (flag == true) { A[i][j] = counter; }
					else { A[j][i] = counter; }
			}
		}
	}
}

void task1(int** arr, int rows, int cols) {
	int idx = 1;
	for (int i = 0; i < rows; ++i) {							 //task1
		if (i % 2 == 0) {
			for (int j = 0; j < cols; ++j, ++idx) {
				arr[i][j] = idx;
			}
		}
		else {
			for (int j = cols - 1; j >= 0; --j, ++idx) {
				arr[i][j] = idx;
			}
		}
	}
}



int len(int val){
	int cnt = 0;
	while (val > 0)
	{
		val /= 10;
		++cnt;
	}
	return cnt;
}

int maxlen(int** arr, int rows, int cols) {
	int max = arr[0][0];
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			if (max > arr[i][j]) {
				max = arr[i][j];
			}
	}

	int cnt = len(max);

	return cnt;
}

void task2(int** arr, int rows, int cols) {	//task2
	
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			arr[i][j] = rand() % 100000 + 1;
		}
	}
}


void printMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << matrix[i][j] << '\t';
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

double mysqrt(double x, double eps = 1e-6) {			//task4		
	double z_n1 = 1.0, z_n = 0.0;
	while (std::abs(z_n1 - z_n) > eps)
	{
		z_n = z_n1;
		z_n1 = z_n - (z_n * z_n - x) / (2 * z_n);
	}
	return z_n1;
}


void task5(int** arr, int rows, int cols, bool flag) {
	int i = 0, j;
	int k = 0, idx = 0;

	while (i < rows * cols) {
		++k;
		if (flag == true) {
			for (j = k - 1; j < cols - k + 1; ++j) {
				arr[k - 1][j] = ++idx;
				++i;
			}

			for (j = k; j < rows - k + 1; ++j) {  //ïðàâàÿ âåðòèêàëü
				arr[j][cols - k] = ++idx;
				++i;
			}

			for (j = cols - k - 1; j >= k - 1; --j) {
				arr[rows - k][j] = ++idx;
				++i;
			}

			for (j = rows - k - 1; j >= k; --j) {
				arr[j][k - 1] = ++idx;
				++i;
			}

		}
		else {
			if (idx != rows * cols - 1)
			{
				for (j = k - 1; j < rows - k; ++j) {
					arr[j][k - 1] = ++idx;
					++i;
				}
				for (j = k - 1; j < cols - k; ++j) {
					arr[rows - k][j] = ++idx;
					++i;
				}
				for (j = rows - k; j >= k; --j) {
					arr[j][cols - k] = ++idx;
					++i;
				}
				for (j = cols - k; j > k - 1; --j) {
					arr[k - 1][j] = ++idx;
					++i;
				}
			}
			else {
				arr[k - 1][k - 1] = ++idx;
				++i;
			}			
		}
	}
}

void task6(int** arr, int rows, int cols ) {
		int max = 0;
		
		for (int j = 0; j < cols; ++j) {
			for (int i = 0; i < rows; ++i) {
				arr[i][j] = rand() % 10000 + 1;
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}
		}
		max = len(max);
		for (int j = 0; j < cols; ++j) {
			for (int i = 0; i < rows; ++i) {
				int x = len(arr[i][j]);
				
				for (int i = 0; i <= max - x; ++i) std::cout << " ";
				std::cout << arr[i][j];
			}
			std::cout << std::endl;
		}
}

void shiftArray(int* A, int n, int k){
  	k %= n;
   	if (k == 0)
        	return;
	while (counter < k) {
		int tmp_1 = A[0];
		for (int i = 0; i < n; ++i) {
			A[i] = A[i + 1];
		}
		A[n - 1] = tmp_1;
		++counter;
	}
	std::cout << "The result (task 7):\n";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}


void task8(int**arr, int rows, int cols, bool flag) {
	int idx = 0, x = -1, y = 1, x1 = 1, y1 = -1;
	while (idx < rows * cols) {
		if (flag == true) {
			while (y > 0 && x < cols - 1) {
				--y, ++x, ++idx;
				arr[y][x] = idx;
			}
			if (y == 0 && x < cols - 1)
				++x;
			else
				++y;
			++idx; arr[y][x] = idx;
		}
		else {
			while (x1 > 0 && y1 < rows - 1) {
				++idx; ++y1; --x1;
				arr[y1][x1] = idx;
			}
			if (x1 == 0 && y1 < rows - 1)
				++y1;
			else
				++x1;
			++idx; arr[y1][x1] = idx;
		}
		if (flag == true) {
			if (idx != cols * rows)	{
				while (y < rows - 1 && x > 0) {
					++idx; ++y; --x;
					arr[y][x] = idx;
				}
				if (x == 0 && y < rows - 1)
					++y;
				else
					++x;
				++idx; arr[y][x] = idx;
			}
		}
		else {
			if (idx != cols * rows) {
				while (y1 > 0 && x1 < cols - 1) {
					++idx; --y1; ++x1;
					arr[y1][x1] = idx;
				}
				if (y1 == 0 && x1 < cols - 1)
					++x1;
				else
					++y1;
				++idx; arr[y1][x1]= idx;
			}
		}
	}
	printMatrix(arr, rows, cols);

}

int main() {
	int cols, rows, n;
	bool flag;
	std::cout << "Enter columns: ";
	std::cin >> cols;
	std::cout << "Enter rows: ";
	std::cin >> rows;
	std::cout << "Enter n (for tasks 3 and 7): ";
	std::cin >> n;
	std::cout << "Enter '1' if you want to fill in ONE way and enter '0' in ANOTHER way: ";
	std::cin >> flag;


	int** arr;
	arr = new int* [rows];
	for (int i = 0; i < rows; ++i)
		arr[i] = new int[cols];


	int** arr5;
	arr5 = new int* [rows];
	for (int i = 0; i < rows; ++i)
		arr5[i] = new int[cols];


	int** arr2;
	arr2 = new int* [n];
	for (int i = 0; i < n; ++i)
		arr2[i] = new int[n];


	int** arr8;
	arr8 = new int* [rows];
	for (int i = 0; i < rows; ++i)
		arr8[i] = new int[cols];

	int* A = new int[n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = i;
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	int k;
	std::cout << "Enter shifting num: ";
	std::cin >> k;
	shiftArray(A, n, k);

	std::cout << "Snake array(3): \n";
	snakeArray(arr2, n, flag);
	printMatrix(arr2, n, n);


	std::cout << "Task 1: \n";
	task1(arr, rows, cols);
	printMatrix(arr, rows, cols);


	std::cout << "Task 2: \n";
	task2(arr, rows, cols);
	printMatrix(arr, rows, cols);


	std::cout << "Task 5: \n";
	task5(arr5, rows, cols, flag);
	printMatrix(arr5, rows, cols);

	std::cout << "Task 6: \n";
	task6(arr, rows, cols);
	

	std::cout << "Task 8: \n";
	task8(arr8, rows, cols, flag);






	for (int i = 0; i < rows; ++i)
		delete[] arr5[i];

	for (int i = 0; i < rows; ++i)
		delete[] arr8[i];

	for (int i = 0; i < n; ++i)
		delete[] arr2[i];

	for (int i = 0; i < rows; ++i)
		delete[] arr[i];

	delete[]arr2;
	delete[]arr;
	delete[]arr5;
	delete[]arr8;
	delete[]A;
	return 0;
}
