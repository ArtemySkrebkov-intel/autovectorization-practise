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
           a[i] = static_cast <short> (rand()) % 100;
        }
#pragma clang diagnostic pop
    }

    __attribute__((noinline))
	void run(){
        short min = 0;
		for (int i=0; i < N; i++) {
            short val = a[i];
            if (val < min) min = val;
        }

        min_ = min;
	}
    short min_;
private:
	short a[N];
};