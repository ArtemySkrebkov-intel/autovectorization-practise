#pragma once

#include <vector>
#include <climits>

#define N 1024*1024

struct testFunc{
    testFunc() : r(N) {
    }

    __attribute__((noinline))
	void run(){
		for (int i=0; i < N; i++) {
            r[i] += 10;
        }
	}
private:
	std::vector<short> r;
};