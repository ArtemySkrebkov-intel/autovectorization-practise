#pragma once

#include <cstdlib>
#include <ctime>

#define N 1024*1024

struct testFunc{
    testFunc() {
        srand (time(NULL));
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Rpass"
#pragma clang diagnostic ignored "-Rpass-missed"
#pragma clang diagnostic ignored "-Rpass-analysis"
        for (int i =0; i < N; i++) {
           a[i] = static_cast <int> (rand()) % 100;
        }
#pragma clang diagnostic pop
    }

    __attribute__((noinline))
	void run(){
        int min = 0;
		for (int i=0; i < N; i++) {
            int val = a[i];
            if (val < min) min = val;
        }

        min_ = min;
	}
    int min_;
private:
	int a[N];
};