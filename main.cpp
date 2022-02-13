#include <iostream>
#include <cmath>

// 3.14159/180

float func(float x) {
    return x - 5 * std::sin(x);
}

int main() {
    float first, second; //Первая граница и вторая
    float accuracy; //Точность

    std::cout << "Enter first gap end: " << std::endl;
    std::cin >> first;
    std::cout << "Enter second gap end: " << std::endl;
    std::cin >> second;

    std::cout << "Enter accuracy: " << std::endl;
    std::cin >> accuracy;

    float temp;
    while((second - first) > 2 * accuracy) {
        temp = (first + second) / 2;
        if (func(first) * func(temp) > 0) {
            first = temp;
        } else {
            second = temp;
        }
        std::cout << "First " << first <<  " | Second " << second << std::endl;
    }
    const float result = (first + second) / 2;
    std::cout << "Root value with accuracy " << accuracy << " equals " << result << std::endl;
    return 0;
}
