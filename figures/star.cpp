#include <iostream>

//  Теория     метод луча нечетное кол-во - входит, четное - нет
//  Реализация луч горизотально влево

bool inPoly(double* xp, double* yp, float x, float y) {
    //количество пересечений с лучом влево
    int cnt = 0;
    for (int i = 0, j = 9; i < 10; j = i++) {
        if ((((yp[i] <= y) && (y < yp[j])) || ((yp[j] <= y) && (y < yp[i]))) &&
            (x > ((xp[j] - xp[i]) * (y - yp[i]) / (yp[j] - yp[i]) + xp[i])))
            ++cnt;
    } 
    return cnt % 2;
}
int main() {
    double Pi = 3.14159265358979323846;
    double topX[10];
    double topY[10];
    double const R = 5;
    for (int i = 0; i < 10; i += 2) {    //внешние углы
        topX[i] = R * cos(i * 2 * Pi / 10);
        topY[i] = R * sin(i * 2 * Pi / 10);
        std::cout<<" i="<<i<<" x= "<<topX[i]<<" y= "<<topY[i]<< std::endl;
    }
    // найдем расстояние до внутреней вершины
    // координаты по X совпадают (108/2+36 = 90) 
    double r = topX[2] / cos(2 * Pi / 10);
    for (int i = 1; i < 10; i += 2) {
        topX[i] = r * cos(i * 2 * Pi / 10);
        topY[i] = r * sin(i * 2 * Pi / 10);
        std::cout<<"r="<<r<<"== i="<<i<<" x= "<<topX[i]<<" y= "<<topY[i]<< std::endl;
    }

    float x_p, y_p;
    std::cout << "Enter x: ";
    std::cin >> x_p;
    std::cout << "Enter y: ";
    std::cin >> y_p;

    if (inPoly(topX, topY, x_p, y_p))
        std::cout << "Point is inside a star" << std::endl;
    else
        std::cout << "Point is not inside a star" << std::endl;
    return 0;
}
