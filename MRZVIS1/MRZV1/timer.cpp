#include "timer.h"

timer::timer() {
	start = chrono::high_resolution_clock::now();
}

void timer::getTime() {
	end = chrono::high_resolution_clock::now();
	float res = (end - start).count();
	cout << "time passed:" << res;
}

timer::~timer() {

}
