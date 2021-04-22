#include <iostream>
#include <sstream>
#include <chrono>
#include <numeric>
#include <array>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

template <typename Runnable, int num_run_cycles = 1000000, int num_tests = 10>
	struct BenchmarkingTimer{
		void run(){
			for(int i = 0; i < num_tests; i++){
				Runnable runnable_object_{};
				Timer t{intervals_[i].first, intervals_[i].second};
				for(int i = 0; i < num_run_cycles; i++){
					runnable_object_.run();
				}
			}
		}

		std::string durations() const{
			std::stringstream ss;
			int i{1};
			for(const auto& interval: intervals_){
				ss << "Test-" << i++  << " duration = " << (interval.second - interval.first) * 0.001 << " ms" << std::endl;
			}
			return ss.str();
		}

		double average_duration(){
			auto duration_sum{0.0};
			for(const auto& interval: intervals_){
				duration_sum += (interval.second - interval.first) * 0.001;
			}
			if (num_tests) return (duration_sum/num_tests);
			return 0;
		}

		private:
		std::array<std::pair<double, double>, num_tests> intervals_{};

		struct Timer{
			Timer(double& start, double& finish):finish_(finish) { start = now(); }
			~Timer() { finish_ = now(); }

			private:
			double& finish_;
			double now(){ 
				return std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
			}
		};

	};

#define N 10*1024*1024
struct testFunc{
    testFunc() : a(N), b(N), r(N) {
        srand (time(NULL));
        for (int i =0; i < N; i++) {
           a[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
           b[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        }
    }

	void run(){
		for (int i=0; i < N; i++) {
            r[i] = a[i] * b[i];
        }
	}
	private:
	    std::vector<float> a, b, r;
};


int main() {
    BenchmarkingTimer<testFunc, 100, 10> test;
	test.run();
	std::cout << test.durations() << std::endl;
	std::cout << "average duration = " << test.average_duration() << " ms" << std::endl;
	return 0;
}
