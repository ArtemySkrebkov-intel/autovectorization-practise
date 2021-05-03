
#pragma once

#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

#define N 1024*1024
struct Point {
    float x;
    float y;
    float z;
};

// Цикл представленный здесь успешно векторизуется компилятором,
// но есть возможность его соптимизировать, что позволит получить
// больший прирост от векторизации.
// Программист, помоги компилятору выжать максимум из этого цикла!
struct testFunc{
    testFunc() : a(N), r(N) {
        srand (time(NULL));
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Rpass"
#pragma clang diagnostic ignored "-Rpass-missed"
#pragma clang diagnostic ignored "-Rpass-analysis"
        for (int i =0; i < N; i++) {
           a[i].x = static_cast <float> (rand()) / static_cast<float>(RAND_MAX);
           a[i].y = static_cast <float> (rand()) / static_cast<float>(RAND_MAX);
           a[i].z = static_cast <float> (rand()) / static_cast<float>(RAND_MAX);
        }
#pragma clang diagnostic pop
    }

    __attribute__((noinline))
	void run() {
        for (int i = 0; i < N; i++) {
            r[i] = a[i].x * a[i].x + a[i].y * a[i].y + a[i].z * a[i].z;
        }
	}

private:
	std::vector<Point> a;
    std::vector<float> r;
};