#include <iostream>
#include <cmath>

//task 1
 /*
int main() {
	setlocale(LC_ALL, "rus");
	int hours1, hours2, min1, min2, sec1, sec2, res, hour;

	std::cout << "¬ведите врем€ начала в часах: ";
	std::cin >> hours1;
	std::cout << "¬ведите врем€ начала в минутах: ";
	std::cin >> min1;
	std::cout << "¬ведите врем€ начала в секундах: ";
	std::cin >> sec1;
	std::cout << "¬ведите врем€ завершени€ в часах: ";
	std::cin >> hours2;
	std::cout << "¬ведите врем€ завершени€ в минутах: ";
	std::cin >> min2;
	std::cout << "¬ведите врем€ завершени€ в секундах: ";
	std::cin >> sec2;

	res = (hours2 - hours1) * 3600 + (min2 - min1) * 60 + (sec2 - sec1); //все в сек

	hour = res / 3600;//тип инт, поэтому отрубит концовку, надо будет умножать на 3600 дл€ вычитани€ только часов в сек

	std::cout<<"ѕрошло "<< hour << " часа(-ов)" << std::endl;
	std::cout << "ѕрошло " << (res - hour * 3600)/ 60 << " минут" << std::endl;
	std::cout << "ѕрошло " << res - (hour * 3600) - (((res - hour * 3600) / 60) * 60) << " секунд" << std::endl;

	return 0;
}
*/

//task 2
/*
int main() {
	setlocale(LC_ALL, "rus");

	double x;
	int N, S = 0;

	std::cout << "¬ведите x: ";
	std::cin >> x;
	std::cout << "¬ведите N: ";
	std::cin >> N;

	int* A = new int [N + 1];

	for (int i = 0; i < N + 1; ++i) {
		std::cout << "¬ведите " << i << "-ый коэффициент: ";
		std::cin >> A[i];
		S += A[i] * pow(x, i);
	}
	std::cout << "Summ = " << S << std::endl;
	delete[]A;

	return 0;
}
*/



//task 3
/*
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

long hex2dec(const char* hex, int len) {
    //найдем знак
    int  sign = 1;
    if (len > 0 && hex[0] == '-')
        sign = -1;
    long result = 0;
    // 16 - максимальное кол-во символов в long hex
    for (int i = (sign == 1) ? 0 : 1; i < len && i < 17; ++i) {
        if (hex[i] >= '0' && hex[i] <= '9')
            result += (hex[i] - '0') * pow(16, len - i - 1);
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            result += (hex[i] - 55) * pow(16, len - i - 1);
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            result += (hex[i] - 87) * pow(16, len - i - 1);
        else {
            std::cout << "Error \n";
            return 0;
        }
    }
    return sign * result;
}

std::string dec2hex(int dec) {
    //найдем знак
    char tmp[20];
    bool pos = true;
    if (dec < 0) {
        pos = false;
        dec = -1 * dec;
    }
    short count_dig = 0;
    while (dec > 0) {
        int dig = dec % 16;
        if (dig < 10)
            dig += '0';
        else
            dig += 55; // 'A'=65 тогда 10= 65-55 ; 11 'B'-55
        tmp[count_dig++] = dig;
        dec /= 16;
    }
    //дл€ того чтобы строку можно вывести строка дожна заканчиватьс€ 0
    tmp[count_dig] = 0;
    char result[20] = { '-' };
    int j = (pos) ? 0 : 1;

    for (int i = count_dig - 1; i >= 0; --i, ++j) // эфективней было бы swap, но тогда сложнее алгоритм
        result[j] = tmp[i];

    return result;
}

int main() {
    char hex[18];
    int hex2, len;
    std::cout << "Enter the number (from 16 to 10): ";
    std::cin >> hex;
    std::cout << "Enter the amount of elements (ex: ABCD = 4): ";
    std::cin >> len;
    std::cout << "Result: " << hex2dec(hex, len) << std::endl;
    std::cout << "Enter the number (from 10 to 16): ";
    std::cin >> hex2;
    std::cout << "Result: " << dec2hex(hex2);
    return 0;
}
*/


//task 4

/*
int main() {
    int N;
    std::cout << "Enter N: ";
    std::cin >> N;
    int *A = new int[N];

    for (int i = 0; i < N + 1; ++i)
        A[i] = i;

    for (int i = 0, j = N; i <= N / 2; ++i, --j)
        std::cout << A[i] << '\t' << A[j] << '\t';

    delete[]A;
    return 0;
}

*/

//task 5

/*
int main() {
    int N, summax = 0, A1, A2;
    std::cout << "Enter N: ";
    std::cin >> N;
    int* A = new int[N];

    for (int i = 0; i <= N; ++i) {
        A[i] = rand() % 100 + 1;
        std::cout << "A [ " << i << " ] = " << A[i] << "\t";
    }
    std::cout << '\n';

    for (int i = 0; i < N; ++i) {
        if (A[i] + A[i + 1] > summax) {
            summax = A[i] + A[i + 1];
            A1 = A[i];
            A2 = A[i + 1];
        }
    }
    std::cout << "The first element: " << A1 << "\t" << "The second element: " << A2 << "   Their sum = " << summax;
    delete[]A;
    return 0;
}
*/

//task 6

/*
int main() {
    int N, d;
    bool flag = true;
    std::cout << "Enter N: ";
    std::cin >> N;

    int* A = new int[N];
    for (int i = 0; i < N; ++i) {
        std::cout << "A [ " << i << " ] = ";
        std::cin >> A[i];
    }
    int a = A[1];
    d = A[1] - A[0];
    if (N > 2) {
        for (int i = 2; i < N; ++i) {
            if (A[i] - a == d) {
                a = A[i];
            }
            else
                flag = false;
        }
    }
    if (flag) {
        std::cout << "d = " << d;
    }
    else
        std::cout << "0";

    delete[]A;
    return 0;
}
*/


