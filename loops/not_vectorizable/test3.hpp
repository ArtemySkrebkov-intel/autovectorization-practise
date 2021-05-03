
#pragma once

#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

#define N 1024*1024

// Цикл не может быть автовекторизован. Программист, помоги компилятору!
struct testFunc{
    testFunc() : a(N), r(N) {
        srand (time(NULL));
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Rpass"
#pragma clang diagnostic ignored "-Rpass-missed"
#pragma clang diagnostic ignored "-Rpass-analysis"
        for (int i =0; i < N; i++) {
           a[i] = static_cast <short> (rand()) % 100;
        }
#pragma clang diagnostic pop
    }

    __attribute__((noinline))
	void run() {
		for (int i=0; i < N; i++) {
            if (a[i] < 0) {
                break;
            }
            r[i] = a[i] + 100;
        }
	}

private:
	std::vector<short> a, r;
};