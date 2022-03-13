//
// Created by KirilliriK on 13.03.2022.
//

#include <iostream>

const int N = 4;

void reverse(float *matrix, float *vectB, int k, int r) {
    float c;
    for (int i = k; i < N; i++) {
        c = matrix[k + i * N];
        matrix[k + i * N] = matrix[r + i * N];
        matrix[r + i * N] = c;
    }
    c = vectB[k];
    vectB[k] = vectB[r];
    vectB[r] = c;
}

void divide(float *matrix, float *vectB, int k) {
    for (int i = k + 1; i < N; i++) {
        matrix[k + i * N] /= matrix[k + k * N];
    }
    vectB[k] /= matrix[k + k * N];
}

void clear(float *matrix, float *vectB, int k, int r) {
    for (int i = k + 1; i < N; i++) {
        matrix[r + i * N] -= matrix[k + i * N] * matrix[r + k * N];
    }
    vectB[r] -= vectB[k] * matrix[r + k * N];
}

int main() {
    float *matrix;
    float *vectB;
    float vectX[N];
    int i, j, k;

    matrix = new float[N * N] {
            1, -1,  2,  3,
            2,  1,  0,  2,
            1,  3,  1, -1,
            2,-3,  1,  0
    };

    vectB = new float[N] {
            1,2,-1,3
    };

    for (k = 0; k < N - 1; k++) {
        if (matrix[k + k * N] == 0) {
            i = k + 1;
            while(matrix[i + k * N] == 0) {
                i++;
            }
            reverse(matrix, vectB, k, i);
        }
        divide(matrix, vectB, k);
        for (i = k + 1; i < N; i++) {
            clear(matrix, vectB, k, i);
        }
    }
    divide(matrix, vectB, N - 1);

    for (i = N - 1; i >= 0; i--) {
        vectX[i] = vectB[i];
        for (j = i + 1; j < N; j++) {
            vectX[i] -= matrix[i + j * N] * vectX[j];
        }
        std::cout << "x(" << i + 1 << ") = " << vectX[i] << std::endl;
    }
    return 0;
}

//