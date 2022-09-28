#include<iostream>
#include <fstream>

int main(int argc, const char* argv[]) {

	if (argc < 3) {
		// 1-file name, 2-1_file, 3 - 2_file
		std::cout << "Error";
		return -1;
	}

	std::ifstream input(argv[1]);

	if (!input.is_open()) {   // check if the file is open
		std::cout << "Error";
		return -1;
	}
	else {
		std::cout << "The file is opened correctly \n";
	}

	std::ofstream output(argv[2]);

	if (!output.is_open()) {   // check if the file is open
		std::cout << "Error";
		return -1;
	}
	else {
		std::cout << "The file is opened correctly \n";
	}

	char a; //because our text in file is full of symbols
	int cnt = 0;
	while ((a = input.get()) != EOF) {    //read the symbols
		if ((a == '$') && (input.peek() == '$') && (cnt % 2 == 0)) {  //checks if the 1st sym is $ and then the second 
			output << "<math>";										  // if cnt is even - the '$' is open
			a = input.get();
			a = input.get();
			++cnt;
		}
		else if ((a == '$') && (input.peek() == '$') && (cnt % 2 != 0)) {
			output << "<\\math>";
			a = input.get();
			a = input.get();
			++cnt;
		}
		if ((a == '$') && (input.peek() != '$') && (cnt % 2 == 0)) {   //checks for 1 sym of '$'
			output << "<math>";
			a = input.get();
			++cnt;
		}
		else if ((a == '$') && (input.peek() != '$') && (cnt % 2 != 0)) {
			output << "<\\math>";
			a = input.get();
			++cnt;
		}
		output << a;
	}


	input.close();
	output.close();
	return 0;
}
