#pragma once

#include <vector>

#define N 1024*1024

struct testFunc{
    testFunc() : r(N) {
    }

    __attribute__((noinline))
	void run(){
		for (int i=0; i < N; i++) {
            r[i] = i;
        }
	}
private:
	std::vector<int> r;
};