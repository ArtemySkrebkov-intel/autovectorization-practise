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
           a[i] = static_cast <int> (rand()) % static_cast <int> (100);
           b[i] = static_cast <int> (rand()) % static_cast <int> (100);
        }
#pragma clang diagnostic pop
    }

    __attribute__((noinline))
	void run(){
		for (int i=0; i < N; i++) {
            r[i] = a[i] + b[i];
        }
	}
private:
	int a[N], b[N], r[N];
};