//task 7

/*
void floor(int n) {
    int sections = 1, floor = 1, prev, room;
    int S = 0;
        do {
            prev = S;
            S += sections * sections;
            sections++;
        } while (S < n);

        int prev_floor = (sections - 1) * (sections - 2) / 2;
        int floor_sec = (n - prev) / (sections - 1);

        if (((n - prev) - floor_sec * (sections - 1)) == 0) {
            room = sections - 1;
            floor = prev_floor + floor_sec - 1;
        }
        else {
                room = (n - prev) - floor_sec * (sections - 1);
            floor = prev_floor + floor_sec;
        }
        std::cout << "floor = " << floor + 1 << " location = " << room << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the room: ";
    std::cin >> n;
    floor(n);
}
*/

//task 8

/*
#include <string>

	void simple(int N, bool feminine = false) {
	setlocale(LC_ALL, "rus");
	switch (N / 100) {
	case 1:
		std::cout << "сто ";
		break;
	case 2:
		std::cout << "двести ";
		break;
	case 3:
		std::cout << "триста ";
		break;
	case 4:
		std::cout << "четыреста ";
		break;
	case 5:
		std::cout << "п€тьсот ";
		break;
	case 6:
		std::cout << "шестьсот ";
		break;
	case 7:
		std::cout << "семьсот ";
		break;
	case 8:
		std::cout << "восемьсот ";
		break;
	case 9:
		std::cout << "дев€тьсот ";
		break;
	default:
		break;
	}
	N %= 100;
	if (N >= 10 && N <= 19) {
		switch (N) {
		case 10:
			std::cout << "дес€ть ";
			break;
		case 11:
			std::cout << "одиннадцать ";
			break;
		case 12:
			std::cout << "двенадцать ";
			break;
		case 13:
			std::cout << "тринадцать ";
			break;
		case 14:
			std::cout << "четырнадцать ";
			break;
		case 15:
			std::cout << "п€тнадцать ";
			break;
		case 16:
			std::cout << "шестнадцать ";
			break;
		case 17:
			std::cout << "семнадцать ";
			break;
		case 18:
			std::cout << "восемнадцать ";
			break;
		case 19:
			std::cout << "дев€тнадцать ";
			break;
		default:
			break;
		}
	}
	switch ((N / 10) % 10) {
	case 2:
		std::cout << "двадцать ";
		break;
	case 3:
		std::cout << "тридцать ";
		break;
	case 4:
		std::cout << "сорок ";
		break;
	case 5:
		std::cout << "п€тьдес€т ";
		break;
	case 6:
		std::cout << "шестьдес€т ";
		break;
	case 7:
		std::cout << "семьдес€т ";
		break;
	case 8:
		std::cout << "восемдес€т ";
		break;
	case 9:
		std::cout << "дев€носто ";
		break;
	}
	N %= 10;
	switch (N % 10) {
	case 1:
		if (!feminine) //всегда ж.р
			std::cout << "один ";
		else
			std::cout << "одна ";
		break;
	case 2:
		if (!feminine)
			std::cout << "два ";
		else
			std::cout << "две ";
		break;
	case 3:
			std::cout << "три ";
		break;
	case 4:
		std::cout << "четыре ";
		break;
	case 5:
		std::cout << "п€ть ";
		break;
	case 6:
		std::cout << "шесть ";
		break;
	case 7:
		std::cout << "семь ";
		break;
	case 8:
		std::cout << "восемь ";
		break;
	case 9:
		std::cout << "дев€ть ";
		break;
	default:
		break;
	}
}


int main() {
	setlocale(LC_ALL, "rus");

	int N;
	std::cout << "¬ведите N (меньше 1млрд): ";
	std::cin >> N;

	if (N >= 1000000000) {
		std::cout << "¬ы ввели некорректное число: " << std::endl;
		return -1;
	}

	if (N >= 1000000) {
		if (N / 1000000 > 0) {
			simple(N / 1000000);
			if (N / 1000000 == 11) {
				std::cout << "миллионов ";
			}
			else if ((N / 1000000) % 10 == 1)
				std::cout << "миллион ";
			else if ((N / 1000000) % 10 == 2 || (N / 1000000) % 10 == 3
				|| (N / 1000000) % 10 == 4)
				std::cout << "миллиона ";
			else
				std::cout << "миллионов ";
		}
	}
	N = N % 1000000; //на тыс€чи
	if (N >= 1000) {
		int n = N / 1000;
		if (n > 0) {
			simple(n, true);
			if (n == 11)
				std::cout << "тыс€ч ";
			else if (n % 10 == 1)
				std::cout << "тыс€ча ";
			else if (n % 10 == 2 || n % 10 == 3 || n % 10 == 4)
				std::cout << "тыс€чи ";
			else
				std::cout << "тыс€ч ";
		}
	}
	N = N % 1000;

	if (N > 0) {
		simple(N);
		std::cout << std::endl;
	}
	return 0;
}
*/

//task 9

/*
	int main() {
	const int N = 10;
	int sum = 0, arith_sum = 0;
	int A[N];
	for (int i = 0; i < N; ++i) {
		std::cout << "A [" << i << "] = ";
		std::cin >> A[i];
		sum += A[i];
	}
	arith_sum = (1 + N) * N / 2;
	std::cout << "The missing number is " << arith_sum - sum << std::endl;
	return 0;
}
*/