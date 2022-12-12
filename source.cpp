#include <iostream>
//#include <cmath>
#include <math.h>
//#define _USE_MATH_DEFINES


class RegularPolygon {
private:
    int n;
    float angle;
    static int count;
public:
    RegularPolygon(int n) {
        this->n = n;
        this->angle = 2 * M_PI / n;
        count++;
    }
    float area(float length) {
        float height = (length * 0.5) / tan(angle * 0.5);
        float partial_area = length * height * 0.5;
        return (n * partial_area);
    }
    float length(float area) {
        float partial_area = area / n;
        float length = sqrt(partial_area * tan(angle * 0.5) * 4);
        return length;
    }
    int getCount() {
        return count;
    }
};

int RegularPolygon::count = 0;


int main(){
    for (int i = 3; i < 10; i++) {
        RegularPolygon myPolygon(i);
        std::cout << "N: " << i << std::endl;
        std::cout << "Area: " << myPolygon.area(10) << std::endl;
        std::cout << "Length: " << myPolygon.length(100) << std::endl;
        std::cout << "Count: " << myPolygon.getCount() << std::endl;
    }

    return 0;
}