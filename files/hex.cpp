#include <fstream>
#include <iostream>

std::string to_HeX(int n) {
    std::string s;
    while (n) {
        int r = n % 16;
        if (r < 10)
            s = char(r + '0') + s;
        else
            s = char(r - 10 + 'A') + s;
        n /= 16;
    }
    return s;
}

std::string to_HeX(unsigned char ch) {
    int n = ch;
    std::string s;

    while (n) {
        int r = n % 16;
        if (r < 10)
            s = char(r + '0') + s;
        else 
            s = char(r - 10 + 'A') + s;
        n /= 16;
    }
    if (s.length() < 2)
        s = "0" + s;

    return s;
}

std::string str_num(int n) {
    std::string s = to_HeX(n);
    int len = s.length();

    for (int i = 0; i < 10 - len; ++i) 
        s = '0' + s;
    return s;
}

int main() {
    char ifname[256];
    char ofname[256];

    std::cout << "Source: ";
    std::cin.getline(ifname, 256);

    std::cout << "Destination: ";
    std::cin.getline(ofname, 256);
   
    std::ifstream inFile(ifname, std::ios_base::binary);
    if (!inFile) {
        std::cout << "Can not open file " << ifname << std::endl;
        return 1;
    }
    std::ofstream outFile(ofname, std::ios_base::binary);
    if (!inFile) {
        std::cout << "Can not open file " << ofname << std::endl;
        inFile.close();
        return 2;
    }

    unsigned char ch;
    int count = 0, count_str = 0;
    std::string s;

    while (inFile.peek() != EOF) {
        if (!count) 
            outFile << str_num(count_str) << "0: ";
        
        ch = inFile.get();
        ++count;

        if (ch < 32)
            s += '.';
        else 
            s += ch;
        outFile << to_HeX(ch) << " ";
        if (count == 8) {
            outFile << "| ";
        }

        if (count == 16) {
            outFile << " | " << s << std::endl;
            count = 0;
            s = "";
            ++count_str;
        }

    }
    if (count and count < 8) {
        for (int i = 0; i < 8 - count; ++i) 
            outFile << "   ";

        outFile << "| ";

        for (int i = 0; i < 8; ++i)
            outFile << "   ";

        outFile << " | " << s;
    }
    else if (count) {
        for (int i = 0; i < 16 - count; ++i) 
            outFile << "   ";

        outFile << " | " << s;
    }

    inFile.close();
    outFile.close();
    return 0;
}