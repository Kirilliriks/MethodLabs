//
// Created by KirilliriK on 20.02.2022.
//

#include <iostream>
#include <cmath>

float func(float x) {
    return x + std::log10(x) - 0.5;//x * x * x + 3 * x + 1;
}

float funcFirst(float x) {
    return 1 + 1 / (std::log(10) * x);//3 * x * x + 3;
}

int main() {
    float accuracy, M; //Точность
    float initialApproximation;

    accuracy = 0.0000001;

    M = 1.4;//3;

    initialApproximation = 1;//-1;

    std::cout << "Xi " << initialApproximation << " f(Xi) " << func(initialApproximation) << " f1(Xi) " << funcFirst(initialApproximation) << " |f(Xi)|/m " << (std::abs(func(initialApproximation)) / M) << std::endl;
    while ((std::abs(func(initialApproximation)) / M) > accuracy) {
        initialApproximation = initialApproximation - func(initialApproximation) / funcFirst(initialApproximation);
        std::cout << "Xi " << initialApproximation << " f(Xi) " << func(initialApproximation) << " f1(Xi) " << funcFirst(initialApproximation) << " |f(Xi)|/m " << (std::abs(func(initialApproximation)) / M) << std::endl;
    }

    std::cout << "Root value " << initialApproximation << std::endl;
    std::cout << "Function value " << func(initialApproximation) << std::endl;
    return 0;
}
