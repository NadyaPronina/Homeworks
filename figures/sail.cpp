#include <iostream>
#include <cmath>

bool inPolygon(double* xp, double* yp, float x, float y, int countSide) {  
    //the same as in star.cpp
    int cnt = 0;
    for (int i = 0, j = countSide - 1; i < countSide; j = i++) {
        if ((((yp[i] <= y) && (y < yp[j])) || ((yp[j] <= y) && (y < yp[i]))) &&
            (x > ((xp[j] - xp[i]) * (y - yp[i]) / (yp[j] - yp[i]) + xp[i])))
            ++cnt;
    }
    return cnt % 2;
}

bool inHalfRound(int R, int x0, int y0, float x, float y) {
    if ((pow(x0 - x, R) + pow(y0 - y, R)) <= pow(R, 2) && y <= 0) {
        return true;
    }
    return false;
}

void figure() {
    double topX[3] = { 1,0,-1 };
    double topY[3] = { 0,2,0 };


    float x_p, y_p;
    std::cout << "Enter x: ";
    std::cin >> x_p;
    std::cout << "Enter y: ";
    std::cin >> y_p;

    if (inPolygon(topX, topY, x_p, y_p, 3) ||
        inHalfRound(1, 1, 0, x_p, y_p) ||
        inHalfRound(1, -1, 0, x_p, y_p)){
        std::cout << "Point is inside a figure" << std::endl;
    }
    else
        std::cout << "Point is not inside a figure" << std::endl;
}

int main() {
    figure();
    return 0;
}
