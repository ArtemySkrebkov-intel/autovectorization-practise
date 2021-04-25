#pragma once

#include <cstdlib>
#include <ctime>

#define N 1024*1024

struct testFunc{
    __attribute__((noinline))
	void run(){
		for (int i=0; i < N; i++) {
            r[i] = i;
        }
	}
private:
	int r[N];
};