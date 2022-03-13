//
// Created by KirilliriK on 06.03.2022.
//

#include <iostream>
#include <cmath>
#include <iomanip>

float function(float x) {
    return std::exp(x) * std::cos(x) + x;
}

int main() {
    float first = -1;
    float second = 0;
    float accuracy = 0.00001f;
    float m = 1;
    float initialApproximation = -1;
    if (initialApproximation == second) {
        second = first;
    }
    while(std::abs(function(initialApproximation) / m) > accuracy) {
        initialApproximation -= function(initialApproximation) / (function(initialApproximation) - function(second)) * (initialApproximation - second);
    }
    std::cout << std::fixed << std::setprecision(10) << std::endl;
    std::cout << "x= " << initialApproximation << std::endl;
    std::cout << "f(x)= " << function(initialApproximation) << std::endl;
    return 0;
}